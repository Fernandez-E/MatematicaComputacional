#include <DHT.h>
#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "SSID_REDE";
const char* password = "SENHA_REDE";

WiFiClient  client;

unsigned long myChannelNumber = CHANNELID;
const char * myWriteAPIKey = "APIKEY";

unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

void setup() {
  Serial.begin();

  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);
}

void loop() {
  delay(5000);
  if ((millis() - lastTime) > timerDelay) {
    
  // CONEXAO WIFI
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }

    //
    //
    // INSERIR CODIGOS DE LEITURA DE SENSORES AQUI
    //
    //

    ThingSpeak.setField(NUMERO_CAMPO_TS, VARIAVEL); // REPLICAR DE ACORDO COM A NECESSIDADE

    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    lastTime = millis();

    delay(15000); //INTERVALO ENTRE ENVIOS DE DADOS PARA O THINGSPEAK
  }
}
