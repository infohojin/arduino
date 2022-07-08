#include <DHT.h>

DHT mydht(A1, DHT11);


void setup() {
  Serial.begin(115200);
  mydht.begin();
}

void loop() {
  int temp = mydht.readTemperature();
  int humi = mydht.readHumidity();

    Serial.print("Temp: ");
    Serial.println(temp);
    Serial.print("Humidity: ");
    Serial.println(humi);

    Serial.println("-----");
    delay(1000);
}
