/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

//pinX pin del display
//El otro es la conexion al arduino (gpio)
//   D4 A F D3 D2 B
//      8.8.8.8.
//   E D . C G D1
int pinA = 9;
int pinB = 13;
int pinC = 5;
int pinD = 3;
int pinE = 2;
int pinF = 10;
int pinG = 6;
//int dot = 4;
int D1 = 7;
int D2 = 12;
int D3 = 11;
int D4 = 8;

//D7 dht11
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);



// the setup routine runs once when you press reset:
void setup() {                
  Serial.begin(9600);
  dht.begin();
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT); 
  pinMode(4,INPUT)  ;
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);
  
}
  int cont=0;  

// the loop routine runs over and over again forever:
void loop() {
  int t= dht.readTemperature();//Lee la temperatura
  int h= dht.readHumidity();//Lee la temperatura
  while (cont < 1500){
  show_temp(t);
  cont++;
  }
  cont=0;
//delay(2000);
  while (cont <1500){
   show_hum(h);
   cont++;
  }
  cont=0;

}

void show_temp(int temp){
  int d=temp/10;
  int u=temp%10;
 Serial.println(d);
 Serial.println(u);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW); 
  te();
  delay(2);
  show_dec(d);
  delay(2);
  show_uni(u);
  delay(2); 
  }

void show_hum(int hum){
  int d=hum/10;
  int u=hum%10;
 Serial.println(d);
 Serial.println(u);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW); 
  hache();
  delay(2);
  show_dec(d);
  delay(2);
  show_uni(u);
  delay(2); 
  }
void show_dec(int dec){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
 
   switch (dec) {
      case 1:
        uno();
        break;
      case 2:
        dos();
        break;
      case 3:
        tres();
        break;
      case 4:
        cuatro();
        break;
      case 5:
        cinco();
        break;
      case 6:
        seis();
        break;
       case 7:
        siete();
        break;
       case 8:
        ocho();
        break;
        case 9:
        nueve();
        break;
      default:
         Serial.println("nada");
         break;
    }
  }

void show_uni(int uni){
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH); 
 
   switch (uni) {
      case 1:
        uno();
        break;
      case 2:
        dos();
        break;
      case 3:
        tres();
        break;
      case 4:
        cuatro();
        break;
      case 5:
        cinco();
        break;
      case 6:
        seis();
        break;
       case 7:
        siete();
        break;
       case 8:
        ocho();
        break;
        case 9:
        nueve();
        break;
      default:
         Serial.println("nada");
         break;
    }
  }

void cero(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void uno(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void dos(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
  }

void tres(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void cuatro(){ 
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  }


void cinco(){ 
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
  }

void seis() { 
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void siete() { 
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void ocho() { 
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void nueve(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void te() { 
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void hache() { 
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
