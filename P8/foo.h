#ifndef foo_h
#define foo_h
#include <ncurses.h>
#include <math.h>
#include "bar.h"
//NARWALS

static int count=0;



int imc(person paciente,int d){
	
	double classif;
	
	classif=(paciente.weight/(pow(paciente.height,2)));
	
	if(classif<=18.00){
		idmc[d]=classif;
		return 0;
	}else if(classif>18.00&&classif<25.00){
		idmc[d]=classif;
		return 1;
	}else if(classif>=25.00&&classif<27.00){
		idmc[d]=classif;
		return 2;	
	}else if(classif>=27.00&&classif<30.00){
		idmc[d]=classif;
		return 3;	
	}else if(classif>=30.00&&classif<40.00){
		idmc[d]=classif;
		return 4;
	}else{
		idmc[d]=classif;
		return 5;
			
}};

void readStack(WINDOW *l, WINDOW *m){
	
	int min,max,masudas[count+1];
	
	
		redraw(m,l);
		mvwprintw(m,2,2,"Ingresa los limites para el rango de edades");
		mvwprintw(m,3,2,"Minimo >>");
		wscanw(m,"%d",&min);
		mvwprintw(m,3,2,"Maximo >>     \b\b\b\b");
		wscanw(m,"%d",&max);
		
		redraw(l,m);
		
		mvwprintw(m,2,5,"Nombre\tSexo \t    Edad \tMts\tKg\tClass\t        IMC");
		mvwprintw(m,3,4,"------------------------------------------------------------------------------");
		
		for(int x=0; x<count;x++){
		
			masudas[x]=imc(persona[x],x);
	
			if(persona[x].age<=max&&persona[x].age>=min){
				mvwprintw(m,5+x,5,"%s\t%s\t%d\t%.2f\t%.2f\t%s\t%.2f",persona[x].name,gen[persona[x].sex],persona[x].age,persona[x].height,persona[x].weight,desnutrida[masudas[x]],idmc[x]);
			}else{
				wattron(m,COLOR_PAIR(4));
					mvwprintw(m,5+x,5,"\t\t\t    <--  ! MATCH  --->");
				wattroff(m,COLOR_PAIR(4));	
			}
		}
		
		wattron(l,COLOR_PAIR(4));
		mvwprintw(l,2,2,"[!] Presione Cualquier Tecla Para Continuar");
		wattroff(l,COLOR_PAIR(4));
		wrefresh(m);
		wrefresh(l);
		getch();	
};

