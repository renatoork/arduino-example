/*
Projeto Arduino controlando um motor cc.
Por Jota
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/
 
//pino analógico onde o potenciômetro está conectado.
int const potenciometro = 0; 
 
//pino digital onde o TIP120 está conectado.
int const transistor = 3;    
 
//armazenará o valor lido no potenciômetro.
int valPotenciometro = 0;    
 
//função setup é executada uma vez quando o arduino é ligado.
void setup() {
 Serial.begin(9600);
  //definindo o pino digital 9 como de saída.
  pinMode(transistor, OUTPUT); 
}
 
//Função loop é executada repetidamente enquanto 
//o arduino estiver ligado.
void loop() {    
   
  //lendo o valor do potenciômetro (0 até 1023) e 
  //dividindo por 4 para obter um valor entre 0 e 255
  //que são valores adequados para a base do TIP120.
  valPotenciometro = analogRead(potenciometro) / 4;
  
  Serial.println(valPotenciometro);
 
   
  //atribuindo o valor lido no potenciômetro 
  //a base do TIP120.  
  analogWrite(transistor, valPotenciometro); 
} 
