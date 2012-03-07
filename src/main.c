/* TODO (#6#): Lägga till "grindar och knappar" */
/* TODO (#9#): Lägga till "andra faror" */



#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <curses.h>
#include <io.h>       //för _access
#include "levels.h"
/*
#define COLOR1	1
#define COLOR2	2
   */ 
#define DELAYSIZE 200
int numlevels=2;    //anger antal banor
typedef struct {
	int x,y;
	char dir;
} player;
/*typedef struct {//flyttad till levels.h
    int enabeled;  //anger om grinden finns i banan
    int x,y;
    int	range;
    char gatechar;
    char dir;
    int closed;
} gate;
typedef struct {
    int enabeled;  //anger om grinden finns i banan
    int x,y;
    //char gates[10];
} button;
typedef struct {
	int start_x;
	int start_y;
	int goal_x;
	int goal_y;
	int numgates;
	int numbuttons;
	char leveldata[30][80];    //orginal banan utan grindar och faror
	char curleveldata[30][80];//innehåller alla grindar och "andra faror"
	gate gates[10]; 
	button buttons[10];
} level;*/




level* curlevel=0;
void draw_player(int row,int col);
int detect_colision(int x,int y,char dir,level curlvl);
int detect_gatecolission(int x,int y,char dir,level* thislvl);
char getDirFromKey(int key);
char intToChar(int num);
time_t timeStart,timeEnd;
double timeDif=0.0;
int keyCount=0;
player player1;
//level level1;
int debugrow=0;         
char colChars[]="#q";    //de tecken som ska upptäckas som en kollision
int ch;                 //används för att läsa in knapptryckningar
int main () {
//	int c;
//	char *s;

	initscr ();
	cbreak ();
	noecho ();
	start_color ();
	keypad (stdscr, TRUE);
	curs_set(0);
	
	//int x=0,y=0;/* DONE (#3#): Byt till player struct */
	
	
    
	level levels[numlevels];
	int i=0;
	while(i<numlevels){
    	init_level(&levels[i]);
    	i++;
    }
    i=0;
	
    /* DONE (#3#): Flytta in i räcka*/
    /* TODO (#8#): Flytta in banorna i filer*/
    //level1 data
    
    
    
    
//    keyct137
    int levl_row=0;
    strcpy (levels[0].leveldata[levl_row],"################################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"################################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###      #######################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###      #######################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###      ####################################                              #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ######################################                               #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   #####################################                                #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ####################################      ########################   #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ###################################      #########################   #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ##################################      ##########################   #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   #################################      ###########################   #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ################################      ############################   #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ################################     #############################   #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###   ################################     #############################   #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###                                        ####!!!                         #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###                                        ####!!!                         #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"###                                        ####!!!                         #####");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"################################################################################");levl_row++;
    strcpy (levels[0].leveldata[levl_row],"################################################################################");debugrow=levl_row;levl_row++;
    
    
    
    levels[0].start_x=4;
    levels[0].start_y=4;
    levels[0].goal_x=47;
    levels[0].goal_y=21;
    
    
    levels[0].gates[1].enabeled=1;
    levels[0].gates[1].closed=1;
    levels[0].gates[1].range=9;
    levels[0].gates[1].x=35;
    levels[0].gates[1].y=18;
    levels[0].gates[1].dir='r';
    levels[0].gates[1].gatechar='*';
    
    levels[0].buttons[1].enabeled=1;
    levels[0].buttons[1].x=6;
    levels[0].buttons[1].y=9;
    
    //level2 data
    //keycount215
    levl_row=0;
    strcpy (levels[1].leveldata[levl_row],"################################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"################################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ##########################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###                                                                        #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###                                                                        #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###                                                                        #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"##########################################      ########################   #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"#########################################      #########################   #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"########################################      ##########################   #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"#######################################      ###########################   #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ################################      ########################4###   #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ################################     #############################   #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###   ################################     #############################   #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###                                        ####!!!                         #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###                                        ####!!!                         #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"###                                        ####!!!                         #####");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"################################################################################");levl_row++;
    strcpy (levels[1].leveldata[levl_row],"################################################################################");debugrow=levl_row;levl_row++;
    
    levels[1].start_x=4;
    levels[1].start_y=4;
    levels[1].goal_x=47;
    levels[1].goal_y=21;
    
    
    levels[1].gates[1].enabeled=1;
    levels[1].gates[1].closed=1;
    levels[1].gates[1].range=9;
    levels[1].gates[1].x=68;
    levels[1].gates[1].y=17;
    levels[1].gates[1].dir='r';
    levels[1].gates[1].gatechar='*';
    
    levels[1].buttons[1].enabeled=1;
    levels[1].buttons[1].x=3;
    levels[1].buttons[1].y=18;
    
    levl_row=0;
    
    
    
    
    
    curlevel=&levels[0]; /* DONE (#2#): Återställ den här till 0 */
    player1.x=curlevel->start_x;
    player1.y=curlevel->start_y;
    
    
   /* DONE (#2#): level pointer */
    
    i=0;
    while(i!=numlevels){
        switch (levelLoop()){
            case 1:
            /* TODO (#5#): Ladda nästa bana */
            mvprintw(debugrow/2, 10, "Grattis, Du klarade nivå %i!",i);/* TODO (#4#): förbättra banan avklarad meddelandet */
            refresh ();
            getch();
            //curlevel++;
            i++;
            curlevel=&levels[i];
            player1.x=curlevel->start_x;
            player1.y=curlevel->start_y;
			//if(i==numlevels){}
            //return 0;
            break;	  
        default:
            napms(1000);
            return 0;
            break;
        }   
    }
    erase ();
    mvprintw(debugrow/2, 10, "Grattis, Du klarade spelet!");/* TODO (#4#): förbättra banan avklarad meddelandet */
    refresh ();
    getch();
    
	erase ();		//tömmer skärmen
	refresh ();
	endwin ();		//Avslutar curces
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


void draw_player(int row,int col){
     
    col--; 
	mvaddstr(row - 1, col, "/|\\");
	mvaddstr(row,     col, "-+-");
	mvaddstr(row + 1, col, "\\|/");
	
    //debug info
    mvprintw(debugrow, 10, "x:%i   ",col);
    mvprintw(debugrow, 15, "y:%i",row);
    mvprintw(debugrow, 20, "x:%i   ",curlevel->buttons[1].x);
    mvprintw(debugrow, 25, "y:%i",curlevel->buttons[1].y);
    mvprintw(debugrow, 45, "time:%.3lf",timeDif);
    mvprintw(debugrow, 40, "k:%i",keyCount);
    }
drawlevel(level* curlevel){
    
    int row=0;
	while(row<30){
         mvaddstr(row, 0, curlevel->leveldata[row]); row++;     
    }
}

int detect_colision(int x,int y,char dir,level curlvl){
//     dir=u,l,d,r,a(all)
//colChars[]
    char* pColChar = colChars;
    
    while(*pColChar != '\0'){
    
        //printf("%c",*pColChar);
    
        switch (dir){
        case 'l':
             if(curlvl.leveldata[y][x-2]==*pColChar||(curlvl.leveldata[y-1][x-2]==*pColChar||curlvl.leveldata[y+1][x-2]==*pColChar)){return 1;}
            break;
        case 'r':
             if(curlvl.leveldata[y][x+2]==*pColChar||(curlvl.leveldata[y-1][x+2]==*pColChar||curlvl.leveldata[y+1][x+2]==*pColChar)){return 1;}
            break;
        case 'u':
             if(curlvl.leveldata[y-2][x]==*pColChar||(curlvl.leveldata[y-2][x-1]==*pColChar||curlvl.leveldata[y-2][x+1]==*pColChar)){return 1;}
            break;
        case 'd':
             if(curlvl.leveldata[y+2][x]==*pColChar||(curlvl.leveldata[y+2][x-1]==*pColChar||curlvl.leveldata[y+2][x+1]==*pColChar)){return 1;}
           break; 
        case 'a':
            break;
        } 
        pColChar++;
    
    }
    pColChar=0;
    
    
     
    return 0;

}int detect_buttonpress(int x,int y,level * thislvl){
     /* TODO (#6#): Lägg till stöd för andra grind nr */
     
    /*if(thislvl->leveldata[y][x]=='1'){
         thislvl->gates[1].closed=0;                            
        //switch (thislvl->gates[1]->dir=='r'){}
                                                                     
                                                                     
    }*/
    int i=0;
    while(i<thislvl->numbuttons){
        if(
         (
          (x-1==thislvl->buttons[i].x)
          &&
          (y==thislvl->buttons[i].y)
         )
         &&
         (1)
        ){thislvl->gates[1].closed=0;return 1;}
    
        i++;
    }
    mvprintw(debugrow, 35, "nobtn");
    return 0;

}

int levelLoop(){
    drawlevel(curlevel);
    draw_player(player1.y,player1.x);
    drawgatesandbuttons(curlevel);
    detect_buttonpress(player1.x,player1.y,curlevel);
    keyCount=0;
    player1.dir='x';
    time(&timeStart);
    
     
	while((ch = getch()))
	{
        player1.dir=getDirFromKey(ch);
        erase ();
        drawlevel(curlevel);
        time(&timeEnd);
        timeDif = difftime (timeEnd,timeStart);
        //drawgate(curlevel,1);
        
        //detect_gatecolission(player1.x,player1.y,player1.dir,*curlevel)
        
		switch(ch)
		{	case KEY_LEFT:
                 if((detect_colision(player1.x,player1.y,player1.dir,*curlevel)==0)&&(detect_gatecolission(player1.x,player1.y,player1.dir,curlevel)==0)){
                      player1.x--;
                 }
                 keyCount++;
				 break;
			case KEY_RIGHT:
                 if((detect_colision(player1.x,player1.y,player1.dir,*curlevel)==0)&&(detect_gatecolission(player1.x,player1.y,player1.dir,curlevel)==0)){
                      player1.x++;
                 }
                 keyCount++;
				 break;
			case KEY_UP:
                 if((detect_colision(player1.x,player1.y,player1.dir,*curlevel)==0)&&(detect_gatecolission(player1.x,player1.y,player1.dir,curlevel)==0)){
				      player1.y--;
                 }
                 keyCount++;
				 break;
			case KEY_DOWN:
                 if((detect_colision(player1.x,player1.y,player1.dir,*curlevel)==0)&&(detect_gatecolission(player1.x,player1.y,player1.dir,curlevel)==0)){
				      player1.y++;
                 }
                 keyCount++;
				 break;		
            //case 'q':
                 /*mvprintw(0, 0, "Vill du verkligen avsluta denna bana?(J,N)");
                 if(getch()==106){
                     return 2;
                 }
                 return 0;*/
				 //break;	
            default://övriga knappar, 
                    mvprintw(0, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", ch, ch);
				    break;
		}
    
    detect_buttonpress(player1.x,player1.y,curlevel);
    drawgatesandbuttons(curlevel);
    draw_player(player1.y,player1.x);  
    refresh();
    napms(10);		//väntar 10 ms
    
    if(player1.x-1==curlevel->goal_x&&player1.y==curlevel->goal_y){
        return 1;
    } 	
	}
 
 	
    
}

int init_level(level* thislvl){
    //initsierar en bana till 0
    thislvl->goal_x=0;
    thislvl->goal_y=0;
    thislvl->start_x=0;
    thislvl->start_y=0;
    thislvl->numgates=0;
    thislvl->numbuttons=0;
    int i=0;
    while(i<thislvl->numbuttons){
        thislvl->buttons[i].enabeled=0;
        thislvl->buttons[i].x=0;
        thislvl->buttons[i].y=0;
        i++;
    }
    i=0;
    while(i<thislvl->numgates){
        thislvl->gates[i].closed=0;
        thislvl->gates[i].dir='x';
        thislvl->gates[i].enabeled=0;
        thislvl->gates[i].range=0;
        thislvl->gates[i].x=0;
        thislvl->gates[i].y=0;
        thislvl->gates[i].gatechar='*';
        i++;
    }
    thislvl->numbuttons=sizeof(thislvl->buttons)/sizeof(thislvl->buttons[0]);
    thislvl->numgates=sizeof(thislvl->gates)/sizeof(thislvl->gates[0]);
}
int drawgatesandbuttons(level* thislvl){
    //memcpy(&(*thislvl).curleveldata,&(*thislvl).leveldata,sizeof(char)*80*30);
    //cpytocurrlvldata(curlevel);
    
    
    //thislvl->curleveldata=thislvl->&leveldata;
    /* DONE (#5#): gör färdigt */
    int i=0;
    while(i<10){//grindar
        if(thislvl->gates[i].enabeled==1){
            drawgate(thislvl,i);
        }
        i++;
    }
    i=0;
    while(i<10){//grindar
        if(thislvl->buttons[i].enabeled==1){
            drawbtn(thislvl,i);
        }
        i++;
    }
    
    i=0;
    
    return 1;
    
}
int drawgate(level* thislvl,int gatenr){
    int i=0;
    int x=thislvl->gates[gatenr].x;
    //x++;
    int y=thislvl->gates[gatenr].y;
    char gatechar=thislvl->gates[gatenr].gatechar;
    char gateid=intToChar(gatenr);/* DONE (#5#): hämta detta automatiskt */
    mvaddch(y,x,(char)gateid);
    if(thislvl->gates[gatenr].closed){/* DONE (#3#): något fel i denna if*/
//        mvaddch(y,x,gatechar);    
        
        i=0;                          
        switch(thislvl->gates[gatenr].dir){
            /* DONE (#5#): lägg till stöd för alla riktningar */
            
            case 'l':
                 while(i<thislvl->gates[gatenr].range){
                      mvaddch(y,x-(i+1),gatechar);
                      i++;
                 }
                 break;
            case 'r':
                 while(i<thislvl->gates[gatenr].range){
                      mvaddch(y,x+(i+1),gatechar);
                      i++;
                 }
                 break;
            case 'u':
                 while(i<thislvl->gates[gatenr].range){
                      mvaddch(y-(i+1),x,gatechar);
                      i++;
                 }
                 break;
            case 'd':
                 while(i<thislvl->gates[gatenr].range){
                      mvaddch(y+(i+1),x,gatechar);
                      i++;
                 }
                 break;
             default:
                 break;
                 
        }//endof switch
        i=0;
    }
    return 0;
}

int drawbtn(level* thislvl,int btnnr){
    int x=thislvl->buttons[btnnr].x;
    int y=thislvl->buttons[btnnr].y;
    char btnid=intToChar(btnnr);
	
    mvprintw(y-1,x,"+-+");
    mvprintw(y  ,x,"|%c|",btnid);
    mvprintw(y+1,x,"+-+");
    return 0;
}


char intToChar(int num){
    switch(num){
     case 0:
         return '0';
         break;
     case 1:
         return '1';
         break;
     case 2:
         return '2';
         break;
     case 3:
         return '3';
         break;
     case 4:
         return '4';
         break;
     case 5:
         return '5';
         break;
     case 6:
         return '6';
         break;
     case 7:
         return '7';
         break;
     case 8:
         return '8';
         break;
     case 9:
         return '9';
         break;
     default:
         return 'A';
         break;
              
    }
}
int detect_gatecolission(int x,int y,char usrDir,level* thislvl){
    int i=0;
    int j=-1;
    /* TODO (#5#): Lägg till stöd för andra riktningar */
    while(i<thislvl->numgates){
        if(thislvl->gates[i].enabeled){
        if(thislvl->gates[i].closed==0){
            //grinden är öppen
            return 0;                                
        }	if(thislvl->gates[i].dir=='r'){
				switch(usrDir){
				case 'd':
					if(
					 (y==thislvl->gates[i].y-2)
					&&
					 (
					  (x>thislvl->gates[i].x-2)
					 &&
					  (x<thislvl->gates[i].x+thislvl->gates[i].range+2)
					 )
					){return 1;}break;
				case 'u':
					if(
					 (y==thislvl->gates[i].y+2)
					&&
					 (
					  (x>thislvl->gates[i].x-2)
					 &&
					  (x<thislvl->gates[i].x+thislvl->gates[i].range+2)
					 )
					){return 1;}break;
				}
			}else/*(thislvl->gates[i].dir=='d')*/{
				switch(usrDir){
				case 'd':/* TODO (#2#): Skriv om koden för dir=d grindar */
					if(
					 (y==thislvl->gates[i].y-2)
					&&
					 (
					  (x>thislvl->gates[i].x-2)
					 &&
					  (x<thislvl->gates[i].x+thislvl->gates[i].range+2)
					 )
					){return 1;}break;
				case 'u':
					if(
					 (y==thislvl->gates[i].y+2)
					&&
					 (
					  (x>thislvl->gates[i].x-2)
					 &&
					  (x<thislvl->gates[i].x+thislvl->gates[i].range+2)
					 )
					){return 1;}break;
				}
			}
        }
	i++;
    }
    return 0;
}
char getDirFromKey(int key){
     switch(key){
       case KEY_LEFT:
            return 'l';
            break;
       case KEY_RIGHT:
            return 'r';
            break;
       case KEY_UP:
            return 'u';
            break;
       case KEY_DOWN:
            return 'd';
            break;
     }
}
//int ifNoColissionMvPlayer(){}