void readBack(WINDOW *in,WINDOW *m, char *arch,int flag){
	
	person personas[count+1];
	int masudas[count+1],aux[2],hl=0,c;
	
	if(fexists(arch))
		f=fopen(arch,"rb+");
	else
		perror("El archivo imc.dat no pudo ser abierto");	
	
	fread(personas,sizeof(personas),1,f);
	
	if(flag){
		mvwprintw(m,1,2,"Seleccione o ingrese los siguientes filtros:");
		mvwprintw(m,3,4,"Mostrar solo personas del sexo:");
		
		do{
	
			for(int x=0;x<3;x++){
			
				if(x==hl)
					wattron(m,A_REVERSE);
			
				mvwprintw(m,x+5,8,"%d) %s",x+1,gen[x]);
				wattroff(m,A_REVERSE);
			}
			
			wrefresh(m);
			c=wgetch(in);
			switch(c){
				case KEY_UP:
					if(hl>0)
						hl--;
					else
						hl=2;
				break;
				case KEY_DOWN:
					if(hl<2)
						hl++;
					else
						hl=0;
				break;
				case 10:
						aux[0]=hl;
				break;
				default:
					wattron(in,COLOR_PAIR(4));
					mvwprintw(in,1,1,"  [!] Presione Flechas o [ENTER]");
					wattroff(in,COLOR_PAIR(4));			
				}
			}while(c!=10);
		redraw(in,m);	
		mvwprintw(m,3,4,"Mostrar solo personas con IMC de classificacion:");
		do{
	
			for(int x=0;x<6;x++){
			
				if(x==hl)
					wattron(m,A_REVERSE);
			
				mvwprintw(m,x+5,8,"%d) %s",x+1,desnutrida[x]);
				wattroff(m,A_REVERSE);
			}			
			wrefresh(m);
			c=wgetch(in);
			switch(c){
				case KEY_UP:
					if(hl>0)
						hl--;
					else
						hl=5;
				break;
				case KEY_DOWN:
					if(hl<6)
						hl++;
					else
						hl=0;
				break;
				case 10:
						aux[1]=hl;
				break;
				default:
					wattron(in,COLOR_PAIR(4));
					mvwprintw(in,1,1,"  [!] Presione Flechas o [ENTER]");
					wattroff(in,COLOR_PAIR(4));			
				}
			}while(c!=10);
		}
		
		redraw(in,m);
		
		mvwprintw(m,2,5,"Nombre\tSexo \t    Edad \tMts\tKg\tClass\t        IMC");
		mvwprintw(m,3,4,"------------------------------------------------------------------------------");
	
		for(int x=0;x<count;x++){
			
			masudas[x]=imc(personas[x],x);
			
			if(flag){
				if(aux[0]==2){
					if(masudas[x]!=aux[1])
						masudas[x]=-1;
				}else if(masudas[x]!=aux[1]||personas[x].sex!=aux[0]){
					masudas[x]=-1;
				}}
				
			switch(masudas[x]){
				
				case -1:
					wattron(m,COLOR_PAIR(4));
						mvwprintw(m,5+x,5,"\t\t\t    <--  ! MATCH  --->");
					wattroff(m,COLOR_PAIR(4));	
				break;
				
				case 0 :

					wattron(m,COLOR_PAIR(3));
							mvwprintw(m,5+x,5,"%s\t%s\t%d\t%.2f\t%.2f\t%s\t%.2f",personas[x].name,gen[personas[x].sex],personas[x].age,personas[x].height,personas[x].weight,desnutrida[masudas[x]],idmc[x]);
					wattroff(m,COLOR_PAIR(3));
				break;
				
				case 5 :
				
				
					wattron(m,COLOR_PAIR(5));
							mvwprintw(m,5+x,5,"%s\t%s\t%d\t%.2f\t%.2f\t%s\t%.2f",personas[x].name,gen[personas[x].sex],personas[x].age,personas[x].height,personas[x].weight,desnutrida[masudas[x]],idmc[x]);
					wattroff(m,COLOR_PAIR(5));				
				break;
				
				default :
				
				
					mvwprintw(m,5+x,5,"%s\t%s\t%d\t%.2f\t%.2f\t%s\t%.2f",personas[x].name,gen[personas[x].sex],personas[x].age,personas[x].height,personas[x].weight,desnutrida[masudas[x]],idmc[x]);
				break;
				
		}
	}
	
	
	wattron(in,COLOR_PAIR(4));
	mvwprintw(in,2,2,"[!] Presione Cualquier Tecla Para Continuar");
	wattroff(in,COLOR_PAIR(4));
	wrefresh(m);
	wrefresh(in);
	getch();
	
	
	fclose(f);
	
};


//writeback
void writethrough(char *arch){
	
	char buff[1024];
	
	if(fexists(arch))
		f=fopen(arch,"wb+");
	else
		perror("El archivo imc.dat no pudo ser abierto");
		
	fwrite(persona,sizeof(persona),1,f);	
	fclose(f);	

};


