const int sensorpin = 3; // il DO del sensore e’ collegato alla porta 3
const int ledpin = 9; // il led e’ collegato alla porta 9
int statosensore = 0; // variabile di memorizzazione dello stato del sensore
//
//
void setup()
{
 pinMode(sensorpin,INPUT);
 pinMode(ledpin,OUTPUT);
}
void loop(){
 statosensore = digitalRead(sensorpin); //rileva lo stato del sensore
 if(statosensore == HIGH) 
 {
 digitalWrite(ledpin,HIGH); // attiva l’allarme
 delay (300); 
  digitalWrite(ledpin,LOW);
  delay(300);
 }else{
digitalWrite(ledpin,LOW); 
delay (300); // attende 3/10 di secondo e verifica nuovamente lo stato del sensore
}
}
