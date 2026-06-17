#include <Arduino.h>

#include "display_manager.h"
#include "wifi_manager.h"
#include "rfid_manager.h"
#include "api_client.h"
#include "buzzer_manager.h"

void setup()
{
    Serial.begin(115200);

    delay(2000);

    initDisplay();

    initBuzzer();

    showBootScreen();

    startupTone();

    delay(3000);

    showWiFiScreen();

    connectWiFi();

    pingServer();

    initRFID();

    showReadyScreen();
}

void loop()
{
    String uid =
        readUID();

    if(uid != "")
    {
        Serial.print(
            "Card UID: "
        );

        Serial.println(
            uid
        );

        FlightResponse result =
            processFlight(
                uid
            );

        if(result.success)
        {
            if(
                result.action ==
                "CHECK_IN"
            )
            {
                Serial.println(
                    "Flight Started"
                );

                showFlightStarted(
                    result.pilot
                );

                successTone();
            }

            else if(
                result.action ==
                "CHECK_OUT"
            )
            {
                Serial.println(
                    "Flight Ended"
                );

                showFlightEnded(
                    result.hours
                );

                successTone();
            }
        }
        else
        {
            Serial.println(
                result.errorMessage
            );

            if(
                result.errorMessage ==
                "Aircraft grounded"
            )
            {
                showGrounded();
            }
            else
            {
                showAccessDenied();
            }

            errorTone();
        }

        delay(3000);

        showReadyScreen();
    }

    delay(100);
}