/* Write a program that when you send a color to a diode, it will change its state to the opposite state. If the diode is on, it will be turned off, and vice versa.*/

#define redLed 10
#define greenLed 11

boolean redStatus = false;
boolean greenStatus = false;

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
      greenStatus = !greenStatus;
    } else if (data == "red") {
      redStatus = !redStatus;
    } else {
      Serial.println("Incorrect data: " + data);
    }
  }
  led();
}

void led() {
  digitalWrite(redLed, redStatus ? HIGH : LOW);
  digitalWrite(greenLed, greenStatus ? HIGH : LOW);
}
