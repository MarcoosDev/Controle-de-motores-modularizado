#include <Arduino.h>
#include <sensores.h>
#include <motor.h>

Motor motorE(8,9,10);
Motor motorD(5,6,7);

ControleMotor mover(motorE,motorD);

Sensor sensor(4,3,2,800); 

int contador = 0;

void setup() {
  sensor.begin();
  mover.begin();
  Serial.begin(115200);
}

void loop() {
  mover.frente(2000);
  mover.direita(500);
  mover.parar(1000);
}
