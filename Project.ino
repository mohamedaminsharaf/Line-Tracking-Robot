#include <NewPing.h>
int pos = 0;
int x;
int y;
int TRIGGER_PIN=8;
int ECHO_PIN=7;
int MAX_DISTANCE=200;
int motor_pins[]={2,3,12,13};
int speed_pins[]={5,6};
NewPing sonar (TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
pinMode(motor_pins[0],OUTPUT);//back left
pinMode(motor_pins[1],OUTPUT);//front left
pinMode(motor_pins[2],OUTPUT);//back right
pinMode(motor_pins[3],OUTPUT);//front right
pinMode(speed_pins[0],OUTPUT);//left
pinMode(speed_pins[1],OUTPUT);//right
pinMode(ECHO_PIN,INPUT);
pinMode(TRIGGER_PIN,INPUT);
pinMode(A2,INPUT);//right
pinMode(A1,INPUT);//center
pinMode(A0,INPUT);//left
//digitalWrite(motor_pins[0],LOW);
//digitalWrite(motor_pins[1],HIGH);
//digitalWrite(motor_pins[2],LOW);
//digitalWrite(motor_pins[3],HIGH);
//analogWrite(speed_pins[0],67);
//analogWrite(speed_pins[1],70);
Serial.begin(9600);

}

void loop() {
  byte rightSensor=analogRead(A2);
  byte centerSensor=analogRead(A1);
  byte leftSensor=analogRead(A0);
  
  Serial.print(" Left : ");
  Serial.print(leftSensor);
  Serial.print(" Centre : ");
  Serial.print(centerSensor);
  Serial.print(" Right : ");
  Serial.print(rightSensor);
  Serial.print("Sonar: ");
  Serial.print(sonar.ping_cm());
  Serial.println();
 
  if(centerSensor <60  && leftSensor >60  && rightSensor >60){//forward
    digitalWrite(motor_pins[0],LOW);
    digitalWrite(motor_pins[1],HIGH);
    digitalWrite(motor_pins[2],LOW);
    digitalWrite(motor_pins[3],HIGH);
    analogWrite(speed_pins[0],47);
    analogWrite(speed_pins[1],50);
    delay(100);
  }
  if(centerSensor <60 && leftSensor >60 && rightSensor <60){//turn right
    digitalWrite(motor_pins[0],LOW);
    digitalWrite(motor_pins[1],HIGH);
    digitalWrite(motor_pins[2],LOW);
    digitalWrite(motor_pins[3],LOW);
    analogWrite(speed_pins[0],47);
    analogWrite(speed_pins[1],50);
    delay(100);
  }
   if(centerSensor <60 && leftSensor <60 && rightSensor >60){//turn left
    digitalWrite(motor_pins[0],LOW);
    digitalWrite(motor_pins[1],LOW);
    digitalWrite(motor_pins[2],LOW);
    digitalWrite(motor_pins[3],HIGH);
    analogWrite(speed_pins[0],47);
    analogWrite(speed_pins[1],50);
    delay(100);
  }
  if(centerSensor <60 && leftSensor <60 && rightSensor <60){//forward
    digitalWrite(motor_pins[0],LOW);
    digitalWrite(motor_pins[1],LOW);
    digitalWrite(motor_pins[2],LOW);
    digitalWrite(motor_pins[3],LOW);
    analogWrite(speed_pins[0],47);
    analogWrite(speed_pins[1],50);
    delay(100);
  }
  
  if(centerSensor >60 && leftSensor >60 && rightSensor <60){//turn right
    digitalWrite(motor_pins[0],LOW);
    digitalWrite(motor_pins[1],HIGH);
    digitalWrite(motor_pins[2],LOW);
    digitalWrite(motor_pins[3],LOW);
    analogWrite(speed_pins[0],47);
    analogWrite(speed_pins[1],50);
    delay(100);
  }
  if(centerSensor >60 && leftSensor <60 && rightSensor >60){//turn left
    digitalWrite(motor_pins[0],LOW);
    digitalWrite(motor_pins[1],LOW);
    digitalWrite(motor_pins[2],LOW);
    digitalWrite(motor_pins[3],HIGH);
    analogWrite(speed_pins[0],47);
    analogWrite(speed_pins[1],50);
    delay(100);
  }  
  if(centerSensor >60 && leftSensor <60 && rightSensor <60){//forward
    digitalWrite(motor_pins[0],LOW);
    digitalWrite(motor_pins[1],HIGH);
    digitalWrite(motor_pins[2],LOW);
    digitalWrite(motor_pins[3],HIGH);
    analogWrite(speed_pins[0],47);
    analogWrite(speed_pins[1],50);
    delay(100);
  
  }


 
}

int distantfun(){    
 return sonar.ping_cm();
}
