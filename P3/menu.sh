#!/bin/bash

choose=0

while [ $choose != 4 ]
do

echo "Acontinuacion se presenta un menu de opciones, favor de seleccionar la funcion deseada"
echo ""
echo "  1) Encontrar archivos de un tipo definido"
echo "  2) Imprimir Fecha anterior a la ingresada"
echo "  3) Evaluar una sequencia de numeros y determinar numeros primos"
echo "  4) Salir"
echo ""
read -p "Favor de ingresar su eleccion >>" choose

case $choose in

  1 )
    clear
    sh oneliner.sh ;;
  
  2 )
    clear
    sh datetimectl.sh ;;
  3 ) 
    clear
    sh desire.sh ;;
  4 )
    clear
    echo "Gracias por usar el programa. Vuelva pronto"
    break ;;

esac    

done
