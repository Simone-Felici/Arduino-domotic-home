void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
      pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A1));
 if(analogRead(A1)>=600){
  digitalWrite(7,HIGH);
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
 }
 if(analogRead(A1)== 0){
  digitalWrite(10,HIGH);
  delay(5);
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  delay(5);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  delay(5);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  delay(5);
  digitalWrite(7,LOW);
 }
 

   
  

}
