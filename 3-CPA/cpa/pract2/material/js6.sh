#!/bin/sh
#PBS -l nodes=1,walltime=00:05:00
#PBS -q cpa
#PBS -d .

OMP_NUM_THREADS=32 OMP_SCHEDULE=dynamic,1 ./simil3 donantes.txt pacientes.txt salida6.txt
