#include <ESP8266WiFi.h>

const char* ssid = "Xyz";
const char* password = "mrunmai123";

WiFiServer server(80);
const int irPin = D5; // GPIO5
const int irPin1 = D4; // GPIO4

bool flag = true;

void setup() {
  Serial.begin(115200);
  pinMode(irPin, INPUT_PULLUP);
  pinMode(D6, OUTPUT);
  pinMode(D8, OUTPUT);
  Serial.println("Attempting to connect to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server started");
}

void loop() {


  if (flag == true) {
WiFiClient client = server.available(); 
  if (!client) {
    return;
  }

  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  client.flush();

  if (digitalRead(irPin) == HIGH) {
    client.println("LED_OFF");
    digitalWrite(D6, LOW);
    Serial.println("IR Sensor triggered. LED_ON sent to client.");
  }
  else {
    client.println("LED_ON");
    digitalWrite(D6, HIGH);
    Serial.println("IR Sensor triggered. LED_OFF sent to client.");
  }
  flag = false;
  delay(10);
  }





  else {
    WiFiClient client1 = server.available(); 
  if (!client1) {
    return;
  }

  while (!client1.available()) {
    delay(1);
  }

  String request = client1.readStringUntil('\r');
  client1.flush();

  if (digitalRead(irPin1) == HIGH) {
    client1.println("LED_OFF");
    digitalWrite(D8, LOW);


    Serial.println("IR Sensor1 triggered. LED_ON sent to client.");
  }
  else { 
    client1.println("LED_ON");
    digitalWrite(D8, HIGH);

    Serial.println("IR Sensor1 triggered. LED_OFF sent to client.");
  }

  delay(10);
  flag = true;
  }
  
  }

  

//server