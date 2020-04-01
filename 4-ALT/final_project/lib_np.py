#!/usr/bin/env python3

'''
Nombre Alumno: Barbas Rebollo, David
Nombre Alumno: Beltrán Domínguez, Victoria
Nombre Alumno: Ge, Xiangyang
Nombre Alumno: Romero Fernández, Alberto
'''

import sys
import re
import numpy as np
import time

def clean_text(text):
    # Remove all the special characters
    text = re.sub('\W+', ' ', text)
    # Substituting multiple spaces with single space
    text = re.sub(r'\s+', ' ', text, flags=re.I)
    return text.lower()

def process_file(filename):
    text = open(filename, 'r', encoding="utf8").read()
    text = clean_text(text).split(" ")
    text.remove("")
    return list(set(text))

#Devuelve la distancia de leveshtein de alfa a beta o negativo cuando esa palabra conlleva más operaciones que el threshold permitido
def levenshtein_distance(alfa, beta, threshold):
    current_row = np.arange(len(alfa)+1)
    previous_row = np.zeros( (len(alfa)+1),dtype=np.int16 )+ max(len(alfa),len(beta)) +2

    for j in range(1, len(beta)+1):

        previous_row, current_row = current_row, previous_row

        current_row[0] = previous_row[0] + 1

        for i in range(1, len(alfa)+1):
            current_row[i] = min(current_row[i-1]+1,
                                previous_row[i]+1,
                                previous_row[i-1]+ (alfa[i-1] != beta[j-1]))

        if (current_row.min() > threshold):
            return -1
    return current_row[len(alfa)]

def levenshtein_distance_simple(w1, words, threshold):

    v = {}
    for w2 in words:
        distance = levenshtein_distance(w1, w2, threshold)
        if distance>=0 and distance<=threshold:
            if (v.get(distance,0)==0):
                v[distance]=[w2]
            else:
                l=v.get(distance,0)
                l.append(w2)
                v[distance]=l
    aux=""
    lol=0
    for i in range(0,threshold+1):
        listwords=v.get(i,[])
        for x in listwords:
            aux +="{}:{}  ".format(i,x)
            lol+=1

    res=w1+"  "+str(threshold)+"  "+str(lol)+ "  " +aux+"\n"
    print("RESULTADOS CON DISTANCIA DE LEVESHTEIN")
    return res

def damerau4_levenshtein_distance(alfa, beta, threshold):
    current_row = np.arange(len(alfa)+1)
    previous_row = np.zeros( (len(alfa)+1),dtype=np.int16 )+ max(len(alfa),len(beta)) +2
    previous2row = np.copy(current_row)
    j = 1
    while j < len(beta)+1:
        previous_row, current_row, previous2row = current_row, previous2row, previous_row

        current_row[0] = previous_row[0] + 1
        i = 1
        while i < len(alfa)+1:

            current_row[i] = min(current_row[i-1]+1,
                                previous_row[i]+1,
                                previous_row[i-1] + (alfa[i-1] != beta[j-1]))
            if i>1 and j>1 and alfa[i-1]==beta[j-2] and alfa[i-2]==beta[j-1]:
                current_row[i] = min(current_row[i], previous2row[i-2]+1)

            i += 1
        if (current_row.min() > threshold):
            return -1
        j +=1

    return current_row[len(alfa)]

def damerau4_levenshtein_distance_simple(w1, words, threshold):
    v = {}
    for w2 in words:
        distance = damerau4_levenshtein_distance(w1, w2, threshold)
        if distance>=0 and distance<=threshold:
            if (v.get(distance,0)==0):
                v[distance]=[w2]
            else:
                l=v.get(distance,0)
                l.append(w2)
                v[distance]=l
    aux=""
    lol=0
    for i in range(0,threshold+1):
        listwords=v.get(i,[])
        for x in listwords:
            aux +="{}:{}  ".format(i,x)
            lol+=1
    res=w1+"  "+str(threshold)+"  "+str(lol)+"  "+aux+"\n"
    print("RESULTADOS CON DISTANCIA DE DAMERAU")
    return res

