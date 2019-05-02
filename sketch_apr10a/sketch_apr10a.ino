int led = 1;
int cont = 1;
int i = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);  
  pinMode(2, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  led++;
  if (led > 2){
    led = 1;
  }
  digitalWrite(led, HIGH);
  if (cont == 50) {
    i = rand() % 300 + 10;
    cont = 1;
  }
  delay(i);
  cont++;
  digitalWrite(led, LOW);
}
