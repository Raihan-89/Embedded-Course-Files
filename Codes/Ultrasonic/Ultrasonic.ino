const int trigPin = 13;
const int echoPin = 12;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  Serial.println("Hello");
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= (duration*0.034)/2;
  Serial.print("Distance(cm): ");
  Serial.println(distance);
  delay(1000);
}
