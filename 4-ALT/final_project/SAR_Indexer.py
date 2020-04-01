#!/usr/bin/env python

"""
Nombre Alumno: Xianyang Ge
Nombre Alumno: Alberto Romero Fernández
Nombre Alumno: Victoria Beltrán Domínguez
Nombre Alumno: David Barbas Rebollo
"""

import sys
import os
import json
import pickle
import re
import nltk
from lib import generate_trie
stemmer = nltk.stem.SnowballStemmer('spanish')

def load_json(filename):
    with open(filename) as fh:
        obj = json.load(fh)
    return obj

def save_object(object, filename):
    with open(filename, "wb") as fh:
        pickle.dump(object, fh)

def clean_text(text):
    
    # Remove all the special characters
    text = re.sub('\W+', ' ', text)

    # Substituting multiple spaces with single space
    text = re.sub(r'\s+', ' ', text, flags=re.I)

    return text.lower()

def create_indexer(news_directory, index_directory, stemming):
    
    termDict = {}
    docDict = {}
    docID = 0
    stemTermDict = {}
    stemTitleDict = {}
    stemSummaryDict = {}
    titleDict = {}
    urlDict = {}
    summDict = {}
    dateDict = {}
    keywordsDict = {}
    idDict = {}
    aux = 0
    trieTerms = []
    
    # Read all documents
    for dirname, subdirs, files in os.walk(news_directory):        
        if (files != []):           
            for filename in files:
                
                filename = os.path.join(dirname, filename)
                news_list = load_json(filename)
                
                # Process all the news in a document
                for pos in range(0, len(news_list)):
                    
                    news = news_list[pos]

                    # Process id
                    idDict.setdefault(news['id'], []).append((docID, pos, [0]))

                    # Process url
                    urlDict.setdefault(news['url'], []).append((docID, pos, [0]))

                    # Process date
                    dateDict.setdefault(news['date'], []).append((docID, pos, [00.]))

                    # Process keywords
                    keywords = clean_text(news['keywords']).split()
                    terms = list(set(keywords))
                    #trieTerms = trieTerms + terms

                    for t in terms:
                        indexes = [i for i,x in enumerate(keywords) if x == t]                        
                        keywordsDict.setdefault(t, []).append((docID, pos, indexes))

                    # Process title
                    title = clean_text(news['title']).split()
                    terms = list(set(title))
                    #trieTerms = trieTerms + terms

                    for t in terms:
                        indexes = [i for i,x in enumerate(title) if x == t]                        
                        titleDict.setdefault(t, []).append((docID, pos, indexes))
                        
                        stemTitleDict.setdefault(stemmer.stem(t),[]).append(t)

                    # Process summary
                    summary = clean_text(news['summary']).split()
                    terms = list(set(summary))
                    #trieTerms = trieTerms + terms

                    for t in terms:
                        indexes = [i for i,x in enumerate(summary) if x == t]  
                        summDict.setdefault(t, []).append((docID, pos, indexes))
                        
                        stemSummaryDict.setdefault(stemmer.stem(t),[]).append(t)                  

                    # Process article
                    article = clean_text(news['article']).split()
                    terms = list(set(article))
                    trieTerms = trieTerms + terms

                    for t in terms:
                        indexes = [i for i,x in enumerate(article) if x == t]                        
                        termDict.setdefault(t, []).append((docID, pos, indexes))
                        stemTermDict.setdefault(stemmer.stem(t),[]).append(t)
                    
                    # Create a custom dictionary for each new
                    n = {
                        'id' : news['id'],
                        'newsID' : (docID, pos),
                        'title' : news['title'],                    
                        'keywords' : news['keywords'],
                        'date' : news['date'],                    
                        'path' : filename,
                        'url' : news['url']
                    }
                    docDict.setdefault(docID, []).append(n)
                    
                docID += 1
    
    tup = (termDict, docDict, stemTitleDict, stemSummaryDict, stemTermDict, titleDict, urlDict, summDict, dateDict, keywordsDict, idDict, generate_trie(list(set(trieTerms))))
    save_object(tup, index_directory)

if __name__ == "__main__":

    if len(sys.argv) < 2:
        print("FORMAT ERROR: python SAR_Indexer.py news_directory indexer_directory stemming=True/False")
    
    arguments = sys.argv[2:]
    # Perform stems
    stemming = True if ("-s" in arguments) else False

    create_indexer(sys.argv[1], sys.argv[2], stemming)