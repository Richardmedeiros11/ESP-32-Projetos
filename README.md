# ESP-32-Projetos
#### Diagrama da placa
![image](https://github.com/user-attachments/assets/c2547f05-9527-4ab0-9daa-fa24093cecb7)
#### Pinagem da Placa 
![image](https://github.com/user-attachments/assets/aefc4b7d-3e22-40ab-9707-65f11a3d2971)
 - Pinos GPIOs: GPIO (General Purpose Input/Output), são pinos de proposito geral que podem ser configurados como I/O Digital alem de outras funções (PWM etc.)

| **Pino**  | **Função Extra**  | **Restrições/Observações** |
|-----------|------------------|----------------------------|
| **GPIO 0**  | Boot Mode, ADC2  | Deve estar em HIGH na inicialização |
| **GPIO 1**  | TX (UART0)  | Usado para comunicação serial (debug) |
| **GPIO 2**  | ADC2, LED interno | Deve estar em LOW para modo de boot correto |
| **GPIO 3**  | RX (UART0)  | Usado para comunicação serial (debug) |
| **GPIO 4**  | ADC2, Touch  | Sem restrições |
| **GPIO 5**  | SCK (SPI) | Boot falha se estiver em HIGH |
| **GPIO 6-11** | Flash SPI  | **Não pode ser usado** (conectado à memória flash) |
| **GPIO 12** | ADC2, Touch  | Boot falha se estiver em HIGH |
| **GPIO 13** | ADC2, Touch  | Sem restrições |
| **GPIO 14** | ADC2, Touch  | Sem restrições |
| **GPIO 15** | ADC2, Touch  | Boot falha se estiver em HIGH |
| **GPIO 16** |  | Pode ser usado normalmente |
| **GPIO 17** |  | Pode ser usado normalmente |
| **GPIO 18** | SCK (SPI) | Pode ser usado normalmente |
| **GPIO 19** | MISO (SPI) | Pode ser usado normalmente |
| **GPIO 21** | SDA (I2C) | Pode ser usado normalmente |
| **GPIO 22** | SCL (I2C) | Pode ser usado normalmente |
| **GPIO 23** | MOSI (SPI) | Pode ser usado normalmente |
| **GPIO 25** | ADC2, DAC | Pode ser usado normalmente |
| **GPIO 26** | ADC2, DAC | Pode ser usado normalmente |
| **GPIO 27** | ADC2, Touch | Pode ser usado normalmente |
| **GPIO 32** | ADC1, Touch | Apenas entrada analógica/digital |
| **GPIO 33** | ADC1, Touch | Apenas entrada analógica/digital |
| **GPIO 34** | ADC1 | **Somente entrada** |
| **GPIO 35** | ADC1 | **Somente entrada** |
| **GPIO 36** | ADC1 | **Somente entrada** |
| **GPIO 39** | ADC1 | **Somente entrada** |
 - Pinos ADC: Analog-to-Digital Converter (ADC) são os pinos que fazem a conversão analogica-digital, são usadas para receber/enviar dados digitais, como dados de potenciometros etc. A resolução do ADC pode ser configurada até 12 bits, o que significa que o valor lido varia de 0 a 4095 (para tensões entre 0V e 3.3V).

##### **ADC1 (Recomendado para Uso Geral)**
| **GPIO** | **Canal ADC** | **Observações** |
|---------|--------------|----------------|
| **GPIO 32** | ADC1_CH4 | Sem restrições |
| **GPIO 33** | ADC1_CH5 | Sem restrições |
| **GPIO 34** | ADC1_CH6 | **Somente entrada** |
| **GPIO 35** | ADC1_CH7 | **Somente entrada** |
| **GPIO 36 (VP)** | ADC1_CH0 | **Somente entrada** |
| **GPIO 37** | ADC1_CH1 | **Somente entrada** |
| **GPIO 38** | ADC1_CH2 | **Somente entrada** |
| **GPIO 39 (VN)** | ADC1_CH3 | **Somente entrada** |

##### **ADC2 (Pode ter conflito com Wi-Fi)**
| **GPIO** | **Canal ADC** | **Observações** |
|---------|--------------|----------------|
| **GPIO 0**  | ADC2_CH1 | Conflito com Wi-Fi |
| **GPIO 2**  | ADC2_CH2 | Conflito com Wi-Fi |
| **GPIO 4**  | ADC2_CH0 | Conflito com Wi-Fi |
| **GPIO 12** | ADC2_CH5 | Conflito com Wi-Fi |
| **GPIO 13** | ADC2_CH4 | Conflito com Wi-Fi |
| **GPIO 14** | ADC2_CH6 | Conflito com Wi-Fi |
| **GPIO 15** | ADC2_CH3 | Conflito com Wi-Fi |
| **GPIO 25** | ADC2_CH8 | Conflito com Wi-Fi |
| **GPIO 26** | ADC2_CH9 | Conflito com Wi-Fi |
| **GPIO 27** | ADC2_CH7 | Conflito com Wi-Fi |
 
# Sobre
### do Software
Usaremos o modulo C++ INO usado no desenvolvimento de projetos arduinos
### Do Hardware
Usaremos o ESP-32 de 30 pinos
