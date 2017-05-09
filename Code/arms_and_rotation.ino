int forward = 0;
const int speed = 255;
long duration1;
int distance1 = 100;
const int trigPin1 = 11;
const int echoPin1 = 12;
unsigned long motorStartMillis;
unsigned long motorRunMillis = 10000;
const int motor1Pin = 36;    // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 37;    // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 38;    // H-bridge enable pin
int i = 1;

void setup() {
    Serial.begin(9600);
    pinMode(motor1Pin, OUTPUT);
    pinMode(motor2Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    analogWrite(enablePin, speed);
}

void loop() {
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);
      duration1 = pulseIn(echoPin1, HIGH);
      distance1 = duration1*0.034/2;
      Serial.print("Distance: ");
      Serial.println(distance1);
      
      digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
      if(distance1 <= 5)
      {
      digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
        //Arms
        delay(2000);
      }
      analogWrite(enablePin, speed);
       digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
  }