//ya no me acuerdo lol
int gotcha(WINDOW *in,WINDOW *m,int parentalCont){
	
int xx,yy,c,hl=0;
char op;
	
while(1){

	getmaxyx(in,yy,xx);
	
	mvwprintw(m,1,2,"MENU:");
		
	for(int x=0;x<6;x++){
		
		if(x==hl)
			wattron(m,A_REVERSE);
		
		mvwprintw(m,x+3,8,"%d) %s",x+1,opc[x]);
		wattroff(m,A_REVERSE);
	}
	
	wrefresh(in);
	wrefresh(m);
	
	c=wgetch(in);
	switch(c){
		case KEY_UP:
			if(hl>0){
				hl--;
			}else{
				hl=5;
			}
		break;
		case KEY_DOWN:
			if(hl<5){
				hl++;
			}else{
				hl=0;
			}
		break;
		case 10:
			return hl+1;
		break;
		default:
			wattron(in,COLOR_PAIR(4));
			mvwprintw(in,1,1,"  [!] Presione Flechas o [ENTER]");
			wattroff(in,COLOR_PAIR(4));
		break;
		}
}};

//Capturala

int capture(WINDOW *in,WINDOW *m){
	
	int c,hl=0;
	register bool success;
	
	while(1){
	
	box(m,'#','*');
	mvwprintw(m,2,2,"\tUsuario, Favor de registrar lo que acontinuacion se pide:");
	mvwprintw(m,5,2,"Ingresa el Nombre de la persona #%d \n >>",count+1);
	wscanw(m,"%s",cur.name);
	mvwprintw(m,6,2,"Ingresa la edad de %s \n >>",cur.name);
	wscanw(m,"%d", & cur.age);
	mvwprintw(m,7,2,"Ingresa la estatura de %s en Metros \n >>",cur.name);
	wscanw(m,"%f", & cur.height);	
	mvwprintw(m,8,2,"Ingresa el peso de %s en Kilogramos \n >>",cur.name);
	wscanw(m,"%f", & cur.weight);
	mvwprintw(m,9,2,"escoge el sexo de %s",cur.name);
	
	do{
	
		for(int x=0;x<2;x++){
		
			if(x==hl)
				wattron(m,A_REVERSE);
		
			mvwprintw(m,x+11,8,"%d) %s",x+1,gen[x]);
			wattroff(m,A_REVERSE);
		}
		
		wrefresh(m);
		c=wgetch(in);
		switch(c){
			case KEY_UP:
				if(hl>0)
					hl--;
				else
					hl=1;
			break;
			case KEY_DOWN:
				if(hl<1)
					hl++;
				else
					hl=0;
			break;
			case 10:
				cur.sex=hl;
				persona[count]=cur;
				count++;
			break;
			default:
				wattron(in,COLOR_PAIR(4));
				mvwprintw(in,1,1,"  [!] Presione Flechas o [ENTER]");
				wattroff(in,COLOR_PAIR(4));			
			}
		}while(c!=10);
				
		redraw(in,m);
		wattron(in,COLOR_PAIR(3));
		mvwprintw(in,1,2,"[+] La persona #%d fue grabada al listado.",count);
		wattroff(in,COLOR_PAIR(4));
		wrefresh(in);
		mvwprintw(m,3,2,"Desea agregar otra persona?");	
		
		do{	
			
				for(int x=0;x<2;x++){
					
					if(x==hl)
						wattron(m,A_REVERSE);
		
					mvwprintw(m,x+4,8,"%d %s",x+1,yn[x]);
					wattroff(m,A_REVERSE);
				}
			wrefresh(m);
			c=wgetch(in);
			switch(c){
			case KEY_UP:
				if(hl>0)
					hl--;
				else
					hl=1;
			break;
			case KEY_DOWN:
				if(hl<1)
					hl++;
				else
					hl=0;
			break;
			case 10:
					if(hl){
						redraw(in,m);
						break;
					}else{
						writethrough("imc.dat");
						return 0;
					}	
			break;
			default:
				wattron(in,COLOR_PAIR(4));
				mvwprintw(in,1,1,"  [!] Presione Flechas o [ENTER]");
				wattroff(in,COLOR_PAIR(4));			
			}}while(c!=10);
		}
};
//
/*
MODIFICALA!
*/
//
void modifica(WINDOW *l,WINDOW *m){
	
	int c,hl=0,aux[2];
	
	redraw(l,m);
	mvwprintw(m,1,2,"Usuario, Favor de Seleccionar un registro a modificar:");
	
		do{
	
		mvwprintw(m,3,8,"#)  Name   IMC");
		mvwprintw(m,4,7,"-------------------------");
	
		for(int x=0;x<count;x++){
		
			if(x==hl)
				wattron(m,A_REVERSE);
		
			mvwprintw(m,x+6,8,"%d) %s %.2f",x+1,persona[x].name,idmc[x]);
			wattroff(m,A_REVERSE);
		}
		wrefresh(m);
		c=wgetch(l);
		switch(c){
			case KEY_UP:
				if(hl>0)
					hl--;
				else
					hl=count;
			break;
			case KEY_DOWN:
				if(hl<count)
					hl++;
				else
					hl=0;
			break;
			case 10:
				aux[0]=hl;
			break;
			default:
				wattron(l,COLOR_PAIR(4));
				mvwprintw(l,1,1,"  [!] Presione Flechas o [ENTER]");
				wattroff(l,COLOR_PAIR(4));			
			}
		}while(c!=10);
		

		redraw(l,m);
		wattron(l,COLOR_PAIR(3));
		mvwprintw(l,1,2,"[+] Modidicando el listado en la persona #%d ",aux[0]+1);
		wattroff(l,COLOR_PAIR(3));
		wrefresh(l);
		mvwprintw(m,2,2,"Que atributo desea modificar?");	
		
		do{	
			
				for(int x=0;x<5;x++){
					
					if(x==hl)
						wattron(m,A_REVERSE);
		
					mvwprintw(m,x+4,8,"%d) %s",x+1,mods[x]);
					wattroff(m,A_REVERSE);
				}
				
			wrefresh(m);
			c=wgetch(l);
			switch(c){
			case KEY_UP:
				if(hl>0)
					hl--;
				else
					hl=4;
			break;
			case KEY_DOWN:
				if(hl<4)
					hl++;
				else
					hl=0;
			break;
			case 10:
				aux[1]=hl;
			break;
			default:
				wattron(l,COLOR_PAIR(4));
				mvwprintw(l,1,1,"  [!] Presione Flechas o [ENTER]");
				wattroff(l,COLOR_PAIR(4));			
			}}while(c!=10);
	
		redraw(l,m);
		switch(aux[1]){
			
			case 0:
				mvwprintw(m,2,2,"Ingresa el Nombre de la persona #%d \n >>",aux[0]+1);
				wrefresh(m);
				getstr(persona[aux[0]].name);
			break;
			case 1:
				if(persona[aux[0]].sex)
					persona[aux[0]].sex=0;
				else
					persona[aux[0]].sex=1;
				wattron(l,COLOR_PAIR(3));
				mvwprintw(l,2,2,"[i] Seleccion Binaria Invertida! ");
				wattroff(l,COLOR_PAIR(3));
				wattron(l,COLOR_PAIR(4));
				mvwprintw(l,3,2,"[!] Presione Cualquier Tecla Para Continuar ");
				wattroff(l,COLOR_PAIR(4));				
				wrefresh(l);
				getch();
			break;
			case 2:
				mvwprintw(m,2,2,"Ingresa la edad de %s \n >>",persona[aux[0]].name);
				wrefresh(m);
				wscanw(m,"%d",&persona[aux[0]].age);
			break;
			case 3:
				mvwprintw(m,2,2,"Ingresa la estatura de %s en Metros \n >>",persona[aux[0]].name);
				wrefresh(m);
				wscanw(m,"%f",&persona[aux[0]].height);
			break;
			case 4:
				mvwprintw(m,2,2,"Ingresa el peso de %s en Kilogramos \n >>",persona[aux[0]].name);
				wrefresh(m);
				wscanw(m,"%f",&persona[aux[0]].weight);
			break;
			}
	writethrough("imc.dat");
	for(int x=0;x<count;x++){
		int y=imc(persona[x],x);
	}
};

#endif
