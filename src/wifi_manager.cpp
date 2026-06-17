#include "wifi_manager.h"
#include "buzzer_manager.h"

#include <WiFi.h>

const char* WIFI_SSID =
"GGate26";

const char* WIFI_PASSWORD =
"DDaudi@123";

void connectWiFi()
{
    Serial.println("Connecting to WiFi...");

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );

    int attempts = 0;

    while(
        WiFi.status() != WL_CONNECTED
    )
    {
        delay(500);

        Serial.print(".");

        attempts++;

        if(attempts > 40)
        {
            Serial.println();
            Serial.println("WiFi Failed");

            return;
        }
    }

    Serial.println();
    Serial.println("WiFi Connected");

    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    Serial.println("WiFi Connected");
    successTone();
}
