#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Nombre Alumno: Xianyang Ge
Nombre Alumno: Alberto Romero Fernández
Nombre Alumno: Victoria Beltrán Domínguez
Nombre Alumno: David Barbas Rebollo
"""
from ALT_library import *
import sys
import os
import pickle
import re
import json
import nltk
stemmer = nltk.stem.SnowballStemmer('spanish')

#Variable que servirá para controlar si la búsqueda se hace por stemming o no
stemming=False
#Diccionarios globales
termDic = {}
docDic = {}
stemTitleDict={}
stemSummaryDict={}
stemTermDict={}
titleDict={}
urlDict={}
summDict={}
dateDict={}
keywordsDict={}
idDict={}
rankDict = {}
#palabras para snippet
wordlist = []


def load_json(filename):
    with open(filename) as fh:
        obj = json.load(fh)
    return obj

def load_object(filename):
    with open(filename, "rb") as fh:
        obj = pickle.load(fh)
    return obj

def inicializar(filename):
    obj = load_object(filename)
    global termDic
    global docDic
    global titleDict
    global urlDict
    global summDict
    global dateDict
    global keywordsDict
    global idDict
    global stemTitleDict
    global stemSummaryDict
    global stemTermDict
    global trie
    termDic =           obj[0]
    docDic =            obj[1]
    stemTitleDict =     obj[2]
    stemSummaryDict =   obj[3]
    stemTermDict =      obj[4]
    titleDict =         obj[5]
    urlDict =           obj[6]
    summDict =          obj[7]
    dateDict =          obj[8]
    keywordsDict =      obj[9]
    idDict =            obj[10]
    trie =              obj[11]

#Dada una lista=[(docId,newId),(docId,newId),...] la ordena ascendientemente.
def ordenar_lista_tuplas(lista):
    postinglist = []
    s = sorted(lista, key=lambda x: (x[0], x[1]))
    anteriornot=-1
    anteriordoc=-1
    pl=[]
    for i in range(len(s)):

        if anteriornot==s[i][1] and anteriordoc==s[i][0]: pl=list(set(pl+s[i][2]))
        else:
            if anteriornot != -1:
                postinglist.append((anteriordoc,anteriornot,pl))
                anteriornot=s[i][1]
                anteriordoc=s[i][0]
                pl=[]
            else:
                anteriornot=s[i][1]
                anteriordoc=s[i][0]
    i=len(s)-1
    if(i>=0):
        if s[i][0]==anteriordoc and s[i][1]==anteriornot:
            pl=list(set(pl+s[i][2]))
            postinglist.append((anteriordoc,anteriornot,pl))
        else:
            postinglist.append((s[i][0],s[i][1],s[i][2]))

    return postinglist

#Si sólo hay una o dos noticias relevantes.
#Se mostrará la fecha, el titular, las keywords y todo el cuerpo de la o las noticias.
#La entrada es una lista de diccionarios que cada uno contiene los datos de las noticias
def mostrar1a2noticias(resultados):

    for i in range(0, len(resultados)):

        docID = resultados[i][0]
        newsID = resultados[i][1]
        n = docDic[docID][newsID]

        path = n['path']
        d = load_json(path)

        print("[{}]".format(i+1))
        print('Fecha: {}\nTitular: {}\nKeywords: {}\n\n{}\n'.format(n['date'], n['title'], n['keywords'], d[newsID]['article']))

#Si hay entre 3 y 5 noticias relevantes.
#Se mostrará de cada noticia la fecha, el titular, las keywords y un snippet del cuerpo
#de la noticia que contenga los términos buscados.
#Si no se hace búsqueda por el cuerpo de la noticia se mostrarán las primeras 100 palabras.
def mostrar3a5noticias(resultados):
    global wordlist
    wordlist = list(set(wordlist))
    for i in range(0, len(resultados)):
        margen = 5

        docID = resultados[i][0]
        newsID = resultados[i][1]
        n = docDic[docID][newsID]

        path = n['path']
        d = load_json(path)

        print("[{}]".format(i+1))
        print('Fecha: {}\nTitular: {}\nKeywords: {}\n'.format(n['date'], n['title'], n['keywords']))

        palabras = d[newsID]['article']
        palabras = re.sub('\W+', ' ', palabras)
        palabras = palabras.lower().split()

        #Encontrar los indices en los que aparecen las palabras en el documento
        apariciones = []
        start_at = -1
        for word in wordlist:
            while True:
                try:
                    aux = palabras.index(word, start_at+1)
                except ValueError:
                    break
                else:
                    apariciones.append(aux)
                    start_at = aux

        #Establecer un margen en base a los indices
        snippetPos = []
        for pos in apariciones:
            value = pos
            if value-margen < 0:
                value = margen
            snippetPos.append([value-margen, pos+margen])

        #Borrar duplicados dentro de los indices
        mergedPos = []
        posicionesCorregidas = 0
        if len(snippetPos) > 0:
            mergedPos.append(snippetPos[0])
        for i in range(1, len(snippetPos)):
            if(snippetPos[i][0] < mergedPos[posicionesCorregidas][1]):
                mergedPos[posicionesCorregidas]
            else:
                mergedPos.append(snippetPos[i])
                posicionesCorregidas+=1

        #Buscar las palabras en base al rango de indices y convertirlas a texto
        snippet = []
        for pos in mergedPos:
            snippet.append(palabras[pos[0]:pos[1]])

        if len(snippet) > 0:
            text = ' '.join(snippet[0])
        for i in range(1, len(snippet)):
            text += ' ... '
            text += ' '.join(snippet[i])

        print(text+'...\n')
    wordlist = []

#Si hay más de 5 noticias relevantes.
#Se mostrará la fecha, el titular y las keywords de las 10 primeras en una única línea por noticia.
def mostrar6amasnoticias(resultados):
    max = len(resultados)
    if max > 10:
        max = 10
    for i in range(0, max):

        docID = resultados[i][0]
        newsID = resultados[i][1]

        n = docDic[docID][newsID]

        kw = n['keywords'].split()
        kw = (" ").join(kw[:10])

        print("[{}]".format(i+1))
        print('Fecha: {}\nTitular: {}\nKeywords: {}\n'.format(n['date'], n['title'], kw))

#Dadas dos posting list, devolvemos la intersección de ellas
def and_op(l1,l2):
    result=[]
    p1=0
    p2=0
    while p1<len(l1) and p2<len(l2):
        #Si el documento y la noticia es la misma, añadir a respuestas y avanzar ambos p1 y p2
        if (l1[p1][0]==l2[p2][0]) and (l1[p1][1]==l2[p2][1]):
            result.append((l1[p1][0],l1[p1][1], l1[p1][2]+l2[p2][2]))
            p1+=1
            p2+=1
        #Si el documento es el mismo, avanzar el px que tenga menor pos_in_doc
        elif (l1[p1][0]==l2[p2][0]):
            if l1[p1][1]<l2[p2][1]: p1+=1
            else : p2+=1
        #Si el documento no es el mismo,avanzar el px que tenga menor docId
        else:
            if l1[p1][0]<l2[p2][0]: p1+=1
            else: p2+=1
    return result

#Dadas dos posting list, devolvemos la unión de ellas
def or_op(l1,l2):
    result=[]
    p1=0
    p2=0
    while p1<len(l1) and p2<len(l2):
        #Si el documento y la noticia es la misma, añadir a respuestas y avanzar ambos p1 y p2
        if (l1[p1][0]==l2[p2][0]) and (l1[p1][1]==l2[p2][1]):
            result.append((l1[p1][0],l1[p1][1], l1[p1][2]+l2[p2][2]))
            p1+=1
            p2+=1
        #Si el documento es el mismo, avanzar el px que tenga menor pos_in_doc
        elif (l1[p1][0]==l2[p2][0]):
            if l1[p1][1]<l2[p2][1]:
                result.append((l1[p1][0],l1[p1][1], l1[p1][2]))
                p1+=1
            else :
                result.append((l2[p2][0],l2[p2][1], l2[p2][2]))
                p2+=1
        #Si el documento no es el mismo,añadir el menor
        elif(l1[p1][0]<l2[p2][0]):
            result.append((l1[p1][0],l1[p1][1], l1[p1][2]))
            p1+=1
        else:
            result.append((l2[p2][0],l2[p2][1], l2[p2][2]))
            p2+=1
    while p1 < len(l1):
        result.append((l1[p1][0],l1[p1][1], l1[p1][2]))
        p1+=1
    while p2 < len(l2):
        result.append((l2[p2][0],l2[p2][1], l2[p2][2]))
        p2+=1
    return result
#Dada una posting list, devolvemos la negaciń de ellas
def not_op(l1):
    dictlist = []
    for key, value in docDic.items():
        for dic in value:
            tup = (dic['newsID'][0], dic['newsID'][1], [])
            dictlist.append(tup)
    for ite in l1:
        temp = (ite[0], ite[1], [])
        dictlist.remove(temp)
    return dictlist

#la entrada será una subquery sin parentesis
#Asumimos que todas las querys tienen espacios que separan sus terminos
#Devolverá una lista con las noticias que cumplen las especificaciones
def procesaquery(query,diccionario_resultados):
    if query.startswith("("): query=query[1:len(query)-1]
    terminos=query.split(" ")
    resultados=[]
    if len(terminos)==1:
        resultados=procesa_termino(terminos[0],diccionario_resultados)
    else:
        i=0
        #Nos aseguramos de que no hay huecos vacíos en la lista y si hay dos NOT seguidos nos los cargamos
        while i<len(terminos):
            if terminos[i]=="not" and i+1<len(terminos) and terminos[i+1]=="not":
                terminos.pop(i+1)
                terminos.pop(i)
            elif terminos[i]=="":terminos.pop(i)
            else: i+=1
        #Procesamos los operadores lógicos
        i=0
        #En este primer bucle solo vamos a procesar los NOT term
        while i<len(terminos):
            #En la primera posición solo puede haber o un NOT o un término
            if terminos[i]=="not" and i+1<len(terminos):
                #Si el primer elemento que nos encontramos es un not necesariamente el segundo es un término.
                pl=procesa_termino(terminos[i+1],diccionario_resultados)
                pl=not_op(pl)
                terminos.pop(i+1)
                terminos.pop(i)
                terminos.insert(i,pl)
            else :i+=1
        #Si todo funciona bien, tendré una lista con esta estructura lista operador lista operador lista operador...
        #lo mínimo que puedo tener es un elemento con la lista por lo que inicializo resultados a terminos por si fuera el caso
        resultados=terminos[0]
        while len(terminos)>1:
            pl1=procesa_termino(terminos[0],diccionario_resultados)
            pl2=procesa_termino(terminos[2],diccionario_resultados)
            if terminos[1]=="and" : resultados=and_op(pl1,pl2)
            elif terminos[1]=="or" : resultados=or_op(pl1,pl2)
            else:
                print("Situación no contemplada.Se ha asumido que el formato de la query es adecuado...")
                sys.exit(0)
            terminos.pop(2)
            terminos.pop(1)
            terminos.pop(0)
            terminos.insert(0,resultados)
            resultados=terminos[0]

    return resultados

#Dado un termino, te devuelve su posting list dependiendo de donde estes buscando
def procesa_termino(term,dic):
    postinglist=[]
    global wordlist
    #Miramos si el término es una lista y si lo es la devolvemos tal cual
    if type(term) is list:
        postinglist=term

    elif term.startswith("&€"):
        postinglist=dic.get(term,[])
    
    #Buscar con el mejor Leveshtein
    elif "%" in term:
        index=term.index("%")
        threshold=int(term[index+1:])
        term=term[0:index]
        
        if threshold > 5:
            posible_terms_aux = trie_ramificacion(trie,term,threshold,False)
        else:
            posible_terms_aux = leveshtreincontratrie(trie, term, threshold)
        
        posible_terms=[]
        for i in range(threshold+1):
            lista=posible_terms_aux.get(i,-1)
            if(type(lista) is list):
                for termino in lista:
                    posible_terms.append(termino)

            for i in posible_terms:
                aux=termDic.get(i,[])
                wordlist.append(i)
                if len(aux)>0:
                    postinglist=postinglist+aux
                   
            postinglist=ordenar_lista_tuplas(postinglist)
    #Buscar con el mejor Damerau
    elif "@" in term:
        index=term.index("@")
        threshold=int(term[index+1:])
        term=term[0:index]

        if threshold > 5:
            posible_terms_aux = trie_ramificacion(trie,term,threshold,True)
        else:
            posible_terms_aux=damerau_trie(trie, term, threshold)
        
        posible_terms=[]
        for i in range(threshold+1):
            lista=posible_terms_aux.get(i,-1)
            if(type(lista) is list):
                for termino in lista:
                    posible_terms.append(termino)

            for i in posible_terms:
                aux=termDic.get(i,[])
                wordlist.append(i)
                if len(aux)>0:
                    postinglist=postinglist+aux
                   
            postinglist=ordenar_lista_tuplas(postinglist)
        
    #Miramos si el usuario está buscando en un campo en específico
    #Buscamos en keywords
    elif term.startswith("keywords:"):
        #Salvador nos dijo que no hacía falta que hiciesemos stemming en las keywords
        term=term[9:]
        postinglist=keywordsDict.get(term,[])

    #Buscamos en titulo
    elif term.startswith("title:"):
        term=term[6:]
        if stemming:
            term=stemmer.stem(term)
            posibles_terminos=stemTitleDict.get(term,[])
            for i in posibles_terminos:
                aux=titleDict.get(i,[])
                if len(aux)>0:
                    postinglist=postinglist+aux
            postinglist=ordenar_lista_tuplas(postinglist)
        else:
            postinglist=titleDict.get(term,[])

    #Buscamos en url
    elif term.startswith("url:"):
        #No tiene sentido utilizar stemming aunque la opción esté marcada, así que no chequeamos nada
        term=term[4:]
        postinglist=urlDict.get(term,[])

    #Buscamos en date
    elif term.startswith("date:"):
        #No tiene sentido utilizar stemming aunque la opción esté marcada, así que no chequeamos nada
        term=term[5:]
        postinglist=dateDict.get(term,[])

    #Buscamos en id
    elif term.startswith("id:"):
        #No tiene sentido utilizar stemming aunque la opción esté marcada, así que no chequeamos nada
        term=term[3:]
        postinglist=idDict.get(term,[])

    #Buscamos en summary
    elif term.startswith("summary:"):
        term=term[8:]
        if stemming:
            term=stemmer.stem(term)
            posibles_terminos=summDict.get(term,[])
            for i in posibles_terminos:
                aux=termDic.get(i,[])
                if len(aux)>0:
                    postinglist=postinglist+aux
            postinglist=ordenar_lista_tuplas(postinglist)
        else:
            postinglist=summDict(term,[])

    # Buscamos en el article o no se especifica campo de busqueda
    else:
        if term.startswith("article:"):
            term=term[8:]
        if stemming:
            term=stemmer.stem(term)
            posibles_terminos=stemTermDict.get(term,[])
            posibles_terminos=list(set(posibles_terminos))
            
            for i in posibles_terminos:
                aux=termDic.get(i,[])
                wordlist.append(i)
                if len(aux)>0:
                    postinglist=postinglist+aux
                   
            postinglist=ordenar_lista_tuplas(postinglist)
            
        else:
            postinglist=termDic.get(term,[])
            wordlist.append(term)

    return postinglist

#Entramos en un bucle de petición de consulta y devolución de noticias relevantes hasta que la consulta esté vacía.
def resolverconsulta(query):
    nombre=0
    diccionario_resultados={}
    #Asumimos que la query estará bien redactada-> siempre que haya un '(' habrá otro ')' asociado.
    while("(" in query):
        lastpos=query.find(")")
        firstpos=lastpos-1
        while firstpos >0:
            if query[firstpos]=="(": break
            else: firstpos-=1

        subquery=query[firstpos:lastpos+1]
        #En resultados habrá una lista de noticias que cumplen las especificaciones
        resultado=procesaquery(subquery,diccionario_resultados)
        diccionario_resultados["&€"+str(nombre)]=resultado
        query=query[0:firstpos]+" &€"+str(nombre)+" "+query[lastpos+1:len(query)]
        nombre+=1
    termino=query.split()
    i=0
    while(i<len(termino)):
        if(termino[i]==""): termino.pop(i)
        else: i+=1
    #Si aún quedan cosas por procesar
    if len(termino)>1 : resultado= procesaquery(query,diccionario_resultados)
    #Sólo queda una palabra del formato &€número
    else :
        if termino[0].startswith("&€"): resultado=diccionario_resultados[termino[0]]
        elif type(termino[0]) is list: resultado=termino[0]
        else: resultado=procesa_termino(termino[0],diccionario_resultados)
    return resultado


#   AMPLIACION RANK
# Ordenar noticias por longitud de posting list. Cuantas más coincidencias
# tenga una busqueda en una noticia más relevante se considera
def rank_results(resultados):
    return sorted(resultados, key=lambda x: len(x[2]), reverse=True)

if __name__ == "__main__":

    #Si no le pasamos argumentos, mostrar error
    if len(sys.argv)<=1 : print("FORMAT ERROR: python SAR_searcher.py index_directory -s [-q=query]")

    #Si sólo le pasamos un argumento, ese será el índice.Entramos en modo iterativo
    elif len(sys.argv)==2 :
        inicializar(sys.argv[1])
        query = input("Query?: ")
        while(query!=""):

            query=query.lower()
            resultado = rank_results(resolverconsulta(query))

            #Depende de la cantidad de resultados, se muestran cosas diferentes:
            if len(resultado)<=2: mostrar1a2noticias(resultado)
            elif len(resultado)<=5:mostrar3a5noticias(resultado)
            else: mostrar6amasnoticias(resultado)
            print("Encontrado en ",len(resultado)," articulos")
            query=input("Query?: ")

        print("Apagando el programa...")
    #O se le proporcionan el índice y la consulta o se le proporciona el índice y la opción -s
    elif len(sys.argv)==3 :

        inicializar(sys.argv[1])

        #Entramos en modo iterativo pero buscando en stemming
        if sys.argv[2]=="-s":
            stemming=True
            query=input("Query?: ")
            while(query!=""):
                query=query.lower()

                resultado = rank_results(resolverconsulta(query))

                #Depende de la cantidad de resultados, se muestran cosas diferentes:
                if len(resultado)<=2: mostrar1a2noticias(resultado)
                elif len(resultado)<=5:mostrar3a5noticias(resultado)
                else: mostrar6amasnoticias(resultado)
                print("Encontrado en ",len(resultado)," articulos")
                query=input("Query?: ")

            print("Apagando el programa...")

        #Tenemos el índice y la consulta. La resolvemos y finalizamos
        else:
            query=sys.argv[2]
            query=query.lower()
            if not query.startswith('-q='):
                print("FORMAT ERROR: python SAR_searcher.py index_directory [-q=query]")
                sys.exit(1)
            query=query[3:]

            resultado = rank_results(resolverconsulta(query))

            #Depende de la cantidad de resultados, se muestran cosas diferentes:
            if len(resultado)<=2: mostrar1a2noticias(resultado)
            elif len(resultado)<=5:mostrar3a5noticias(resultado)
            else: mostrar6amasnoticias(resultado)
            #Se informará al usuario del número total de noticias recuperadas como último resultado.
            print("Encontrado en ",len(resultado)," articulos")

    #Si proporcionamos tres argumentos, serán el indice, el -s y la query.Resolvemos y finalizamos.

    elif len(sys.argv)==4:
        inicializar(sys.argv[1])
        if sys.argv[2]!="-s":
            print("FORMAT ERROR: python SAR_searcher.py index_directory -s [-q=query]")
            sys.exit(1)
        stemming=True
        query=sys.argv[3]
        if not query.startswith('-q='):
                print("FORMAT ERROR: python SAR_searcher.py index_directory [-q=query]")
                sys.exit(1)
        query=query[3:]
        query=query.lower()

        resultado = rank_results(resolverconsulta(query))

        #Depende de la cantidad de resultados, se muestran cosas diferentes:
        if len(resultado)<=2: mostrar1a2noticias(resultado)
        elif len(resultado)<=5:mostrar3a5noticias(resultado)
        else: mostrar6amasnoticias(resultado)
        #Se informará al usuario del número total de noticias recuperadas como último resultado.
        print("Encontrado en ",len(resultado)," articulos")


    #Demasiados argumentos
    else: print("FORMAT ERROR: python SAR_Searcher.py index_directory [-q=query]")
