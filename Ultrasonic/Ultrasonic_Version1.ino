int trigPin = 11;    //Trigger pin for ultrasonic sensor
int echoPin = 12;    //Echo pin for ultrasonic sensor

int distance;

void setup() {
  Serial.begin (9600);    //Serial Port begin
  
  //Define inputs and outputs for the ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop(){
  distance=getDistance();
}

long getDistance()
{
  long duration;
  long cm;
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  return cm;
}

