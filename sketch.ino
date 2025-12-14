/****************************************************
 * Blynk Configuration
 ****************************************************/
#define BLYNK_TEMPLATE_ID   "TMPL31eunSADZ"
#define BLYNK_TEMPLATE_NAME "NM IOT"
#define BLYNK_AUTH_TOKEN    "Oxx9zdlI9sYHpbNd6FAhkysxMCcuh9G8"

/****************************************************
 * Required Libraries
 ****************************************************/
#include <Wire.h>                 // I2C communication
#include <LiquidCrystal_I2C.h>    // I2C LCD library
#include <WiFi.h>                // ESP32 WiFi library
#include <BlynkSimpleEsp32.h>    // Blynk ESP32 support

/****************************************************
 * Ultrasonic Sensor Pin Definitions
 ****************************************************/
const int trigPin1 = 12;
const int echoPin1 = 14;
const int trigPin2 = 27;
const int echoPin2 = 13;

/****************************************************
 * Traffic Light LED Pin Definitions
 ****************************************************/
// Lane 1 LEDs
const int redLED1    = 33;
const int yellowLED1 = 25;
const int greenLED1  = 26;

// Lane 2 LEDs
const int redLED2    = 18;
const int yellowLED2 = 19;
const int greenLED2  = 23;

/****************************************************
 * LCD Configuration (20x4, I2C Address 0x27)
 ****************************************************/
LiquidCrystal_I2C lcd(0x27, 20, 4);

/****************************************************
 * Blynk & WiFi Credentials
 ****************************************************/
char auth[] = "Oxx9zdlI9sYHpbNd6FAhkysxMCcuh9G8";
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

/****************************************************
 * Setup Function (Runs once)
 ****************************************************/
void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Diversion");

  // Configure ultrasonic sensor pins
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Configure LED pins
  pinMode(redLED1, OUTPUT);
  pinMode(yellowLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);

  pinMode(redLED2, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);

  // Connect ESP32 to Blynk server
  Blynk.begin(auth, ssid, pass);
}

/****************************************************
 * Main Loop (Runs continuously)
 ****************************************************/
void loop() {
  long duration1, distance1;
  long duration2, distance2;

  /******** Ultrasonic Sensor 1 ********/
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Measure echo pulse duration
  duration1 = pulseIn(echoPin1, HIGH);
  // Convert time to distance (cm)
  distance1 = (duration1 / 2) / 29.1;

  /******** Ultrasonic Sensor 2 ********/
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  /************************************************
   * Traffic Decision Logic
   ************************************************/
  if (distance1 < 50 || distance2 < 50) {
    // HIGH vehicle density detected
    lcd.setCursor(0, 1);
    lcd.print("HIGH Vehicles    ");
    lcd.setCursor(0, 2);
    lcd.print("L STOP , R GO    ");

    // Lane 1: STOP
    digitalWrite(redLED1, HIGH);
    digitalWrite(yellowLED1, LOW);
    digitalWrite(greenLED1, LOW);

    // Lane 2: GO
    digitalWrite(redLED2, LOW);
    digitalWrite(yellowLED2, LOW);
    digitalWrite(greenLED2, HIGH);

    // Send status to Blynk dashboard
    Blynk.virtualWrite(V1, "HIGH Vehicles");
    Blynk.virtualWrite(V2, "L STOP , R GO");
    Blynk.virtualWrite(V3, distance1);
    Blynk.virtualWrite(V4, distance2);

    delay(2000);
  } 
  else {
    // LOW vehicle density detected
    lcd.setCursor(0, 1);
    lcd.print("LOW Vehicles     ");
    lcd.setCursor(0, 2);
    lcd.print("Ready            ");

    // Lane 1: WAIT
    digitalWrite(redLED1, LOW);
    digitalWrite(yellowLED1, HIGH);
    digitalWrite(greenLED1, LOW);

    // Lane 2: STOP
    digitalWrite(redLED2, HIGH);
    digitalWrite(yellowLED2, LOW);
    digitalWrite(greenLED2, LOW);

    Blynk.virtualWrite(V1, "LOW Vehicles");
    Blynk.virtualWrite(V2, "Ready");
    Blynk.virtualWrite(V3, distance1);
    Blynk.virtualWrite(V4, distance2);

    delay(2000);
  }

  // Keep Blynk connection alive
  Blynk.run();
}
