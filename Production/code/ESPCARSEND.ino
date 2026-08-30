#include <esp_now.h>
#include <WiFi.h>
#define pot_pin 23

typedef struct struct_message {
    int pot_value;
  int xValue;
  int yValue;
} struct_message;

struct_message dataToSend;

uint8_t receiverAddress[] = {0x00, 0x4B, 0x12, 0xE7, 0xA8}; // Replace with your receiver MAC, dont use mine

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed!");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  dataToSend.xValue = analogRead(34); // Joystick X pin
  dataToSend.yValue = analogRead(35); // Joystick Y pin
  dataToSend.pot_value = analogRead(pot_pin); // Send the pot value

  esp_now_send(receiverAddress, (uint8_t *) &dataToSend, sizeof(dataToSend));
  Serial.print("Sent X: ");
  Serial.print(dataToSend.xValue);
  Serial.print(" | Y: ");
  Serial.print(dataToSend.yValue);
  Serial.print(" | Pot: ");
  Serial.println(dataToSend.pot_value);
  delay(100);
}
