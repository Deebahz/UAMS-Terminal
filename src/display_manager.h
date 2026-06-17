#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Arduino.h>

void initDisplay();

void showBootScreen();

void showReadyScreen();

void showFlightStarted(
    String pilot
);

void showFlightEnded(
    float hours
);

void showAccessDenied();

void showGrounded();

void showEnrollmentScreen();

void showCardUID(
    String uid
);

void showWiFiScreen();

#endif