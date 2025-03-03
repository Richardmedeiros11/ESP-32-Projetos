const int OPCAO1 = 1;
const int OPCAO2 = 2;
const int OPCAO3 = 3;
const int OPCAO4 = 4;

const byte poten = 34;
const byte ok = 35;
const byte cancel = 25;

void setup() {
  pinMode(ok, INPUT);
  pinMode(cancel, INPUT);
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  int opcaoUsed = opcao(analogRead(poten));
  selectedCancel(ok, cancel, opcaoUsed);
}
int opcao(int potencia) {
  // O Range de Potencia varia de 0 - 4095
  if(potencia >= 0 && potencia < 1023) {
    return OPCAO1;
  } else if (potencia > 1023 && potencia < 2046) {
    return OPCAO2;
  } else if (potencia > 2046 && potencia < 3069) {
    return OPCAO3;
  } else if (potencia >= 3069) {
    return OPCAO4;
  }
}
void selectedCancel(byte ok, byte cancel, int used) {
  if(digitalRead(ok) == HIGH) {
    if(used == OPCAO1) {
      Serial.println("Opção 1");
      delay(500);
    } else if (used == OPCAO2) {
      Serial.println("Opção 2");
      delay(500);
    } else if (used == OPCAO3) {
      Serial.println("Opção 3");
      delay(500);
    } else if (used == OPCAO4) {
      Serial.println("Opção 4");
      delay(500);
    }    
  } else if (digitalRead(cancel) == HIGH) {
    Serial.println("CANCEL!");
    delay(500);
  }
}