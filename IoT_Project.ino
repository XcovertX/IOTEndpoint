#include <SPI.h>
#include <Ethernet.h>
#include <DHT.h>
#include "config.h" // Include the configuration file

// Ethernet settings
byte mac[] = MAC_ADDRESS;
IPAddress ip = IP_ADDRESS;
EthernetServer server(SERVER_PORT);

// DHT sensor settings
DHT dht(DHT_PIN, DHT_TYPE);

// DHT sensor settings
#define DHTPIN 2        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT sensor type (DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start Ethernet connection
  Ethernet.begin(mac, ip);
  server.begin();

  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  EthernetClient client = server.available();

  if (client) {
    // Read temperature and humidity from DHT sensor
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Send HTTP response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Connection: close");
    client.println();

    // Create JSON response
    client.print("{\"temperature\": ");
    client.print(temperature);
    client.print(", \"humidity\": ");
    client.print(humidity);
    client.println("}");

    // Close the connection
    client.stop();
  }
}

