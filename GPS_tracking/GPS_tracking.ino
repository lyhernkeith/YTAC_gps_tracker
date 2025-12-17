// /* ESP8266 with NEO6M GPS Module
//  * Uses Software Serial for GPS communication
//  */

// #include <TinyGPSPlus.h>
// #include <SoftwareSerial.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>


// #define GPS_RX_PIN D7  // GPIO13 - Connect to GPS TX
// #define GPS_TX_PIN D8  // GPIO15 - Connect to GPS RX

// // GPS baud rate
// #define GPS_BAUD 9600

// // Create TinyGPS++ object
// TinyGPSPlus gps;

// // Create Software Serial for GPS (RX, TX)
// SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

// const char* ssid = "BASK@unifi-2.4G";
// const char* password = "CHM@iterim";

// ESP8266WebServer server(80);

// void handleGPS() {
//   if (!gps.location.isValid()) {
//     server.send(200, "application/json",
//       "{\"valid\":false}");
//     return;
//   }

//   char json[256];
//   snprintf(json, sizeof(json),
//     "{"
//       "\"valid\":true,"
//       "\"lat\":%.6f,"
//       "\"lon\":%.6f,"
//       "\"speed\":%.2f,"
//       "\"sat\":%d,"
//       "\"hdop\":%.2f"
//     "}",
//     gps.location.lat(),
//     gps.location.lng(),
//     gps.speed.kmph(),
//     gps.satellites.value(),
//     gps.hdop.hdop()
//   );

//   server.send(200, "application/json", json);
// }




// // void setup() {
// //   // Initialize Serial Monitor
// //   Serial.begin(115200);
  
// //   // Initialize GPS Serial
// //   gpsSerial.begin(GPS_BAUD);
// // }

// void setup() {
//   Serial.begin(115200);
//   gpsSerial.begin(GPS_BAUD);

//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println();
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   server.on("/gps", handleGPS);
//   server.begin();
// }





// // void loop() {
// //   // Diagnostic counter
// //   static unsigned long lastPrint = 0;
// //   static int chars_processed = 0;
  
// //   // Read GPS data
// //   while (gpsSerial.available() > 0) {
// //     char c = gpsSerial.read();
// //     Serial.write(c); // Print raw GPS data for debugging
// //     gps.encode(c);
// //     chars_processed++;
// //   }

// //   // Print diagnostic info every 5 seconds
// //   if (millis() - lastPrint > 5000) {
// //     lastPrint = millis();
// //     Serial.print(F("Satellites: "));
// //     Serial.println(gps.satellites.value());
// //     Serial.print(F("Location valid: "));
// //     Serial.println(gps.location.isValid() ? "YES" : "NO");
    
// //     if (gps.location.isValid()) {
// //       displayLocationInfo();
// //     } else {
// //       Serial.println(F("Waiting"));
// //     }
// //   }

// //   delay(10);
// // }

// void loop() {
//   while (gpsSerial.available()) {
//     gps.encode(gpsSerial.read());
//   }

//   server.handleClient();
// }






// void displayLocationInfo() {
//   // Latitude
//   Serial.print(F("Latitude:   "));
//   if (gps.location.isValid()) {
//     Serial.print(gps.location.lat(), 6);
//     Serial.print(" ");
//     Serial.println(gps.location.rawLat().negative ? "S" : "N");
//   } else {
//     Serial.println(F("Invalid"));
//   }

//   // Longitude
//   Serial.print(F("Longitude:  "));
//   if (gps.location.isValid()) {
//     Serial.print(gps.location.lng(), 6);
//     Serial.print(" ");
//     Serial.println(gps.location.rawLng().negative ? "W" : "E");
//   } else {
//     Serial.println(F("Invalid"));
//   }

//   // Date
//   Serial.print(F("Date:       "));
//   if (gps.date.isValid()) {
//     Serial.printf("%02d/%02d/%04d\n", gps.date.day(), gps.date.month(), gps.date.year());
//   } else {
//     Serial.println(F("Invalid"));
//   }

//   // Time (UTC)
//   Serial.print(F("Time (UTC): "));
//   if (gps.time.isValid()) {
//     Serial.printf("%02d:%02d:%02d\n", gps.time.hour(), gps.time.minute(), gps.time.second());
//   } else {
//     Serial.println(F("Invalid"));
//   }

//   // Satellites
//   Serial.print(F("Satellites: "));
//   if (gps.satellites.isValid()) {
//     Serial.println(gps.satellites.value());
//   } else {
//     Serial.println(F("Invalid"));
//   }

//   // HDOP (Horizontal Dilution of Precision)
//   Serial.print(F("HDOP:       "));
//   if (gps.hdop.isValid()) {
//     Serial.println(gps.hdop.hdop());
//   } else {
//     Serial.println(F("Invalid"));
//   }

//   // Speed
//   Serial.print(F("Speed:      "));
//   if (gps.speed.isValid()) {
//     Serial.print(gps.speed.kmph());
//     Serial.println(F(" km/h"));
//   } else {
//     Serial.println(F("Invalid"));
//   }
// }

