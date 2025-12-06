#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ------------- WiFi Login ----------------
const char* ssid = "Batmobile ";      
const char* password = "papu@007"; 

// ------------- Pin Setup ------------------
#define RELAY_PIN D1        // Relay connected to D1 = GPIO5
const bool ACTIVE_LOW = false;  // Most relay modules are active-LOW

ESP8266WebServer server(80);

// Function to turn relay ON or OFF
void setRelay(bool on) {
  if (ACTIVE_LOW)
    digitalWrite(RELAY_PIN, on ? LOW : HIGH);
  else
    digitalWrite(RELAY_PIN, on ? HIGH : LOW);
}

// HTML Webpage
String webpage(bool state) {
  String html = "<html><body style='text-align:center; font-family:Arial;'>";
  html += "<h2>NodeMCU Home Automation</h2>";
  html += "<p>Relay is <b>" + String(state ? "ON" : "OFF") + "</b></p>";
  html += "<a href='/on'><button style='padding:15px;font-size:20px;'>TURN ON</button></a><br><br>";
  html += "<a href='/off'><button style='padding:15px;font-size:20px;'>TURN OFF</button></a>";
  html += "</body></html>";
  return html;
}

// Home page
void handleRoot() {
  bool state = digitalRead(RELAY_PIN) == (ACTIVE_LOW ? LOW : HIGH);
  server.send(200, "text/html", webpage(state));
}

void handleON() {
  setRelay(true);
  server.sendHeader("Location", "/");
  server.send(303);   // Redirect to home page
}

void handleOFF() {
  setRelay(false);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);

  // Start with relay OFF
  setRelay(false);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  

  // Web routes
  server.on("/", handleRoot);
  server.on("/on", handleON);
  server.on("/off", handleOFF);

  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  server.handleClient();
}