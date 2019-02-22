/*
Distance sensor with HC-SR04 ultrasound sensor
The shorter the distance to the sensor the more LED's will be on 
by soleil_zero
*/

const int trigPin = 3;  //Pins 2 and 3 are trigPin (sends an ultrasound signal) and echoPin (recieves the ultrasound signal)
const int echoPin = 2;

int duration; //Creates duration and distance variables
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);    //Pins 2 and 3 are trigPin and echoPin
  pinMode(echoPin, INPUT);
  for (int i = 4; i < 9; i++){ //Turns the pins from 4 to 8 to binary output
    pinMode(i, OUTPUT);
  }
}

void loop(){
digitalWrite(trigPin, LOW);  //Initially sets off the ultrasound
delayMicroseconds(2);

digitalWrite(trigPin, HIGH); //Turn the ultrasound on sending a signal on trigPin for 10 microseconds 
delayMicroseconds(10);

digitalWrite(trigPin, LOW);   
duration = pulseIn(echoPin, HIGH);//Takes the time the signal took to reflect itself and calculates the distance from it
distance = 0.034 * duration/2;

if(distance < 5){               //If an object is less than 5cm away all LEDs will be turned ON
  for(int i = 4; i < 9; i++){
    digitalWrite(i, HIGH);
  }
}

else if(5 < distance && distance < 10){ // For every 5cm farther one LED won't be turned ON
  digitalWrite(8,LOW);
  for (int i = 4; i < 8; i++){
    digitalWrite(i, HIGH);
  }
}
else if(10 < distance && distance < 15){
  digitalWrite (7,LOW);
  digitalWrite (8,LOW);
  for(int i = 4; i < 7; i++){
    digitalWrite(i, HIGH);
  }

}
else if(15 < distance && distance < 20){
    for (int i = 6; i < 9; i++){
    digitalWrite(i, LOW);
    }
  for(int i = 4; i < 6; i++){
    digitalWrite(i, HIGH);
  }
}
else if(20 < distance && distance < 25){
  digitalWrite (4,HIGH);
  for (int i = 5; i < 9; i++){
    digitalWrite(i, LOW);
  }
}
}
