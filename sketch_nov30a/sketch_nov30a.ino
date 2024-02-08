/*
THIS IS THE ONE
THIS IS THE ONE
THIS IS THE ONE
THIS IS THE ONE
*/

//Light sensor pins
int sensorLeft = 25;
int sensorMLeft = 17;
int sensorMiddle = 16;
int sensorMRight = 27;
int sensorRight = 14;

//Right motor pins
int enableRightMotor=12;
int rMPin1=13;
int rMPin2=5;

//Left motor pins
int enableLeftMotor=18;
int lMPin1=19;
int lMPin2=23;

void setup(){
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rMPin1, OUTPUT);
  pinMode(rMPin2, OUTPUT);
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(lMPin1, OUTPUT);
  pinMode(lMPin2, OUTPUT);
  pinMode(sensorLeft, INPUT);
  pinMode(sensorMLeft, INPUT);
  pinMode(sensorMiddle, INPUT);
  pinMode(sensorMRight, INPUT);
  pinMode(sensorRight, INPUT);

  digitalWrite(enableRightMotor, HIGH);
  digitalWrite(enableLeftMotor, HIGH);
  Serial.begin(9600);
}

void loop(){
  int rightSensorValue = digitalRead(sensorRight);//|| digitalRead(sensorMRight);
  int leftSensorValue = digitalRead(sensorLeft); //|| digitalRead(sensorMLeft);
  int middleSensorValue = digitalRead(sensorMiddle);

  Serial.println(rightSensorValue + "  " + leftSensorValue);
  //GO STRAIGHT
  if (leftSensorValue == HIGH && rightSensorValue == HIGH){
    digitalWrite(lMPin1, LOW);
    digitalWrite(lMPin2, HIGH);
    digitalWrite(rMPin1, LOW);
    digitalWrite(rMPin2, HIGH);
  } // TURN LEFT
  else if (leftSensorValue == LOW && rightSensorValue == HIGH){
    digitalWrite(lMPin1, LOW);
    digitalWrite(lMPin2, LOW);
    digitalWrite(rMPin1, LOW);
    digitalWrite(rMPin2, HIGH);
  } // TURN RIGHT
  else if (leftSensorValue == HIGH && rightSensorValue == LOW){
    digitalWrite(lMPin1, LOW);
    digitalWrite(lMPin2, HIGH);
    digitalWrite(rMPin1, LOW);
    digitalWrite(rMPin2, LOW);
  } // STOP
  else if (leftSensorValue == LOW && rightSensorValue == LOW){
    digitalWrite(lMPin1, LOW);
    digitalWrite(lMPin2, LOW);
    digitalWrite(rMPin1, LOW);
    digitalWrite(rMPin2, LOW);
  }
}