#ifndef bar_h   
#define bar_h
#include <sys/stat.h>
#include <ncurses.h>

/*
 *              Este es el header global. Las variables aqui definidas son 
 *              estaticas alo largo de todo el programa.
 */


typedef struct{
        
                char name[30];
                int sex;
                int age;
                float height;
                float weight;
                
        }person;
        
person cur;
person persona[10];
double idmc[10];
FILE *f;


char *yn[]={
        "No",
        "Si",
        };
char *gen[]={
        "Masculino",
        "Femenino ",
        "Ambos    ",
        };
char *desnutrida[]={
        "Peso Bajo   ",
        "Normal      ",
        "Sobrepeso   ",
        "Obesidad I  ",
        "Obesidad II ",
        "Obesidad III",
        };
char *opc[]={
        "Grabar",
        "Leer  ",
        "IMC y Sexo",
        "Impresion por Rango de Edad",
        "Modificar",
        "Salir ",
        };
char *mods[]={
        "Nombre  ",
        "Sexo    ",
        "Edad    ",
        "Estatura",
        "Peso    ",
        };
int fexists(const char *filename){
        
        struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)
        return 1;
    else 
        return 0;
};

int wincomps(){
        
int flag=0;
        
 initscr();
 cbreak();
         if(has_colors()&&can_change_color()){
                        start_color();
         }else{
                        flag=1;
         }
         
 init_pair(1, COLOR_BLACK, COLOR_GREEN);//CONDITION MET
 init_pair(2, COLOR_WHITE, COLOR_BLACK);//NORMAL
 init_pair(3, COLOR_BLUE, COLOR_BLACK);//ACTION DESCRIBE && Desnutrias
 init_pair(4, COLOR_YELLOW, COLOR_BLACK); //WARN 
 init_pair(5, COLOR_RED, COLOR_BLACK);//morbido
         
 refresh();
return flag;
};

void redraw(WINDOW *in, WINDOW *w){
        
        int yy,xx;
        
        getmaxyx(stdscr,yy,xx);
        wclear(in);
        wclear(w);
        box(stdscr,'|','=');
        refresh();
        mvwvline(in,0,xx/2,0,4);
        box(in,0,0);
        mvwaddstr(in,0,2,"<Input Handle>");
        mvwprintw(in,1,xx/2+3,"Ultima Entrada Std [ %c ]");

        wrefresh(in);
        wrefresh(w);
        
};
#endif
bb        
