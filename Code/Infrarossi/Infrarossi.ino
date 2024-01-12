#include <IRremote.h> // use the library
int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11
IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results;
#include <DHT.h>





#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 28
// 8 è il pin di Arduino a cui collego il sensore di temperatura
#define DHTTYPE DHT11
// dht11 è il tipo di sensore che uso
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);
// connessione display (pin
void setup()
{
  Serial.begin(9600); // for serial monitor output
  irrecv.enableIRIn(); // Start the receiver
  pinMode(12, OUTPUT); 
 lcd.begin(16, 2);
// imposto il tipo di display (colonne, righe)
lcd.print("Temperatura");
lcd.setCursor(0,1);
lcd.print("Umidita'");




}
void loop()
{
  
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    Serial.println(results.value, HEX); // display it on serial monitor in hexadecimal
    irrecv.resume();// receive the next value
    digitalWrite(12,HIGH);
    delay(100);
    digitalWrite(12,LOW);
  
  if(results.value= "C26BF044"){
   
      int t = dht.readTemperature();                    //temperatura lcd
int h = dht.readHumidity();
// posiziono il cursore alla colonna 12 e riga 0
lcd.setCursor(14, 0);
lcd.print(t);
lcd.setCursor(14, 1);
lcd.print(h);

}
  
  
  }



  
  }





 
   

