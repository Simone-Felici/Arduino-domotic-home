#include <DHT.h>
#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 28
// 8 è il pin di Arduino a cui collego il sensore di temperatura
#define DHTTYPE DHT11
// dht11 è il tipo di sensore che uso
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);
// connessione display (pin)
LiquidCrystal lcd1(38,39 ,40 ,41 ,42 ,43 );
//display orto

int micSPin = 2;
int micAPin = 0;

#include <IRremote.h> // use the library
int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11
IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results;






void setup() 
 {        



          
  pinMode(micSPin, INPUT);
  pinMode(micAPin, INPUT);
  Serial.begin(9600);  
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);  //sensore terremoto 
  pinMode(5,OUTPUT); // buzzer
  pinMode(6,OUTPUT);// led allarme

  pinMode(7,OUTPUT);    //pin Motore passo passo antenna
  pinMode(8,OUTPUT);    //pin Motore passo passo antenna
  pinMode(9,OUTPUT);    //pin Motore passo passo antenna
  pinMode(10,OUTPUT);   //pin Motore passo passo antenna
  pinMode(29,INPUT);   // pin Pulsante 3 posizioni
  
  pinMode(30,INPUT);   //pin allarme finestre 
  pinMode(31,INPUT);   //pin allarme finestre
pinMode(32,INPUT);     //pin allarme finestre
  pinMode(33,INPUT);   //pin allarme finestre
  pinMode(34,OUTPUT); //accendi sensori allarme
  pinMode(35,OUTPUT);
  pinMode(36,INPUT);  //sensore fiamma
  pinMode(37,OUTPUT); //buzzer 2
 pinMode(44,OUTPUT); // avvio dht
 pinMode(45,OUTPUT); // avvio sensore umidita terreno 
 pinMode(46,OUTPUT); //avvio rele per pompa 
 pinMode(47,OUTPUT); //avvio sens pioggia
 pinMode(49,INPUT); // sens pioggia
 pinMode(50,OUTPUT);//avvio sens lvl acqua
 pinMode(51,HIGH); // led per sensore lvl acqua
 
  
  irrecv.enableIRIn(); // Avvia il ricevitore
  pinMode(12, OUTPUT); //led ricevitore


  lcd.begin(16, 2);
lcd.print("Temperatura");
lcd.setCursor(0,1);
lcd.print("Umidita'");

 lcd1.begin(16, 2);
 lcd1.print("Umidita t.");
 lcd1.setCursor(0,1);
 lcd1.print("lvl Acqua");


  

  

      
     
      







 
 }
void loop() 
{


   
  if(digitalRead(4) == HIGH && digitalRead(3)==HIGH){   // sensore terremoto
  digitalWrite(5,HIGH); 
  digitalWrite(6,HIGH); 
  
 }else{

   digitalWrite(6,LOW);
   digitalWrite(5,LOW);
                                   
 }                                                      // sensore terremoto





 if(analogRead(micAPin)>=600 ){
  
  digitalWrite(3,HIGH);
 }


  
 
Serial.println(analogRead(micAPin));
 
 if(digitalRead(29)==LOW){

  digitalWrite(3,LOW);
  
   digitalWrite(7,HIGH);     //motore cpanna
  delay(5);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(5);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(5);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(5);
  digitalWrite(10,LOW);
  delay(5);              //motore capanna
  
 }
  


 else if(digitalRead(29)==HIGH){
   if(digitalRead(3)==HIGH ){
 if(analogRead(A1) >=900){                             // sensore joystick e mpp
  
digitalWrite(7,HIGH); //motore cpanna
  delay(5);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(5);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(5);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(5);
  digitalWrite(10,LOW);
  delay(5);              //motore capanna

   }
else if(analogRead(A1) <100){

  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  delay(10);
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  delay(10);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  delay(10);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  delay(10);
  

 
   }
   }// sensore joystick e mpp
 }




   
     if (irrecv.decode(&results)) // have we received an IR signal?
  {
    Serial.println(results.value, HEX); // display it on serial monitor in hexadecimal
    irrecv.resume();// receive the next value
    digitalWrite(12,HIGH);
    delay(100);
    digitalWrite(12,LOW);
  
if(results.value== 0xC26BF044){    //sensore dht umidita e temperatura

  digitalWrite(44,HIGH);
   
     

 
}                                  //sensore dht umidita e temperatura

  
 if(results.value== 0x53801EE8){   //allarme

      digitalWrite(34,HIGH);
      
      

 
 
 
 }
   if(results.value== 0xC4FFB646){  //orto

    

   digitalWrite(45,HIGH);
   digitalWrite(47,HIGH);
   digitalWrite(50,HIGH);
    
   }
if(results.value== 0xF4BA2988){   //pulsante per spegnere (POWER)
  digitalWrite(44,LOW);
 digitalWrite(34,LOW);
      digitalWrite(35,LOW);
  digitalWrite(45,LOW);
   digitalWrite(47,LOW);
   digitalWrite(50,LOW);
   
lcd1.setCursor(13, 0);
lcd1.print("  ");
lcd1.setCursor(13, 1);
lcd1.print("  ");

lcd.setCursor(14, 0);
lcd.print("  ");
lcd.setCursor(14, 1);
lcd.print("  ");

  
}


   
}



if(digitalRead(34)==LOW){   //allarme

if(digitalRead(30)==LOW || digitalRead(31)==HIGH || digitalRead(32)==LOW || digitalRead(33)==LOW || digitalRead(36)==LOW){
  
  
  digitalWrite(37, LOW);
  
  }
}


if(digitalRead(34)==HIGH){

  delay(5);
   if(digitalRead(30)==HIGH || digitalRead(31)==LOW || digitalRead(32)==HIGH|| digitalRead(33)==HIGH || digitalRead(36)==HIGH){
  digitalWrite(37,HIGH);
  
  
   }



 else if(digitalRead(30)==LOW || digitalRead(31)==HIGH || digitalRead(32)==LOW || digitalRead(33)==LOW || digitalRead(36)==HIGH  ){
    digitalWrite(37, LOW);

 }
 
 }    //allarme
  
  
  if(digitalRead(44)==HIGH){
     int t = dht.readTemperature();                    //temperatura ed umidita dht
int h = dht.readHumidity();
// posiziono il cursore alla colonna 12 e riga 0
lcd.setCursor(14, 0);
lcd.print(t);
lcd.setCursor(14, 1);
lcd.print(h);
    
    
  }                                                  //temperatura ed umidita dht

  
  int UmiditaT = map(analogRead(A2),0,1000,100,0);    //orto sensore umità terreno
 lcd1.setCursor(15, 0);
    lcd1.print("%");

    if(digitalRead(45)==HIGH){                
    
  
      
       lcd1.setCursor(13, 0);
    lcd1.print( UmiditaT);

    

      
      
      
      }                                     //orto sensore umidità terreno



   
   if(digitalRead(49)==HIGH){            //pompa e sens pioggia
    
    digitalWrite(46,HIGH);
    
    
   }else{
digitalWrite(46,LOW);

    
   }             //pompa e sensore pioggia

   
 lcd1.setCursor(15,1);
  lcd1.print("%");
int LvlAcqua = map(analogRead(A3),0,590,0,100);
  
if(digitalRead(50)==HIGH){
  

     
      
  lcd1.setCursor(13,1);
  lcd1.print(LvlAcqua);
  
 
  
  }

  if(analogRead(A3)>=540)
  {
 digitalWrite(51,HIGH);
   
    
  }else{

    digitalWrite(51,LOW);
  }




      
  
  

  
   

  

  
  

 
 
 }  //fine void loop


