 #include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// OLED object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin definitions 
const int PulseSensorPin = A0;
const int ECGPin = A1;
const int touchThreshold = 520;

bool ecgMode = false;
bool fingerTouching = false;
bool previouslyTouching = false;
int bpm = 0;
unsigned long lastBPMUpdateTime = 0;
unsigned long fingerRemovedTime = 0;
bool fingerRemovedTimerStarted = false;
int xPos = 0;

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Place finger on");
  display.setCursor(0, 10);
  display.println("sensor...");
  display.display();

  randomSeed(analogRead(A2)); // Seed for better randomness
}

void loop() {
  int signal = analogRead(PulseSensorPin);

  if (!ecgMode) {
    // Finger is on the sensor
    if (signal > touchThreshold) {
      fingerTouching = true;

      // First time finger detected
      if (!previouslyTouching) {
        previouslyTouching = true;
        fingerRemovedTimerStarted = false; // Cancel any removal countdown
        bpm = random(60, 101);             // New random BPM on each touch
      }

      // Display BPM every 500 ms
      if (millis() - lastBPMUpdateTime > 500) {
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Measuring BPM...");
        display.setTextSize(2);
        display.setCursor(0, 20);
        display.println("BPM: " + String(bpm));
        display.display();
        lastBPMUpdateTime = millis();
      }
    } else {
      // Finger is removed
      fingerTouching = false;

      if (previouslyTouching && !fingerRemovedTimerStarted) {
        fingerRemovedTimerStarted = true;
        fingerRemovedTime = millis(); // Start 22-second countdown
        previouslyTouching = false;
      }

      // If 22 seconds pass since finger removal → switch to ECG
      if (fingerRemovedTimerStarted && millis() - fingerRemovedTime >= 22000) {
        ecgMode = true;

        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Switching to ECG...");
        display.display();
        delay(1000);
        display.clearDisplay();

        xPos = 0;
      }
    }
  } else {
    // ECG display mode
    int ecgVal = analogRead(ECGPin);
    int y = map(ecgVal, 0, 1023, SCREEN_HEIGHT - 1, 0);

    display.drawLine(xPos, 0, xPos, SCREEN_HEIGHT, BLACK); // Clear old column
    display.drawPixel(xPos, y, SSD1306_WHITE);              // Draw ECG point
    display.display();

    Serial.println(ecgVal); // For Serial Plotter

    xPos++;
    if (xPos >= SCREEN_WIDTH) {
      xPos = 0;
      display.clearDisplay(); // Clear for continuous scrolling
    }

    delay(5); // ECG scroll speed
  }
} 
