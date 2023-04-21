#include "connectionManager.h";
#include "time.h";

connectionManager ConnectionManager;

const char* ssid = "";
const char* password = "";
const String deviceId = "";
const String deviceKey = "";



// Get the time
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

void onMessage(DynamicJsonDocument message) {
  String error = message["error"];
  String packetType = message["type"];

  Serial.print("[OnMessage] Error: ");
  Serial.println(error);
  Serial.print("[OnMessage] type: ");
  Serial.println(packetType);
  //
  //  if (packetType == "setLampState")
  //  {
  //
  //  }
}


void setup() {
  Serial.begin(115200);

  Serial.setDebugOutput(true);

  delay(1000);
  Serial.println("Waking up...");

  ConnectionManager.setup(ssid, password, deviceId, deviceKey, &onMessage);

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {

  ConnectionManager.loop();

}
