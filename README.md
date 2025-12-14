Objectives

Detect traffic congestion in real time

Automatically divert or control traffic signals based on vehicle density

Reduce human intervention in traffic management

Enable remote monitoring using IoT

System Components

  ESP32 – Central controller with WiFi capability

  Ultrasonic Sensors (2x) – Vehicle distance and density detection

  LCD Display (I2C) – Displays traffic condition (LOW / HIGH)

  LED Indicators – Traffic signal status (Red / Yellow / Green)

  Breadboard – Circuit connections

  Blynk IoT Platform – Remote monitoring dashboard

Working Principle

  Ultrasonic sensors continuously measure the distance of vehicles on both lanes

  ESP32 calculates vehicle density based on measured distance

  If congestion is detected on one lane:

  That lane is stopped (RED)

  The opposite lane is allowed to move (GREEN)

  Traffic status is displayed on the LCD

  Sensor data and traffic state are sent to Blynk IoT in real time

Functionality

  Distance Measurement: Ultrasonic sensors calculate distance using echo pulse timing

  Traffic Status Display: LCD shows LOW or HIGH vehicle density

  Signal Indication: LEDs act as traffic signals

IoT Monitoring: Traffic data is pushed to the Blynk dashboard

Simulation Details

Platform: Wokwi

Controller: ESP32

Language: Embedded C / Arduino

Connectivity: WiFi + Blynk

🔗 Wokwi Simulation Link:
HTTPS://WOKWI.COM/PROJECTS/399694412130711553
