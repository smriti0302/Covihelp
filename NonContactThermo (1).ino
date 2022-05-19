#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);




SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint8_t proximity_data = 0;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  mlx.begin();
  apds.init();
  apds.enableProximitySensor(false);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  Serial.begin(9600);
  Serial.println("Setup Done");

}


void loop() {
   String temp_celsius = ""; 
   float temp_farenheit=0.0;
    
   apds.readProximity(proximity_data);

   Serial.println(proximity_data);
   Serial.println(mlx.readObjectTempF());

   
  
   if (proximity_data < 255) {
        
        delay(1000);
    
        display.clearDisplay();
        display.invertDisplay(false);
        display.setTextSize(2.8);
        display.setTextColor(WHITE);
        display.setCursor(0, 1);
        display.clearDisplay();
        display.println("6AM YOGA");
        display.setCursor(0,0);
        display.display();
        digitalWrite(5, LOW);
  }
  else
  {
    temp_celsius = String(mlx.readObjectTempC(), 1);
    temp_farenheit =  mlx.readObjectTempF() + 11;
    tone(8, 523,800);
    if (temp_farenheit <= 100){
        Serial.print(" Body Temperature:");
        Serial.println(temp_celsius);
        Serial.println(temp_farenheit);
        display.clearDisplay();
        display.invertDisplay(false);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(8, 0);
        display.clearDisplay();
        display.println("Body Temp:");
        display.setCursor(25, 18);
        display.print(temp_farenheit);
        display.setCursor(85, 8);
        display.print(".");
        display.setTextColor(WHITE);
        display.setCursor(85, 18);
        display.print(" F");
        display.display();
        delay(5000);
   }
   else {
        Serial.print(" Body High Temperature:");
        Serial.println(temp_celsius);
        Serial.println(temp_farenheit);
        tone(8, 1023, 10000);

        display.clearDisplay();
        display.invertDisplay(false);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(20, 0);
        display.clearDisplay();
        display.println("CRITICAL");

        display.invertDisplay(true);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(20, 0);
        display.clearDisplay();
        display.println("CRITICAL");

        display.invertDisplay(true);
        display.setTextColor(WHITE);
        display.setCursor(20, 0);
        display.clearDisplay();
        display.println("CRITICAL");

        display.invertDisplay(false);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(20, 0);
        display.clearDisplay();
        display.println("CRITICAL");

        display.invertDisplay(true);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(20, 0);
        display.clearDisplay();
        display.println("CRITICAL");

        display.invertDisplay(true);
        display.setTextColor(WHITE);
        display.setCursor(20, 0);
        display.clearDisplay();
        display.println("CRITICAL");
  
        display.invertDisplay(false);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(20, 0);
        display.clearDisplay();
        display.println("CRITICAL");

        display.setCursor(23, 18);
        display.print(temp_farenheit);
        display.setCursor(93, 8);
        display.print(".");
        display.setTextColor(WHITE);
        display.setCursor(93, 18);
        display.print(" F");
        display.display();
        delay(5000);
      }
    }
}
