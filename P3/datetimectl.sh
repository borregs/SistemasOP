#!/bin/bash
#########################
# Miguel Bravo -1122832 #
#########################
#      Sistemas OP      #
#      -Practica 3a     #
#   (fecha anteriror)   #
#########################

read -p "Ingrese la fecha a Evaluar en formato numerico yyyymmdd EX(2015-10-10): " fecha;
echo "";
yesteryear=$(date -d " $fecha 1 day ago" +'%F%n%Y-%m-%d%n%c');
echo "El dia anterior fue: $yesteryear";

