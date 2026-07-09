#ifndef CARRINHO_H
#define CARRINHO_H

#include <Arduino.h>

struct Motor {
    int pin1;
    int pin2;
    int pwm;

    
    Motor(int p1, int p2, int p3)
        : pin1(p1), pin2(p2), pwm(p3)
    {
    }

    void begin() {
        pinMode(pin1, OUTPUT);
        pinMode(pin2, OUTPUT);
        pinMode(pwm, OUTPUT);
    }

    void frente(uint8_t velocidade) {
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        analogWrite(pwm, velocidade);
    }

    void tras(uint8_t velocidade) {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        analogWrite(pwm, velocidade);
    }

    void parar(uint8_t velocidade = 0) {
        analogWrite(pwm, 0);
    }
};

struct ControleMotor {
    Motor ladoE;
    Motor ladoD;

    ControleMotor(Motor m1, Motor m2)
        : ladoE(m1), ladoD(m2)
    {
    }

    void begin() {
        ladoE.begin();
        ladoD.begin();
    }

    void frente(int time_delay = 0) {
        ladoE.frente(255);
        ladoD.frente(255);
        if (time_delay > 0) delay(time_delay);
    }

    void tras(int time_delay = 0) {
        ladoE.tras(255);
        ladoD.tras(255);
        if (time_delay > 0) delay(time_delay);
    }

    void esquerda(int time_delay = 0) {
        ladoE.tras(255);
        ladoD.frente(255);
        if (time_delay > 0) delay(time_delay);
    }

    void direita(int time_delay = 0) {
        ladoE.frente(255);
        ladoD.tras(255);
        if (time_delay > 0) delay(time_delay);
    }

    void parar(int time_delay = 0) {
        ladoE.parar();
        ladoD.parar();
        if (time_delay > 0) delay(time_delay);
    }
};

#endif