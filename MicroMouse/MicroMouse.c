//****** Required Libraries ********
#include <stdio.h>
#include <windows.h> // Color
//******************************
//  maX value for x direction in the array 
#define XMAX 10
// max value for y direction in the array 
#define YMAX 10
// Maze is the target array ; we use it to solve any maze problem give
//  as an example if the user choose maze 1 then we copy all the data from maze0 to maze; same thing
// goes for the other options
char maze[XMAX][YMAX];
// *********************** Mazes**************************
char maze0[XMAX][YMAX] = {
		"XXXXXXXXXX",
		"X  X X X X",
		"XX X   X X",
		"XX XXX   X",
		"X    X XXX",
		"XX X X XEX",
		"X  X   X X",
		"XX XXX X X",
		"XS   X   X",
		"XXXXXXXXXX"
};
char maze1[XMAX][YMAX] = {
		"XXXXXXXXXX",
		"X  X X X X",
		"XX X   X X",
		"XXEXXX   X",
		"X    X XXX",
		"XX X X XXX",
		"X  X   X X",
		"XX XXX X X",
		"XS   X   X",
		"XXXXXXXXXX"
};
char maze2[XMAX][YMAX] = {
		"XXXXXXXXXX",
		"X  X X X E",
		"XX X   X X",
		"XX XXX   X",
		"X    X XXX",
		"XX X X XXX",
		"X  X   X X",
		"XX XXX X X",
		"XS   X   X",
		"XXXXXXXXXX"
};
char maze3[XMAX][YMAX] = {
		"XXXXXXXXXX",
		"X  X X X S",
		"XX X   X X",
		"XX XXX   X",
		"X    X XXX",
		"XX X X XXX",
		"X  X   X X",
		"XX XXX XEX",
		"XX   X   X",
		"XXXXXXXXXX"
};
char maze4[XMAX][YMAX] = {
		"XXXXXXXXXX",
		"X  X X X S",
		"XX X   X X",
		"XX XXX   X",
		"X    X XXX",
		"XX X X XXE",
		"X  X   X X",
		"XX XXX XXX",
		"XX   X   X",
		"XXXXXXXXXX"
};
// *********************** Mazes**************************
// the below array used to disply the original maze chosen by the user; so we display it first
// then we solve the problem
char orgMaze[XMAX][YMAX];
// We use these two variables to count the number the arrow travel 
int counter = 0,countReverse=0;
//To count the number of calls for the recursion function 
int recursionCount = 0;
// to always point at the top of the stack
int top = -1;
int top2=-1;
//***************************************
// Here we have created two stacks 
int stack[2000];
int stackB[2000];
// **************Functions prototype************************
void push();
int pop();
void traverse();
int is_empty();
int top_element();
void delay ();
void printMaze(void);
void printReverseMaze(void);
int mazeWalk(int x, int y);
void reverseBack();
void start ();
void resetData();
///************Functions Protoypes ************************
int main(void){

start();
getchar();
getchar();
return(0);
}
void printMaze1(void){
	
int x, y;
for (x=0; x<XMAX; x++){
for (y=0; y<YMAX; y++){
	if (maze[x][y]=='\032' || maze[x][y]=='\033'||maze[x][y]=='\030'||maze[x][y]=='\031')
	{
 	
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs; 
 	 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
  SetConsoleTextAttribute ( h, FOREGROUND_BLUE  );
   
  //printf ( "This is a test\n" );
		putchar(maze[x][y]);	
	}
	else
	{
		HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs; 
 	 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
		SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY);
		putchar(maze[x][y]);
	}
	
}
putchar('\n');

}
}
// This function displays the maze on the screen using two colors (Blue , White)
void printMaze(void){
	//system("cls");
	
int x, y;
for (x=0; x<XMAX; x++){
for (y=0; y<YMAX; y++){
	if (maze[x][y]=='\032' || maze[x][y]=='\033'||maze[x][y]=='\030'||maze[x][y]=='\031')
	{
 	
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs; 
 	 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
  SetConsoleTextAttribute ( h, FOREGROUND_RED  );
   
  //printf ( "This is a test\n" );
		putchar(maze[x][y]);	
	}
	else
	{
		HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs; 
 	 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
		SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY);
		putchar(maze[x][y]);
	}
	
}
putchar('\n');

}
printf("Number of Movements = %d \n",counter);
}
// This function displays the maze on the screen using two colors (Green , White)
void printReverseMaze ()
{
		system("cls");
		
int x, y;
for (x=0; x<XMAX; x++){
for (y=0; y<YMAX; y++){
	
	if (orgMaze[x][y]=='\032' || orgMaze[x][y]=='\033'||orgMaze[x][y]=='\030'||orgMaze[x][y]=='\031')
	{
 	
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs; 
 	 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
  SetConsoleTextAttribute ( h, FOREGROUND_GREEN  );
   
  //printf ( "This is a test\n" );
		putchar(orgMaze[x][y]);	
	}
	else
	{
		HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs; 
 	 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
		SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY);
		putchar(orgMaze[x][y]);
	}
}
putchar('\n');
}
printf("Number of Movements in Reverse = %d \n",countReverse);
}
// a recursion function used to solve our maze problem by finding the pather
// from point S to point E
int mazeWalk(int x, int y){
	recursionCount++;

	if (maze[x][y]=='E')
		
	return(1);
		system("cls");
//east

	if ((maze[x][y+1]==' ')||(maze[x][y+1]=='E')){
		
		maze[x][y]='\032';
		push(x,y);
		counter++;
		printMaze();
		delay ();
		if(mazeWalk(x,y+1))
		   return(1);
		  	system("cls");
		   
	}
	//North
	if ((maze[x-1][y]==' ')||(maze[x-1][y]=='E')){
	
		maze[x][y]='\030';
		push(x,y);
		counter++;
		printMaze();
		delay ();
		if(mazeWalk(x-1,y))return(1);
		system("cls");
	}
//west
	if ((maze[x][y-1]==' ')||(maze[x][y-1]=='E')){
		maze[x][y]='\033';
		push(x,y);
		counter++;
		printMaze();
		delay ();
		if(mazeWalk(x,y-1))return(1);
			system("cls");
	
	}
//south
	if ((maze[x+1][y]==' ')||(maze[x+1][y]=='E')){
		maze[x][y]='\031';
		push(x,y);
		counter++;
		printMaze();
		delay ();
		if(mazeWalk(x+1,y))return(1);
			system("cls");
	}
		printMaze1();
	delay ();
	maze[x][y]=' ';

	pop();
	pop2();

    return(0);
	}
	// A delay function used to animate the movmenet of the arrow on the screen
