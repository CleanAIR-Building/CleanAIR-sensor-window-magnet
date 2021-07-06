#include "MagnetSensor.h"
#include "CleanAIRDevice.h"

MagnetSensor::MagnetSensor() {
    Serial.println("Sarting sensor setup now...");
    pinToRead = D1;
    initalMessageSent = false;
    pinMode(pinToRead, INPUT);
    Serial.println("Magnetic sensor successfully set up!");
}

void MagnetSensor::Loop() {
    MagnetSensor::STATE newState;
    if (digitalRead(pinToRead) == LOW) { 
        newState = MagnetSensor::STATE::OPEN;
    } 
    else { 
        newState = MagnetSensor::STATE::CLOSED;
    }
    if (!initalMessageSent) {
        char stateString[8];
        StateToString(newState, stateString);
        Serial.printf("The initial state of the window is %s\n", stateString);
        state = newState;
        Publish(CleanAIR::GetConfig().mqttTopic.c_str(), CreateMessage(newState), true);
        initalMessageSent = true;
    } else if (state != newState) {
        char stateString[8];
        StateToString(newState, stateString);
        Serial.printf("State has changed, window is now %s\n", stateString);
        state = newState;
        Publish(CleanAIR::GetConfig().mqttTopic.c_str(), CreateMessage(newState), true);
    }
}

CleanAIR::MessageJson MagnetSensor::CreateMessage(const MagnetSensor::STATE newState){
    CleanAIR::MessageJson message;
    message["sensor"] = CleanAIR::GetConfig().mqttClientName.c_str();
    char stateString[8];
    StateToString(newState, stateString);
    message["window_state"] = stateString;
    return message;
}

void MagnetSensor::StateToString(MagnetSensor::STATE state, char* outString){
    strcpy(outString, (state == MagnetSensor::STATE::OPEN) ? "open" : "closed");
}