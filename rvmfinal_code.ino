#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#include <Servo.h>
Servo myservo1;
Servo myservo2;

int pos1=95;
int pos2=70;
int pos3=105;
int servopin1=7;
int servopin2=8;

int irsensor=6;
int metalsensor=A0;
int plastic=0;
int metal=0;

void setup() 
{
  Serial.begin(9600);
   lcd.init();
   lcd.begin(16,2);
   lcd.clear();    
   lcd.backlight();   
   lcd.setCursor(2,0);   
   lcd.print("Hello world!");
    delay(1000);
   pinMode(irsensor, INPUT);
   pinMode(metalsensor,INPUT_PULLUP);    

  // pinMode(ledpin1,OUTPUT);
   //pinMode(ledpin2,OUTPUT);
   myservo1.attach(servopin1);
   myservo2.attach(servopin2); 

}

void loop() 
{
    myservo1.write(pos1);
    int val = digitalRead(irsensor);
    int sensor_read_m=digitalRead(metalsensor);

   if (val == LOW)
   {      
     delay(2000);
     //digitalWrite(ledpin2, LOW);
     if(sensor_read_m==1)
     {   
     //  digitalWrite(ledpin1,LOW);
          myservo1.write(pos3);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("plastic detected");
       //Serial.println("plastic is detected");
       delay(1000);
       for(pos3=95;pos3>=50;pos3-=1)
       {
        myservo1.write(pos3);
        delay(15);
       }
        delay(3000);

       for(pos3=50;pos3<=95;pos3+=1)
       {
        myservo1.write(pos3);
        delay(5);
       }
       delay(900);
       plastic+=1;
       char buffer[30];
       sprintf(buffer,"plasticbottles=%d",plastic);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.println(buffer);
       //Serial.println(buffer);
       delay(2000);
//servo2
       myservo2.write(pos2);
       for(pos2=70;pos2<=155;pos2+=1)
      {
        myservo2.write(pos2);
        delay(5);
      }
      delay(1000);

      for(pos2=155;pos2>=70;pos2-=1)
      {
       myservo2.write(pos2);
       delay(5);
      } 
       delay(1000);

    }  
     else
     {
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Metal detected");
       delay(2000);
       for(pos1=95;pos1<=145;pos1+=1)
       {
        myservo1.write(pos1);
        delay(5);
       }
       delay(2000);

      for(pos1=145;pos1>=95;pos1-=1)
      {
       myservo1.write(pos1);
       delay(5);
      }
       delay(900);
       metal+=1;
       char buffer2[20];
       sprintf(buffer2,"metalbottles=%d",metal);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.println(buffer2);
       delay(2000);
//servo2

     myservo2.write(pos2);
     for(pos2=70;pos2<=155;pos2+=1)
    {
    myservo2.write(pos2);
    delay(5);
  }
  delay(1000);

  for(pos2=155;pos2>=70;pos2-=1)
  {
    myservo2.write(pos2);
    delay(5);
  }
  delay(1000);
  myservo2.write(pos2);
  for(pos2=70;pos2<=155;pos2+=1)
  {
    myservo2.write(pos2);
    delay(5);
  }
  delay(1000);

  for(pos2=155;pos2>=70;pos2-=1)
  {
    myservo2.write(pos2);
    delay(5);
  }
  delay(1000);
     }
   } 
    else
    {
      //digitalWrite(ledpin2, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("place object");
      delay(500);
      //Serial.println(" place object ");
      delay(2000);     
    }  
}
