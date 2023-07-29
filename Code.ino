#include <Servo.h>
Servo myservo;
int pos = 90;
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 8
#define TRIG_FRONT A2
#define ECHO_FRONT A3
#define TRIG_LEFT A5
#define ECHO_LEFT A4
#define TRIG_RIGHT 10
#define ECHO_RIGHT 11
#define servoo 9
char Direction;
void forward();
void Back();
void Left();
void Right();
void stope();
void servoD();
int readSensor(int, int);
void servoposD(int);
void servoposU(int);
int time_delay = 100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // Initialize motor driver pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stope();

  // UltraSonic Sensors

  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  myservo.attach(servoo);
  myservo.write(pos);
}

 void loop() {
   if(Serial.available()){
          int front_dist = readSensor(TRIG_FRONT, ECHO_FRONT);
          int left_dist = readSensor(TRIG_LEFT, ECHO_LEFT);
          int right_dist = readSensor(TRIG_RIGHT, ECHO_RIGHT);
          Serial.print("Front: ");
          Serial.print(front_dist);
          Serial.print(", Left: ");
          Serial.print(left_dist);
          Serial.print(", Right: ");
          Serial.println(right_dist);
        Direction = Serial.read();
        switch(Direction){
          case 'F':{
            forward();
            break;
          }
          case 'B':{
            Back();
            break;
          }
          case 'L':{
            Left();
            break;
          }
          case 'R':{
            Right();
            break;
          }
          case 'S':{
            stope();
            break;
            }
          case 'U':{
            servoD();
            break;
            }
          case 'D':{
            servoB();
            break;
            }
          case 'A':{
            pos+=10;
            servoposU(pos);
            break;
            }
          case 'M':{
            pos-=10;
            servoposD(pos);
            break;
            }
      }
     }
 }
  void forward(){
    digitalWrite(IN1,LOW); 
    digitalWrite(IN2,HIGH); 
    digitalWrite(IN3,HIGH); 
    digitalWrite(IN4,LOW);
  }
  void Back(){
    digitalWrite(IN1,HIGH); 
    digitalWrite(IN2,LOW); 
    digitalWrite(IN3,LOW); 
    digitalWrite(IN4,HIGH);
  }
  void Right(){
    digitalWrite(IN1,LOW); 
    digitalWrite(IN2,HIGH); 
    digitalWrite(IN3,LOW); 
    digitalWrite(IN4,HIGH);
    }
  void Left(){
    digitalWrite(IN1,HIGH); 
    digitalWrite(IN2,LOW); 
    digitalWrite(IN3,HIGH); 
    digitalWrite(IN4,LOW); 
  }
  void stope(){
    digitalWrite(IN1,LOW); 
    digitalWrite(IN2,LOW); 
    digitalWrite(IN3,LOW); 
    digitalWrite(IN4,LOW);
  }
  int readSensor(int trig_pin, int echo_pin) {
  // Send ultrasonic pulse
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  long duration = pulseIn(echo_pin, HIGH);
  
  // Convert duration to distance in cm
  int distance = duration * 0.034 / 2;

  return distance;
  }
  void servoD(){
    myservo.write(0);
  }
  void servoB(){
    myservo.write(90);
  }
  void servoposD(int ps){
    myservo.write(ps);
    }
   void servoposU(int ps){
    myservo.write(ps);
    }
