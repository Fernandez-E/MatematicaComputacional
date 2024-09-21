#include <SD.h>

const int chipSelect = 10;

File myFile;

void setup() {
  Serial.begin(9600);
  Serial.println("Inicializando SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Falha na detecção do cartão SD");
  }
  Serial.println("Cartão lido.");
}

void loop() {
  myFile = SD.open("pratica.txt", FILE_WRITE);

  //
  //
  // INSERIR CODIGO DE LEITURA DE DADOS AQUI
  //
  //

  if (myFile) {
    // myFile.println() - Função de escrita no arquivo .txt
    // CODIGO DE ESCRITA DE DADOS NO ARQUIVO AQUI
    myFile.close();
  } else {
    Serial.println("Erro ao abrir o arquivo");
  }
}