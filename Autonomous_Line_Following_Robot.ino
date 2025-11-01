#define LEFT_SENSOR A0
#define MID_SENSOR  A1
#define RIGHT_SENSOR A2
#define TRIG_PIN 9
#define ECHO_PIN 8
#define ENA 10
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define ENB 11

void setup() {
  Serial.begin(9600);
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(MID_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 130);
  analogWrite(ENB, 130);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 130);
  analogWrite(ENB, 130);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  int left = digitalRead(LEFT_SENSOR);
  int mid = digitalRead(MID_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);
  long distance = getDistance();

  if (distance < 15) {
    stopMotors();
    delay(200);
    turnRight();
    delay(600);
    moveForward();
    delay(800);
    turnLeft();
    delay(600);
  } 
  else {
    if (mid == 1 && left == 0 && right == 0) {
      moveForward();
    } 
    else if (left == 1 && mid == 0) {
      turnLeft();
    } 
    else if (right == 1 && mid == 0) {
      turnRight();
    } 
    else {
      stopMotors();
    }
  }
}
