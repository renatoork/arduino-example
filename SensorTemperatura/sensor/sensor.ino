int pinTemp = A1;
int pinleit = A5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp1 = analogRead(pinTemp);
  float leitV = analogRead(pinleit);
  Serial.println(1023/leitV);
  int v = (4.98 * temp1 * 100.0) / 1023;
  Serial.println(v);
  Serial.println(temp1);
  int temp = temp1 * 0.4868035190615836;
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  delay(1000);  
}

