#include <sqlite3.h>
//this for store  Database in ESP32 FLash with Code
#include <SPIFFS.h>
//this for hash password
#include  "mbedtls/sha256.h"
sqlite3 *db;

void setup() {
   
    Serial.begin(115200);
    Serial.print("Setup Core = ");
    Serial.println(xPortGetCoreID());
  // تشغيل SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS Failed");
    return;
  }

  // فتح قاعدة البيانات
  if (sqlite3_open("/spiffs/users.db", &db) == SQLITE_OK) {
    Serial.println("Database Opened");

    char *errMsg = NULL;

    sqlite3_exec(
      db,
      "CREATE TABLE IF NOT EXISTS users("
      "id INTEGER PRIMARY KEY,"
      "username TEXT,"
      "password TEXT);",
      NULL,
      NULL,
      &errMsg
    );

    if (errMsg == NULL)
      Serial.println("Table Created");
    else
      Serial.println(errMsg);

  } else {
    Serial.println("Open Database Failed");
  }
}

void loop() {

    Serial.print("Running on Core ");
    Serial.println(xPortGetCoreID());
    delay(2000);

}