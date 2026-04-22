//declaracao dos botoes e do motor e qual local eles serao ligados 
#define AUMENTA 2
#define DIMINUI 3
#define LIGA 4
#define DESLIGA 5
#define MOTOR 6

int velocidade = 0;
bool ligado = false;
// pra saber se esta ligado 
// velocidade sera ate 255 
// 0 = desligado 
// 127 == 50%
// 255 = 100%
// porque vao ate 255? Porque o arduino é um microcontrolador de 8 bits e vai de 0 a 255

void setup()
{
//pinmode diz qual o pino e qual a funcao dele (entrada ou saida)
  pinMode(AUMENTA, INPUT);
  pinMode(DIMINUI, INPUT);
  pinMode(LIGA, INPUT);
  pinMode(DESLIGA, INPUT);
  pinMode(MOTOR, OUTPUT);
}

void loop()
{ 
//digitalRead serve para saber se o botao foi acionado, se foi HIGH, se nao LOW
  if (digitalRead(LIGA) == HIGH){
    if(!ligado){        // bug corrigido: era (= 255) atribuição em vez de comparação
      velocidade = 1;
      ligado = true;
    }
  }

  if (digitalRead(DESLIGA) == HIGH){
    velocidade = 0;     // bug corrigido: chave } faltando no bloco original
    ligado = false;
  }      
        
  if (ligado == true) {
  
    if (digitalRead(AUMENTA) == HIGH) {
      if(velocidade < 255){
        velocidade++;
        delay(100);
      }
    }

    if (digitalRead(DIMINUI) == HIGH){
      if(velocidade > 1){       // bug corrigido: > 0 desligaria o motor sem mudar ligado
        velocidade--;
        delay(100);         
      }
    }

    analogWrite(MOTOR, velocidade); 
    // Envia um sinal PWM pro pino do motor.
    // Isso controla a potência de 0 (desligado) até 255 (força máxima).

  } else {
    analogWrite(MOTOR, 0); // garante motor desligado quando ligado == false
  }
}
