void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13, OUTPUT);
}
int StartLoop=0,EndLoop=1;
void loop()
{
  if(StartLoop<EndLoop){
    LED();
    //PASTE FUNCTIONS HERE//
      //WG(); WO(); WGAP(); WGAP(); WA(); WW(); WA(); WY(); 
      //WTEST();
      LED();LED();
    //====================//
    StartLoop++;
  }
  else{
    MOV(0,0);
  }
}
void MOV(float x, float y)
{
    x=x*1;
    y=y*1;
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
    SpeedX=175;//255*(x1/y1);
    SpeedY=255;
    dly=y1;
  }
  else if(x1>y1){
    SpeedY=175;//255*(y1/x1);
    SpeedX=255;
    dly=x1;
  }

  //MOVE X AXIS
  if(x>0){
    digitalWrite(2,HIGH);
    analogWrite(3,-SpeedX);
  }
  else if(x==0){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }
  else{
    digitalWrite(2,LOW);
    analogWrite(3,SpeedX);
  }
  
  //MOVE Y AXIS
  if(y>0){
    digitalWrite(4,HIGH);
    analogWrite(5,-SpeedY);
  }
  else if(y==0){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  else{
    digitalWrite(4,LOW);
    analogWrite(5,SpeedY);
  }
  delay(500*dly);
  //
}
void PEN(int pos)
{
  MOV(0,0);
  if(pos){
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
  else{
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }
  delay(1000);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
void LED() {
  MOV(0,0);
  digitalWrite(13, HIGH);
  digitalWrite(13, LOW);     
  delay(500);     
  digitalWrite(13, HIGH);
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
  LED();
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
  LED();
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
  LED();
}
void WD()
{
  PEN(1);
  MOV(0,4);
  MOV(2,-1);
  MOV(0,-2);
  MOV(-2,-1);
  MOV(-2,0);
  PEN(0);
  MOV(4,0);
  LED();
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
  LED();
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
  LED();
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
  LED();
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
  LED();
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
  LED();
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
  LED();
}
void WK()
{
  PEN(1);
  MOV(4,0);
  PEN(0);
  MOV(2,0);
  PEN(1);
  MOV(-2,-2);
  MOV(2,-2);
  PEN(0);
  LED();
}
void WL()
{
  MOV(2,0);
  PEN(1);
  MOV(-2,0);
  MOV(4,0);
  PEN(0);
  MOV(2,0);
  MOV(0,-4);
  LED();
}
void WM()
{
  PEN(1);
  MOV(0,4);
  MOV(2,-2);
  MOV(2,2);
  MOV(0,-4);
  PEN(0);
  LED();
}
void WN()
{
  PEN(1);
  MOV(0,4);
  MOV(4,-4);
  MOV(0,4);
  PEN(0);
  MOV(0,-4);
  LED();
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
  LED();
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
  LED();
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
  LED();
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
  LED();
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
  LED();
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
  LED();
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
  LED();
}
void WV()
{
  MOV(0,4);
  PEN(1);
  MOV(2,-4);
  MOV(2,4);
  PEN(0);
  MOV(0,-4);
  LED();
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
  LED();
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
  LED();
}
void WY()
{
  MOV(0,4);
  PEN(1);
  MOV(2,-2);
  MOV(2,2);
  PEN(0);
  MOV(-2,-2);
  PEN(1);
  MOV(0,-2);
  PEN(0);
  MOV(2,0);
  LED();
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
  LED();
}
void WSPACE()
{
  MOV(4,0);
  LED();
}
void WGAP()
{
  MOV(2,0);
}
void WLINE()
{
  MOV(0,-2);
}
void WTEST()
{
  MOV(5,5);
  MOV(-5,-5);
}


