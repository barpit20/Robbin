#include <Servo.h>
#include <SoftwareSerial.h>


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
int pos=0;

SoftwareSerial mySerial(9, 10);
const int trigPin = 44;
const int echoPin = 45;
int flag = 0;
// defines variables
long duration;
int distance = 100;



Servo myservo;
Servo myservo1;
Servo myservo2;

Servo myservo3;
Servo myservo4;



void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);  
    pinMode(motor1Pin, OUTPUT);
    pinMode(motor2Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
    analogWrite(enablePin, speed);
    myservo.attach(3);
myservo1.attach(5); 
myservo2.attach(4);
myservo3.attach(6);  
  myservo4.attach(7);
}
int t=0;
void loop() 
{
t+=1;
 if(t<20) 
{
  distance = sense_dist();
Serial.print("DIstance");
      Serial.println(distance);
if(distance <= 5)
    {
      compress();
      distance= sense_dist();
      
      if(distance <= 5)
      {
      delay(2000);
      SendMessage();
      Serial.println("Exiting the code");  
      delay(2000);
      if (mySerial.available()>0)
   Serial.write(mySerial.read());
      exit(0);
      }
    }
}
else
{  
int ko=0;
ko=rot_main();
while(ko!=1)
  {
   ko= rot_main();
  }
  delay(3000);
  t=0;
}  
   delay(500); 
}

void compress()
 {
  
  int pos = 0;
  int po=0;
  
for (pos = 0; pos <= 90; pos += 1,po+=2) { 
    // in steps of 1 degree
    myservo3.write(pos);
    delay(15);
    myservo4.write(180-po);
    delay(15);            
}

delay(2000);

po=180;

for (pos = 90; pos >= 0; pos -= 1,po-=2) {
    myservo3.write(pos);
    delay(15);
    myservo4.write(180-po);
    delay(30);             
  }

  delay(1000);
  
  
 }



void SendMessage()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000); 
  mySerial.println("AT+CMGS=\"+919810334230\"\r");
  delay(1000);
  mySerial.println("The dustbin is full!!");
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

int sense_dist()
{
 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
return duration*0.034/2;
}

int rot_main()
{

  digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);
      duration1 = pulseIn(echoPin1, HIGH);
      distance1 = duration1*0.034/2;
      Serial.print("Distance1: ");
      Serial.println(distance1);
      
      digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
      if(distance1 <= 5)
      {
      digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
      delay(2000);
      arms();
        delay(2000);
        return 1;
      }
      analogWrite(enablePin, speed);
       digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
      return 0;
}

  void arms()
  {

    rotat2();
    rotat();
    delay(1000);
    rotat1();
    
  }


  
void rotat()
{
for (pos = 90; pos >=10; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(40);                       // waits 15ms for the servo to reach the position
  
    myservo.write(180-pos);              // tell servo to go to position in variable 'pos'
    delay(40);                       // waits 15ms for the servo to reach the position
  
  }
}
  void rotat1()
{
    
  for (pos = 90; pos >= 60; pos -=1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
for (pos = 60; pos >= 0; pos -=1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  

delay(1000);

}
  
  void rotat2()
{
    
  for (pos = 0; pos <=80; pos +=1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);


}

