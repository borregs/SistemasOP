/*
 * imc.c
 * 
 *	Se desea que tenga un archivo que guarde los siguientes datos: Nombre, sexo, edad,
 *	estatura en metros y cantidad de kilos en kgs. El programa tendrá las siguientes
 *	opciones:
 *	
 *  a) Grabar (El nombre del archivo será “imc.dat”,grabar con fwrite).
 *	
 *  b) Leer: Se imprimirá en pantalla todo el archivo en columnas para cada dato. (Leer con
 *	fread y poner encabezados. Se calculará el IMC por persona, pintar con color rojo las
 *	personas que tengan obesidad mórbida, pintar con color azul las personas que
 *	padezcan desnutrición. En la tabla deberá de imprimir el IMC y una leyenda que diga si
 *	su IMC fue desnutrición, normal, sobrepeso, obesidad, obesidad grado I, obesidad
 *	grado 2 u obesidad mórbida según la tabla de abajo)
 *	
 *  c) IMC y sexo: Imprimir del archivo, una lista todos los nombres que tengan
 *	determinado IMC y sexo requerido. (Leer con fread).
 *	
 *  d) Impresión por rangos de edad (Realizar una lista con los nombres de las personas
 *	que cumplan con el rango de edad dado).
 *	
 *  e) Modificar: La búsqueda para modificar será por nombre. Cualquiera de los datos se
 *	podrá modificar, por lo que se mostrará un menú para elegir el dato deseado
 *	(Utilización de fseek).
 *	
 *  f) Salida.
 * 
 * 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <math.h>
#include <string.h>
#include "foo.h"
#include "bar.h"

//using namespace std;
 
int main(int argc, char **argv)
{
	
	WINDOW * in,*w;
	int xx,yy,c,pc=0,color=0;
	color=wincomps();
	
	getmaxyx(stdscr,yy,xx);
	in=newwin(5,xx-12,yy-6,5);
	w=newwin((yy-8),(xx-4),2,2);
	
	redraw(in,w);
	
	if(color){
	 	mvwprintw(in,1,2,"[i] Esta terminal no soporta colores ");			//if no color
		mvwprintw(in,2,2,"[+] Colores interactivos han sido Desactivados "); //show dis
	}
	
	keypad(in,TRUE);
	
	
	while(c!=6){

	c=gotcha(in,w,pc);
	redraw(in,w);
	
	switch(c){
		case 1:
			capture(in,w);
			redraw(in,w);
		break;
		case 2:
			readBack(in,w,"imc.dat",0);
			redraw(in,w);
		break;
		case 3:
			readBack(in,w,"imc.dat",1);
			redraw(in,w);
		break;
		case 4:
			readStack(in,w);
			redraw(in,w);
		break;
		case 5:
			modifica(in,w);
			redraw(in,w);
		break;
		case 6:
			wattron(in,COLOR_PAIR(4));
			mvwprintw(in,1,2,"[+] cerrando archivos y session");
			wattroff(in,COLOR_PAIR(4));
			wrefresh(in);
			system("sleep 1");
			wattron(in,COLOR_PAIR(3));
			mvwprintw(in,2,2,"[i] Gracias por usar el programa, Vuelva pronto");
			wattroff(in,COLOR_PAIR(3));
			wrefresh(in);
			system("sleep 2");
		break;		
	}}
	endwin();
	return 0;
}
