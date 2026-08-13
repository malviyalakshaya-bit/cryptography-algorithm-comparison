void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      digitalWrite(13, HIGH);
      Serial.println("LED ON");
    }

    else if (command == '0') {
      digitalWrite(13, LOW);
      Serial.println("LED OFF");
    }
  }
}
