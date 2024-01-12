void setup() {
pinMode(2,INPUT);
pinMode(9,OUTPUT);
}

void loop() {
  if(digitalRead(2) == HIGH){
    digitalWrite(9,HIGH);
  }else{
    digitalWrite(9,LOW);
  }

}
