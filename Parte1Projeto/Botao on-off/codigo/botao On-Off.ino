// C++ code
//
int pinLed = 13;
int pinBotao = 9;
int estadoBotao;
int estadoLed;
void setup()
{
  pinMode(pinLed,OUTPUT);
  pinMode(pinBotao,INPUT);
}

void loop()
{
  estadoBotao = digitalRead(pinBotao);
  estadoLed = digitalRead(pinLed);
  
  if(estadoBotao == HIGH)
  {
    digitalWrite(pinLed,!estadoLed);
    delay(200);
  }
   
}