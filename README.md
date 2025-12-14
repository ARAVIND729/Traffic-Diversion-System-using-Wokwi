🚦 Smart Traffic Diversion System (ESP32 – Wokwi Simulation)

📘 Overview

  This project presents a Smart Traffic Diversion System for road congestion management, simulated using Wokwi and implemented with ESP32.
The system dynamically controls traffic signals based on real-time vehicle density detected using ultrasonic sensors, aiming to reduce congestion and improve traffic flow efficiency.

   An LCD display and LED indicators provide real-time traffic status, while Blynk IoT enables remote monitoring of traffic conditions.

🎯 Objectives

   Detect traffic congestion in real time

   Automatically divert or control traffic signals based on vehicle density

   Reduce human intervention in traffic management

   Enable remote monitoring using IoT

🧩 System Components

   ESP32 – Central controller with WiFi capability

   Ultrasonic Sensors (2×) – Vehicle distance and density detection

   LCD Display (I2C) – Displays traffic condition (LOW / HIGH)

   LED Indicators – Traffic signal status (Red / Yellow / Green)

   Blynk IoT Platform – Remote monitoring dashboard

⚙️ Working Principle

   Ultrasonic sensors continuously measure the distance of vehicles on both lanes

   ESP32 calculates vehicle density based on measured distance

   If congestion is detected on one lane:

   That lane is stopped (RED)

   The opposite lane is allowed to move (GREEN)

   Traffic status is displayed on the LCD

   Sensor data and traffic state are sent to Blynk IoT in real time

🔍 Functionality

   Distance Measurement: Ultrasonic sensors calculate distance using echo pulse timing

   Traffic Status Display: LCD shows LOW or HIGH vehicle density

   Signal Indication: LEDs act as traffic signals

   IoT Monitoring: Traffic data is pushed to the Blynk dashboard

🧪 Simulation Details

   Platform: Wokwi

   Controller: ESP32

   Language: Embedded C / Arduino

   Connectivity: WiFi + Blynk

🔗 Wokwi Simulation Link:
HTTPS://WOKWI.COM/PROJECTS/399694412130711553
