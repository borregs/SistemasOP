#ifndef glob_h
#define glob_h
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/stat.h>

typedef struct {
    char name[50];		
    int mat;
    float calif[2];
    bool lab;
} alumno;

FILE *matriz,*aprovd,*reprovd;
alumno al,alumnos[10];
float prom[10];

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
	 if(has_colors()&&can_change_color()){
			start_color();
	 }else{
			flag=1;
	 }

	 init_pair(1, COLOR_BLACK, COLOR_GREEN);
	 init_pair(2, COLOR_WHITE, COLOR_BLACK);	
	 init_pair(3, COLOR_BLUE, COLOR_BLACK);
	 init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	 
	 cbreak();
	 refresh();
	
 	 return flag;
	};

#endif
