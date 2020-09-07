
unsigned long Time=0;
const byte interruptPin1 = 2;
const byte interruptPin2 = 3;
const byte ThresholdPin = 7;
const byte HVoffPin = 8;
const byte Tx1Pin = 5;
const byte Tx2Pin = 6;
const byte EchoPin = 4;
volatile byte PulseTrain = LOW;
volatile byte state2 = LOW;
volatile int Threshold = HIGH;
volatile byte HVoff = HIGH;
volatile byte Echo = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  pinMode(ThresholdPin, OUTPUT);
  pinMode(HVoffPin, OUTPUT);
  pinMode(Tx1Pin, OUTPUT);
  pinMode(Tx2Pin, OUTPUT);
  pinMode(EchoPin, OUTPUT);
  digitalWrite(ThresholdPin, Threshold);
  digitalWrite(HVoffPin, HVoff);
  digitalWrite(Tx1Pin, LOW);
  digitalWrite(Tx2Pin, LOW);
  digitalWrite(EchoPin, Echo);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), Trigger, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), Signal, RISING);
}

void loop() {
  while(PulseTrain = HIGH){
    for(int i = 1; i <= 8; i++){
      digitalWrite(Tx1Pin, HIGH);
      digitalWrite(Tx2Pin, LOW);
      delayMicroseconds(12);
      digitalWrite(Tx1Pin, LOW);
      digitalWrite(Tx2Pin, HIGH);
      delayMicroseconds(12);
      
    }
    digitalWrite(Tx2Pin, LOW);
    Echo = HIGH;
    digitalWrite(EchoPin, Echo);
    Threshold = HIGH;
    HVoff = HIGH;
    digitalWrite(ThresholdPin,Threshold);
    digitalWrite(HVoffPin, HVoff);
    PulseTrain = LOW;
    break;
  }
  while(Echo == HIGH){
    if(Time>200){
      digitalWrite(EchoPin, LOW);
      Time = 0;
      Serial.print("Long Echo Error");
      Echo = LOW;
      break;
    }
    else{
      delay(1);
      Time++;
    }
  }
}

void Trigger() {
  delayMicroseconds(12);
  Threshold = LOW;
  digitalWrite(ThresholdPin,Threshold);
  HVoff=LOW;
  digitalWrite(HVoffPin, HVoff);
  delayMicroseconds(248);
  PulseTrain = HIGH;
}

void Signal() {
  Echo = LOW;
  digitalWrite(EchoPin, Echo);
}

