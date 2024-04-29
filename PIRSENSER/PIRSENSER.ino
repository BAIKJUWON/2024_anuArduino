int PIR = 7;
int LED = 8;
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);
}

void loop()
{
  if (digitalRead(PIR) == HIGH) 
  { 
    digitalWrite(LED, HIGH);      
    Serial.println("Motion detected!"); 
    delay(100);                   
  } 
  else 
  {
    digitalWrite(LED, LOW);       
    Serial.println("Motion stopped!");
    delay(100);                   
  }

}