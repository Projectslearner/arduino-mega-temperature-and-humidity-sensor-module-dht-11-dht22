/*
    Project name : Temperature and humidity sensor module DHT 11 DHT22
    Modified Date: 15-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-temperature-and-humidity-sensor-module-dht-11-dht22
*/

#include <DHT.h>

// Constants for DHT sensor type and pin
#define DHTPIN 2      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 22 (AM2302) sensor type

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Initialize serial communication
  dht.begin();        // Initialize DHT sensor
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  float humidity = dht.readHumidity();    // Read humidity value
  float temperatureC = dht.readTemperature(); // Read temperature in Celsius (the default)

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute temperature in Fahrenheit
  float temperatureF = temperatureC * 9.0 / 5.0 + 32.0;

  // Print temperature and humidity values to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C   ");
  Serial.print(temperatureF);
  Serial.print(" °F   ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
