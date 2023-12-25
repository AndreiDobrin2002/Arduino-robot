// D4, D2, D1 si D0 - distanta
// A5, A4, A2, A1 - linie
#include <xmotion.h>


int distantaFata = 4; // Digital sensor connected to D4
int distantaDreapta = 2; //Connected to D2
int distantaStanga = 1; //Connected to D1
int valueDistantaFata, c=0, valueDistantaDreapta, valueDistantaStanga, linieFataDreapta, linieFataStanga, linieSpateDreapta, linieSpateStanga; // We define variable for storing sensor output.

void setup() {
  xmotion.ToggleLeds(100); 
  pinMode(distantaFata, INPUT); 
  pinMode(distantaDreapta, INPUT);
  pinMode(distantaStanga, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600); 
}
void bek() {
  linieFataDreapta = analogRead(A1); //fata dreapta
  linieFataStanga = analogRead(A2); // fata stanga
  linieSpateDreapta = analogRead(A4); //spate dreapta 
  linieSpateStanga = analogRead(A5); //spate stanga
  if (linieFataDreapta < 300 && linieFataStanga < 300)
  {
   xmotion.StopMotors(20);
    xmotion.Backward(50, 250);
  }
  else if (linieSpateDreapta < 300 && linieSpateStanga < 300)
  {
    xmotion.StopMotors(20);
    xmotion.Forward(50, 100);
  }
  else if (linieFataDreapta < 300 || linieSpateDreapta < 300)
  {
    xmotion.StopMotors(20);
    xmotion.Left0(61,80);
    xmotion.Forward(10,100);
  }
  else if (linieFataStanga < 300 || linieSpateStanga < 300)
  {
    xmotion.StopMotors(20);
    xmotion.Right0(61,80);
    xmotion.Forward(10,100);
  }
  

}
void loop() {
  /*xmotion.Forward(100,100); // %100 Speed, both motor forward 100mS.
    xmotion.StopMotors(100);  // 100ms Stop Both Motors
    xmotion.Backward(70,250); // %70 Speed, both motor backward 250mS.
    xmotion.Right0(51,1000);  // %51 Speed, 1 second Right 0 Turn. (Left Motor Forward, Right Backward)
    xmotion.Left0(20,3500);   // %20 Speed, 3.5 second Left 0 Turn. (Right Motor Forward, Left Backward)
    xmotion.ArcTurn(20,60,250); // 250 millisecond %20 Speed Left, %60Speed Right Motor
    xmotion.MotorControl(-150,190); //Timeless -150/255 Left Motor Backward Speed, 190/255 Right Motor Speed
    delay(100); // 100ms Delay  */

  // Distance sensor getting information
  
//  linieFataDreapta = analogRead(A1);
//  linieFataStanga = analogRead(A2);
//  linieSpateDreapta = analogRead(A4);
//  linieSpateStanga = analogRead(A5);
//  Serial.print("Sensor Output: "); 
//  Serial.println(valueDistantaFata); 
//  Serial.println(valueDistantaDreapta);
//  Serial.println(valueDistantaStanga);
  bek();
  valueDistantaFata = digitalRead(distantaFata); // Senzor fata
  valueDistantaDreapta = digitalRead(distantaDreapta); // Senzor dreapta
  valueDistantaStanga = digitalRead(distantaStanga); // Senzor stanga
  if (valueDistantaFata) {
    xmotion.Forward(100, 1);
    //xmotion.StopMotors(5);
    bek();
  }
  else if (valueDistantaStanga) {
    xmotion.Left0(100, 20);
    xmotion.StopMotors(3);
    c=0;
  }
  else if (valueDistantaDreapta) {
    xmotion.Right0(100, 20);
    xmotion.StopMotors(3);
    c=1;
  }
  else if(!valueDistantaFata && !valueDistantaDreapta && !valueDistantaStanga)
  {
    xmotion.StopMotors(10);
    if (c==0) xmotion.Left0(100, 20);
    else xmotion.Right0(100, 20);
    xmotion.StopMotors(5);
    
  }
  bek();
  delay(100); 
}
