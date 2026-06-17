#ifndef RFID_MANAGER_H
#define RFID_MANAGER_H

#include <Arduino.h>

void initRFID();

String readUID();

void enrollmentMode();

#endif