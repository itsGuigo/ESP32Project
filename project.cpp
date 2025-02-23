byte a[10] = {0,1,0,0,1,0,0,0,0,0};
byte b[10] = {0,0,0,0,0,1,1,0,0,0};
byte c[10] = {0,0,1,0,0,0,0,0,0,0};
byte d[10] = {0,1,0,0,1,0,0,1,0,0};
byte e[10] = {0,1,0,1,1,1,0,1,0,1};
byte f[10] = {0,1,1,1,0,0,0,1,0,0};
byte g[10] = {1,1,0,0,0,0,0,1,0,0};

int display1[7] = {0,1,2,3,4,5,6};
int display2[7] = {7,8,9,10,11,12,13}; 
int display3[7] = {14,15,16,17,18,19,20};
int display4[7] = {21,22,23,24,25,26,27};

byte l = 0;
byte l2 = 0;
byte l3 = 0;
byte l4 = 0;

unsigned long tempoAnterior = 0;

void setup() {
  for (int pin = 0; pin <= 27; pin++) {
    pinMode(pin, OUTPUT);
  }
  //pin mode específico do botão
  //pinMode(34, INPUT);
}

void loop() {
  atualizarDisplay(display1, l);
  atualizarDisplay(display2, l2);
  atualizarDisplay(display3, l3);
  atualizarDisplay(display4, l4);

  delay(60000);
  atualizarTempo();
//se o botão (pino 34) for true devemos incrementar +1 minuto l4++, mantendo a lógica de caso o minuto seja maior que 9 o l4 vira 0 e o l3 soma mais um e assim por diante
  // if(!digitalRead(34))
  // {
  //   //delay(60000);
  //   //atualizarTempo();   

  //   //if para não acontecer nada durante 1 minuto
  //   if (millis() - tempoAnterior >= 60000) 
  //   { 
  //     tempoAnterior = millis();
  //     atualizarTempo();
  //   }
  // }
  // else
  // {
  //   delay(200);
  //   while (digitalRead(34));
  //   atualizarTempo();
  // }  
}

void atualizarDisplay(int display[], byte valor) {
  digitalWrite(display[0], a[valor]);
  digitalWrite(display[1], b[valor]);
  digitalWrite(display[2], c[valor]);
  digitalWrite(display[3], d[valor]);
  digitalWrite(display[4], e[valor]);
  digitalWrite(display[5], f[valor]);
  digitalWrite(display[6], g[valor]);
}

void atualizarTempo()
{
  l4++;
  if (l4 > 9) 
  {
    l4 = 0;
    l3++; 
    if (l3 > 5) 
    {
      l3 = 0;
      l2++; 
      if (l2 > 9 || (l == 2 && l2 > 3)) 
      {
        l2 = 0;
         l++;
        if (l > 2) 
        {
           l = 0;
        }
      }
    }
  }
}

