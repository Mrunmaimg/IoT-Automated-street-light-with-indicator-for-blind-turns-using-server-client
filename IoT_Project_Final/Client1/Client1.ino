#include <ESP8266WiFi.h>
const char* ssid = "Xyz";
const char* password = "mrunmai123";
const char* serverIp = "192.168.204.254";
const int serverPort = 80;
WiFiClient client1;
void setup() {
  Serial.begin(115200);
  pinMode (D4, OUTPUT);
  pinMode (D8, OUTPUT);
  delay(1000);
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");

  Serial.println("Sending request to server...");
}

void loop() {
  if (!client1.connect(serverIp, serverPort)) {
    Serial.println("Connection failed.");
    return;
  }
  
  Serial.println("Connected to server");
  client1.print("GET / HTTP/1.1\r\n");
  client1.print("Host: ");
  client1.print(serverIp);
  client1.print("\r\n");
  client1.print("Connection: close\r\n\r\n");
  delay(10);
  
  while (client1.available()) {
    String line = client1.readStringUntil('\r');
    if (line == "LED_OFF") {
      digitalWrite(D4, LOW);
      Serial.println("Received LED_OFF from server. LED turned OFF.");
    }
    else {
      digitalWrite(D4, HIGH);
      Serial.println("Received LED_ON from server. LED turned ON.");
    }
  }
}