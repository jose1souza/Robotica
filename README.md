# Robotica | Arduino & ESP32

Um laboratório de prototipagem: exemplos curtos para aprender entradas, sensores, atuadores, comunicação e conectividade. Os projetos estão separados por plataforma e categoria; cada pasta contém um sketch independente.

## Arduino Uno / Nano

### Fundamentos

| Projeto | Experimento |
| --- | --- |
| [Buzzer](Arduino/Fundamentos/Buzzer/Buzzer.ino) | Acionamento sonoro em intervalos regulares (D9). |
| [LED com chave](Arduino/Fundamentos/LedComChave/LedComChave.ino) | Entrada digital controla um LED (chave D3, LED D2). |
| [Semáforo](Arduino/Fundamentos/Semaforo/Semaforo.ino) | Saída digital com temporização (LED D11). |

### Sensores

| Projeto | Experimento |
| --- | --- |
| [LDR](Arduino/Sensores/Ldr/Ldr.ino) | Mede luminosidade e comanda um LED (sensor A0, LED D10). |
| [Iluminação automática](Arduino/Sensores/Poste/Poste.ino) | Simula um poste controlado pela luminosidade (sensor A0, LED D11). |
| [Potenciômetro](Arduino/Sensores/potenciometro/potenciometro.ino) | Compara a entrada analógica com um limite (A0, saída D2). |
| [Temperatura analógica](Arduino/Sensores/Temperatura/Temperatura.ino) | Lê o sensor em A1 e sinaliza leituras acima de 600 (LED D2). |
| [Alerta de temperatura](Arduino/Sensores/sensorTemperatura/sensorTemperatura.ino) | Calcula a temperatura e sinaliza a partir de 30 °C (sensor A0, saída D2). |
| [Ultrassônico com alerta](Arduino/Sensores/Ultrasonico/Ultrasonico.ino) | HC-SR04 mede distância e aciona LED abaixo de 20 cm (TRIG D7, ECHO D6, LED D13). |

### Atuadores

| Projeto | Experimento |
| --- | --- |
| [LED RGB](Arduino/Atuadores/LedRgb/LedRgb.ino) | Combina canais PWM para alternar cores (D3, D5 e D6). |
| [Servo motor](Arduino/Atuadores/servoMotor/servoMotor.ino) | Controla o ângulo do servo com potenciômetro (A0, servo D2). |

### Interfaces

| Projeto | Experimento |
| --- | --- |
| [Chave no LCD](Arduino/Interfaces/lcd/lcd.ino) | Mostra o estado da chave no display (chave D2, LCD 16×2). |
| [Distância no LCD](Arduino/Interfaces/sensorUltrasonico/sensorUltrasonico.ino) | Exibe a distância do HC-SR04 (TRIG D2, ECHO D3, LCD 16×2). |

## ESP32 DevKit

Os exemplos desta seção são voltados ao ESP32 clássico, como ESP32 DevKit V1. Os pinos e APIs não são necessariamente compatíveis com ESP8266 ou outras variantes ESP32.

| Categoria | Projeto | Experimento |
| --- | --- | --- |
| Fundamentos | [Blink](ESP32/Fundamentos/Blink/Blink.ino) | Pisca um LED externo no GPIO 18. |
| Sensores | [Leitura analógica](ESP32/Sensores/LeituraAnalogica/LeituraAnalogica.ino) | Lê a tensão no ADC do GPIO 34 e envia milivolts pela serial. |
| Sensores | [HC-SR04](ESP32/Sensores/DistanciaHC_SR04/DistanciaHC_SR04.ino) | Mede distância com timeout e mostra o resultado pela serial. |
| Conectividade | [Scanner Wi-Fi](ESP32/Conectividade/ScannerWiFi/ScannerWiFi.ino) | Lista redes próximas e intensidade do sinal; não se conecta a elas. |
| Comunicação | [Scanner I²C](ESP32/Comunicacao/ScannerI2C/ScannerI2C.ino) | Procura dispositivos nos pinos SDA 21 e SCL 22. |

## Executar um projeto

1. Instale a [Arduino IDE](https://www.arduino.cc/en/software).
2. Abra o `.ino` desejado diretamente da pasta do projeto. O nome da pasta corresponde ao nome do sketch.
3. Selecione a placa e a porta. Para ESP32, instale antes o pacote de placas **esp32 by Espressif Systems** no Gerenciador de Placas.
4. Instale **Adafruit_LiquidCrystal** para os projetos com LCD. `Servo.h`, `WiFi.h` e `Wire.h` acompanham os respectivos pacotes de placas.
5. Verifique e carregue o sketch. Abra o Monitor Serial em **9600 baud** para exemplos Arduino ou **115200 baud** para ESP32.

## Ligações e segurança

- Use resistor limitador em cada LED. Para chaves configuradas como `INPUT`, monte um resistor externo de pull-up ou pull-down.
- LDR e potenciômetro devem formar divisores de tensão. Nas entradas ESP32, mantenha o sinal dentro de 0 a 3,3 V: GPIOs não são tolerantes a 5 V.
- O pino ECHO do HC-SR04 pode entregar 5 V. Ao conectar ao ESP32, use divisor resistivo ou conversor de nível lógico.
- GPIO 34 do ESP32 é somente entrada. Os pinos I²C podem variar entre placas; ajuste SDA/SCL se necessário.
- Confira a alimentação exigida pelos módulos e servos. Evite alimentar cargas diretamente pelos GPIOs.

## Organização

```text
Robotica/
├── Arduino/
│   ├── Fundamentos/
│   ├── Sensores/
│   ├── Atuadores/
│   └── Interfaces/
└── ESP32/
    ├── Fundamentos/
    ├── Sensores/
    ├── Conectividade/
    └── Comunicacao/
```

Os valores de referência são pontos de partida; calibração e pinagem podem variar conforme os componentes e a placa usados.