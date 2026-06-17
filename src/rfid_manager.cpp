#include "rfid_manager.h"

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(
    SS_PIN,
    RST_PIN
);

void initRFID()
{
    Serial.println("RFID INIT START");

    SPI.begin(
        12, // SCK
        13, // MISO
        11, // MOSI
        10  // SS
    );

    rfid.PCD_Init();

    byte version =
        rfid.PCD_ReadRegister(
            MFRC522::VersionReg
        );

    Serial.print("Version: ");
    Serial.println(
        version,
        HEX
    );

    Serial.println("RFID READY");
}

String readUID()
{
    if(
        !rfid.PICC_IsNewCardPresent()
    )
    {
        return "";
    }

    if(
        !rfid.PICC_ReadCardSerial()
    )
    {
        return "";
    }

    String uid = "";

    for(
        byte i = 0;
        i < rfid.uid.size;
        i++
    )
    {
        if(
            rfid.uid.uidByte[i] < 0x10
        )
        {
            uid += "0";
        }

        uid += String(
            rfid.uid.uidByte[i],
            HEX
        );
    }

    uid.toUpperCase();

    rfid.PICC_HaltA();

    rfid.PCD_StopCrypto1();

    return uid;
}

void enrollmentMode()
{
    Serial.println();
    Serial.println(
        "=== ENROLLMENT MODE ==="
    );

    Serial.println(
        "Scan Card..."
    );

    while(true)
    {
        String uid =
            readUID();

        if(uid != "")
        {
            Serial.print(
                "NEW CARD UID: "
            );

            Serial.println(
                uid
            );

            break;
        }

        delay(100);
    }
}