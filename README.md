# Tipo de ESP-32
ESP-32 de 38 pinos
# Pinos 
![image](https://github.com/user-attachments/assets/e9367378-8811-4d7b-8707-c98237623c6e)
 - Pinos GPIO (General Purpose Input/Output): ESP32 são pinos de propósito geral que podem ser configurados como entrada ou saída digital, além de outras funções especiais, como PWM, I2C, SPI, UART, ADC, DAC, entre outras.

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

 - Pinos ADC (Analog-to-Digital Converter): ESP32 são usados para converter sinais analógicos em valores digitais, permitindo que o microcontrolador leia sensores analógicos, como potenciômetros, sensores de temperatura, entre outros. A resolução do ADC pode ser configurada até 12 bits, o que significa que o valor lido varia de 0 a 4095 (para tensões entre 0V e 3.3V).

###### **ADC1 (Recomendado para Uso Geral)**
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

###### **ADC2 (Pode ter conflito com Wi-Fi)**
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

 - Pinos TOUCH: O ESP32 de 38 pinos possui 10 pinos touch capacitivos, que podem ser usados para detectar variações de capacitância ao tocar com o dedo ou aproximar um objeto condutivo. Esses pinos são úteis para criar botões sensíveis ao toque, sensores de proximidade ou detecção de líquidos.

| **GPIO** | **Canal Touch (constante do pino)** | **Observações** |
|---------|----------------|----------------|
| **GPIO 4**  | T0  | Pode ser usado livremente |
| **GPIO 0**  | T1  | ⚠️ Boot falha se estiver em LOW |
| **GPIO 2**  | T2  | ⚠️ Necessário estar em LOW para boot correto |
| **GPIO 15** | T3  | Pode ser usado |
| **GPIO 13** | T4  | Pode ser usado |
| **GPIO 12** | T5  | ⚠️ Boot falha se estiver em HIGH |
| **GPIO 14** | T6  | Pode ser usado |
| **GPIO 27** | T7  | Pode ser usado |
| **GPIO 33** | T8  | Apenas entrada (não pode ser saída digital) |
| **GPIO 32** | T9  | Apenas entrada (não pode ser saída digital) |

Para usar esses pinos para a função TOUCH, temos que usar elas no codico com a constante do pino (não é necessario usar o pinMode), para indentificar o input basta usar a função `touchRead(PINO)`, exemplo:
```ino
const byte TOUCH_PIN = T0  // GPIO 4

void setup() {
  Serial.begin(115200);
}

void loop() {
  int touchValue = touchRead(TOUCH_PIN);  // Lê o valor do sensor
  Serial.println(touchValue);  // Exibe o valor no monitor serial
  delay(200);
}
```
 - Pinos DAC: O ESP32 possui dois conversores digital-analógico (DAC) embutidos, que permitem gerar tensões analógicas variáveis diretamente nos pinos. Isso é útil para geração de sinais de áudio, controle de brilho em LEDs, acionamento de motores e outras aplicações analógicas.

| **GPIO** | **Canal DAC** | **Faixa de Saída** | **Observações** |
|---------|---------------|--------------------|----------------|
| **GPIO 25** | DAC1 | 0V - 3.3V | Pode ser usado livremente |
| **GPIO 26** | DAC2 | 0V - 3.3V | Pode ser usado livremente |

Para aplicar a faixa de tensão no pino, temos de usar a função `dacWrite(pino, tensão)`, aonde a tensão em 3.3V varia de 0 a 255
```ino
#define DAC_PIN 25
void setup() {
 Serial.begin(9600);
}
void loop() {
 for(int i = 0; i <= 255; i++){
  Serial.println(i);
  dacWrite(DAC_PIN, i);
  delay(10); 
 }
}
```
aonde vai sair uma tensão de aproximadamente
 - 0 → 0V
 - 128 → 1.65V
 - 255 → 3.3V
