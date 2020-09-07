const int TriggerPin = 4;
const int EchoPin = 5;
long Duration;
int DistanceCm;
const float SoundSpeed = 348;

void setup() {
Serial.begin(9600); 
pinMode(TriggerPin, OUTPUT);
pinMode(EchoPin, INPUT);
}

void loop() {
digitalWrite(TriggerPin, LOW);
delayMicroseconds(2);
digitalWrite(TriggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(TriggerPin, LOW);
Duration = pulseIn(EchoPin, HIGH);
DistanceCm= (Duration*100*0.000001*SoundSpeed)/2; 
Serial.print("Distance: "); 
Serial.print(DistanceCm); 
Serial.print(" cm\n");
delay(1000);
}
