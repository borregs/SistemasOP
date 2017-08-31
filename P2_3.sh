#!/bin/bash

# ######################################
#   SISTEMAS OPERATIVOS - PRACTICA 2   #
#    Profra. Claudia Mijares           #
#    Elaboro: Miguel Bravo - 01122832  #
########################################

N=0
Nx=0
C=0

for N in 0 1 2 3 4 5 6 7 8 9 10
do
  echo "Tabla del $N :"
  echo ""
  for Nx in 0 1 2 3 4 5 6 7 8 9 10
  do
    echo " $N x $Nx = $(( $N * $Nx ))"
  done
  echo ""
done
