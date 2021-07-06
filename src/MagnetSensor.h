#pragma once
#include "MessageProducer.h"

class MagnetSensor : public CleanAIR::MessageProducer {
    public:
        enum class STATE {OPEN, CLOSED};

        MagnetSensor();
        virtual void Loop() override;
    private:
        int pinToRead;
        boolean initalMessageSent;
        STATE state;
        CleanAIR::MessageJson CreateMessage(STATE newState);
        void StateToString(STATE state, char* outString);
};