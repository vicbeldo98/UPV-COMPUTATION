#!/bin/sh
#PBS -l nodes=2:ppn=10,walltime=00:10:00
#PBS -W x="NACCESSPOLICY:SINGLEJOB"
#PBS -q cpa
#PBS -d .

cat $PBS_NODEFILE
mpiexec ./hello