#define sensor1EchoPin 13
#define sensor1TrigPin 12

#define sensor2EchoPin 11
#define sensor2TrigPin 10

#define sensor3EchoPin 9
#define sensor3TrigPin 8

#define sensor4EchoPin 7
#define sensor4TrigPin 6

#define GreenLedPin 5
#define RedLedPin 4

bool sensor1ISsence = false;
bool sensor2ISsence = false;
bool sensor3ISsence = false;
bool sensor4ISsence = false;


void setup() {
 
 Serial.begin(9600);
 pinMode(sensor1TrigPin, OUTPUT);
 pinMode(sensor1EchoPin, INPUT);
 pinMode(sensor2TrigPin, OUTPUT);
 pinMode(sensor2EchoPin, INPUT);
 pinMode(sensor3TrigPin, OUTPUT);
 pinMode(sensor3EchoPin, INPUT);
 pinMode(sensor4TrigPin, OUTPUT);
 pinMode(sensor4EchoPin, INPUT);

 pinMode(RedLedPin,OUTPUT);
 pinMode(GreenLedPin,OUTPUT);
}

void loop() {
  sensor1Sence();
  sensor2Sence();
  sensor3Sence();
  sensor4Sence();
  
 if(sensor1ISsence==true && sensor2ISsence==true && sensor3ISsence==true && sensor4ISsence==true){
      digitalWrite(GreenLedPin,LOW);
      digitalWrite(RedLedPin,HIGH);
  }

  else{
      digitalWrite(GreenLedPin,HIGH);
      digitalWrite(RedLedPin,LOW);
    }
  delay(100);
}

void sensor1Sence(){
 long duration, distance;
 digitalWrite(sensor1TrigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(sensor1TrigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(sensor1TrigPin, LOW);
 duration = pulseIn(sensor1EchoPin, HIGH);
 distance = (duration/2) / 29.1;

 if ( distance <= 5){
     sensor1ISsence=true;
    }
else{
     sensor1ISsence = false;
    }
}

void sensor2Sence(){
 long duration, distance;
 digitalWrite(sensor2TrigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(sensor2TrigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(sensor2TrigPin, LOW);
 duration = pulseIn(sensor2EchoPin, HIGH);
 distance = (duration/2) / 29.1;

 if ( distance <= 5){
     sensor2ISsence=true;
    }
else{
      sensor2ISsence=false;
    }
}

void sensor3Sence(){
 long duration, distance;
 digitalWrite(sensor3TrigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(sensor3TrigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(sensor3TrigPin, LOW);
 duration = pulseIn(sensor3EchoPin, HIGH);
 distance = (duration/2) / 29.1;

 if ( distance <= 5){
     sensor3ISsence=true;
    }
else{
     sensor3ISsence=false;
    }
}

void sensor4Sence(){
 long duration, distance;
 digitalWrite(sensor4TrigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(sensor4TrigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(sensor4TrigPin, LOW);
 duration = pulseIn(sensor4EchoPin, HIGH);
 distance = (duration/2) / 29.1;

 if ( distance <= 5){
      sensor4ISsence=true;
    }
else{
     sensor4ISsence=false;
    }
}

