// step04_drive_4x4.ino — 2x TB6612 control
const int STBY = 8;
const int AIN1 = 5;
const int AIN2 = 6;
const int PWMA = 3; // PWM
const int BIN1 = 10;
const int BIN2 = 11;
const int PWMB = 9;  // PWM

void setup() {
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT); pinMode(AIN2, OUTPUT); pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT); pinMode(BIN2, OUTPUT); pinMode(PWMB, OUTPUT);
  digitalWrite(STBY, HIGH);
  stopAll();
  Serial.begin(9600);
}

void rampWrite(int pin, int target, int step=8, int delayMs=10){
  for (int v=0; v<=target; v+=step){
    analogWrite(pin, v);
    delay(delayMs);
  }
  analogWrite(pin, target);
}

void driveSide(int in1, int in2, int pwmPin, int speed, int dir){
  if (dir == 0){
    digitalWrite(in1, LOW); digitalWrite(in2, LOW);
    analogWrite(pwmPin, 0);
    return;
  }
  if (dir > 0){ digitalWrite(in1, HIGH); digitalWrite(in2, LOW); }
  else        { digitalWrite(in1, LOW);  digitalWrite(in2, HIGH); }
  rampWrite(pwmPin, constrain(speed, 0, 255));
}

void forward(int speed){ driveSide(AIN1,AIN2,PWMA,speed, 1); driveSide(BIN1,BIN2,PWMB,speed, 1); }
void back(int speed)   { driveSide(AIN1,AIN2,PWMA,speed,-1); driveSide(BIN1,BIN2,PWMB,speed,-1); }
void left(int speed)   { driveSide(AIN1,AIN2,PWMA,speed,-1); driveSide(BIN1,BIN2,PWMB,speed, 1); }
void right(int speed)  { driveSide(AIN1,AIN2,PWMA,speed, 1); driveSide(BIN1,BIN2,PWMB,speed,-1); }
void stopAll()         { driveSide(AIN1,AIN2,PWMA,0,0); driveSide(BIN1,BIN2,PWMB,0,0); }

void demo(){
  forward(180); delay(1500);
  stopAll();    delay(300);
  left(180);    delay(800);
  stopAll();    delay(300);
  right(180);   delay(800);
  stopAll();    delay(300);
  back(160);    delay(1200);
  stopAll();    delay(500);
}

void loop(){
  demo();
  delay(1000);
}
