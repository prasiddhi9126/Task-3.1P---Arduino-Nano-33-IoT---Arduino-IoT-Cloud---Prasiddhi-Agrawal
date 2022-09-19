#include "arduino_secrets.h"
// DHT sensor library - Version: Latest 
#include <DHT.h>
#include <DHT_U.h>

#include "thingProperties.h"

#include <DHT.h>

#define DHTPIN 6     
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);
float temp;
float hum;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  pinMode(LED_BUILTIN, OUTPUT);
  dht.begin();
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  delay(1000);
  
  humidity = hum;
  temperature = temp;
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C");
  Serial.print(" Humidity: ");
  Serial.print(hum);
  Serial.print("%");
  Serial.println();
  delay(1000);
}




/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/
 void onLedChange()  {
   // Add your code here to act upon Led change
   digitalWrite(LED_BUILTIN, led);
 }


/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/

/*
  Since SmartTemperature is READ_WRITE variable, onSmartTemperatureChange() is
  executed every time a new value is received from IoT Cloud.
*/
