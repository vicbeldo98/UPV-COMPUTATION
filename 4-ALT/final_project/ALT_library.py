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
    #print("RESULTADOS CON DISTANCIA DE LEVESHTEIN")
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
    #print("RESULTADOS CON DISTANCIA DE DAMERAU")
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
        # pero si currentState no existe ademas se crea un estado nuevo
        if (currentState not in trie):
            trie[currentState] = (previousState, {}, w)
        else :
            trie[currentState] = (trie[currentState][0], trie[currentState][1], w)

    return trie

def return_character(trie,child):
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
            char=return_character(parenttrie,i)
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
    #print(w1+"  "+str(threshold)+"  "+str(lol)+"  "+aux+"\n")
    return v

def damerau_trie(trie, word, threshold):
    current_row = np.zeros(len(trie))
    previous_row = np.zeros(len(trie))

    for i in range(1, len(current_row)):
        parent = trie[i][0]
        current_row[i] = current_row[parent]+1

    previous2row = np.copy(current_row)
    for i in range(1,len(word)+1):
        previous_row, current_row, previous2row = current_row, previous2row, previous_row
        current_row[0] = previous_row[0] + 1
        for j in range(1, len(current_row)):
            parent = trie[j][0]
            parenttrie = trie[parent][1]
            char = return_character(parenttrie,j)

            current_row[j] = min(current_row[parent]+1,
                                previous_row[parent]+(char!=word[i-1]),
                                previous_row[j]+1)

            if i>1 and j>1:
                nabuelo=trie[parent][0]
                if nabuelo != -1:
                    abuelo=trie[nabuelo][1]
                    char2=return_character(abuelo, parent)
                    if char==word[i-2] and char2==word[i-1]:
                        current_row[j] = min(current_row[j], previous2row[nabuelo]+1)

    v={}
    for i in range(1, len(current_row)):
        distance = int(current_row[i])
        if distance<=threshold and trie[i][2] != None:
            if(v.get(distance, -1)==-1):
                v[distance] = [trie[i][2]]
            else:
                l = v.get(distance, 0)
                l.append(trie[i][2])
                v[distance]= l
    print(v)
    return v

def damerau_trie_simple(word, words, threshold):
    trie = generate_trie(words)
    v = damerau_trie(trie, word, threshold)
    aux=""
    lol=0
    for i in range(0,threshold+1):
        listwords=v.get(i,[])
        for x in listwords:
            aux +="{}:{}  ".format(i,x)
            lol+=1
    res=w1+"  "+str(threshold)+"  "+str(lol)+"  "+aux+"\n"
    #print("RESULTADOS CON DAMERAU vs TRIE")
    return v


def trie_ramificacion(trie, word, threshold, damerau = False):
    # Stack wit initial state to explore
    # indice de la cadena, estado del trie, distancia
    stack = [(0, 0, 0)]
    distance = {}
    res = {}

    while (len(stack) > 0):
        # (wordindex, currentNode, distance)
        currentState = stack.pop()

        currentDistance = currentState[2]
        if (currentDistance > threshold): continue

        currentNode = currentState[1]
        wordIndex = currentState[0]
        childs = trie[currentNode][1]
        
        # Si es final y el indice coincide con la longitud de la palabra
        # se guarda la palabra en el indice del threshold
        if (trie[currentNode][2] is not None and wordIndex == len(word)):
            if res.get(distance[(wordIndex, currentNode)]) is None:
                res[distance[(wordIndex, currentNode)]] = [trie[currentNode][2]]
            else :
                res[distance[(wordIndex, currentNode)]].append(trie[currentNode][2])

        # Deletion
        if (wordIndex < len(word)) :
            s = (wordIndex + 1, currentNode)
            if ((s not in distance) or (currentDistance + 1 < distance[s])):
                distance[s] = currentDistance + 1
                stack.append((s[0], s[1], currentDistance + 1))

        for childChar, childNode in childs.items():
            # Insertion
            s = (wordIndex, childNode)
            if ((s not in distance) or (currentDistance + 1 < distance[s])):
                distance[s] = currentDistance + 1
                stack.append((s[0], s[1], currentDistance + 1))

            # Substitution
            if (wordIndex < len(word)):
                s = (wordIndex + 1, childNode)
                subCost = word[wordIndex] != childChar
                if ((s not in distance) or (currentDistance + subCost < distance[s])):
                    distance[s] = currentDistance + subCost
                    stack.append((s[0], s[1], currentDistance + subCost))

            # Damerau
            if (damerau and wordIndex < len(word) -1) :
                grandsons = trie[childNode][1]

                for grandsonChar, grandsonNode in grandsons.items():                 
                    s = (wordIndex + 2, grandsonNode)
                    # Comprueba que se puede realizar la trasposicion antes de añadir el nuevo estado
                    transposable = word[wordIndex] == grandsonChar and word[wordIndex+1] == childChar
                    if (transposable and ((s not in distance) or (currentDistance + 1 < distance[s]))):
                        distance[s] = currentDistance + 1
                        stack.append((s[0], s[1], currentDistance + 1))

    return res

