#define SENSOR_H
#ifdef SENSOR_H

#include <Arduino.h>

#define BRANCO LOW
#define PRETO HIGH

struct Leituras {
    int esquerda;
    int meio;
    int direita;
};

struct Sensor {
    int esquerda;
    int meio;
    int direita;
    int limite;

    Sensor(int p1, int p2, int p3, int l)
        : esquerda(p1), meio(p2), direita(p3), limite(l){}

    void begin() {
        pinMode(esquerda, INPUT);
        pinMode(meio, INPUT);
        pinMode(direita, INPUT);
    }

    Leituras ler() {
        return {
            (analogRead(esquerda) < limite) ? PRETO : BRANCO,
            (analogRead(meio) < limite) ? PRETO : BRANCO,
            (analogRead(direita) < limite) ? PRETO : BRANCO
        };
    }
};

#endif