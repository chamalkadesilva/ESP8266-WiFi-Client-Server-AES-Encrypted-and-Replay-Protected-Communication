#include <AESLib.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "SSIDNAME";
const char* password = "PASSWORD";
const char* serverName = "http://192.168.137.111/api"; //replace with your server address

AESLib aesLib;

uint8_t key[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; // 128 bit key
uint8_t iv[N_BLOCK] = {0};  // initialization vector
char data[] = "MESSAGE";
uint8_t encryptedData[32]; // Stores the encrypted data

uint32_t sequenceNumber = 0; // Added sequence number

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  aesLib.gen_iv(iv);
}

void loop() {
  // Add sequence number to the message
  String message = String(sequenceNumber) + "," + data;
  
  int encryptedLength = aesLib.encrypt((uint8_t*)message.c_str(), message.length(), encryptedData, key, sizeof(key), iv);
  String encryptedString = "";
  for (int i = 0; i < encryptedLength; i++) {
    encryptedString += String(encryptedData[i]);
    if(i < encryptedLength - 1) {
      encryptedString += ",";  // add comma as separator
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST("data=" + encryptedString);
    http.end();
  }
  sequenceNumber++; // Increment the sequence number
  delay(5000);
}