#include <Servo.h>
#include <stdio.h>
#include <stdlib.h>


Servo piede;
Servo base;
Servo gomito;
Servo tarso;
Servo mano;

int pos = 0;
int pulsante = 13;
int i = 0;


int foto1 = A0;
int foto2 = A1;
int terreno = A4;
int valore1, valore2;


Servo movimentopos(Servo, int, int, int);
Servo movimentoneg(Servo, int, int, int);
Servo potdestro();
Servo potsinistro();
Servo start();
Servo ripdestro();
Servo ripsinistro();
Servo controllo();
Servo acqua();


void setup() {
// put your setup code here, to run once:
piede.attach(3);
base.attach(5);
gomito.attach(6);
tarso.attach(10);
mano.attach(11);

pinMode(foto1, INPUT);
pinMode(foto2, INPUT);
pinMode(terreno, INPUT);

pinMode(pulsante, INPUT);

Serial.begin(9600);
}


void loop() 
{
  i++;
  Serial.print("orologio: ");
  Serial.println(i);

  int val = digitalRead(pulsante);
  
  Serial.print("pulsante: ");
  Serial.println(val);
  int valTerreno = analogRead(terreno);
  Serial.print("terreno: ");
  Serial.println(valTerreno);
  delay(1000);

  if (val == 1 || i == 1800)
  {
    valore1 = analogRead(foto1);

    Serial.println("si funziono");
    Serial.print("valore1: ");
    Serial.println(valore1);
    if (valore1 == 0)
    {
      potsinistro();
      delay(1000);
      controllo();
      delay(100);
      acqua();
      delay(1000);
      ripsinistro();
    }

    delay(1000);

    valore2 = analogRead(foto2);
    Serial.print("valore2: ");
    Serial.println(valore2);

    if (valore2 == 0)
    {
      potdestro();
      delay(1000);
      controllo();
      delay(100);
      acqua();
      delay(1000);
      ripdestro();
    }
    
    delay(1000);
    i = 0;
    start();
  }
  
}

//FUNZIONE che può essere usata per qualunque servo, basta cambiare la chiamata della funzione


Servo start()
{
  if (gomito.read() < 180)
  {
    for (int i = gomito.read(); i < 180; i++)
    {
      gomito.write(i);
      delay(20);
    }
  }

  if (base.read() < 70)
  {  
    for (int i = base.read(); i < 70; i++)
    {
      base.write(i);
      delay(30);
    }
  }
  pos = piede.read();

  if (pos < 90)
  {
    for (int i = pos; i <= 87; i++)
    {
      piede.write(i);
      delay(40);
    }
  }

  if (pos > 90)
  {
    for (int i = pos; i >= 87; i--)
    {
      piede.write(i);
      delay(40);
    }
  }
  
  tarso.write(180);

  for (int i = base.read(); i > 30; i--)
  {
    base.write(i);
    delay(40);
  }
  
  for (int i = gomito.read(); i < 180; i++)
  {
    gomito.write(i);
    delay(40);
  }
  /*
  delay(1000);
  piede.detach();
  base.detach();
  gomito.detach();
  polso.detach();
  tarso.detach();
  mano.detach();
  delay(1000);*/
}

Servo movimentopos(Servo prova, int k, int j, int v)
{
  for (int i = k; i <= j; i += v)
  {
    prova.write(i);
    delay(30);    
  }
}

Servo movimentoneg(Servo prova, int k, int j, int v)
{
  for (int i = k; i >= j; i -= v)
  {
    prova.write(i);
    delay(30);
  }
}

