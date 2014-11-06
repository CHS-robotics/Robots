 <img src="https://github.com/CHS-robotics/Robots/blob/master/L293D%20Setup_bb1.png" alt="Fritzing" style="width:640px;height:480px">

The ENABLE pins can be used just as on/off for the motors using 
 
 • digitalWrite (enable1, HIGH) and 

 • digitalWrite(enable1, LOW)

But they can also control speed using analogWrite(pin, number), where number is from 0 to 255. For our motors 
anything under 150 doesn’t turn them. To use analogWrite the ENABLE pins need to be connected to a pwm
(pulse width modulation) pin on the Arduino. Note: you don’t need to initialize an analogWrite pin using 
pinMode().

The INPUT pins control the direction on the motor. If one is HIGH and the other is LOW the motor will turn one 
direction, and if you swap the HIGH/LOW the motor will turn the other way. If they are both HIGH or both LOW 
the motor will stop.

// Set up the pins with variable names 

// Left motor  
const int enable1=3; // const=constant, int=integer  
const int input1=1;  
const int input2=2;  

// Right motor  
const int enable2=5;  
const int input3=6;  
const int input4=7;


<b>void setup()</b> {

  //intialize the input pins as digital outputs  
  // the enable pins will use analogWrite, so they don't need to be intialized
  
  pinMode (input1, OUTPUT);  
  pinMode (input2, OUTPUT);
  pinMode (input3, OUTPUT);  
  pinMode (input4, OUTPUT);  
  
}

<b>void loop()</b>{

<b>Sample code to make the left motor turn at full speed:</b>  
analogWrite (enable1, 255); //Spins the motor  
digitalWrite (input1, HIGH); //Selects Direction  
digitalWrite (input2, LOW); //Selects Direction 


<b>Sample code to make it turn the other direction:</b>  
analogWrite (enable1, 255); //Spins the motor  
digitalWrite (input1, LOW); //Selects Direction  
digitalWrite (input2, HIGH); //Selects Direction


}
