#ifndef API_CLIENT_H
#define API_CLIENT_H

#include <Arduino.h>

struct FlightResponse
{
    bool success;

    String action;

    String pilot;

    float hours;

    String errorMessage;
};

FlightResponse processFlight(
    String uid
);

void pingServer();

#endif