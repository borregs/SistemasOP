/*
 * Practica7.c
 * 
 * Copyright 2017 Borregs  <borregs@yopmail.com>
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/stat.h>
#include "glob.h"
#include "funciona.h"


int main(int argc, char **argv)
{
	WINDOW *m, *s;
	register bool c, lab=0;
	int op,yy,xx,cursedFlag=0;
	
	 cursedFlag=wincomps();
	 getmaxyx(stdscr,yy,xx);     
	 clear();
	 m=subwin(stdscr,yy-10,xx-8,2,4); 
	 s=subwin(stdscr,7,xx-8,yy-8,4);
	 
	 if(fexists("calificaciones.dat")){ // veryficamos que el archivo con el nombre "$arch" existe
		matriz=fopen("calificaciones.dat","r+"); // si existe lo abrimos
	 }else{ 
		perror("No existe el archivo"); // sino existe manda error y sale del programa
		return 1;// aun no se implementa una forma segura de retornar la silda del programa ya que el main es un ciclo infinito...
	 }
	 
	 fputs("\n\tNombre\tMatricula\tC1\tC2\tLaboratorio\tPromedio",matriz);
	 fputs("\n\t-------------------------------------------------------------------------\n",matriz);
	 fclose(matriz);
	 
	 do{ 
	
	 box(stdscr,'*','*');				//bordes a stdscr
	 box(m,0,0);		  				//bordes a log
	 box(s,0,0);					    //bordes a ctrl

	 if(cursedFlag){
	 	mvwprintw(s,2,2,"[i] Esta terminal no soporta colores ");			//if no color
		mvwprintw(s,3,2,"[+] Colores interactivos han sido Desactivados "); //show dis
	 }

	 // Titulo a ventanas
	 mvwprintw(stdscr,0,xx/2-12,"P7: Archivos - By Borregs");
 	 mvwprintw(m,2,2,"\t\t\tBIENVENIDO\n\n  Este programa captura datos de los alumnos y los graba en un archivo llamado: calificaciones.dat\n\n\t 1) Capturar Alumno\n\t 2) Despliega REG\n\t 3) Impresion por Rango de calif\n\t 4) Impresion de alumnos aprobados\n\t 5) Impresion de alumnos reprobados\n\t 6) Impresion por letra\n\t 7) Grabar Aprobados/reprobados\n\t 8) Impresion de laboratorios repbrobados\n\t 9) Impresion por rango de letra\n\t10) Salir\n\n  Ingrese la seleccion a modificar:\n  >> ");
	 box(m,0,0);
	 mvwprintw(s,0,4, "< Log : (stdout) >");
	 
	 // Refrescamos lo que quedo impreso	
	 wrefresh(stdscr);
	 wrefresh(m);
	 wrefresh(s);
	
	 wscanw(m,"%d", & op );
	 wclear(m);
	 wclear(s);
	 switch(op){
		 
		case 1:
			c=capture(m);
		break;
		case 2:
			despliega(op,alumnos,m,s);
		break;
		case 3:
			despliega(op,alumnos,m,s);
		break;				 
		case 4:
			despliega(op,alumnos,m,s);
		break;		 
		case 5:
			despliega(op,alumnos,m,s);
		break;
		case 6:
			despliega(op,alumnos,m,s);
		break;		
		case 7:
			despliega(op,alumnos,m,s);
		break;				 
		case 8:
			despliega(op,alumnos,m,s);
		break;		 
		case 9:
			despliega(op,alumnos,m,s);
		break;
		case 10:
			box(s,0,0);
			mvwprintw(s,0,4, "< Log : (stdout) >");
			wrefresh(s);
			wattron(s,COLOR_PAIR(4));
			mvwprintw(s,2,2,"[+] cerrando archivos y session");
			wattroff(s,COLOR_PAIR(4));
			wrefresh(s);
			system("sleep 1");
			wattron(s,COLOR_PAIR(3));
			mvwprintw(s,3,2,"[i] Gracias por usar el programa, Vuelva pronto");
			wattroff(s,COLOR_PAIR(3));
			wrefresh(s);
			system("sleep 2");			
		break;					 
		 }
	 
	}while(op!=10);
	
	endwin();
	
	return 0;
}

