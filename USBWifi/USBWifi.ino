
byte byteRead;
 
void setup() {                
//configura a comunicação seria com baud rate de 9600
  Serial.begin(9600);
}
 
void loop() {
   
  if (Serial.available())  //verifica se tem dados diponível para leitura
  {
    byteRead = Serial.read(); //le bytwe mais recente no buffer da serial
    Serial.println(byteRead);
    Serial.write(byteRead);   //reenvia para o computador o dado recebido
    delay(500);
  }
}
