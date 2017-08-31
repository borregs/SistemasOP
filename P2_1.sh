#!/bin/bash

# ######################################
#   SISTEMAS OPERATIVOS - PRACTICA 2   #
#    Profra. Claudia Mijares           #
#    Elaboro: Miguel Bravo - 01122832  #
########################################

N="0"
S="0"


while [ $N -lt 10 ] 
do    
  N=$(( $N + 1 )) 
  S=$(( $S + $N ))
  echo $N
done
echo ""
echo "La suma de todos los numeros fue de: $S"
echo ""
echo "Limpiando pantalla en 5 sec..."

sleep 5

clear
