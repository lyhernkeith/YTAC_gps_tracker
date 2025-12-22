
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char* ssid     = "HONOR X9d";
const char* password = "keithlee";


#define GPS_RX_PIN D7   
#define GPS_TX_PIN D8  
#define GPS_BAUD   9600

TinyGPSPlus gps;
SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);


ESP8266WebServer server(80);

void handleGPS() {
  server.sendHeader("Access-Control-Allow-Origin", "*");

  if (!gps.location.isValid()) {
    char json[64];
    snprintf(json, sizeof(json),
      "{\"valid\":false,\"sats\":%d}",
      gps.satellites.value()
    );
    server.send(200, "application/json", json);
    return;
  }

  char json[256];
  snprintf(json, sizeof(json),
    "{"
      "\"valid\":true,"
      "\"lat\":%.6f,"
      "\"lon\":%.6f,"
      "\"speed\":%.2f,"
      "\"sat\":%d,"
      "\"hdop\":%.2f"
    "}",
    gps.location.lat(),
    gps.location.lng(),
    gps.speed.kmph(),
    gps.satellites.value(),
    gps.hdop.hdop()
  );

  server.send(200, "application/json", json);
}


void setup() {
  Serial.begin(115200);
  gpsSerial.begin(GPS_BAUD);

  Serial.println("\nStarting ESP8266 in STA mode");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  unsigned long startAttempt = millis();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() - startAttempt > 15000) {
      Serial.println("\n WiFi connection failed");
      return;
    }
  }

  Serial.println("\n WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/gps", handleGPS);
  server.begin();

}

void loop() {

  while (gpsSerial.available()) {
    char c = gpsSerial.read();
    gps.encode(c);
    Serial.write(c);   
  }

  server.handleClient();
  yield();
}
