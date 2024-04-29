#include <Arduino.h>

#define piezo 2
#define TRIG_PIN 3
#define ECHO_PIN 4

void setup() {
  pinMode(piezo, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(5, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2); 
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  
  distance = duration * 0.034 / 2;
  
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");


  if (distance <= 10) {
    digitalWrite(piezo, HIGH);
    digitalWrite(5, HIGH);
    } 
    else if (distance <= 30) {
      digitalWrite(piezo, HIGH);
      digitalWrite(5, HIGH);
      delay(50);
      digitalWrite(5, LOW);
      digitalWrite(piezo, LOW);
      delay(50);
    } 
    else if (distance <= 50) {
      digitalWrite(piezo, HIGH);
      digitalWrite(5, HIGH);
      delay(200);
      digitalWrite(piezo, LOW);
      digitalWrite(5, LOW);
      delay(200);
    }
}
