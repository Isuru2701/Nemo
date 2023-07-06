#include <Servo.h>

//servo
#define servoPin 13

//ultrasonic sensors
#define echoPin 12
#define trigPin 11

//motor driver
#define in1 10
#define in2 9
#define in3 8
#define in4 7

Servo servo;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  //ULTRASONIC SENSOR
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //SERVO
  servo.attach(13);
  servo.write(90);

  //MOTOR DRIVER 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


//set all motors to low 
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  long distance = scanDistance();
  if (distance <= 30) {
    halt();
    changeDirection();
  } else {
    forward();

  }
}



void changeDirection(){

  //check left
  servo.write(0);
  delay(1000);
  
  // long distance = scanDistance();
  // if(distance < 30) {

  //   //turn
  //   return;
  // }

  //check right
  servo.write(180);
  delay(1000);
  // delay(1000);

  // distance = scanDistance();
  // if(distance < 30) {

  //   //turn
  //   return;
  // }


  servo.write(90);
  delay(1000);



  
  

}



//get ultrasonic sensor reading (returns distance in cm)
long scanDistance() {

  long distance, duration;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  return distance;


}


void forward() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(200);
}

void backward(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(200);

}

void halt() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(200);


}

void turnRight() {

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(200);


}

void turnLeft() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(200);

}


