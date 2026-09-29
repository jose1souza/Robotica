#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  Serial.println("Buscando redes Wi-Fi...");
  const int networkCount = WiFi.scanNetworks();

  if (networkCount == 0) {
    Serial.println("Nenhuma rede encontrada.");
  } else if (networkCount < 0) {
    Serial.println("Falha ao buscar redes.");
  } else {
    for (int network = 0; network < networkCount; network++) {
      Serial.print(WiFi.SSID(network));
      Serial.print(" | sinal: ");
      Serial.print(WiFi.RSSI(network));
      Serial.println(" dBm");
    }
  }

  WiFi.scanDelete();
  delay(5000);
}