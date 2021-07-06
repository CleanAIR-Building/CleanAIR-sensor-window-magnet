#include <Arduino.h>
#include "CleanAIRDevice.h"
#include "Definitions.h"
#include "MagnetSensor.h"

MagnetSensor magnetSensor;

void setup() {
  Serial.begin(BAUDRATE);
  CleanAIR::SetProducer(&magnetSensor);
  CleanAIR::LoadConfiguration(CONFIG_FILE);
  CleanAIR::ConnectToWifi();
  CleanAIR::ConnectToMQTT();
  CleanAIR::InitializeHeartBeat(HEARTBEAT);
}

void loop() {
  CleanAIR::Loop();
}