void delay (){
	int i;
	for ( i=0;i<10999;i++)
	{
		int j=0;
		for (j=0;j<10999;j++)
		{
		}
	}
}
// To solve the problem of returning back from point E to point S by using stacks
void reverseBack()
{
	
	int x,y;
	int n = top+1;
	
	do {
	
	
	x = pop();
	y = pop2();
	if (maze[x][y]=='\032')
	{
		orgMaze[x][y] = '\033';
		countReverse++;
		
		printReverseMaze();
		delay();
		
	}
	else if (maze[x][y]=='\033')
	{
		orgMaze[x][y] = '\032';
		countReverse++;
		printReverseMaze();
		delay();
	}
		else if (maze[x][y]=='\030')
	{
		orgMaze[x][y] = '\031';
		countReverse++;
		printReverseMaze();
		delay();
	}
		else if (maze[x][y]=='\031')
	{
		orgMaze[x][y] = '\030';
		countReverse++;
		printReverseMaze();
		delay();
	}
	n--;
}while (n>=0);
}
// Insert Data into stack
void push(int value,int v2)
{   
   top++;
   top2++;
   stack[top] = value;
   stackB[top2]= v2;
}
 // retrive data from stack
int pop()
{
   int element;
 
   if ( top == -1 )
      return top;
 
   element = stack[top];
   top--;
 
   return element;
}   
 // retrive data from stack
 int pop2()
{
   int element;
 
   if ( top2 == -1 )
      return top2;
 
   element = stackB[top2];
   top2--;
 
   return element;
} 
// The below function is used to solve our problem  and display the information
void run ()
{
	system ("cls");
		int x, y;
for (x=0; x<XMAX; x++){
{

 for (y=0; y<YMAX; y++)
if (maze[x][y]=='S')
if(!mazeWalk(x,y))
puts("No route to [E]xit from [S]tart.");

}
}


int distance = top+1;
system("pause");
reverseBack();
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs; 
 	 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
  SetConsoleTextAttribute ( h, FOREGROUND_GREEN );
printf("Number of Signs = %d \n",counter);
printf("Number of Recursions Calls = %d \n",recursionCount);
if (distance>0)
printf("Distance to Destination = %d \n",distance);
else
printf("No route to [E]xit from [S]tart.\n");
}
//In this function we display the Menu and we the user choise and then we start solving the maze  
void start ()
{
	while (1==1){
		system ("cls");
			HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  WORD wOldColorAttrs; 
 	 CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  GetConsoleScreenBufferInfo(h, &csbiInfo);
  wOldColorAttrs = csbiInfo.wAttributes; 
		SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY);
	printf("\t\t\t Algorithm and Data Structure Assignment\n");
	printf("\t\t\t A. Maze 1 \n \t\t\t B. Maze 2 \n \t\t\t C. Maze 3 \n \t\t\t D. Maze 4 \n \t\t\t E.Maze 5 \n \t\t\t F.Exit \n \t\t\t Please Choose an Option\n");
	printf("\t\t\t-----------------------------------------------------\n");
	printf("\t\t\t");
char userChoice;
scanf("%c",&userChoice);
if (userChoice == 'A')
{
	
	int x,y;
	for (x=0; x<XMAX; x++)
		{
 		for (y=0; y<YMAX; y++)
 		{
 			maze[x][y]=maze0[x][y];
 			orgMaze[x][y]=maze0[x][y];
 		}
 		}
	run ();
		resetData();
	system("pause");
}
else if (userChoice == 'B')
{
	
	int x,y;
	for (x=0; x<XMAX; x++)
		{
 		for (y=0; y<YMAX; y++)
 		{
 			maze[x][y]=maze1[x][y];
 				orgMaze[x][y]=maze1[x][y];
 		}
 		}
	run ();
		resetData();
	system("pause");
}
else if (userChoice == 'C')
{
		int x,y;
	for (x=0; x<XMAX; x++)
		{
 		for (y=0; y<YMAX; y++)
 		{
 				maze[x][y]=maze2[x][y];
 					orgMaze[x][y]=maze2[x][y];
 		}
 		}
	run ();
	resetData();
	system("pause");
}
else if (userChoice == 'D')
{
		int x,y;
	for (x=0; x<XMAX; x++)
		{
 		for (y=0; y<YMAX; y++)
 		{
 			maze[x][y]=maze3[x][y];
 				orgMaze[x][y]=maze3[x][y];
 		}
 		}
	run ();
		resetData();
	system("pause");
}
else if (userChoice == 'E')
{
		int x,y;
	for (x=0; x<XMAX; x++)
		{
 		for (y=0; y<YMAX; y++)
 		{
 				maze[x][y]=maze4[x][y];
 					orgMaze[x][y]=maze4[x][y];
 		}
 		}
	run ();
		resetData();
	system("pause");
}
else if (userChoice == 'F')
{
exit(1);
}
}
}
// clear data before the next run
void resetData()
{
	counter = 0,countReverse=0;
	 top = -1;
	 top2=-1;
	 recursionCount = 0;
}


