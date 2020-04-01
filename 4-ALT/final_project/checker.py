#!/usr/bin/env python3
'''Este código se ejecuta de la siguiente manera:
python checker.py INDEXERX (donde X puede ser 2015,201501 o 2016)
Así, coge todas las queries que están dispuestas en filas en queries.txt y crea un nuevo
archivo donde vuelca los resultados obtenidos con el indexer indicado :)'''

import sys
import re
import numpy as np
import time
from SAR_Searcher import *

def process_file(filename):
    text = open(filename, 'r', encoding="utf8").read()
    return text

if __name__ == "__main__":

#Si no recibe argumentos
    if len(sys.argv)<2:
        print('FORMAT ERROR: python checker.py INDEXADOR')
        sys.exit()
    queries=process_file('queries.txt')
    queries=queries.split("\n")
    if sys.argv[1]=='indexers/INDEXER2015': f = open ("RESULTADOS2015.txt", "w")
    elif sys.argv[1]=='indexers/INDEXER201501': f = open ("RESULTADOS201501.txt", "w")
    elif sys.argv[1]=='indexers/INDEXER2016': f = open ("RESULTADOS2016.txt", "w")
    else: 
        print("No reconozco el indexer que me estás pasando :) ")
        sys.exit()
    inicializar(sys.argv[1])
    for query in queries:
        if query=="":
            f.write("\n")
        else:
            query=query.lower()
            resultados=resolverconsulta(str(query))
            f.write(query+'     '+str(len(resultados))+"\n")
    f.close()
                