#!/bin/sh
#PBS -l nodes=1,walltime=00:05:00
#PBS -q cpa
#PBS -d .

./simil donantes.txt pacientes.txt salida.txt
