
#include <SoftwareSerial.h>
int rxPin = 0;
int txPin = 1;
String message;
SoftwareSerial bluetooth(rxPin, txPin);

int motorSpeed;

void setup() {
  Serial.begin(9600);
   bluetooth.begin(9600);
  pinMode(2, OUTPUT); // Linea prese Soggiorno
  pinMode(3, OUTPUT); // Linea prese Cucina
  pinMode(4, OUTPUT); // Linea prese Camera
  pinMode(5, OUTPUT); // Linea prese Giardino
  pinMode(6, OUTPUT); // Linea luce Soggiorno
  pinMode(7, OUTPUT); // Linea luce Cucina
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);//fc verde
  pinMode(12,INPUT);//fc nero



  pinMode(14,OUTPUT);  //2 (A0)
  pinMode(15,OUTPUT); //3  (A1)
  pinMode(16,OUTPUT); //9  (A2)
  pinMode(17,INPUT); //fotoresistenza
 pinMode(18,OUTPUT);  //accesione rele porta garage
  pinMode(19,OUTPUT);  //accesione rele porta garage

  //pin A3=potenziometro
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  

}

 void loop(){


  






  
if(digitalRead(4) == LOW){



 if(digitalRead(11)==HIGH){
  digitalWrite(16,HIGH);
  digitalWrite(15,HIGH);

 

  
 
  
  delay(1000);

  digitalWrite(15,LOW);
  digitalWrite(16,LOW);
  
  
   delay(100);
   
 }


  


else if(digitalRead(11) == LOW){

  delay(6000);

  
   digitalWrite(16,HIGH);
   digitalWrite(14,HIGH);
   digitalWrite(15,LOW);
   
  delay(500);

  digitalWrite(16,LOW);
  
  

  
}


} 















  while (bluetooth.available())
   { 
         
 

    
       char dato= bluetooth.read(); // "dato" è il valore che viene ricevuto dalla seriale
Serial.println(dato);
delay(500);
       switch(dato)
       {
     
         case 'A': // Se ricevo la lettera A,
         {
  digitalWrite(2, LOW); // eccito il relè collegato al pin2
            
           break;
         }
         case 'a': // Se ricevo la lettera a
         {
  digitalWrite(2, HIGH); // Spenfo il relè
           
           break;
         }    
                   // E così anche di seguito...
                  case 'B':
         {
  digitalWrite(3, LOW);
           
           break;
         }
         case 'b':
         {
  digitalWrite(3, HIGH);
          
           break;
         }    


         case 'C':
         {
  digitalWrite(4, LOW);
            
           break;
         }
         case 'c':
         {
  digitalWrite(4, HIGH);
           
           break;
         }    
                  case 'D':
         {
  digitalWrite(5, LOW);
            
           break;
         }
         case 'd':
         {
  digitalWrite(5, HIGH);
          
           break;
         }    
                  case 'E':
         {
  digitalWrite(6, LOW);
            
           break;
         }
         case 'e':
         {
  digitalWrite(6, HIGH);
           
           break;
         }    
                  case 'F':
         {
  digitalWrite(7, LOW);
            
           break;
         }
         case 'f':
         {
  digitalWrite(7, HIGH);
           
           break;
         }    
                  case 'G':
         {
  digitalWrite(8, LOW);
            
           break;
         }
         case 'g':
         {
            digitalWrite(8, HIGH);
          
           break;
         }    
         case 'H':
         {
  digitalWrite(9, LOW);
            
           break;
         }
         case 'h':
         {
        digitalWrite(9, HIGH);   
           break;
         }    
                         
           
         }
   } }
 
