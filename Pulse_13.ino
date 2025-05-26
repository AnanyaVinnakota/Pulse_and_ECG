#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <PulseSensorPlayground.h> 

// initialize the LCD with I2C address 0x27, 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int PulseSensorPin = A0;         // Pulse Sensor purple wire connected to A0
const int LED13 = 13;                  // Onboard LED blinks with heartbeat

PulseSensorPlayground pulseSensor;

void setup() {
  lcd.init();         // initialize the LCD
  lcd.backlight();    // turn on backlight
  Serial.begin(9600);                 // Set up Serial Monitor
  pulseSensor.analogInput(PulseSensorPin);
  pulseSensor.blinkOnPulse(LED13);   // Blink LED with heartbeat
  pulseSensor.setThreshold(550);   // Optional: set signal threshold
  if (pulseSensor.begin()) {
  lcd.setCursor(1, 0);
  lcd.print("Pulse Sensor");
  lcd.setCursor(0, 1);
  lcd.print("is ready");
  }
}
void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();   // Read BPM

  if (pulseSensor.sawStartOfBeat()) {
    lcd.print("BPM:");
    lcd.println(myBPM);                       // Print BPM when beat is detected
  }

  delay(20);
}
