/*
Distance sensor with HC-SR04 ultrasound sensor
The shorter the distance to the sensor the more LED's will be on 
by soleil_zero
*/

const int trigPin = 4;  //Pins 2 and 3 are trigPin (sends an ultrasound signal) and echoPin (recieves the ultrasound signal)
const int echoPin = 3;

int duration; //Creates duration and distance variables
int distance;

void setup() {
pinMode(trigPin, OUTPUT);    //Pins 2 and 3 are trigPin and echoPin
pinMode(echoPin, INPUT);
  for (int i = 5; i < 14; i++){ //Turns the pins from 4 to 8 to binary output
    pinMode(i, OUTPUT);
  }


}
void loop(){
digitalWrite(trigPin, LOW);  //Initially sets off the ultrasound
delayMicroseconds(2);

digitalWrite(trigPin, HIGH); //Turn the ultrasound on sending a signal on trigPin for 10 microseconds 
delayMicroseconds(10);

duration = pulseIn(echoPin, HIGH);//Takes the time the signal took to reflect itself and calculates the distance from it
distance = 0.034 * duration/2;


if(distance < 5){               //If an object is less than 5cm away all LEDs will be turned ON
  for(int i = 5; i < 14; i++){
    digitalWrite(i, HIGH);
  }
}

else if(5 < distance && distance < 10){ // For every 5cm farther one LED won't be turned ON
  
  digitalWrite(13,LOW);
   for (int i = 5; i < 12; i++){
    digitalWrite(i, HIGH);
  }
}
else if(10 < distance && distance < 15){
  digitalWrite (11,LOW);
  digitalWrite (13,LOW);
  for(int i = 5; i < 10; i++){
    digitalWrite(i, HIGH);
  }

}
else if(15 < distance && distance < 20){
  digitalWrite (9,LOW);
   digitalWrite (11,LOW);
  digitalWrite (13,LOW);
  for(int i = 5; i < 8; i++){
    digitalWrite(i, HIGH);
  }
}
else if(20 < distance && distance < 25){
    digitalWrite (7,LOW);
  digitalWrite (9,LOW);
   digitalWrite (11,LOW);
  digitalWrite (13,LOW);

  

  }
  else if(25 < distance && distance < 30){
 digitalWrite (6,LOW);
 digitalWrite (7,LOW);
 digitalWrite (9,LOW);
 digitalWrite (11,LOW);
  digitalWrite (13,LOW);
  
  

  }
  else if (distance > 30){
      for(int i = 5; i < 14; i++){
    digitalWrite(i, LOW);
  }
  }
  
}



