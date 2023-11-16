int pinAzul = 12; //Controle do Led usando a porta 12
int pinInterruptor = 7; //Controle do Botao usando a porta 7
int estadoInterruptor;  //Guarda o estado do interruptor caso Pressionado ou Nao
int pinBuzzer = 2;  //Controle do Buzzer usando a porta 2
int lastPressTime = 0; //Variavel usada para controlar tem do interruptor ligado
int duration = 1000;  //Variavel usada para controlar tambem o tempo que o buzzer emite som
int pinMotor = 3; //Controle do motor usando a porta 3

void setup()
{
  pinMode(pinAzul,OUTPUT);  //Saida de corrente da porta 12
  pinMode(pinInterruptor,INPUT);  //Entrada de corrente na porta 7
  pinMode(pinBuzzer,OUTPUT);  //Saida de corrente na porta 2
  pinMode(pinMotor,OUTPUT); //Saida de corrente na porta 3
}

void loop()
{
 
  estadoInterruptor = digitalRead(pinInterruptor);  //estadoBotao guarda a situação caso Interruptor seja ligado ou nao
  
  if (estadoInterruptor == HIGH)  //Verificar se interruptor foi ligado 
  {
    digitalWrite(pinAzul,HIGH); //Led liga

    if(millis() - lastPressTime < duration) //Verifica se o tempo do interruptor é menor que a variavel duracao
    {
      digitalWrite(pinBuzzer,HIGH); // Buzzer emite som
    }
    else
    {
      digitalWrite(pinBuzzer,LOW); //Buzzer para de emitir som
    }

    digitalWrite(pinMotor,HIGH); //Motor começa a funcionar
  }
  else
  {
    digitalWrite(pinBuzzer,LOW);  //Buzzer desliga
    digitalWrite(pinAzul,LOW);  //Led desliga
    digitalWrite(pinMotor,LOW); //Motor desliga
    lastPressTime = millis(); //Atualiza a variavel do tempo que o interruptor fica ligado
  }
  
  delay(500); //Intervalo de tempo para outra instrução quando ligar e desligar o interruptor
   
}
