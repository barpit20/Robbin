//ERFINDER CODE
#include <SoftwareSerial.h>

#include <Servo.h>
int i=0;

Servo myservo;
Servo myservo1;

   


SoftwareSerial mySerial(9, 10);
const int trigPin = 44;
const int echoPin = 45;
int flag = 0;
// defines variables
long duration;
int distance = 100;



void setup()
{
  mySerial.begin(9600);  
  Serial.begin(9600);   
  delay(100);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

  myservo.attach(6);  
  myservo1.attach(7);
}


void loop()
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
  delay(1000);
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    
  delay(1000); 
  mySerial.println("AT+CMGS=\"+919560823326\"\r");
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


 void compress()
 {
  
  int pos = 0;
  int po=0;
  
for (pos = 0; pos <= 90; pos += 1,po+=2) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(15);
    myservo1.write(180-po);
    delay(15);            
}

delay(2000);

po=180;

for (pos = 90; pos >= 0; pos -= 1,po-=2) {
    myservo.write(pos);
    delay(15);
    myservo1.write(180-po);
    delay(30);             
  }

  delay(1000);
  
  
 }

