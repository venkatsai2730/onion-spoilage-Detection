#include <DHT.h>

#define MQ135_PIN_1 A0
#define MQ135_PIN_2 A1
#define MQ135_PIN_3 A2 
#define buzzer 7
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  int gasValue1 = analogRead(MQ135_PIN_1);
  int gasValue2 = analogRead(MQ135_PIN_2);
  int gasValue3 = analogRead(MQ135_PIN_3);
  int threshold = 800;
  Serial.println(gasValue1,DEC);
  Serial.println(gasValue2,DEC);
  Serial.println(gasValue3,DEC);
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
    if(gasValue1 > threshold){
    
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);


   }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C");
  Serial.println();
}
