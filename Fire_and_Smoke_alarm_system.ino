#include <LiquidCrystal.h>
int rs = 3, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

int gas_sensor = 8;
int gasState;
int fire_sensor = 9;
int fireState;
int buzzer = 2;
int led = 10;


void setup() {
  // put your setup code here, to run once:
   lcd.begin(16, 2);
   lcd.setCursor(1,0);
   lcd.print("Fire and Smoke");
   lcd.setCursor(1,1);
   lcd.print(" Alarm System");
   pinMode (gas_sensor, INPUT);
   pinMode (fire_sensor, INPUT);
   pinMode (led, OUTPUT);
   pinMode (buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  gasState = digitalRead(gas_sensor);
  fireState = digitalRead(fire_sensor);

//when gas sensor detects a condition
  if(gasState == LOW){
    for (int x=0; x<5; x++) {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Gas Detected");
          delay(500);
          digitalWrite (led, HIGH);
          digitalWrite(buzzer,HIGH);
          delay (100);
          digitalWrite(led,LOW);
          digitalWrite(buzzer,LOW);
          delay (100);
        }
    }
   else{
          
          digitalWrite(led,LOW);
          digitalWrite(buzzer,LOW);
          delay(1000);
   }

//when fire sensor detects a condition
  if(fireState == LOW){
    for (int x=0; x<5; x++) {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Fire Detected");
          delay(500);
          digitalWrite (led, HIGH);
          delay (500);
          digitalWrite(buzzer,HIGH);
          delay (500);
          digitalWrite(led,LOW);
          digitalWrite(buzzer,LOW);
          delay (500);
      }
    }
   else{  
         
          digitalWrite(led,LOW);
          digitalWrite(buzzer,LOW);
          delay (500);
   }
   
//when both sensor detects a condition
   if((gasState && fireState ) == ( LOW )){
    for (int x=0; x<5; x++) {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Critical State");
          delay(500);
          digitalWrite (led, HIGH);
          digitalWrite(buzzer,HIGH);
          delay (50);
          digitalWrite(led,LOW);
          digitalWrite(buzzer,LOW);
          delay (50);
      }
    }
   else{  
         
          digitalWrite(led,LOW);
          digitalWrite(buzzer,LOW);
          delay (500);
   }

          return setup();
}
