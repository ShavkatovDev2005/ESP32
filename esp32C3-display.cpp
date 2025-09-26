#include <Arduino.h>
#include <WS2812FX.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define LED_COUNT 1
#define LED_PIN 2
#define SDA_PIN 5
#define SCL_PIN 6

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

// 0.42" OLED (SSD1306 72x40 ERF)
U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  // LED sozlash
  ws2812fx.init();
  ws2812fx.setBrightness(255);
  ws2812fx.setSpeed(1000);
  ws2812fx.setColor(0x007BFF);
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.start();

  // OLED sozlash
  Wire.begin(SDA_PIN, SCL_PIN);
  u8g2.begin();
}

void loop(void) {
  ws2812fx.service();  

  // OLED ekranga yozuv chiqarish
  u8g2.clearBuffer();                  
  u8g2.setFont(u8g2_font_6x10_tf);     // Shrift tanlash

  // Yozuvni chiqarish
  u8g2.drawStr(10, 10, "Salom");
  u8g2.drawStr(10, 25, "Dunyo");
  u8g2.sendBuffer();                   

  delay(500);
}
