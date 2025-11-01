// step03_ultrasonic.ino — HC-SR04 alert
const int TRIG = 9;
const int ECHO = 10;
const int LED  = 3;
const int BUZZ = 4; // optional active buzzer

long duration;
float distance_cm;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  Serial.begin(9600);
}

float readDistanceCM() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH, 30000UL); // 30 ms timeout ~ 5 m
  if (duration == 0) return 999.0; // timeout
  distance_cm = duration * 0.0343 / 2.0;
  return distance_cm;
}

void loop() {
  float d = readDistanceCM();
  Serial.print("Distance (cm): ");
  Serial.println(d);

  bool close = d < 20.0;
  digitalWrite(LED, close ? HIGH : LOW);
  digitalWrite(BUZZ, close ? HIGH : LOW);
  delay(100);
}
