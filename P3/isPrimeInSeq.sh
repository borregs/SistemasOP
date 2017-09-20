#!/bin/bash

i=2
flag=0
n=1
li=$(seq $i $lim);


read -p "Ingrese el limite para la sequencia numerada: " lim
echo " "
echo "Evaluando..."
echo " "

while [ $n -le $lim ]
do
 # if (( n%1 == 0 && n%n == 0 ))
 # then
    for x in $li;
    do
      if (( $n % $x -eq 0))
      then
        if (( x != 1 && x != n ))
        then
          echo "el numero $n no es primo"
          echo ""
          break
        else
          echo "$n / $x = $(( $n / $x  ))"
        fi
        echo " "
      fi
    done
  #fi

  n=$(( $n + 1 ))

done
