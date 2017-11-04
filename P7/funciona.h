#ifndef funciona_h
#define funciona_h
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/types.h>
#include "glob.h"

static int count=0;

void despliega(int op, alumno alumnos[], WINDOW *m, WINDOW *l){

float daca=0.0;
char buff[100];
int j=0,k=0,ds=0,ls=0;
float swp=0.0,min=0.0,max=0.0;

wclear(l);
wclear(m);
box(l,0,0);
mvwprintw(l,0,4, "< Log : (stdout) >");
box(m,'#','*');
wrefresh(m);
wrefresh(l);

if(fexists("calificaciones.dat")){ // veryficamos que el archivo con el nombre "$arch" existe
	matriz=fopen("calificaciones.dat","r+"); // si existe lo abrimos
}else{ 
	perror("No existe el archivo"); // sino existe manda error y sale del programa
	exit(1);
}if(fexists("aprobados.dat")){ 
	aprovd=fopen("aprobados.dat","a"); // si existe lo abrimos
}else{ 
	perror("No existe el archivo"); // sino existe manda error y sale del programa
	exit(1);
}if(fexists("reprobados.dat")){ // veryficamos que el archivo con el nombre "$arch" existe
	reprovd=fopen("reprobados.dat","a"); // si existe lo abrimos
}else{ 
	perror("No existe el archivo"); // sino existe manda error y sale del programa
	exit(1);
}


switch(op){
		
	case 2:
		
		for(k=0;k<=count;k++){
			if(prom[k]>daca){
				daca=prom[k];
				ds=k;
			}}
			
		wbkgd(l,COLOR_PAIR(1));
		snprintf(buff,100," [+]  %s\t%d\t\t%.2f\t%.2f\t%.2f",alumnos[ds].name,alumnos[ds].mat,alumnos[ds].calif[0],alumnos[ds].calif[1],daca);
		wattron(l,A_REVERSE);
		mvwaddstr(l,2,2,"El promedio mayor fue de:");
		mvwaddstr(l,4,2,buff);
		box(l,0,0);
		
		
		while(fgets(buff,100,matriz) != NULL){

			mvwprintw(m,j+3,8,"%s",buff);
			j++;
		}
		
		wrefresh(m);
		wrefresh(l);
		getch();
		wbkgd(l,COLOR_PAIR(2));
		wattroff(l,A_REVERSE);
		wclear(l);
		fclose(matriz);
		
		
	break;
	case 3:
	
		wattron(l,COLOR_PAIR(4));
		mvwprintw(l,2,2,"[+] Ordenado por Rango de Consulta Personalizado");	
	
		for(int x=0;x<(count-1);x++){
			for(int y=0; y<(count-x-1);y++){
				
				if(prom[y]>prom[y+1]){
				
						swp=prom[y];
						prom[y]=prom[y+1];
						prom[y+1]=swp;
						
						al=alumnos[y];
						alumnos[y]=alumnos[y+1];
						alumnos[y+1]=al;
				
				}
			}
		}
		
		mvwprintw(m,2,2,"Ingresa los limites para el rango de calificaciones");
		mvwprintw(m,3,2,"Minimo >>");
		wscanw(m,"%f",&min);
		mvwprintw(m,3,2,"Maximo >>     \b\b\b\b");
		wscanw(m,"%f",&max);
		
		wclear(m);
		box(m,'#','*');
				
		mvwprintw(m,3,2,"\tNombre\tMatricula\tC1\tC2\tPromedio");
		mvwprintw(m,4,2,"\t-------------------------------------------------------------");
		
		for(int x=0; x<count;x++)
			if(prom[x]<max&&prom[x]>min)
				mvwprintw(m,6+x,2,"\t%s\t%d\t\t%.2f\t%.2f\t%.2f",alumnos[x].name,alumnos[x].mat,alumnos[x].calif[0],alumnos[x].calif[1],prom[x]);
	
		wrefresh(m);
		wrefresh(l);
		getch();
		wclear(m);
		wattroff(l,COLOR_PAIR(4));
	
	break;
	case 4:
		
		wattron(l,COLOR_PAIR(3));
		mvwprintw(l,2,2,"[i] Registro de Alumnos aprobados");
		mvwprintw(m,3,2,"\tNombre\tMatricula\tC1\tC2\tLaboratorio\tPromedio");
		mvwprintw(m,4,2,"\t------------------------------------------------------------------------");	
	
		ls=6;
	
		for(int x=0; x<count;x++)
			if(alumnos[x].lab&&prom[x]>=60.0){
				if(!alumnos[x].lab){
					strcpy(buff,"No Acredito!!");
				}else{
					strcpy(buff,"Acredito!");
				}
				mvwprintw(m,ls,2,"\t%s\t%d\t\t%.2f\t%.2f\t%s\t%.2f",alumnos[x].name,alumnos[x].mat,alumnos[x].calif[0],alumnos[x].calif[1],buff,prom[x]);
				ls++;
			}
				
		wrefresh(m);
		wrefresh(l);
		getch();
		wclear(l);
		wclear(m);
		wattroff(l,COLOR_PAIR(3));	
	break;
	case 5:
		wattron(l,COLOR_PAIR(3));
		mvwprintw(l,2,2,"[i] Registro de Alumnos reprobados");
		mvwprintw(m,3,2,"\tNombre\tMatricula\tC1\tC2\tLaboratorio\tPromedio");
		mvwprintw(m,4,2,"\t------------------------------------------------------------------------");	
	
		ls=6;
	
	
		for(int x=0; x<count;x++){
			if(!alumnos[x].lab||prom[x]<=60.0){
				if(!alumnos[x].lab){
					strcpy(buff,"No Acredito!!");
				}else{
					strcpy(buff,"Acredito!");
				}
				mvwprintw(m,ls,2,"\t%s\t%d\t\t%.2f\t%.2f\t%s\t%.2f",alumnos[x].name,alumnos[x].mat,alumnos[x].calif[0],alumnos[x].calif[1],buff,prom[x]);
				ls++;
			}}
				
		wrefresh(m);
		wrefresh(l);
		getch();
		wclear(m);
		wclear(l);
		wattroff(l,COLOR_PAIR(3));	
					
	
	break;
	case 6:
		wattron(l,COLOR_PAIR(4));
		mvwprintw(l,2,2,"[+] Registro de Alumnos ordenado alfabeticamente");
		
		for(int x=0;x<(count-1);x++){
			for(int y=0; y<(count-x-1);y++){
				
				if(strcasecmp(alumnos[y].name,alumnos[y+1].name)>0){
				
						swp=prom[y];
						prom[y]=prom[y+1];
						prom[y+1]=swp;
						
						al=alumnos[y];
						alumnos[y]=alumnos[y+1];
						alumnos[y+1]=al;
				
				}
			}
		}
		
		wclear(m);
		box(m,'#','*');
				
		mvwprintw(m,3,2,"\tNombre\tMatricula\tC1\tC2\tPromedio");
		mvwprintw(m,4,2,"\t-------------------------------------------------------------");
		
		for(int x=0; x<count;x++)
				mvwprintw(m,6+x,2,"\t%s\t%d\t\t%.2f\t%.2f\t%.2f",alumnos[x].name,alumnos[x].mat,alumnos[x].calif[0],alumnos[x].calif[1],prom[x]);
	
		wrefresh(m);
		wrefresh(l);
		getch();
		wclear(m);
		wattroff(l,COLOR_PAIR(4));
	
	
	break;
	case 7:
	
		wattron(l,COLOR_PAIR(4));

		strcpy(buff,"\0");
		
		fputs("\n\tNombre\tMatricula\tC1\tC2\tLaboratorio\tPromedio",aprovd);
		fputs("\n\t-------------------------------------------------------------------------\n",aprovd);
		fputs("\n\tNombre\tMatricula\tC1\tC2\tLaboratorio\tPromedio",reprovd);
		fputs("\n\t-------------------------------------------------------------------------\n",reprovd);
	
		for(int x=0;x<count;x++){
			if(alumnos[x].lab&&prom[x]>=60.0){
				snprintf(buff,100,"\n\t%s\t%d\t\t%.2f\t%.2f\t%.2f",alumnos[x].name,alumnos[x].mat,alumnos[x].calif[0],alumnos[x].calif[1],prom[x]);
				fputs(buff,aprovd);
			}else if(!alumnos[x].lab||prom[x]<60.0){
				snprintf(buff,100,"\n\t%s\t%d\t\t%.2f\t%.2f\t%.2f",alumnos[x].name,alumnos[x].mat,alumnos[x].calif[0],alumnos[x].calif[1],prom[x]);
				fputs(buff,reprovd);
			}}	


		mvwprintw(l,2,2,"[+] Se creo el archivo [aprobados.dat]");
		mvwprintw(l,3,2,"[+] Se creo el archivo [reprobados.dat]");		
		wrefresh(l);
		
		wattroff(l,COLOR_PAIR(4));
		fclose(reprovd);
		fclose(aprovd);

		
	break;
	case 8:
	
		wattron(l,COLOR_PAIR(3));
		mvwprintw(l,2,2,"[i] Registro de Laboratorios reprobados");
		mvwprintw(m,3,2,"\tNombre\tMatricula\tC1\tC2\tLaboratorio\tPromedio");
		mvwprintw(m,4,2,"\t------------------------------------------------------------------------");	
	
		ls=6;
	
		strcpy(buff,"No Acredito!!");
	
		for(int x=0; x<count;x++)
			if(!alumnos[x].lab){
				mvwprintw(m,ls,2,"\t%s\t%d\t\t%.2f\t%.2f\t%s\t%.2f",alumnos[x].name,alumnos[x].mat,alumnos[x].calif[0],alumnos[x].calif[1],buff,prom[x]);
				ls++;
			}
			
		wrefresh(m);
		wrefresh(l);
		getch();
		wclear(m);
		wattroff(l,COLOR_PAIR(3));

	break;		
	case 9:
	
		wattron(l,COLOR_PAIR(4));
		mvwprintw(l,2,2,"[+] Ordenado por Rango de Consulta Personalizado");	
	
		for(int x=0;x<(count-1);x++){
			for(int y=0; y<(count-x-1);y++){
				
				if(strcasecmp(alumnos[y].name,alumnos[y+1].name)>0){
				
						swp=prom[y];
						prom[y]=prom[y+1];
						prom[y+1]=swp;
						
						al=alumnos[y];
						alumnos[y]=alumnos[y+1];
						alumnos[y+1]=al;
				
				}
			}
		}
		
		mvwprintw(m,2,2,"Ingresa los limites para el rango Alfabetico");
		mvwprintw(m,3,2,"Desde la letra >>");
		char first=wgetch(m);
		mvwprintw(m,3,2,"Hasta la letra >>     \b\b\b\b");
		char last=wgetch(m);
		
		wclear(m);
		box(m,'#','*');
				
		mvwprintw(m,3,2,"\tNombre\tMatricula\tC1\tC2\tPromedio");
		mvwprintw(m,4,2,"\t-------------------------------------------------------------");
		
		for(int x=0; x<count;x++)
			if(alumnos[x].name[0]>=first&&alumnos[x].name[0]<=last)
				mvwprintw(m,6+x,2,"\t%s\t%d\t\t%.2f\t%.2f\t%.2f",alumnos[x].name,alumnos[x].mat,alumnos[x].calif[0],alumnos[x].calif[1],prom[x]);
	
		wrefresh(m);
		wrefresh(l);
		getch();
		wclear(m);
		wattroff(l,COLOR_PAIR(4));
	
	break;
				
}
	};

