# PULSE and ECG
## Introduction
- This project implements a real-time heart monitoring system using an Arduino microcontroller. It measures heart rate (BPM) using a pulse sensor and captures ECG signals using the AD8232 module. 
- The system intelligently switches between pulse measurement and ECG waveform display based on user interaction, making it suitable for educational, healthcare, and IoT-based monitoring applications.

## Features
- Real-time heart rate (BPM) calculation
- ECG waveform acquisition using AD8232
- Automatic mode switching (Pulse → ECG)
- OLED display for live data visualization
- Serial Plotter support for ECG waveform analysis
- Compact, low-cost, and portable design

  ## Components Used
- Arduino Uno / Nano
- Pulse Sensor (Heart Rate Sensor)
- AD8232 ECG Module
- OLED Display (I2C – SSD1306)
- Jumper Wires
- Breadboard
- USB Cable

## Clone the Repository
git clone https://github.com/your-username/pulse-ecg-monitor.git

## Output
- OLED Display:
* BPM in pulse mode
* ECG signal visualization
- Serial Plotter:
* Continuous ECG waveform

## Challenges
- Noisy Signal Acquisition
- Accurate BPM Calculation
- ECG Signal Stability
- Mode Switching Logic
- OLED Display Limitations
- Real-Time Processing Constraints
- Library Compatibility Issues
- Power Supply Stability
