#ifndef CONTROLE_H
#define CONTROLE_H

#include <Arduino.h>
#include "motor.h"

struct ControleMotor {
    Motor ladoE;
    Motor ladoD;

    ControleMotor(Motor m1, Motor m2)
        : ladoE(m1), ladoD(m2)
    {
    }

    void begin(){
        ladoE.begin();
        ladoD.begin();
    }

    void frente(int time_delay = 0){
        ladoE.frente(255);
        ladoD.frente(255);
        if (time_delay > 0) delay(time_delay);
    }

    void tras(int time_delay = 0){
        ladoE.tras(255);
        ladoD.tras(255);
        if (time_delay > 0) delay(time_delay);
    }

    void esquerda(int time_delay = 0){
        ladoE.tras(255);
        ladoD.frente(255);
        if (time_delay > 0) delay(time_delay);
    }

    void direita(int time_delay = 0){
        ladoE.frente(255);
        ladoD.tras(255);
        if (time_delay > 0) delay(time_delay);
    }
};

#endif