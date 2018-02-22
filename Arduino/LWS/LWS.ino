int sensorPin = 0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
 
int sensorVCC = 13;
 
void setup() {
  // declare the ledPin as an OUTPUT:
   Serial.begin(9600);  
   pinMode(sensorVCC, OUTPUT); 
   digitalWrite(sensorVCC, LOW);
}
 
void loop() {
  // power the sensor
  digitalWrite(sensorVCC, HIGH);
  delay(1000); //make sure the sensor is powered
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  //stop power 
  digitalWrite(sensorVCC, LOW);  
  //wait
  delay(100);          
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);                   
}
