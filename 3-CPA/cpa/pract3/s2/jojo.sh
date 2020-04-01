#!/bin/sh
#PBS -l nodes=1:ppn=32,walltime=00:10:00
#PBS -W x="NACCESSPOLICY:SINGLEJOB"
#PBS -q cpa
#PBS -d .

mpiexec -n 4 newton -c5
mpiexec -n 8 newton -c5
mpiexec -n 4 newton2 -c5
mpiexec -n 8 newton2 -c5