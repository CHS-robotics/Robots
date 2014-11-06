int trigPin = 11;    //Trigger pin for ultrasonic sensor
int echoPin = 12;    //Echo pin for ultrasonic sensor

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup()
{
	Serial.begin(9600); //Serial Port begin
	
	//Define inputs and outputs for the ultrasonic sensor
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void loop()
{

  dist();
  
}

int dist()
{
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 Serial.print(distance);
 Serial.print("cm");
 Serial.println(); 
 return(distance);
}
