const int trigPin = 7;
const int echoPin = 6;

const int redLed = 8;
const int yellowLed = 9;
const int greenLed = 10;
const int buzzer = 11;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);

  if (distance <= 10) {
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000);
    delay(100);
    noTone(buzzer);
    delay(100);
  }
  else if (distance <= 25) {
    digitalWrite(yellowLed, HIGH);
    tone(buzzer, 800);
    delay(300);
    noTone(buzzer);
    delay(300);
  }
  else {
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
    delay(200);
  }
}
