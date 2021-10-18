#define redLed 10
#define greenLed 11

String data = "";

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
}

void loop() { 
  if(Serial.available() > 0) {
    data = Serial.readStringUntil('\n');
    if(data == "green") {
      green();
    } else if (data == "red") {
      red();
    } else {
      Serial.println("Incorrect data: " + data);
    }
  }
}

void red() {
  digitalWrite(redLed, HIGH);
  delay(1000);
  digitalWrite(redLed, LOW);
}

void green() {
  digitalWrite(greenLed, HIGH);
  delay(1000);
  digitalWrite(greenLed, LOW);
}
