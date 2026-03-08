# Pulse and ECG Monitoring System

**Pulse and ECG Monitoring System** is a real-time heart monitoring project developed using an Arduino microcontroller. The system measures heart rate in **Beats Per Minute (BPM)** using a pulse sensor and captures **Electrocardiogram (ECG) signals** using the **AD8232 ECG Sensor Module**.

The project intelligently switches between **pulse measurement mode and ECG monitoring mode** based on user interaction. The collected data is displayed on an OLED screen and can also be visualized through the **Serial Plotter** for waveform analysis.

This project demonstrates how embedded systems and biomedical sensors can be combined to build a compact and low-cost heart monitoring solution suitable for **educational demonstrations, healthcare experiments, and IoT-based monitoring systems**.

---

# Project Overview

Monitoring heart activity is an essential aspect of healthcare and biomedical engineering. This project provides a simple yet effective way to monitor heart rate and ECG signals using widely available electronic components.

The system initially operates in **Pulse Mode**, where it calculates the heart rate (BPM) when the user places a finger on the pulse sensor. Once the finger is removed, the system automatically switches to **ECG Mode**, where the ECG waveform is captured and displayed in real time.

This intelligent mode-switching mechanism enables seamless monitoring of both heart rate and ECG signals within a single embedded system.

---

# Features

* **Real-Time Heart Rate Monitoring**
  Calculates and displays the heart rate in Beats Per Minute (BPM) using a pulse sensor.

* **ECG Signal Acquisition**
  Captures electrical heart signals using the AD8232 ECG module.

* **Automatic Mode Switching**
  Automatically switches between Pulse Mode and ECG Mode based on finger detection.

* **OLED Display Visualization**
  Displays heart rate and ECG data using the **SSD1306 OLED Display**.

* **Serial Plotter Support**
  Enables ECG waveform visualization using the Arduino IDE Serial Plotter.

* **Compact and Low-Cost Design**
  Uses simple components to build a portable biomedical monitoring system.

---

# Hardware Components Used

The project uses the following components:

* **Arduino Uno** or **Arduino Nano**
* Pulse Sensor (Heart Rate Sensor)
* **AD8232 ECG Sensor Module**
* **SSD1306 OLED Display**
* Jumper Wires
* Breadboard
* USB Cable

---

# System Workflow

The working process of the system is as follows:

1. The pulse sensor detects heartbeats when a finger is placed on it.
2. The Arduino calculates the heart rate and displays the BPM on the OLED screen.
3. When the finger is removed, the system automatically switches to ECG mode.
4. The AD8232 module captures electrical heart signals.
5. The ECG waveform is displayed on the OLED display and transmitted to the Serial Plotter.

---

# Output

### OLED Display

The OLED display shows:

* Heart Rate (BPM) in Pulse Mode
* ECG signal representation in ECG Mode

### Serial Plotter

Using the **Arduino IDE** Serial Plotter, the ECG signal can be visualized as a **continuous waveform**, allowing users to observe heart signal patterns.

---

# Installation and Setup

To run this project:

### Clone the Repository

```bash
git clone https://github.com/your-username/pulse-ecg-monitor.git
```

### Upload the Arduino Code

1. Open the Arduino code in **Arduino IDE**.
2. Connect the Arduino board to your computer.
3. Select the correct **board and COM port**.
4. Upload the code to the microcontroller.

---

# Challenges Faced

During the development of the project, several challenges were encountered:

* **Noisy Signal Acquisition**
  Biomedical sensors are sensitive to noise and require proper filtering.

* **Accurate BPM Calculation**
  Ensuring reliable heart rate detection required careful signal processing.

* **ECG Signal Stability**
  Maintaining stable ECG readings required proper electrode placement and grounding.

* **Mode Switching Logic**
  Implementing reliable switching between pulse and ECG modes.

* **OLED Display Limitations**
  The small screen size limited the level of detail in waveform visualization.

* **Real-Time Processing Constraints**
  Processing signals efficiently within Arduino’s limited resources.

* **Library Compatibility Issues**
  Ensuring compatibility between sensor libraries and display libraries.

* **Power Supply Stability**
  Maintaining stable voltage levels for accurate sensor readings.

---

# Applications

This system can be used in several domains, including:

* Educational demonstrations of biomedical instrumentation
* Basic healthcare monitoring experiments
* IoT-based health monitoring prototypes
* Embedded systems learning projects

---

# Future Improvements

Possible improvements for the project include:

* Integration with **IoT platforms for remote monitoring**
* Mobile application for health data visualization
* Improved ECG waveform visualization
* Advanced signal filtering techniques
* Cloud-based health data storage and analysis

---

# License

This project is developed for **educational and research purposes**.


