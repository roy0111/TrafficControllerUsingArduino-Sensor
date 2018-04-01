#define sencor1EchoPin 13
#define sencor1TrigPin 12

#define GreenLedPin 11


void setup() {
 
 Serial.begin(9600);
 pinMode(sencor1TrigPin, OUTPUT);
 pinMode(sencor1EchoPin, INPUT);

 pinMode(GreenLedPin,OUTPUT);
}

void loop() {
  secsor1Sence();
}

void secsor1Sence(){
 long duration, distance;
 digitalWrite(sencor1TrigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(sencor1TrigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(sencor1TrigPin, LOW);
 duration = pulseIn(sencor1EchoPin, HIGH);
 distance = (duration/2) / 29.1;

 if ( distance <= 15){
 digitalWrite(GreenLedPin,HIGH);
    }
else{
 digitalWrite(GreenLedPin,LOW);
    }
    Serial.println(" countodd");
    delay(50);
    Serial.println(" counteven");
}