bool writeback(WINDOW *m, char arch[], alumno al){
	
	
	char proofmsg[20];
	char buffguy[1024];
	int gains;

	if(fexists(arch));
		matriz=fopen(arch,"a+"); // si existe lo abrimos	
	
	if(al.lab){
		strcpy(proofmsg,"Acredito!");
	}else{strcpy(
		proofmsg,"No Acredito!!");
	}
	
	prom[count]=((al.calif[0]+al.calif[1])/2);
	
	gains=snprintf(buffguy, 1024, "\n\t%s\t%d\t\t%.2f\t%.2f\t%s\t%.2f",al.name,al.mat,al.calif[0],al.calif[1],proofmsg,prom[count]);
	
	if(gains>=0&&gains<1024)
		fputs(buffguy,matriz);
	else 
		return TRUE;

	fclose(matriz);
	count++;

return FALSE;
};

int capture(WINDOW *m){
	
	bool success;
	
	box(m,'#','*');
	mvwprintw(m,2,2,"\tUsuario, Favor de registrar lo que acontinuacion se pide:");
	mvwprintw(m,5,2,"Ingresa el Nombre del alumno #%d \n >>",count+1);
	wrefresh(m);
	wscanw(m,"%s",al.name);
	mvwprintw(m,6,2,"Ingresa la matricula de %s \n >>",al.name);
	wscanw(m,"%d", & al.mat);
	mvwprintw(m,7,2,"Ingresa la calificacion del primer examen de %s \n >>",al.name);
	wscanw(m,"%f", & al.calif[0]);
	mvwprintw(m,8,2,"Ingresa la calificacion del segundo examen de %s \n >>",al.name);
	wscanw(m,"%f", & al.calif[1]);	
	mvwprintw(m,9,2,"El alumno %s, aprobo laboratorio?\n\n\t0) no\n\t1) si \n >>",al.name);
	wscanw(m,"%d", & al.lab);
	
	alumnos[count]=al;
	
	success=writeback(m,"calificaciones.dat",al);
	
	return count;
	
	};
	
#endif
