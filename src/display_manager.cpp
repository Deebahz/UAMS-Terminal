#include "display_manager.h"
#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(
    4,
    5,
    18,
    19,
    20,
    21
);

void initDisplay()
{
    lcd.begin(20, 4);

    lcd.clear();

    Serial.println("LCD INITIALIZED");
}

void showBootScreen()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("UAMS");

    lcd.setCursor(0,1);
    lcd.print("Aircraft Flight");

    lcd.setCursor(0,2);
    lcd.print("Management");

    lcd.setCursor(0,3);
    lcd.print("System");

    Serial.println("BOOT SCREEN");
}

void showReadyScreen()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Welcome To");

    lcd.setCursor(0,1);
    lcd.print("5Y-ABC");

    lcd.setCursor(0,2);
    lcd.print("Please Scan");

    lcd.setCursor(0,3);
    lcd.print("Your ID");
}

void showFlightStarted(String pilot)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Pilot Verified");

    lcd.setCursor(0,1);
    lcd.print(pilot);

    lcd.setCursor(0,3);
    lcd.print("Flight Started");
}

void showFlightEnded(float hours)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Flight Ended");

    lcd.setCursor(0,1);
    lcd.print(hours);

    lcd.setCursor(8,1);
    lcd.print("Hours");
}

void showAccessDenied()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("ACCESS DENIED");

    lcd.setCursor(0,2);
    lcd.print("Unknown Pilot");
}

void showGrounded()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("FLIGHT DENIED");

    lcd.setCursor(0,1);
    lcd.print("Aircraft");

    lcd.setCursor(0,2);
    lcd.print("Grounded");
}

void showEnrollmentScreen()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Enrollment Mode");

    lcd.setCursor(0,2);
    lcd.print("Scan New Card");
}

void showCardUID(String uid)
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Card UID:");

    lcd.setCursor(0,1);
    lcd.print(uid);
}
void showWiFiScreen()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Connecting");

    lcd.setCursor(0,1);
    lcd.print("To WiFi...");

    lcd.setCursor(0,3);
    lcd.print("Please Wait");
}