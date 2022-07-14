#include <Servo.h>
#define sensorPin 3
Servo myservo;
Servo myservo2;
int output_value;
int sensor_pin=A0;
int pos=0;
void setup(){
 pinMode(sensorPin,INPUT_PULLUP);
 myservo.attach(2);
 myservo2.attach(0);
 myservo.writeMicroseconds(1000);
 myservo2.writeMicroseconds(2000);
 Serial.begin(9600);
}
void loop(){
 int sensed=digitalRead(sensorPin);
 if(sensed==HIGH)
 {
 Serial.println("Sensed");
 myservo2.write(45);
 delay(1000);
 myservo2.write(-20);
 delay(1000);

 }
 else
 {
 Serial.println("+++++");
 //myservo2.write(0);
 }
 output_value=analogRead(sensor_pin);
 output_value=map(output_value,1013,0,0,100);
 //Serial.print("Moisture : ");s
 //Serial.print(output_value);
 //Serial.println("%");
 delay(500);

 //myservo.write(0);
 if(output_value>20){
 myservo.write(45);
 delay(7000);
 myservo.write(-20);
 delay(1000);


 }
}
