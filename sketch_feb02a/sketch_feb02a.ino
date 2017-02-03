

int val = 0;
static bool isClicked = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorVal = digitalRead(2);

  val = analogRead(2);
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
    isClicked = false;

  } else {
    digitalWrite(13, HIGH);
    if (!isClicked) {
      isClicked = true;
      Serial.print("openW");
      Serial.flush();
    }
    Serial.print("pot: ");
    Serial.print(val);
    Serial.flush();

  }
  delay(100);
}
