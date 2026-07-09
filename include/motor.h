#define MOTOR_H
#ifdef MOTOR_H

#include <Arduino.h>

struct Motor {
    int pin1;
    int pin2;
    int pwm;

    Motor(int p1, int p2, int p3) {
        pin1 = p1;
        pin2 = p2;
        pwm = p3;
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

#endif