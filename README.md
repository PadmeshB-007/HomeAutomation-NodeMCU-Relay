IoT Home Automation System using NodeMCU (ESP8266) + Relay

This project implements a simple and fully working Wi-Fi–based Home Automation system using NodeMCU ESP8266 and a 5V relay to control an AC bulb from any smartphone browser.
It is a beginner-friendly IoT project that demonstrates practical skills in embedded systems, Wi-Fi communication, relay interfacing, and safe AC wiring.

This repository contains all code, diagrams, and images required to build and understand the system.

Project Overview

The main goal of this project is to allow the user to switch an AC appliance ON or OFF wirelessly using the local Wi-Fi network.
The NodeMCU hosts a small web server that displays ON/OFF buttons.
When the user taps a button, the ESP8266 sends a control signal to a relay module, which then switches the LIVE AC line of a bulb.

This creates a working IoT Smart Switch without any mobile app or cloud service.

Features
	•	📱 Control any AC appliance from your phone’s browser
	•	🌐 Fully Wi-Fi based (no external server required)
	•	⚡ Safe switching of AC Live wire using relay isolation
	•	💡 Works with bulb, fan, charger, or any small AC load
	•	🔧 Very beginner-friendly setup
	•	🧩 Code is simple and easy to modify
	•	🔌 Can be extended to multiple relays or sensors

Components Used
   Component            Quantity          Purpose
   . NodeMCU ESP8266       1                Wi-Fi microcontroller + webserver
   . 5V Single Channel     1                Switches AC Live wire
     Relay
   . AC Bulb + Holder      1                Load to control
   . Jumper Wires          --               Connections
   . USB Power (5V)        1                Powers NodeMCU
   . Extension Box         1                AC supply
   . Screwdriver Tester    1                To identify Live/Neutral safely

Block Diagram
   Smartphone  →  Wi-Fi  →  NodeMCU (Web Server)  →  Relay (Switch)  →  AC Bulb

Circuit Diagram (Text Form)

. Low Voltage Side (NodeMCU ↔ Relay)   
    NodeMCU VU (5V)  → Relay VCC
    NodeMCU GND      → Relay GND
    NodeMCU D1       → Relay IN
. High Voltage Side (Relay ↔ AC Load)
  Only the LIVE wire goes through relay. Neutral goes directly.
    Extension Live (L)  → Relay COM
    Relay NO            → Bulb Live Input
    Extension Neutral   → Bulb Neutral Input
Relay NC is unused.

How It Works (Simple Explanation):
  1.	The NodeMCU connects to your Wi-Fi network.
	2.	It creates a small local web page with ON/OFF buttons.
	3.	When ON is pressed, GPIO D1 sends a HIGH or LOW signal to the relay (based on relay type).
	4.	Relay connects the AC Live wire → Bulb turns ON.
	5.	When OFF is pressed, relay disconnects Live wire → Bulb turns OFF.
	6.	Neutral wire remains directly connected to the bulb for safety.
This forms a complete IoT Smart Switch system.

Arduino Code

All source code is available in this repo as:

📄 home_automation.ino

The code includes:
	•	Wi-Fi login
	•	Webserver setup
	•	ON/OFF routes
	•	Relay control logic
	•	Active-LOW/Active-HIGH compatibility

Demo Video
  https://youtube.com/shorts/Ni8EE9HL16I?si=gLPS3BPr99Z-bP5W

Safety Precautions

This project deals with AC 230V, so safety is important:
	•	Always identify LIVE wire using a tester
	•	Keep relay and AC wires inside a plastic enclosure
	•	Do NOT touch AC parts when power is ON
	•	Double-check that only LIVE wire goes through relay
	•	Neutral wire must never pass through relay
	•	Ensure all screw terminals are tight
	•	Use electrical tape to cover exposed wires

Learning Outcomes

By completing this project, you have learned:
	•	ESP8266 Wi-Fi setup
	•	Hosting a web server on microcontroller
	•	Basics of GPIO control
	•	Relay driver interfacing
	•	Difference between Live & Neutral
	•	Safe AC load switching
	•	GitHub documentation
	•	How to structure a complete IoT project  

Future Improvements

Here are some ideas to extend your project:
	•	Google Assistant / Alexa voice control
	•	Mobile app using Blynk or IoT MQTT platform
	•	Control multiple appliances using 4-channel relay
	•	Add temperature sensor (DHT11/DHT22)
	•	Add scheduling (turn bulb ON at specific time)
	•	Add Over-The-Air (OTA) updates

Author

Padmesh B
Undergraduate Student – B.E. ECE (2nd Year)
Sri Sivasubramaniya Nadar College of Engineering (SSN CE)
IoT & Embedded Systems Enthusiast 
Interested in Smart Automation Projects
