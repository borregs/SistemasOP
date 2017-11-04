#!/bin/bash

# ######################################
#   SISTEMAS OPERATIVOS - PRACTICA 2   #
#    Profra. Claudia Mijares           #
#    Elaboro: Miguel Bravo - 01122832  #
########################################


N=0
NN=10
L=$(( $lines - 10 ))
C=$(( $(tput cols) / 2 )) 


clear

tput cup 9  2
echo "Num1  Num2  Suma  Resta  Multip  Division"


while [ $N -eq 0  ]
do

tput cup 1 1
read -p "Ingresa un Numero: " N1
read -p "Ingresa otro Numero: " N2 

tput cup $NN   2
if [ $N2 -eq 0  ]; then

  echo -n "  $N1    $N2      $(( $N1 + $N2 ))      $(( $N1 - $N2 ))      $(( $N1 * $N2 ))      ERR "

else
  echo -n "  $N1    $N2      $(( $N1 + $N2 ))      $(( $N1 - $N2 ))      $(( $N1 * $N2 ))      $(( $N1 / $N2 )) "
fi

tput cup 1 $C
echo 'Desea Salir del Programa?'
tput cup 2 $C
echo '  0) NO'
tput cup 3 $C
echo '  1) SI'
tput cup 4 $C
read -p ">>> " N


NN=$(( $NN + 1 ))

done

