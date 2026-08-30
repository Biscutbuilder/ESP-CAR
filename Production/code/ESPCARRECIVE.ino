#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>

Servo servo1;
Servo servo2;
Servo ESC;

int servo1Pin = 18;  // Adjust as needed
int servo2Pin = 19;
int Speed;

typedef struct struct_message {
  int xValue;
  int yValue;
  int pot_value;
} struct_message;

struct_message incomingData;

void onDataReceive(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  memcpy(&incomingData, data, sizeof(incomingData));

  Serial.print("X: ");
  Serial.print(incomingData.xValue);
  Serial.print(" | Y: ");
  Serial.println(incomingData.yValue);
  Serial.print("Speed: ");
  Serial.println(incomingData.pot_value);

  // Map joystick to servo angle
  int angleX = map(incomingData.xValue, 0, 4095, 0, 180);
  ESC.writeMicroseconds(Speed);
  ESC.write(Speed);
  //int angleY = map(incomingData.yValue, 0, 4095, 0, 180);

  servo1.write(angleX);
  //use this if youre using another servo, servo2.write(angleY);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  servo1.attach(servo1Pin);
  ESC.attach(21,1000,2000);

  // use this if you are going to use another servo servo2.attach(servo2Pin);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed!");
    return;
  }

  esp_now_register_recv_cb(onDataReceive);
}

void loop() {
  // Nothing to do here, also why did you scroll so far down?
}