def time_function(func, *args):
    start = time.time()
    func(*args)
    end = time.time()
    #return("Execution time of {}:\t{}".format(func.__name__, end - start))
    return(end - start)

if __name__ == "__main__":
    #Si no recibe argumentos
    if len(sys.argv)<4 :
        print('FORMAT ERROR: python ALT_library.py filename word threshold')
        sys.exit()

    words = process_file(sys.argv[1])
    w1 = sys.argv[2]
    threshold = int(sys.argv[3])
    res = ""
    
    inpt = input("¿Qué método quieres usar?\n 1. Levenshtein \n 2. Damerau\n 3. Levenshtein vs Trie\n"
                    + " 4. Damerau trie\n 5. Ramificacion vs Trie\n 6. Ramificacion vs Trie Damerau\n"
                    + " 7. Generate Trie\n 8. Testear tiempos\n 9. Fichero de tiempos\n")

    if int(inpt) == 1:
        res = levenshtein_distance_simple(w1, words, threshold)
    if int(inpt) == 2:
        res = damerau4_levenshtein_distance_simple(w1, words, threshold)
    if int(inpt) == 3:
        res = leveshtreincontratrie_simple(w1, words, threshold)
    if int(inpt) == 4:
        res = damerau_trie_simple(w1, words, threshold)
    if int(inpt) == 5:
        res = trie_ramificacion(generate_trie(words), w1, threshold)
    if int(inpt) == 6:
        res = trie_ramificacion(generate_trie(words), w1, threshold, True)
    if int(inpt) == 7:
        res = generate_trie(words)
    if int(inpt) == 8:
        a = input("¿Qué método quieres medir?\n 1. Levenshtein \n 2. Damerau\n 3. Levenshtein vs Trie\n"
                    + " 4. Damerau trie\n 5. Ramificacion vs Trie\n 6. Ramificacion vs Trie Damerau\n")
        if int(a) == 1:
            res = time_function(levenshtein_distance_simple, w1, words, threshold)
        if int(a) == 2:
            res = time_function(damerau4_levenshtein_distance_simple, w1, words, threshold)
        if int(a) == 3:
            res = time_function(leveshtreincontratrie_simple, w1, words, threshold)
        if int(a) == 4:
            res = time_function(damerau_trie_simple, w1, words, threshold)
        if int(a) == 5:
            res = time_function(trie_ramificacion, generate_trie(words), w1, threshold)
        if int(a) == 6:
            res = time_function(trie_ramificacion, generate_trie(words), w1, threshold, True)
        
    if int(inpt) == 9:
        MAXTHRESHOLD = 10
        methods = [1,2,3,4,5,6]
        testWords = ["de", "lluis", "capital", "antiheroes", "iluminacion"]

        f = open("time.txt", "w")
        f.write("EXECUTION TIMES\n")
        f.write(str(testWords))
        f.write("\n")
        f.write("contra\n")
        f.write("levenshtein_distance_simple\n")
        f.write("damerau4_levenshtein_distance_simple\n")
        f.write("leveshtreincontratrie_simple\n")
        f.write("damerau_trie_simple\n")
        f.write("trie_ramificacion\n")
        f.write("trie_ramificacion damerau\n")

        for threshold in range(1,MAXTHRESHOLD+1):
            f.write("\nThreshold: {}".format(threshold))
            f.write("\n-------------------------------------------------------------------\n")
            for m in methods:
                for word in testWords:
                    if m == 1:
                        res = time_function(levenshtein_distance_simple, w1, words, threshold)
                    elif m == 2:
                        res = time_function(damerau4_levenshtein_distance_simple, w1, words, threshold)
                    elif m == 3:
                        res = time_function(leveshtreincontratrie_simple, w1, words, threshold)
                    elif m == 4:
                        res = time_function(damerau_trie_simple, w1, words, threshold)
                    elif m == 5:
                        res = time_function(trie_ramificacion, generate_trie(words), w1, threshold)
                    elif m == 6:
                        res = time_function(trie_ramificacion, generate_trie(words), w1, threshold, True)
                    res = round(res, 8)
                    f.write(str(res) + "\t")
                f.write("\n")
            f.write("\n")
        f.close()