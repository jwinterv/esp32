

#include "FS.h"
#include <LittleFS.h> //Para armazenar os arquivos de imagem na memória Flash

#include <WiFi.h> //Para criar o ponto de acesso
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <WebServer.h> //Para armazenar o app web

#include <Arduino_JSON.h>

#include <Preferences.h> //Para o NVS(Non-Volatile Storage), que garante que o estado dos LEDs seja mantido entre reinicializações

#include "interface.h" //Arquivo de acesso as pàginas html

#define FORMAT_LITTLEFS_IF_FAILED true

#define LD1 23
#define LD2 22
#define LD3 21
#define LD4 19
#define LD5 18

const char *ssid = "IEEE";
const char *pass = "12345678";

WebServer server(80);

// Objeto para salvar o estado no NVS
Preferences prefs;
bool relayState[] = {false, false, false, false, false};


// Funções para enviar as páginas
void SendLogin() {
  server.send(200, "text/html", PAGE_LOGIN);
}

void SendMain() {
  server.send(200, "text/html", PAGE_MAIN);
}

void SendLight() {
  server.send(200, "text/html", PAGE_LIGHT);
}

void SendLock() {
  server.send(200, "text/html", PAGE_LOCK);
}

void SendDisp() {
  server.send(200, "text/html", PAGE_DISP);
}

// Função para enviar as imagens via LittleFS
void SendImages() {
  server.on("/images/header--image--1.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/header--image--1.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/header--image--2.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/header--image--2.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/logo--ramo.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/logo--ramo.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/plus.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/plus.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/return.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/return.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/lampada.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/lampada.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/lampadaB.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/lampadaB.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/televisao.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/televisao.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/televisaoB.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/televisaoB.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/cadeado.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/cadeado.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });

  server.on("/images/cadeadoB.png", HTTP_GET, [](){
    File file = LittleFS.open("/images/cadeadoB.png", "r");
    if (!file) {
      server.send(404, "text/plain", "Imagem não encontrada");
      return;
    }
    server.streamFile(file, "image/png");
    file.close();
  });  
}

// Controle dos reles
void relayControl () {
   server.on("/H1", []() {   
    digitalWrite(LD1, LOW);
    prefs.putBool("led1", true);
  });
  server.on("/L1", []() {   
    digitalWrite(LD1, HIGH);
    prefs.putBool("led1", false);
  });

  server.on("/H2", []() {   
    digitalWrite(LD2, LOW);
    prefs.putBool("led2", true);
  });
  server.on("/L2", []() {    
    digitalWrite(LD2, HIGH);
    prefs.putBool("led2", false);
  });

  server.on("/H3", []() {    
    digitalWrite(LD3, LOW);
    prefs.putBool("led3", true);
  });
  server.on("/L3", []() {   
    digitalWrite(LD3, HIGH);
    prefs.putBool("led3", false);
  });

  server.on("/H4", []() {    
    digitalWrite(LD4, LOW);
    prefs.putBool("led4", true);
  });
  server.on("/L4", []() {   
    digitalWrite(LD4, HIGH);
    prefs.putBool("led4", false);
  });
  server.on("/H5", []() {    
    digitalWrite(LD5, LOW);
    prefs.putBool("led5", true);
  });
  server.on("/L5", []() {   
    digitalWrite(LD5, HIGH);
    prefs.putBool("led5", false);
  });
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  // Configuração dos LEDs
  pinMode(LD1, OUTPUT);
  pinMode(LD2, OUTPUT);
  pinMode(LD3, OUTPUT);
  pinMode(LD4, OUTPUT);
  pinMode(LD5, OUTPUT);

  // Carregar o estado dos LEDs
  digitalWrite(LD1, HIGH);
  digitalWrite(LD2, HIGH);
  digitalWrite(LD3, HIGH);
  digitalWrite(LD4, HIGH);
  digitalWrite(LD5, HIGH);
  
  relayState[0] = prefs.getBool("led1", true);
  relayState[1] = prefs.getBool("led2", true);
  relayState[2] = prefs.getBool("led3", true);
  relayState[3] = prefs.getBool("led4", true);
  relayState[4] = prefs.getBool("led5", true);
    
  delay(10);

  // Inicialização do Acess Point
  WiFi.softAP(ssid, pass);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  // Inicialização do LittleFS
  if (!LittleFS.begin()) {
    Serial.println("Falha ao montar o sistema de arquivos LITTLEFS");
    return;
  }

  // Inicializando o NVS
  prefs.begin("relayState", false);

  // Envio das páginas
  server.on("/", SendLogin);
  server.on("/login.html", SendLogin);
  server.on("/main.html", SendMain);
  server.on("/light.html", SendLight);
  server.on("/lock.html", SendLock);
  server.on("/disp.html", SendDisp);

  relayControl();

  // Envio das imagens
  SendImages();

  // Inicialização do servidor
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  
}
