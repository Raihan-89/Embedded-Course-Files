const int trigPin = 12; // Trigger pin for ultrasonic sensor
const int echoPin = 13; // Echo pin for ultrasonic sensor
const int motorA1 = 4; // IN1 for Motor A
const int motorA2 = 5; // IN2 for Motor A
const int motorB1 = 6; // IN3 for Motor B
const int motorB2 = 7; // IN4 for Motor B
const int buzzer = 10;
const int ledPin1 = 2;
const int ledPin2 = 3;

long distance, duration;
void setup() {
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //pinMode(buzzer,OUTPUT);
  
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);

}

void loop() {
  if(Serial.available() > 0){
    char command = Serial.read();
    switch(command){
       case 'F':
        moveForward();
        break;
      case 'B':
        moveBackward();
        break;
      case 'L':
        moveLeft();
        break;
      case 'R':
        moveRight();
        break;
      default:
        stopMotors();
        break;
    }
  }
  if (getDistance() < 15) {
    tone(buzzer,500);
    while(getDistance() < 15){
      tone(buzzer,500);
      moveBackward();
    }
    stopMotors();
  }
  else{
    noTone(buzzer);
  }
}

long getDistance() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo
  duration = pulseIn(echoPin, HIGH);
  return (duration * 0.034) / 2; // Convert to cm
}

void moveForward() {
  if(getDistance() > 15){
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
  }
}
void moveBackward(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void moveBackwardForASecond(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  delay(500);
  stopMotors();
}
void stopMotors() {
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void moveLeft() {
  digitalWrite(ledPin1,HIGH);
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

void moveRight() {
  digitalWrite(ledPin2,HIGH);
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB2, LOW);
  digitalWrite(motorB1, HIGH);
}
