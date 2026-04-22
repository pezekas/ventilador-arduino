# Ventilador com Arduino

Projeto feito na faculdade para controlar um ventilador com Arduino.
Nessa versão o controle é feito por botões — ligar, desligar, 
aumentar e diminuir a velocidade manualmente.

O projeto original usava termistor e display LCD para ligar o 
ventilador automaticamente pela temperatura, mas esse código aqui 
é a versão com controle manual que ficou salva.

Como funciona?

Quatro botões controlam o motor via sinal PWM. O Arduino é um 
microcontrolador de 8 bits, então a velocidade vai de 0 a 255:
- 0 = desligado
- 127 = 50% da potência  
- 255 = 100% da potência

O que aprendi?

- Como funciona PWM em microcontroladores
- Leitura de entradas digitais com digitalRead()
- Controle de estado com variáveis booleanas
- Estrutura básica de um programa Arduino (setup/loop)

## Tecnologias

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)
