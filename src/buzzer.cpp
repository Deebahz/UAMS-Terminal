#include "buzzer_manager.h"

#include <Arduino.h>

#define BUZZER_PIN 7

void initBuzzer()
{
    pinMode(
        BUZZER_PIN,
        OUTPUT
    );

    digitalWrite(
        BUZZER_PIN,
        LOW
    );
}

void successTone()
{
    digitalWrite(
        BUZZER_PIN,
        HIGH
    );

    delay(200);

    digitalWrite(
        BUZZER_PIN,
        LOW
    );
}

void errorTone()
{
    digitalWrite(
        BUZZER_PIN,
        HIGH
    );

    delay(1000);

    digitalWrite(
        BUZZER_PIN,
        LOW
    );
}

void startupTone()
{
    successTone();

    delay(150);

    successTone();
}