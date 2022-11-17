/* Name:Anupam kshetri
 *  Matriculation Number:33471
 *  Date:30.05.2021
 *  Code Version:0v1
 */
#include <IRremote.h>   //include library for IR remote
#include <Servo.h>    //include library for servo motor
int sensor = A0;    //assigning pin to receive signal from optical sensor
int IRpin = 10;     //assigning pin to receive data form IR receiver
IRrecv irrecv(IRpin);     //initializing IRrecv object
decode_results results; //to decode the signal
Servo motor;      //initializing motor Servo object
int SensorData;    //defining int variable


void setup()
{
  motor.attach(5);    //assigning pin D5 to motor
  motor.write(0);     //assgning 0 degree to motor
  pinMode(sensor, INPUT);   //defining variable sensor as input
  irrecv.enableIRIn();    //enabling receiver 
  Serial.begin(9600);     //for serial monitor
}

void loop() {
  SensorData = analogRead(sensor); //assigning analog value of sensor to SensorData variable
  Serial.println(SensorData); //displaying data stored in SensorData in serial Monitor
  delay(100);  // delay for 100ms
  
  if(irrecv.decode(&results))  //conditional statement to check value of results
  {
    if(results.value ==16753245) 
      {
        Serial.println("Button CH- pressed");
        motor.write(5);  //assinging value to motor
        delay(5000);
        }

      if(results.value==16736925)
      {
      Serial.println("Button CH pressed");
      motor.write(175);
      delay(5000);
      }
    
      if(results.value==16769565)
      {
      Serial.println("Button CH+ pressed");
      motor.write(135);
       delay(5000);
      }
  }
    irrecv.resume();  //continues to receive signal
}
