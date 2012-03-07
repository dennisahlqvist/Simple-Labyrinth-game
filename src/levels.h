
#ifndef __LEVELS_H__
#define __LEVELS_H__
typedef struct {
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
} level;

#endif
