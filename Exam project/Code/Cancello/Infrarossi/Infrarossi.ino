#include <Wire.h> 
int statokeyesir = 0; 
#define keyesir 7 
void setup() {
  pinMode (keyesir, INPUT);
  pinMode(13,OUTPUT);
 

}

 void loop() {
  digitalWrite(13,LOW);
  statokeyesir = digitalRead (keyesir); 
  if (statokeyesir == LOW) {
    digitalWrite(13,HIGH);
    
  }
  
}

