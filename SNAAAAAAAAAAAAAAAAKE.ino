

#include <MeggyJrSimple.h>   


struct Point
{
  int x;
  int y;
};

Point p1 = {3,4};
Point p2 = {4,4};
Point p3 = {5,4};
Point p4 = {6,4};

Point myArray[64] = {p1,p2,p3,p4};


void setup()                   
{
  MeggyJrSimpleSetup();
  Serial.begin (9600);  
}

int x = 3; //cordinates of plyr dot
int y = 4;
int direction =0; //possible values r 0,90,180,270
int marker=4;
int xapple, yapple;
/*
Draw player-
Display Slate / delay 100
Check Buttons-
update directions if a button is pressed-
update player based on direction-
correct for wrapping-
*/

void loop()
{
  Serial.print ("x is");
  Serial.print(x);
  Serial.print("y is");
  Serial.print(y);

//draw player

//DrawPx(x,y,Blue) ;
//DrawPx(xapple,yapple,Red) ;



/*void DrawApple()
{
if (xapple==x){
if (yapple==y){
  
  xapple=random(8) ;
  yapple=random(8) ;
}  */

DisplaySlate() ;
delay(200  ) ;
ClearSlate() ; 
DrawSnake();
DrawPx(myArray[0].x, myArray[0].y, Red);
UpdateSnake();
DrawPx(xapple, yapple, Green);
if (xapple == myArray[0].x) 
{
  if (yapple == myArray[0].y) 
  {
    xapple = random (8);
    yapple = random (8);
    marker ++;
  }
}
//BUTTONS
  CheckButtonsDown() ;
  if(Button_Right)
    direction=90;
  
  if(Button_Left)
    direction=270;
  
  if(Button_Up)
    direction=0;
  
  if(Button_Down)
    direction=180;
//break

  if(direction==90)
    myArray[0].x++;
  
  if(direction==0)
    myArray[0].y++;
  
  if(direction==180)
    myArray[0].y--;
  
  if(direction==270)
    myArray[0].x--;
//break

  if(myArray[0].x>7)
    myArray[0].x=0;

  if(myArray[0].y>7)
    myArray[0].y=0;
  
  if(myArray[0].x<0)
    myArray[0].x=7;
  
  if(myArray[0].y<0)
    myArray[0].y=7;
  
  
}

void DrawSnake()
{
  for (int i=0; i < marker; i++)
  {
      DrawPx (myArray[i].x,myArray[i].y, Blue);
  }
 
}

void UpdateSnake()
{
    for(int i = marker-1; i>0; i--)
    {
        myArray[i] = myArray[i-1];
    }
}

 
