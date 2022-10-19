float distance;
void setup() {
  pinMode(13, OUTPUT); //RED
  pinMode(12, OUTPUT); //YELLOW
  pinMode(11, OUTPUT); //GREEN
  
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);
}

void loop() { //MODE 1
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(1000);

  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW); 
  distance = pulseIn(3, HIGH);
  distance = distance/58;
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 10){
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    
    for(int i = 0; i <= 10; i++){
      delay(100);
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(12, LOW);
    }
  }
}
