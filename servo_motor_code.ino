#include <Servo.h>

Servo meuServo;

int angulo = 0;

#include <CapacitiveSensor.h>

 

/*

* CapacitiveSense Library Demo Sketch

* Paul Badger 2008

* Uses a high value resistor e.g. 10M between send pin and receive pin

* Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.

* Receive pin is the sensor pin - try different amounts of foil/metal on this pin

*/

 

 

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // resistor de 10M entre os pinos 4 & 2; o pino 2 é o do sensor, o qual pode ser conectado ao alumínio

//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // resistor de 10M entre os pinos 4 & 6; o pino 6 é o do sensor, o qual pode ser conectado ao alumínio

//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // resistor de 10M entre os pinos 4 & 8; o pino 8 é o do sensor, o qual pode ser conectado ao alumínio

 

void setup()                    

{

  meuServo.attach(9);

  meuServo.write(angulo);

   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // o canal não se auto calibra

 

   Serial.begin(9600);

   //pinMode(9, OUTPUT);

}

 

void loop()                    

{

   

    long start = millis();

    long total1 =  cs_4_2.capacitiveSensor(30);

  //  long total2 =  cs_4_6.capacitiveSensor(30);

  //  long total3 =  cs_4_8.capacitiveSensor(30);

 

    Serial.print(millis() - start);        // configuração para milissegundos

    Serial.print("\t");                    // tab character for debug windown spacing

 

    Serial.println(total1);                  // output 1

    Serial.print("\t");

//    Serial.print(total2);                  // output 2

    Serial.print("\t");

//    Serial.println(total3);                // output 3

 

if (total1 > 50){
  Serial.println("180180180180180");

  meuServo.write(180);  

  } else {

    meuServo.write(0);

  }  }
