# System Architecture

## Overview

This project is an IoT monitoring and control system built around ESP32.

The ESP32 hosts a local web server, manages user authentication,
collects sensor data, stores local data in LittleFS, and synchronizes
backups with Firebase Realtime Database.

---

## Architecture Diagram

```
                +----------------------+
                |      Web Browser     |
                |  HTML / CSS / JS     |
                +----------+-----------+
                           |
                      HTTP Requests
                           |
                           ▼
                +----------------------+
                |        ESP32         |
                |----------------------|
                | Web Server           |
                | Authentication       |
                | Sensor Manager       |
                | Dashboard API        |
                | LittleFS             |
                +----+-----------+-----+
                     |           |
          Read/Write |           | Backup
                     |           |
                     ▼           ▼
             users.json     Firebase RTDB
                               |
                               ▼
                    Login History
                    Sensor History
                    Device Status
```

---

## Main Components

### ESP32
Responsible for:

- Hosting the web server
- User authentication
- Reading sensors
- Device control
- Local database management
- Firebase synchronization

---

### LittleFS

Stores:

- users.json
- config.json
- logs (optional)

Acts as the local database.

---

### Firebase

Used for:

- Backup users
- Login history
- Sensor history
- Device status
- Cloud synchronization

---

### Dashboard

Provides:

- Live sensor values
- Charts
- Device control
- User management

---

## Authentication Flow

1. User enters username/password.
2. ESP32 hashes the password.
3. Compare with stored hash.
4. If valid:
   - Create session
   - Log login
5. Otherwise:
   - Reject request
   - Save failed login

---

## Data Flow

Sensor
   ↓
ESP32
   ↓
LittleFS
   ↓
Dashboard

        AND

ESP32
   ↓
Firebase Backup

---

## Future Architecture

- Multiple ESP32 devices
- OTA Updates
- MQTT Support
- Mobile App
- AI Analytics
