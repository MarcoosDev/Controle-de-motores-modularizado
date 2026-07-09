# Controle de motores com ponte H modular

Este projeto é uma base simples e modular para controlar o movimento de carrinhos que usam ponte H com microcontroladores compatíveis com C++/Arduino.  
Ele foi desenvolvido inicialmente para um ESP32-C3 Mini, mas a lógica pode ser adaptada para outros microcontroladores, desde que os pinos e a configuração do ambiente sejam ajustados.

## Objetivo

Criar um facilitador para:
- controlar motores esquerdo e direito;
- mover o carrinho para frente, trás, esquerda e direita;
- ler sensores com facilidade;
- organizar o código de forma limpa e reutilizável.

## Características

- Controle de dois motores independentes;
- Abstração para comandos de movimento básicos;
- Leitura de sensores analógicos;
- Estrutura organizada em arquivos `.h` e `main.cpp`;
- Compatível com PlatformIO, que é a recomendação para este projeto.

## Requisitos

- VS Code
- Extensão PlatformIO
- Placa compatível com Arduino/ESP32 (exemplo: ESP32-C3)
- Ponte H para controle dos motores
- Dois motores DC
- Sensores de linha ou reflectância, se quiser usar a leitura de sensores

## Estrutura do projeto

```text
Carrinho pro max/
├── include/
│   ├── controle.h
│   ├── motor.h
│   └── sensores.h
├── src/
│   └── main.cpp
├── platformio.ini
└── README.md
```

## Configuração atual

No exemplo atual, o projeto está configurado para usar:

- Motor esquerdo:
  - pino 8
  - pino 9
  - pino 10 (PWM)

- Motor direito:
  - pino 5
  - pino 6
  - pino 7 (PWM)

- Sensores:
  - esquerdo: pino 4
  - meio: pino 3
  - direito: pino 2

- Limite de leitura do sensor: `800`

Esses valores podem ser alterados conforme a sua montagem e o hardware utilizado.

## Como usar

1. Instale o VS Code.
2. Instale a extensão PlatformIO.
3. Abra a pasta do projeto no VS Code.
4. Ajuste o arquivo `platformio.ini` conforme a placa e a porta serial.
5. Compile e faça o upload para o microcontrolador.
6. Ajuste os pinos e os limites de sensor no código, se necessário.

## Exemplo de uso

O arquivo `src/main.cpp` já contém um exemplo simples de movimentação:

```cpp
mover.frente(2000);
mover.direita(500);
```

Os comandos disponíveis incluem:

```cpp
mover.frente();
mover.tras();
mover.esquerda();
mover.direita();
```

Os métodos aceitam um tempo opcional em milissegundos, por exemplo:

```cpp
mover.frente(1000);
mover.direita(500);
```

## Componentes principais

### Motor
A classe `Motor` controla um motor individual usando:
- dois pinos digitais para a direção;
- um pino PWM para a velocidade.

### ControleMotor
A classe `ControleMotor` junta os dois motores e fornece comandos de alto nível para movimentar o carrinho.

### Sensor
A classe `Sensor` lê os sensores analógicos e converte a leitura em valores lógicos baseados em um limite.

## Observações importantes

- O valor de `800` como limite pode precisar de ajuste conforme o sensor e a iluminação ambiente.
- Verifique a polaridade dos motores e da ponte H.
- Use uma fonte de alimentação adequada para os motores.
- No Windows, a porta serial do PlatformIO pode precisar ser alterada no `platformio.ini`.

## Recomendações

- O uso do PlatformIO é altamente recomendado, pois facilita a organização do projeto, compilação, upload e monitoramento serial.
- O projeto está estruturado de forma modular, o que facilita futuras expansões, como:
  - seguir linha;
  - controle PID;
  - calibração automática de sensores;
  - máquina de estados para navegação.

## Considerações finais

Este projeto serve como uma base prática para iniciar o desenvolvimento de carrinhos autônomos ou semiautônomos com controle simples por ponte H.  
A estrutura foi pensada para ser simples, didática e fácil de expandir.

## Autor

- Projeto desenvolvido por **Marcoosdev**.
- Email: marcoosdev@gmail.com