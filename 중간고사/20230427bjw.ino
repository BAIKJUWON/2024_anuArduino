void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int a = analogRead(A0);
  Serial.println(a);

  delay(500);

  if(a>=150) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);
}