def generate_trie(words):
    trie = {}
    for w in words:
        previousState = -1
        currentState = 0
        # Se crea un arbol de estados con transiciones de cada letra de la palabra
        # Cada estado referencia su padre, transiciones y si es final
        for i, c in enumerate(w):
            if (currentState not in trie):
                trie[currentState] = (previousState, {}, None)
            trie[currentState][1].setdefault(c, len(trie))

            previousState = currentState
            currentState = trie[currentState][1][c]

        # Se ha terminado la palabra marcar currentState como estado final
        trie[currentState] = (previousState, {}, w)
        print(trie)

        # pero si currentState no existe ademas se crea un estado nuevo
        if (currentState not in trie):
            trie[currentState] = (previousState, {}, w)
        else :
            trie[currentState] = (trie[currentState][0], trie[currentState][1], w)

    return trie

def return_character(trie,parent,child):
    for x in trie.keys():
        if(trie[x]==child):
            return x

def leveshtreincontratrie(trie, word, threshold):

    current_row = np.zeros(len(trie))
    previous_row = np.zeros(len(trie))
    previous_row[0]=0
    #Inicialización de la primera fila
    for i in range(1,len(current_row)):
        parent=trie[i][0]
        current_row[i]=current_row[parent]+1

    #Bucle para el resto de filas
    for c in word:
        previous_row, current_row = current_row, previous_row
        current_row[0]=previous_row[0]+1
        for i in range(1,len(current_row)):
            parent=trie[i][0]
            parenttrie=trie[parent][1]
            char=return_character(parenttrie,parent,i)
            current_row[i]=min(current_row[parent]+1,previous_row[parent]+(char!=c),previous_row[i]+1)

    #Mirar si las entradas con el threshold menor o igual al permitido son finales
    v={}
    for i in range(1,len(current_row)):
        distance=int(current_row[i])
        if(distance<=threshold and trie[i][2]!=None):
            if (v.get(distance,-1)==-1):
                v[distance]=[trie[i][2]]
            else:
                l=v.get(distance,0)
                l.append(trie[i][2])
                v[distance]=l

    return v

def leveshtreincontratrie_simple(w1, words, threshold):
    trie = generate_trie(words)
    v = leveshtreincontratrie(trie, w1, threshold)
    aux=""
    lol=0
    for i in range(0,threshold+1):
        listwords=v.get(i,[])
        for x in listwords:
            aux +="{}:{}  ".format(i,x)
            lol+=1
    res=w1+"  "+str(threshold)+"  "+str(lol)+"  "+aux+"\n"
    print("RESULTADOS CON TRIE")
    return res

def time_funciton(func, *args):
    start = time.time()
    func(*args)
    end = time.time()
    print("Execution time of {}:\t{}".format(func.__name__, end-start))

if __name__ == "__main__":
    #Si no recibe argumentos
    if len(sys.argv)<4 :
        print('FORMAT ERROR: python lib.py filename word threshold')
        sys.exit()

    words = process_file(sys.argv[1])
    w1 = sys.argv[2]
    threshold = int(sys.argv[3])
    res = ""

    inpt = input("Qué método quieres usar:\n 1.Levenshtein \n 2.Damerau\n 3.Levenshtein vs Trie\n 4.Solo Generar Trie\n 5.Testear tiempos\n")
    print("\n")

    if int(inpt) == 1:
        res = levenshtein_distance_simple(w1, words, threshold)
    if int(inpt) == 2:
        res = damerau4_levenshtein_distance_simple(w1, words, threshold)
    if int(inpt) == 3:
        res = leveshtreincontratrie_simple(w1, words, threshold)
    if int(inpt) == 4:
        res = generate_trie(words)
    if int(inpt) == 5:
        pass
    print(res)
