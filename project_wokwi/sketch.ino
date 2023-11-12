//EXEMPLO COM A TAGO.IO
#include <WiFi.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

// Configurações de WiFi
const char *SSID = "Wokwi-GUEST";
const char *PASSWORD = "";  // Substitua pelo sua senha

// Configurações de MQTT
const char *BROKER_MQTT = "mqtt.tago.io";
const int BROKER_PORT = 1883;
const char *ID_MQTT = "natan";
const char *USERNAME = "";  // Deixe em branco se não for usar um nome de usuário MQTT
const char *PASSWORD_MQTT = "46f8f586-9898-40a5-a8b2-375d2cdbcb05";  // Adicione a senha aqui
const char *TOPIC_SEND_VARIABLE = "tago/data/post";  // Tópico para enviar as variáveis

// Configurações de Hardware
#define PUBLISH_DELAY 1000    // delay
#define pirentrada 2      // pir D is connected to D15
#define pirsaida 4       // pir D is connected to D15


// Variáveis globais
WiFiClient espClient;
PubSubClient MQTT(espClient);
unsigned long publishUpdate = 0;
const int TAMANHO = 200;
unsigned int value1, value2 = 0;  // to read pin status
unsigned int count = 1;           //contador;

// Protótipos de funções
void initWiFi();
void initMQTT();
void reconnectMQTT();
void reconnectWiFi();
void checkWiFIAndMQTT();

void initWiFi() {
  Serial.print("Conectando com a rede: ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Conectado com sucesso: ");
  Serial.println(SSID);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void initMQTT() {
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
}

void reconnectMQTT() {
  while (!MQTT.connected()) {
    Serial.print("Tentando conectar com o Broker MQTT: ");
    Serial.println(BROKER_MQTT);

    if (MQTT.connect(ID_MQTT, USERNAME, PASSWORD_MQTT)) {
      Serial.println("Conectado ao broker MQTT!");
    } else {
      Serial.println("Falha na conexão com MQTT. Tentando novamente em 2 segundos.");
      delay(2000);
    }
  }
}

void checkWiFIAndMQTT() {
  if (WiFi.status() != WL_CONNECTED) reconnectWiFi();
  if (!MQTT.connected()) reconnectMQTT();
}

void reconnectWiFi(void)
{
  if (WiFi.status() == WL_CONNECTED)
    return;

  // Conecta na rede WI-FI
  WiFi.begin(SSID, PASSWORD); 

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Wifi conectado com sucesso");
  Serial.print(SSID);
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

void countPeople(int count){
  if (count <= 10){
    Serial.print("Onibus vazio: ");
    Serial.print(count);
    Serial.println(" pessoas.");
  } else if (count <= 20){
    Serial.print("Onibus enchendo: ");
    Serial.print(count);
    Serial.println(" pessoas.");
  } else {
    Serial.print("Onibus lotado: ");
    Serial.print(count);
    Serial.println(" pessoas.");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(pirentrada, INPUT);     // PIR sensor as input
  pinMode(pirsaida, INPUT);     // PIR sensor as input
  initWiFi();
  initMQTT();
}

void loop() {
  checkWiFIAndMQTT();
  MQTT.loop();

  value1 = digitalRead(pirentrada);
  value2 = digitalRead(pirsaida);
  if (value1 == HIGH) {
    countPeople(count);
    count++; // incrementar a variável "count"
    delay(1000); // aguardar um pouco antes de aceitar outra leitura
  } 
  if (value2 == HIGH){
    countPeople(count);
    if (count <= 0){
      count = 0;
    }else{
      count--; // incrementar a variável "count"
    }
    delay(1000);
  }

  if ((millis() - publishUpdate) >= PUBLISH_DELAY) {
    publishUpdate = millis();
    if (!isnan(count)) {
      // Enviar umidade
      StaticJsonDocument<TAMANHO> doc_pessoas;
      doc_pessoas["variable"] = "pessoas";
      //doc_pessoas["unit"] = " pessoas";
      doc_pessoas["value"] = count;

      char buffer_pessoas[TAMANHO];
      serializeJson(doc_pessoas, buffer_pessoas);
      MQTT.publish(TOPIC_SEND_VARIABLE, buffer_pessoas);
      Serial.println(buffer_pessoas);

    }
  }
}

