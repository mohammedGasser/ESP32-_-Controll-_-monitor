#include <WiFi.h>
#include <WebServer.h>

//write your network name and password 
const char* ssid = "";
const char* password = "";

WebServer server(80);
 
void handleSpectrum()
{
    int value = analogRead(34);
    int frequency = random(1000,3000);
    int amplitude = random(0,100);

    String status;

    if(value > 2000)
        status = "Running";
    else
        status = "Idle";

    String data = "{";
    data += "\"value\":\"" + String(value) + "\",";
    data += "\"frequency\":\"" + String(frequency) + " Hz\",";
    data += "\"amplitude\":\"" + String(amplitude) + "%\",";
    data += "\"status\":\"" + status + "\"";
    data += "}";

    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200,"application/json",data);
}
void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/Dashboard1", handleSpectrum);

//   server.on("/Dashboard2", handleSpectrum);

//   server.on("/Dashboard3", handleSpectrum);
  server.begin();

}

void loop() {

  server.handleClient();

}