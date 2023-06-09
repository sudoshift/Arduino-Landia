//Constante que representa o pino onde o positivo do 
//led será ligado.
const int led = 11; //Significa que a porta digital 11 terá o controle do led
 
// Efeito de fader
int brilho = 0;
int fader = 5;
boolean acende = true;
boolean apaga = false;
 
//Método setup, executado uma vez ao ligar o Arduino.
void setup() {
  //Definindo o pino led como de saída.
  pinMode(led,OUTPUT);
}
 
//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {  
  analogWrite(led,brilho);  
   
  //Processo de acendimento do led usando o efeito fader.
  if (acende == true) {
    if (brilho < 255) {
      brilho = brilho + fader; //aumentando o brilho do led.
    } else {     
      acende = false;
      apaga = true;
    }
  }
 
  //Processo para apagar o led com efeito fader.  
  if (apaga == true) {
    if (brilho > 0) {
      brilho = brilho - fader; // diminuindo o brilho do led.
    } else {
      acende = true;
      apaga = false;
    }
  }
   
  delay(20);
}