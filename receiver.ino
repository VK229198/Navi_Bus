#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // Try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // Received a packet
    Serial.println("Received packet:");

    // Read packet and print GPS location
    while (LoRa.available()) {
      String data = LoRa.readStringUntil('\n');
      Serial.println(data);
    }

    // Print RSSI of packet
    Serial.print("RSSI: ");
    Serial.println(LoRa.packetRssi());
  }
}