// jigbfhkmfevgbmjkofddmbgkogfdrmdbo ngfdmkbgm kvdcx


// #include <ESP8266WiFi.h>

// const char* ssid = "BASK@unifi-2.4G";
// const char* password = "CHM@iterim";

// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   Serial.print("Connecting");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nConnected!");
//   Serial.println(WiFi.localIP());
// }

// void loop() {}

//rgbfrebgodvoc kcbfxdnemdkcv jfx dmivmdfjncvm kicfdsmcv 

// #include <ESP8266WiFi.h>

// void setup() {
//   Serial.begin(115200);
//   WiFi.mode(WIFI_STA);
//   WiFi.disconnect();
//   delay(100);

//   Serial.println("Scanning networks...");
//   int n = WiFi.scanNetworks();
//   if (n == 0) {
//     Serial.println("No networks found");
//   } else {
//     for (int i = 0; i < n; i++) {
//       Serial.print(i + 1);
//       Serial.print(": ");

//       Serial.print(WiFi.SSID(i));
//       Serial.print(" (");
//       Serial.print(WiFi.RSSI(i));
//       Serial.print(") Encryption: ");
//       Serial.println(WiFi.encryptionType(i));
//     }
//   }
// }

// void loop() {}


// ap mode

// #include <TinyGPSPlus.h>
// #include <SoftwareSerial.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>

// // --- GPS Setup ---
// #define GPS_RX_PIN D7  // GPS TX → ESP RX
// #define GPS_TX_PIN D8  // GPS RX → ESP TX
// #define GPS_BAUD 9600

// TinyGPSPlus gps;
// SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

// // --- Access Point Setup ---
// const char* apSSID = "ESP_GPS_TEST";
// const char* apPassword = "12345678";


// ESP8266WebServer server(80);

// // --- GPS handler for browser ---
// // void handleGPS() {
// //   if (!gps.location.isValid()) {
// //     server.send(200, "application/json", "{\"valid\":false}");
// //     return;
// //   }
// void handleGPS() {
//   server.sendHeader("Access-Control-Allow-Origin", "*"); // <<< add this line
//   if (!gps.location.isValid()) {
//     char json[64];
//     snprintf(json, sizeof(json),
//       "{\"valid\":false,\"sats\":%d}", gps.satellites.value());
//     server.send(200, "application/json", json);
//     return;
//   }

//   char json[256];
//   snprintf(json, sizeof(json),
//     "{"
//       "\"valid\":true,"
//       "\"lat\":%.6f,"
//       "\"lon\":%.6f,"
//       "\"speed\":%.2f,"
//       "\"sat\":%d,"
//       "\"hdop\":%.2f"
//     "}",
//     gps.location.lat(),
//     gps.location.lng(),
//     gps.speed.kmph(),
//     gps.satellites.value(),
//     gps.hdop.hdop()
//   );

//   server.send(200, "application/json", json);
// }

// void setup() {
//   // Serial for debugging
//   Serial.begin(115200);
//   gpsSerial.begin(GPS_BAUD);

//   // Start Access Point
//   WiFi.mode(WIFI_AP);
//   WiFi.softAP(apSSID, apPassword);
//   Serial.print("AP started! Connect to: ");
//   Serial.println(apSSID);
//   Serial.print("AP IP: ");
//   Serial.println(WiFi.softAPIP());

//   // Start web server
//   server.on("/gps", handleGPS);
//   server.begin();
//   Serial.println("Web server started at /gps");
// }






// void loop() {
//   // Read GPS data continuously
//   // while (gpsSerial.available()) {
//   //   gps.encode(gpsSerial.read());
    
//   // }

//   while (gpsSerial.available()) {
//     char c = gpsSerial.read();
//     Serial.write(c); // raw GPS output
//     gps.encode(c);
//   }

//   // Handle incoming HTTP requests
//   server.handleClient();

//   yield(); // prevent watchdog reset
// }

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ---------- WIFI CREDENTIALS ----------
const char* ssid     = "HONOR X9d";
const char* password = "keithlee";

// ---------- GPS SETUP ----------
#define GPS_RX_PIN D7   // GPS TX → ESP RX
#define GPS_TX_PIN D8   // GPS RX → ESP TX
#define GPS_BAUD   9600

TinyGPSPlus gps;
SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

// ---------- WEB SERVER ----------
ESP8266WebServer server(80);

// ---------- GPS ENDPOINT ----------
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

// ---------- SETUP ----------
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
      Serial.println("\n❌ WiFi connection failed");
      return;
    }
  }

  Serial.println("\n✅ WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/gps", handleGPS);
  server.begin();
  Serial.println("🌐 Web server started at /gps");
}

// ---------- LOOP ----------
void loop() {
  // Read GPS continuously
  while (gpsSerial.available()) {
    char c = gpsSerial.read();
    gps.encode(c);
    Serial.write(c);   // optional raw NMEA output
  }

  server.handleClient();
  yield();
}
