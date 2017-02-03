#include <SoftwareSerial.h>
SoftwareSerial BTserial(3, 4); // RX | TX



static bool isClicked = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  // HC-06 default serial speed is 9600
  BTserial.begin(9600);

}

void loop() {


  if (BTserial.available()) {
    Serial.write(BTserial.read());
  }
  
  if (Serial.available()) {
    BTserial.write(Serial.read());
  }

    int sensorVal = digitalRead(2);
  
    if (sensorVal == HIGH) {
      if (isClicked) {
        isClicked = false;
        Serial.print("closeW");
        Serial.print("\n");
        Serial.flush();
      }
  
    } else {
      if (!isClicked) {
        isClicked = true;
        Serial.print("openW");
        Serial.print("\n");
        Serial.flush();
      }
  
    }
    //delay(100);
}
