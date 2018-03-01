
// Variable to store the value coming from the sensor
int LWS = 0;

void setup() {
    // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);
}

void loop() {

  // Read from A0 and store in LWS
  LWS = analogRead(A0);
  printReading(LWS);
  delay(5000);

}

void printReading(int LWS) {
  Serial.print("LWS currently: ");
  Serial.println(LWS);
}

