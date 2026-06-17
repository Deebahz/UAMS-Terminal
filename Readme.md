# UAMS Terminal (University Aviation Management System)

## Overview

The UAMS Terminal is an IoT-based flight monitoring system built using an ESP32-S3, RFID authentication, LCD display, buzzer notifications, and a Django backend.

The system allows pilots to authenticate using RFID cards before operating an aircraft. Flight sessions are automatically recorded, flight durations are calculated, and pilot and aircraft hours are updated in real time.

---

## Features

* RFID-based pilot authentication
* Flight check-in and check-out
* Real-time communication with Django backend
* MySQL database integration
* Automatic flight hour calculation
* Aircraft utilization tracking
* Aircraft grounding enforcement
* LCD user interface
* Buzzer feedback system
* WiFi-enabled ESP32-S3 terminal

---

## System Architecture

RFID Card
↓
RC522 RFID Reader
↓
ESP32-S3 Terminal
↓
WiFi Network
↓
Django REST Endpoint
↓
MySQL Database
↓
Flight Logs / Pilot Records / Aircraft Records

---

## Hardware Components

### Microcontroller

* ESP32-S3 DevKitM-1

### RFID Reader

* MFRC522 RFID Module

### Display

* 20x4 LCD Display

### Audio Feedback

* Active Buzzer

---

## Wiring Configuration

### RC522 RFID Reader

| RC522    | ESP32-S3      |
| -------- | ------------- |
| SDA (SS) | GPIO 10       |
| SCK      | GPIO 12       |
| MOSI     | GPIO 11       |
| MISO     | GPIO 13       |
| RST      | GPIO 9        |
| 3.3V     | 3V3           |
| GND      | GND           |
| IRQ      | Not Connected |

### LCD Display

| LCD Pin | ESP32-S3 |
| ------- | -------- |
| RS      | GPIO 4   |
| E       | GPIO 5   |
| D4      | GPIO 6   |
| D5      | GPIO 7   |
| D6      | GPIO 15  |
| D7      | GPIO 16  |
| VSS     | GND      |
| VDD     | 5V       |
| RW      | GND      |

### Buzzer

| Buzzer | ESP32-S3 |
| ------ | -------- |
| +      | GPIO 17  |
| -      | GND      |

---

## Startup Sequence

1. Boot Screen
2. WiFi Connection Screen
3. Backend API Ping
4. Ready Screen
5. Await RFID Scan

---

## Flight Workflow

### Flight Start

1. Pilot scans RFID card
2. UID sent to Django API
3. Pilot verified
4. Flight session created
5. LCD displays Flight Started

### Flight End

1. Pilot scans RFID card again
2. Active flight located
3. Flight duration calculated
4. Pilot hours updated
5. Aircraft hours updated
6. LCD displays Flight Ended

---

## Technology Stack

### Embedded System

* ESP32-S3
* PlatformIO
* Arduino Framework

### Backend

* Django
* MySQL

### Communication

* WiFi
* HTTP REST API
* JSON

---

## Future Improvements

* HTTPS communication
* OTA firmware updates
* Admin enrollment mode
* Aircraft selection menu
* OLED dashboard
* Cloud deployment
* Flight analytics dashboard


## Installation and Setup

### Prerequisites

Install the following software before running the project:

#### 1. Git

Download:

https://git-scm.com/downloads

Verify installation:

```bash
git --version
```

---

#### 2. Visual Studio Code

Download:

https://code.visualstudio.com/

Recommended Extensions:

* PlatformIO IDE
* Python
* C/C++
* GitHub Pull Requests and Issues

---

#### 3. Python 3.12+

Download:

https://www.python.org/downloads/

Verify installation:

```bash
python --version
```

---

#### 4. MySQL Server

Download:

https://dev.mysql.com/downloads/mysql/

Create a database:

```sql
CREATE DATABASE uams_db;
```

---

#### 5. PlatformIO

Install from the VS Code Extensions Marketplace.

Verify installation:

```bash
pio --version
```

---

## Clone Repository

```bash
git clone https://github.com/YOUR_USERNAME/UAMS-Terminal.git
```

```bash
cd UAMS-Terminal
```

---

## Django Backend Setup

Navigate to backend directory:

```bash
cd FlightHoursSystem
```

Create virtual environment:

```bash
python -m venv venv
```

Activate environment:

### Windows

```bash
venv\Scripts\activate
```

### Linux

```bash
source venv/bin/activate
```

Install dependencies:

```bash
pip install -r requirements.txt
```

Apply migrations:

```bash
python manage.py migrate
```

Create administrator account:

```bash
python manage.py createsuperuser
```

Run development server:

```bash
python manage.py runserver 0.0.0.0:8000
```

Open:

```text
http://127.0.0.1:8000/admin
```

---

## ESP32 Firmware Setup

Open the project in VS Code.

PlatformIO will automatically install:

* Arduino Framework
* ESP32 Toolchain
* Required libraries

Install libraries:

```ini
MFRC522
ArduinoJson
LiquidCrystal
WiFi
HTTPClient
SPI
```

---

## Configure WiFi

Edit:

```cpp
src/wifi_manager.cpp
```

Update:

```cpp
const char* WIFI_SSID = "YOUR_WIFI";
const char* WIFI_PASSWORD = "YOUR_PASSWORD";
```

---

## Configure Backend Address

Edit:

```cpp
src/api_client.cpp
```

Replace:

```cpp
http://YOUR_IP_ADDRESS:8000
```

with your local machine IP address.

Example:

```cpp
http://192.168.110.24:8000
```

Find your IP:

### Windows

```bash
ipconfig
```

### Linux

```bash
ip addr
```

---

## Upload Firmware

Connect ESP32-S3.

Upload:

```bash
pio run --target upload
```

Open Serial Monitor:

```bash
pio device monitor
```

---

## Test Procedure

1. Start Django backend
2. Power ESP32 terminal
3. Verify WiFi connection
4. Verify API ping
5. Scan registered RFID card
6. Confirm Flight Check-In
7. Scan again to Check-Out
8. Verify flight logs in Django Admin

---

## Default Hardware Connections

### RC522 RFID

SDA → GPIO10

SCK → GPIO12

MOSI → GPIO11

MISO → GPIO13

RST → GPIO9

3.3V → 3V3

GND → GND

---

### LCD

RS → GPIO4

E → GPIO5

D4 → GPIO6

D5 → GPIO7

D6 → GPIO15

D7 → GPIO16

---

### Buzzer

* → GPIO17

- → GND

---

## Troubleshooting

### RFID Reader Not Detected

Expected:

```text
Version: 92
```

If:

```text
Version: 0
```

or

```text
Version: FF
```

Check wiring and power connections.

---

### ESP32 Cannot Reach Backend

Verify:

```bash
python manage.py runserver 0.0.0.0:8000
```

and ensure the computer firewall allows inbound connections.

---

### WiFi Connection Failure

Ensure the ESP32 is connected to a 2.4GHz network.
