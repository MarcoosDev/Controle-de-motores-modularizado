#include <Arduino.h>
#include <motor.h>

Motor motorE(8,9,10);
Motor motorD(5,6,7);

ControleMotor mover(motorE,motorD);

int contador = 0;

void setup() {
  mover.begin();
  Serial.begin(115200);
}

void loop() {
  mover.frente(2000);
  mover.direita(500);
  mover.parar(1000);
}
