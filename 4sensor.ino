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
#define YellowLedPin 3

int range =10;
int sensor1ISsence = 0;
int sensor2ISsence = 0;
int sensor3ISsence = 0;
int sensor4ISsence = 0;


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
  //sensor1ISsence=sensor2ISsence=0;
  sensor1Sence();
  sensor2Sence();
  sensor3Sence();
  sensor4Sence();
   Serial.print(sensor1ISsence);
      Serial.print("  " );
      Serial.print(sensor2ISsence);
      Serial.print("  " );
      Serial.print(sensor3ISsence);
      Serial.print("  " );
      Serial.println(sensor4ISsence);

      
 if(sensor1ISsence==1 && sensor2ISsence==1 ){
   if(sensor3ISsence==1 && sensor4ISsence==1 ){

      digitalWrite(YellowLedPin,HIGH);
      delay(200);
      digitalWrite(GreenLedPin,LOW);
      digitalWrite(YellowLedPin,LOW);
      digitalWrite(RedLedPin,HIGH);

   }
  else{
        digitalWrite(GreenLedPin,HIGH);
        digitalWrite(RedLedPin,LOW);
      }
 }else{
      digitalWrite(GreenLedPin,HIGH);
      digitalWrite(RedLedPin,LOW);
    }

    
delay(1000);
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

 if ( distance <= range){
     sensor1ISsence=1;
    }
else{
     sensor1ISsence = 0;
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

 if ( distance <= range){
     sensor2ISsence=1;
    }
else{
      sensor2ISsence=0;
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

 if ( distance <= range){
     sensor3ISsence=1;
    }
else{
     sensor3ISsence = 0;
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

 if ( distance <= range){
     sensor4ISsence=1;
    }
else{
     sensor4ISsence = 0;
    }
}


