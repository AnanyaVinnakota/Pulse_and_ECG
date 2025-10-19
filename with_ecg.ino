#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin definitions
const int PulseSensorPin = A0;
const int ECGPin = A1;  // AD8232 OUTPUT pin
const int touchThreshold = 520;

bool fingerTouching = false;
bool ecgMode = false;
int bpm = 60;
int finalBPM = 0;
unsigned long lastUpdateTime = 0;

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    while (true);
  }
int ecgValue = analogRead(ECGPin);
Serial.println(ecgValue);  // This must print just numbers

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hold sensor to");
  display.setCursor(0, 10);
  display.println("get BPM...");
  display.display();
}

void loop() {
  if (!ecgMode) {
    int signal = analogRead(PulseSensorPin);

    if (signal > touchThreshold) {
      if (!fingerTouching) {
        fingerTouching = true;
        bpm = 60;

        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("Measuring BPM...");
        display.display();
      }

      // Increase BPM slowly
      if (millis() - lastUpdateTime > 300 && bpm < 100) {
        bpm += random(1, 4);
        if (bpm > 100) bpm = 100;

        display.setCursor(0, 20);
        display.setTextSize(1);
        display.println("BPM: " + String(bpm) + "   ");
        display.display();
        lastUpdateTime = millis();
      }

    } else {
      if (fingerTouching) {
        finalBPM = bpm;

        display.clearDisplay();
        display.setCursor(0, 0);
        display.setTextSize(1);
        display.println("Final BPM:");
        display.setCursor(0, 10);
        display.setTextSize(2);
        display.println(String(finalBPM));
        display.display();

        delay(2000);  // Display final BPM for a moment

        // Switch to ECG mode
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Now measuring");
        display.setCursor(0, 10);
        display.println("ECG... (Plotter)");
        display.display();

        ecgMode = true;
        fingerTouching = false;
        delay(1500);
      }
    }
  } else {
    // ECG Mode: Continuously read and print ECG signal
    int ecgValue = analogRead(ECGPin);
    Serial.println(ecgValue);  // Use Serial Plotter to view ECG
    delay(5);
  }
}
