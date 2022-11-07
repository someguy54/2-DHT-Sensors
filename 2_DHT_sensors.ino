//fuente: https://www.youtube.com/watch?v=oi_GPSLjgBY

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"

//OLED 128x64
#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//DHT Sensor
#define DHT1_PIN 3     // for first DHT module
#define DHT2_PIN 4     // for 2nd DHT module and do the same for 3rd and 4th etc.

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht1(DHT1_PIN, DHTTYPE);//for first DHT module
DHT dht2(DHT2_PIN, DHTTYPE);// for 2nd DHT module and do the same for 3rd and 4th etc.

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  Serial.begin(115200);  
  dht1.begin();//for first DHT module
  dht2.begin();//for 2nd DHT module  and do the same for 3rd and 4th etc.
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  pantalla_inicio();
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  
  //OLED DISPLAY
  // clear display
  display.clearDisplay();
  pantalla_1();
  delay(3000);
  pantalla_2();
  delay(3000);
  display.display();
}

void pantalla_1(){

  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  if (isnan(h1) || isnan(t1)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // DHT1 end
  
  display.clearDisplay();
  // display temperature 1
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperatura 1: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(t1);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display humidity 1
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humedad 1: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h1);
  display.print(" %"); 

display.display();
}

void pantalla_2(){

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  if (isnan(h2) || isnan(t2)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // DHT2 end
  display.clearDisplay();
  // display temperature 2
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperatura 2: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(t2);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display humidity 2
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humedad 2: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h2);
  display.print(" %"); 

display.display();
}

void pantalla_inicio(){
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print("Iniciando sensor humedad y temp ");
  display.cp437(true);
  display.write(3);
  delay(5000);
  display.display();
}


 
