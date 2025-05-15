# 🌡️IOT-Based-Temperature-Controlled-SmartFan-Arduino-System

A thesis Project 
by:
# By-Group-Shapi
🌡️ IoT-Based Smart Fan Temperature Controlled Using Arduino
This project presents a temperature-controlled smart fan system using an Arduino Uno microcontroller, LM35 temperature sensor, L293D motor driver, and HC-05 Bluetooth module. The fan adjusts its speed automatically based on ambient temperature readings and provides a mobile app interface for remote control.

📌 Project Overview
With rising energy demands and the drive for home automation, this system enables automatic and manual control of a fan using real-time temperature data. It aims to enhance indoor comfort, optimize power usage, and provide users with an intuitive way to control climate via their smartphones.


🧠 Features
🔥 Automatic Fan Speed Control based on room temperature.
📱 Bluetooth Connectivity using HC-05 and a custom MIT App Inventor mobile interface.
📊 Real-Time Temperature Display on a 16x2 I2C LCD.
🔋 Energy Efficient operation and fan power management.
🔧 Modular, Scalable System using Arduino Uno for easy upgrades.
🧪 Fully Tested under multiple environmental conditions.



🧱 Components Used
Component	Description
Arduino Uno	Microcontroller for system logic and sensor interface.
LM35 Temperature Sensor	Measures ambient temperature.
L293D Motor Driver	Drives the DC fan based on PWM signals.
3V DC Fan	Adjusts speed based on temperature.
16x2 I2C LCD	Displays temperature and system status.
HC-05 Bluetooth	Enables wireless communication with mobile app.
Lithium Batteries	Portable power source for the fan and system.
MIT App Inventor App	Interface to control the fan remotely.



🖼️ System Design
⚡ Breadboard Circuit Design
🔄 Schematic Diagram
🔌 PCB Layout
📱 Mobile App Interface (MIT App Inventor)

🔁 System Architecture

    A[LM35 Sensor] -->|Temp Data| B[Arduino Uno]
    B --> C[L293D Motor Driver]
    C --> D[DC Fan]
    B --> E[16x2 LCD]
    F[Mobile App via Bluetooth] -->|Control Commands| B



🧪 Testing Summary
Test Case	Temperature	Mode	Fan Speed	App Sync
Ambient Room	31°C	Auto	Off	✅
Warm Hand on Sensor	37°C	Auto	High	✅
Manual Mode	-	Manual	Custom PWM	✅
Frequent Temp Changes	Varying	Auto	Flexible	✅



💡 Benefits
Promotes energy-saving habits.
Ideal for smart homes, offices, and classroom automation.
Easily scalable to integrate with other IoT devices.



⚠️ Known Limitations
Limited range due to Bluetooth (approx. 10m).
Accuracy affected by sensor placement and voltage fluctuations.
System designed for indoor use only.



🛠️ Tools & Technologies
Tool/Platform	Purpose
Arduino IDE	Microcontroller programming
MIT App Inventor	Mobile application development
Fritzing	PCB and circuit diagram design
Tinkercad	Circuit simulation
C++	Arduino codebase



💰 Cost Breakdown
Category	Item	Cost (₱)
Development	Arduino Kit, HC-05	1,709
Operational	Lithium batteries, testing setup, phone	4,052
Total		5,761

📥 Installation & Setup
Upload the Arduino sketch to your Arduino Uno.

Connect hardware components as per the schematic.

Install the Fan Controller App (built in MIT App Inventor).

Pair your smartphone with the HC-05 Bluetooth module.

Launch the app and start monitoring or controlling the fan.




📜 License
This project is licensed under the Apache License. Feel free to modify, distribute, and use it for both educational and personal purposes.






👥 Contributors


Anngelica Eñaga - Project Manager

Precy Faith Bocado - System Analyst

Jhon Guiller E. Barenio - Programmer

Nemfa Ruiz - Documentation

Lyka Paciente - Testing
