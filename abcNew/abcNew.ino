#include <AFMotor.h>
float TotY=0;
AF_DCMotor MotorX(2), MotorY(4),MotorPen(3);
void setup()
{
  
}
int StartLoop=0,EndLoop=1;
void loop()
{
  if(StartLoop<EndLoop){
    TotY=0;
    PEN(0);
     //Adjust(-3,0);
     //Adjust(0,-2);
    // 
    //PASTE FUNCTIONS HERE//
     WF(); WGAP(); WO(); WGAP(); WR(); WGAP(); WGAP(); WB(); WGAP(); WE(); WGAP(); WN(); WGAP(); WI(); WGAP(); WN(); WGAP(); WG(); WGAP(); 
    //====================//
    Reset();
    StartLoop++;
  }
  else{
    MOV(0,0);
  }
}
void MOV(float y, float x)
{
  TotY+=y;
    x=x*(1);
    y=y*(-1);
  float SpeedX,SpeedY;
  float dly;
  float x1=x,y1=y;
  if(x1<0){x1=-x;}
  if(y1<0){y1=-y;}
  if(x1==y1){
    SpeedX=SpeedY=255;
    dly=x1;
  }
  else if(x1<y1){
    SpeedX=190;//255*(x1/y1);
    SpeedY=255;
    dly=y1;
  }
  else if(x1>y1){
    SpeedY=190;//255*(y1/x1);
    SpeedX=255;
    dly=x1;
  }
  MotorX.setSpeed(SpeedX);
  MotorY.setSpeed(SpeedY);
  //MOVE X AXIS
  if(x>0){
	  MotorX.setSpeed(SpeedX);
	  MotorX.run(FORWARD);
  }
  else if(x==0){
	  MotorX.setSpeed(0);
	  MotorX.run(RELEASE);
    dly+=0.5;
  }
  else{
	  MotorX.setSpeed(SpeedX);
	  MotorX.run(BACKWARD);
  }
  
  //MOVE Y AXIS
  if (y>0) {
	  MotorY.setSpeed(SpeedY);
	  MotorY.run(FORWARD);
  }
  else if (y == 0) {
	  MotorY.setSpeed(0);
	  MotorY.run(RELEASE);
    dly+=0.5;
  }
  else {
	  MotorY.setSpeed(SpeedY);
	  MotorY.run(BACKWARD);
  }
  delay(35*dly);
  MotorX.run(RELEASE);
  MotorY.run(RELEASE);
  delay(500);
  //
}
void PEN(int pos)
{
  MOV(0,0);
  if(pos){
    MotorPen.setSpeed(200);
	  MotorPen.run(FORWARD);
    delay(100);
    MotorPen.setSpeed(50);
  }
  else{
    MotorPen.setSpeed(255);
	  MotorPen.run(BACKWARD);
    delay(200);
    MotorPen.setSpeed(100);
  }
  //MotorPen.run(RELEASE);
}
void Reset()
{
  MOV((-1)*TotY,0);
  TotY=0;
}
void Adjust(int x, int y)
{
  MOV(x*4,0);
  MOV(0,y*4);
}
void Draw()
{
  MOV(0,8);
MOV(0,7);
PEN(1);
MOV(7,0);
MOV(9,0);
MOV(0,4);
MOV(-9,0);
MOV(-8,0);
MOV(4,4);
MOV(10,0);
MOV(4,-4);
MOV(-9,0);
MOV(-1,0);
PEN(0);
MOV(-9,0);
PEN(1);
MOV(-4,4);
PEN(0);
MOV(0,-5);
MOV(-1,0);
PEN(1);
MOV(0,-1);
MOV(2,0);
MOV(0,1);
MOV(-2,0);
PEN(0);
MOV(11,0);
MOV(0,-1);
MOV(2,0);
MOV(0,1);
MOV(-2,0);
PEN(0);
MOV(-2,0);
PEN(1);
MOV(-2,0);
MOV(0,-3);
MOV(2,0);
MOV(3,0);
PEN(0);
MOV(-1,0);
PEN(1);
MOV(0,-3);
PEN(0);
MOV(-1,0);
PEN(1);
MOV(-2,-2);
MOV(-1,-1);
MOV(-1,-1);
MOV(-2,-2);
MOV(-2,-2);
PEN(0);
MOV(5,0);
PEN(1);
MOV(1,2);
MOV(1,2);
MOV(1,2);
MOV(2,2);PEN(0);
}
void WTEST()
{
  MOV(0,-4);
}

