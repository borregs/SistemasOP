h=$(date +%H);

echo ""
echo "Son las: $(date +%T)"
echo "Del dia: $(date +%D)"
echo ""

if [[ $h > 6 && $h < 12 ]]; 
then 
    echo "Buenos Dias"
    echo ""   
  elif [[ $h > 12 && $h < 17 ]];
  then
    echo "Buenas Tardes"
    echo ""
  elif [[ $h > 17 && $h < 22 ]];
  then
    echo "Buenas Noches"
    echo "" 
  else [[ $h > 22 || $h < 6 ]];
    echo "A dormir"
    echo "" 
  fi
