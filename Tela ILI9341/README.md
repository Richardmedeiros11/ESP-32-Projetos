# Tela ILI 9341
### Pinagem (segundo o codigo exemplo):
 - VCC: Ligar ao 5V
 - GND: Ligar ao GND
 - CS: Pino Seletor de chip, ligar ao pino 5
 - RST: Pino RESET*, ligar ao pino 4
 - D/C: Pino de dados/comando, ligar ao pino 2
 - MOSI: Dados SPI (MCU → LCD), pino do tipo SPI, ligar ao pino 23
 - SCK: Pino Clock, ligar ao pino 18
 - LED: Luz de fundo com LED, Não usaremos
 - MISO: Dados SPI (LCD → MCU)‡, Ligar ao pino 19

* Os pinos RST e luz de fundo (LED) não estão disponíveis na simulação.
† Você pode conectar o CS e D/C a qualquer pino digital do Arduino. Os números dos pinos aqui são apenas um exemplo.
‡ Você pode deixar o MISO desconectado, a menos que precise ler os dados do LCD.
### Software 
Nos usaremos a biblioteca `Adafruit_ILI9341.h`
Temos de definir um objeto de controle do tipo `Adafruit_ILI9341`, que recebe os pinos aonde foi conectado o CS(5) e o D/C(2), tambem vamos usar as bibliotecas `SPI.h` e `Adafruit_GFX.h`, para definir a cor da letra e etc.
```ino
#include "Adafruit_ILI9341.h"
#define "Adafruit_GFX.h"
#define "SPI.h"

Adafruit_ILI9341 display = Adafruit_ILI9341(5, 2);
``` 
Dentro deste objeto temos varias funções 
 - `begin()`: Estabelece a conexão com a tela, unica instrução obrigatoria
 - ``setCursor(coluna, linha)``: Define apartir de onde sera escrito o texto
 - `setTextColor(constante de cor)`: Define a cor do texto, aonde a constante pode ser por exemplo ILI9341_RED para verde
 - `setTextSize(size)`: Define o tamanho do texto (lembre-se que uma linha pode sobrepor a outra, então use o setCursor com sabedoria)
 - ``println("Texto")``: Define o texto a ser exibido com as configurações anteriores
Veja um exemplo:
```
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 2
#define TFT_CS 5

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  tft.begin();

  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(3);
  tft.println("Hello Word");

  tft.setCursor(0, 22);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);
  tft.println("Eu posso ter cores?");
}

void loop() { }
```
Para acada 1 de tamaho é nescessario +- 8 pixels de espaço para evitar a sobreposição