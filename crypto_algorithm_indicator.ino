arduino/crypto_algorithm_indicator.ino
void blinkPattern(int pattern, int totalDuration) {
  long start = millis();
  
  while (millis() - start < totalDuration) {
    if (pattern == 1) {
      // RSA - slow single blink
      digitalWrite(13, HIGH);
      delay(800);
      digitalWrite(13, LOW);
      delay(400);
      
    } else if (pattern == 2) {
      // AES - double blink
      digitalWrite(13, HIGH); delay(200);
      digitalWrite(13, LOW);  delay(150);
      digitalWrite(13, HIGH); delay(200);
      digitalWrite(13, LOW);  delay(500);
      
    } else if (pattern == 3) {
      // DES - rapid triple blink
      digitalWrite(13, HIGH); delay(100);
      digitalWrite(13, LOW);  delay(100);
      digitalWrite(13, HIGH); delay(100);
      digitalWrite(13, LOW);  delay(100);
      digitalWrite(13, HIGH); delay(100);
      digitalWrite(13, LOW);  delay(400);
    }
  }
  
  digitalWrite(13, LOW); // make sure LED is off
  Serial.println("DONE");
}

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  if (Serial.available() > 0) {
    String msg = Serial.readStringUntil('\n');
    msg.trim();

    if (msg == "RSA") {
      Serial.println("RSA encryption detected - 7s slow blink");
      blinkPattern(1, 7000);

    } else if (msg == "AES") {
      Serial.println("AES encryption detected - 6s double blink");
      blinkPattern(2, 6000);

    } else if (msg == "DES") {
      Serial.println("DES encryption detected - 5s triple blink");
      blinkPattern(3, 5000);
    }
  }
}