void WA()
{
  PEN(1);
  MOV(0,2);
  MOV(1,2);
  MOV(2,0);
  MOV(1,-2);
  MOV(-4,0);
  PEN(0);
  MOV(4,0);
  PEN(1);
  MOV(0,-2);
  PEN(0);
   
}
void WB()
{
  PEN(1);
  MOV(0,4);
  MOV(2,0);
  MOV(2,-1);
  MOV(-2,-1);
  MOV(2,-1);
  MOV(-2,-1);
  MOV(-2,0);
  PEN(0);
  MOV(4,0);
   
}
void WC()
{
  MOV(0,1);
  PEN(1);
  MOV(0,2);
  MOV(1,1);
  MOV(2,0);
  MOV(1,-1);
  PEN(0);
  MOV(0,-2);
  PEN(1);
  MOV(-1,-1);
  MOV(-2,0);
  MOV(-1,1);
  PEN(0);
  MOV(4,0);
  MOV(0,-1);
   
}
void WD()
{
  PEN(1);
  MOV(0,4);
  MOV(2,0);
  MOV(2,-1);
  MOV(0,-2);
  MOV(-2,-1);
  MOV(-2,0);
  PEN(0);
  MOV(4,0);
   
}
void WE()
{
  PEN(1);
  MOV(0,4);
  MOV(4,0);
  PEN(0);
  MOV(0,-2);
  MOV(-1,0);
  PEN(1);
  MOV(-3,0);
  PEN(0);
  MOV(0,-2);
  PEN(1);
  MOV(4,0);
  PEN(0);
   
}
void WF()
{
  PEN(1);
  MOV(0,4);
  MOV(4,0);
  PEN(0);
  MOV(0,-2);
  MOV(-1,0);
  PEN(1);
  MOV(-3,0);
  PEN(0);  
  MOV(4,0);
   
}
void WG()
{
  MOV(2,0);
  MOV(0,1);
  PEN(1);
  MOV(0,1);
  MOV(2,0);
  MOV(0,-2);
  MOV(-4,0);
  MOV(0,4);
  MOV(3,0);
  MOV(1,-1);
  PEN(0);
  MOV(0,-3);
   
}
void WH()
{
  MOV(4,0);
  PEN(1);
  MOV(0,4);
  PEN(0);
  MOV(-4,0);
  PEN(1);
  MOV(0,-4);
  PEN(0);
  MOV(0,2);
  PEN(1);
  MOV(4,0);
  PEN(0);
  MOV(0,-2);
   
}
void WI()
{
  MOV(0,4);
  PEN(1);
  MOV(2,0);
  PEN(0);
  MOV(-1,0);
  PEN(1);
  MOV(0,-4);
  PEN(0);
  MOV(-1,0);
  PEN(1);
  MOV(2,0);
  PEN(0);
   
}
void WJ()
{
  MOV(3,0);
  MOV(0,1);
  PEN(1);
  MOV(-1,-1);
  MOV(-1,0);
  MOV(0,4);
  PEN(0);
  MOV(-1,0);
  PEN(1);
  MOV(3,0);
  PEN(0);
  MOV(0,-4);
   
}
void WK()
{
  PEN(1);
  MOV(0,4);
  PEN(0);
  MOV(2,0);
  PEN(1);
  MOV(-2,-2);
  MOV(2,-2);
  PEN(0);
   
}
void WL()
{
  MOV(2,0);
  PEN(1);
  MOV(-2,0);
  MOV(0,4);
  PEN(0);
  MOV(2,0);
  MOV(0,-4);
   
}
void WM()
{
  PEN(1);
  MOV(0,4);
  MOV(2,-2);
  MOV(2,2);
  MOV(0,-4);
  PEN(0);
   
}
void WN()
{
  PEN(1);
  MOV(0,4);
  MOV(4,-4);
  MOV(0,4);
  PEN(0);
  MOV(0,-4);
   
}
void WO()
{
  MOV(1,0);
  PEN(1);
  MOV(2,0);
  MOV(1,1);
  MOV(0,2);
  MOV(-1,1);
  MOV(-2,0);
  MOV(-1,-1);
  MOV(0,-2);
  MOV(1,-1);
  PEN(0);
  MOV(3,0);
   
}
void WP()
{
  PEN(1);
  MOV(0,4);
  MOV(3,0);
  MOV(1,-1);
  MOV(0,-1);
  MOV(-4,0);
  PEN(0);
  MOV(0,-2);
  MOV(4,0);
   
}
void WQ()
{
  MOV(1,0);
  PEN(1);
  MOV(2,0);
  MOV(1,1);
  MOV(0,2);
  MOV(-1,1);
  MOV(-2,0);
  MOV(-1,-1);
  MOV(0,-2);
  MOV(1,-1);
  MOV(1,1);
  MOV(2,-1);
  PEN(0);
   
}
void WR()
{
  PEN(1);
  MOV(0,4);
  MOV(3,0);
  MOV(1,-1);
  MOV(0,-1);
  MOV(-4,0);
  PEN(0);
  MOV(2,0);
  PEN(1);
  MOV(2,-2);
  PEN(0);
   
}
void WS()
{
  MOV(0,1);
  PEN(1);
  MOV(1,-1);
  MOV(2,0);
  MOV(1,1);
  MOV(-4,2);
  MOV(1,1);
  MOV(2,0);
  MOV(1,-1);
  PEN(0);
  MOV(0,-3);
   
}
void WT()
{
  MOV(0,4);
  PEN(1);
  MOV(4,0);
  PEN(0);
  MOV(-2,0);
  PEN(1);
  MOV(0,-4);
  PEN(0);
  MOV(2,0);
   
}
void WU()
{
  MOV(0,4);
  PEN(1);
  MOV(0,-3);
  MOV(1,-1);
  MOV(2,0);
  MOV(1,1);
  MOV(0,3);
  PEN(0);
  MOV(0,-4);
   
}
void WV()
{
  MOV(0,4);
  PEN(1);
  MOV(2,-4);
  MOV(2,4);
  PEN(0);
  MOV(0,-4);
   
}
void WW()
{
  MOV(0,4);
  PEN(1);
  MOV(0,-4);
  MOV(2,2);
  MOV(2,-2);
  MOV(0,4);
  PEN(0);
  MOV(0,-4);
   
}
void WX()
{
  PEN(1);
  MOV(4,4);
  PEN(0);
  MOV(-4,0);
  PEN(1);
  MOV(4,-4);
  PEN(0);
   
}
void WY()
{
  MOV(0,4);
  PEN(1);
  MOV(2,-2);
  MOV(2,2);
  PEN(0);
  MOV(0,-2);
  MOV(-2,0);
  PEN(1);
  MOV(0,-2);
  PEN(0);
  MOV(2,0);
   
}
void WZ()
{
  MOV(4,0);
  PEN(1);
  MOV(-4,0);
  MOV(4,4);
  MOV(-4,0);
  PEN(0);
  MOV(4,0);
  MOV(0,-4);
   
}
void WSPACE()
{
  MOV(4,0);
   
}
void WGAP()
{
  MOV(1,0);
}
void WLINE()
{
  MOV(0,6);
}