Servo potsinistro()
{
  //movimento alza braccio
  movimentopos(base, base.read(), 90, 1);
  delay(1000);
  movimentoneg(gomito, gomito.read(), 90, 1);
  delay(1000);
  //posizionamento
  movimentopos(piede, piede.read(), 125, 1);
  delay(1000);
  movimentopos(gomito, gomito.read(), 160, 1);
  delay(100);
  movimentopos(tarso, tarso.read(), 180, 1);
  delay(500);
  movimentoneg(base, base.read(), 20, 1);
  delay(2000);
  movimentoneg(gomito, gomito.read(), 140, 1);
  delay(100);
  movimentoneg(tarso, tarso.read(), 130, 1);
  delay(100);
  movimentoneg(gomito, gomito.read(), 130, 1);
  delay(100);
  movimentoneg(base, base.read(), 10, 1);
  delay(100);
  movimentoneg(gomito, gomito.read(), 110, 1);
  delay(100);
  movimentoneg(mano, mano.read(), 50, 1); 
  delay(500);
  //spostamento a base centrale
  movimentopos(base, base.read(), 45, 1);
  delay(1000);
  movimentopos(tarso, tarso.read(), 150, 1);
  delay(500);
  movimentopos(gomito, gomito.read(), 167, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(1000);
  movimentoneg(tarso, tarso.read(), 110, 1);
  delay(100);
  movimentoneg(piede, piede.read(), 87, 1);
  delay(1000);
  movimentoneg(gomito, gomito.read(), 129, 1);
  delay(500);
  movimentoneg(base, base.read(), 55, 1);
  delay(1000);
  movimentopos(tarso, tarso.read(), 130, 1);
  delay(100);
  movimentoneg(base, base.read(), 15, 1);
  delay(1000);
  movimentopos(mano, mano.read(), 90, 1);
  delay(1000);
  //riposizionamento in posizione verticale successivamente il rilascio
  movimentopos(tarso, tarso.read(), 170, 1);
  delay(100);
  movimentopos(gomito, gomito.read(), 165, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(2000);
}

Servo potdestro()
{ 
  //movimento alza braccio
  movimentopos(base, base.read(), 90, 1);
  delay(1000);
  movimentoneg(gomito, gomito.read(), 90, 1);
  delay(1000);
  //posizionamento
  movimentoneg(piede, piede.read(), 54, 1);
  delay(1000);
  movimentopos(gomito, gomito.read(), 160, 1);
  delay(100);
  movimentopos(tarso, tarso.read(), 180, 1);
  delay(500);
  movimentoneg(base, base.read(), 25, 1);
  delay(2000);
  movimentoneg(gomito, gomito.read(), 140, 1);
  delay(100);
  movimentoneg(tarso, tarso.read(), 130, 1);
  delay(100);
  movimentoneg(gomito, gomito.read(), 120, 1);
  delay(100);
  movimentoneg(base, base.read(), 10, 1);
  delay(100);
  movimentoneg(gomito, gomito.read(), 110, 1);
  delay(100);
  movimentoneg(mano, mano.read(), 50, 1); 
  delay(500);
  //spostamento a base centrale
  movimentopos(base, base.read(), 45, 1);
  delay(1000);
  movimentopos(tarso, tarso.read(), 150, 1);
  delay(500);
  movimentopos(gomito, gomito.read(), 167, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(1000);
  movimentoneg(tarso, tarso.read(), 110, 1);
  delay(100);
  movimentopos(piede, piede.read(), 90, 1);
  delay(1000);
  movimentoneg(gomito, gomito.read(), 129, 1);
  delay(500);
  movimentoneg(base, base.read(), 55, 1);
  delay(1000);
  movimentopos(tarso, tarso.read(), 130, 1);
  delay(100);
  movimentoneg(base, base.read(), 15, 1);
  delay(1000);
  movimentopos(mano, mano.read(), 90, 1);
  delay(1000);
  //riposizionamento in posizione verticale successivamente il rilascio
  movimentopos(tarso, tarso.read(), 170, 1);
  delay(100);
  movimentopos(gomito, gomito.read(), 165, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(2000);
}

Servo ripdestro()
{  
  //movimento alza braccio
  movimentopos(base, base.read(), 90, 1);
  delay(1000);
  movimentoneg(gomito, gomito.read(), 90, 1);
  delay(1000);
  //posizionamento
  movimentoneg(piede, piede.read(), 87, 1);
  delay(1000);
  movimentopos(gomito, gomito.read(), 160, 1);
  delay(100);
  movimentopos(tarso, tarso.read(), 180, 1);
  delay(500);
  movimentoneg(base, base.read(), 25, 1);
  delay(2000);
  movimentoneg(gomito, gomito.read(), 140, 1);
  delay(100);
  movimentoneg(tarso, tarso.read(), 140, 1);
  delay(100);
  movimentoneg(base, base.read(), 10, 1);
  delay(100);
  movimentoneg(gomito, gomito.read(), 130, 1);
  delay(100);
  movimentoneg(mano, mano.read(), 50, 1); 
  delay(500);
  //spostamento a base centrale
  movimentopos(base, base.read(), 45, 1);
  delay(1000);
  movimentopos(tarso, tarso.read(), 150, 1);
  delay(500);
  movimentopos(gomito, gomito.read(), 167, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(1000);
  movimentoneg(tarso, tarso.read(), 110, 1);
  delay(100);
  movimentoneg(piede, piede.read(), 54, 1);
  delay(1000);
  movimentoneg(gomito, gomito.read(), 118, 1);
  delay(500);
  movimentoneg(base, base.read(), 35, 1);
  delay(1000);
  movimentopos(tarso, tarso.read(), 155, 1);
  delay(100);
  movimentoneg(base, base.read(), 10, 1);
  delay(1000);
  movimentopos(mano, mano.read(), 90, 1);
  delay(1000);
  //riposizionamento in posizione verticale successivamente il rilascio
  movimentopos(tarso, tarso.read(), 170, 1);
  delay(100);
  movimentopos(gomito, gomito.read(), 165, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(2000);
}

Servo ripsinistro()
{
  //movimento alza braccio
  movimentopos(base, base.read(), 90, 1);
  delay(1000);
  movimentoneg(gomito, gomito.read(), 90, 1);
  delay(1000);
  //posizionamento
  movimentoneg(piede, piede.read(), 87, 1);
  delay(1000);
  movimentopos(gomito, gomito.read(), 160, 1);
  delay(100);
  movimentopos(tarso, tarso.read(), 180, 1);
  delay(500);
  movimentoneg(base, base.read(), 25, 1);
  delay(2000);
  movimentoneg(gomito, gomito.read(), 140, 1);
  delay(100);
  movimentoneg(tarso, tarso.read(), 140, 1);
  delay(100);
  movimentoneg(base, base.read(), 10, 1);
  delay(100);
  movimentoneg(gomito, gomito.read(), 130, 1);
  delay(100);
  movimentoneg(mano, mano.read(), 50, 1); 
  delay(500);
  //spostamento a base centrale
  movimentopos(base, base.read(), 45, 1);
  delay(1000);
  movimentopos(tarso, tarso.read(), 150, 1);
  delay(500);
  movimentopos(gomito, gomito.read(), 167, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(1000);
  movimentoneg(tarso, tarso.read(), 110, 1);
  delay(100);
  movimentopos(piede, piede.read(), 125, 1);
  delay(1000);
  movimentoneg(gomito, gomito.read(), 115, 1);
  delay(500);
  movimentoneg(base, base.read(), 35, 1);
  delay(1000);
  movimentopos(tarso, tarso.read(), 155, 1);
  delay(100);
  movimentoneg(base, base.read(), 10, 1);
  delay(1000);
  movimentopos(mano, mano.read(), 90, 1);
  delay(1000);
  //riposizionamento in posizione verticale successivamente il rilascio
  movimentopos(tarso, tarso.read(), 170, 1);
  delay(100);
  movimentopos(gomito, gomito.read(), 165, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(2000);
}  

Servo controllo()
{
  movimentopos(base, base.read(), 90, 1);
  delay(100);
  movimentopos(piede, piede.read(), 90, 1);
  delay(100);
  movimentoneg(gomito, gomito.read(), 110, 1);
  delay(100);
  movimentoneg(tarso, tarso.read(), 15, 1);
  delay(100);
  movimentoneg(mano, mano.read(), 10, 1);
  delay(100);
  movimentoneg(base, base.read(), 50, 1);
  delay(15000);
  movimentopos(base, base.read(), 70, 1);
  delay(100);
  movimentopos(gomito, gomito.read(), 120, 1);
  delay(100);
  movimentopos(base, base.read(), 90, 1);
  delay(100);
  movimentopos(tarso, tarso.read(), 175, 1);
  delay(100);
  movimentopos(mano, mano.read(), 90, 1);
  delay(1000);
}

Servo acqua()
{
  movimentopos(piede, piede.read(), 96, 1);
  delay(100);
  movimentoneg(gomito, gomito.read(), 100, 1);
  delay(100);
  movimentoneg(base, base.read(), 30, 1);
  delay(100);
  movimentopos(tarso, tarso.read(), 180, 1);
  delay(25000);

}

