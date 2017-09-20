datenow=$(date --utc +%s);


echo "Este programa determina la cantidad de dias transcurridos desde una fecha cualquiera en el pasado."
echo ""

read -p "Ingrese una fecha pasada en formato numerico EX(2015-10-10) : " datefrom
echo ""

fmtdate=$(date --utc --date "$datefrom" +%s);
daysince=$(( (datenow-fmtdate )/(3600*24) ));

echo ""
echo "      Fecha Actual : $(date +%c)"
echo "   Fecha Ingresada : $(date -d "$datefrom" +%c)"
echo "Dias transcurridos : $daysince"

echo ""
