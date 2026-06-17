#include "api_client.h"

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const int AIRCRAFT_ID = 1;

void pingServer()
{
    HTTPClient http;

    http.begin(
        "http://192.168.110.24:8000/api/ping/"
    );

    int httpCode =
        http.GET();

    if(httpCode > 0)
    {
        Serial.print(
            "HTTP Code: "
        );

        Serial.println(
            httpCode
        );

        Serial.println(
            http.getString()
        );
    }

    http.end();
}

FlightResponse processFlight(
    String uid
)
{
    FlightResponse result;

    result.success = false;
    result.hours = 0;

    HTTPClient http;

    http.begin(
        "http://192.168.110.92:8000/api/process-flight/"
    );

    http.addHeader(
        "Content-Type",
        "application/json"
    );

    String jsonBody =
        "{\"uid\":\"" +
        uid +
        "\",\"aircraft_id\":" +
        String(AIRCRAFT_ID) +
        "}";

    int httpCode =
        http.POST(
            jsonBody
        );

    Serial.print(
        "HTTP Code: "
    );

    Serial.println(
        httpCode
    );

    if(httpCode != 200)
    {
        result.errorMessage =
            "Server Error";

        http.end();

        return result;
    }

    String response =
        http.getString();

    Serial.println(
        response
    );

    JsonDocument doc;

    if(
        deserializeJson(
            doc,
            response
        )
    )
    {
        result.errorMessage =
            "JSON Error";

        http.end();

        return result;
    }

    String status =
        doc["status"];

    if(status == "success")
    {
        result.success = true;

        result.action =
            doc["action"]
            .as<String>();

        result.pilot =
            doc["pilot"]
            .as<String>();

        if(
            doc["hours"]
            .is<float>()
        )
        {
            result.hours =
                doc["hours"];
        }
    }
    else
    {
        result.errorMessage =
            doc["message"]
            .as<String>();
    }

    http.end();

    return result;
}