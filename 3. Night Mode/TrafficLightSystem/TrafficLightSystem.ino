unsigned int sensorValue = 0;  
int sensorPin = A0;
int piezoPin = 8;
float distance;
float voltage;

void setup() {
  pinMode(13, OUTPUT); //RED
  pinMode(12, OUTPUT); //YELLOW
  pinMode(11, OUTPUT); //GREEN
  
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);
}

void lightSensor(){
  sensorValue = analogRead(sensorPin);    
  voltage = sensorValue * (5000.0 / 1024.0);
  Serial.print("Sensor Output: ");
  Serial.println(sensorValue);
  Serial.print("Voltage (mv): ");
  Serial.println(voltage);
  Serial.println();
  delay(1000);
}

void pedLights(){
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);

  for(int i = 0; i <= 10; i++){
    delay(100);
    digitalWrite(12, HIGH);
    tone(piezoPin, 500, 100);
    delay(100);
    digitalWrite(12, LOW);
  }
} 

void sensor(){
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW); 
  distance = pulseIn(3, HIGH);
  distance = distance/58;
  Serial.print(distance);
  Serial.println("cm");
}

void normalMode(){
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  sensor();
  if (distance < 10){
    pedLights();
  } 
  delay(2000);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  sensor();
  if (distance < 10){
    pedLights();
  }
  delay(1000);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  sensor();
  if (distance < 10){
    pedLights();
  }
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  sensor();
  if (distance < 10){
    pedLights();
  }
  delay(1000);
}

void nightMode(){
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  while (distance < 10){  
  	digitalWrite(13, LOW);
  	digitalWrite(11, HIGH);
  	delay(2000);
  	digitalWrite(13, HIGH);
  	digitalWrite(11, LOW);
  	sensor();
  }
}

void loop() { 
  lightSensor();
  sensor();
  if (voltage < 30){
    nightMode();
  } else {
    normalMode();
  }
}
