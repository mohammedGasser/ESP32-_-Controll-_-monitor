#include <sqlite3.h>
///make comment for all Libraries ///
#include <SPIFFS.h>
#include "mbedtls/sha256.h"

sqlite3 *db;

TaskHandle_t PrintTask;
TaskHandle_t DatabaseTask;

String hashPassword(const String &password)
{
    unsigned char hash[32];
    char output[65];

    mbedtls_sha256_context ctx;

    mbedtls_sha256_init(&ctx);

    mbedtls_sha256_starts(&ctx, 0);

    mbedtls_sha256_update(
        &ctx,
        (const unsigned char *)password.c_str(),
        password.length());

    mbedtls_sha256_finish(&ctx, hash);

    mbedtls_sha256_free(&ctx);

    for (int i = 0; i < 32; i++)
        sprintf(output + (i * 2), "%02x", hash[i]);

    output[64] = '\0';

    return String(output);
}
//======================
// Task 1
//======================
void PrintCoreTask(void *pvParameters)
{
    while (true)
    {
        Serial.print("Print Task -> Core ");
        Serial.println(xPortGetCoreID());

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

//======================
// Task 2
//======================
void DatabaseTaskCode(void *pvParameters)
{
    while (true)
    {
        Serial.print("Database Task -> Core ");
        Serial.println(xPortGetCoreID());

        // هنا لاحقًا ستضع عمليات SQLite
        // مثل INSERT أو SELECT

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void setup()
{
    Serial.begin(115200);

    Serial.print("Setup Core = ");
    Serial.println(xPortGetCoreID());

    if (!SPIFFS.begin(true))
    {
        Serial.println("SPIFFS Failed");
        return;
    }

    if (sqlite3_open("/spiffs/users.db", &db) == SQLITE_OK)
    {
        Serial.println("Database Opened");

        sqlite3_exec(
            db,
            "CREATE TABLE IF NOT EXISTS users("
            "id INTEGER PRIMARY KEY,"
            "username TEXT,"
            "password TEXT);",
            NULL,
            NULL,
            NULL);

        Serial.println("Table Ready");
    }

    // Task للطباعة على Core 1
    xTaskCreatePinnedToCore(
        PrintCoreTask,
        "PrintTask",
        4096,
        NULL,
        1,
        &PrintTask,
        1);

    // Task لقاعدة البيانات على Core 0
    xTaskCreatePinnedToCore(
        DatabaseTaskCode,
        "DatabaseTask",
        4096,
        NULL,
        1,
        &DatabaseTask,
        0);
}

void loop()
{
    // لم نعد نستخدم loop
    vTaskDelay(pdMS_TO_TICKS(1000));
}