/*
 * =====================================================================
 * Task 1: On / Off Inbuilt LED on ESP32
 * Developer: PRAVEEN. A
 * Board: ESP32 DevKit V1
 * Description: Control and toggle onboard LED connected to GPIO 2.
 * =====================================================================
 */

// Define the inbuilt LED pin for ESP32 (GPIO 2)
#define LED_PIN 2

void setup() {
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);
  delay(500);

  // Configure GPIO 2 as digital output
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Start in OFF state

  Serial.println("=========================================");
  Serial.println("   ESP32 INBUILT LED CONTROLLER ONLINE   ");
  Serial.println("=========================================");
  Serial.println("Type 'ON', 'OFF', or 'TOGGLE' in Serial Monitor:");
}

void loop() {
  // Check if serial command is available from user
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toUpperCase();

    if (command == "ON" || command == "1") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("[STATUS] Inbuilt LED: ON (GPIO 2 HIGH)");
    } 
    else if (command == "OFF" || command == "0") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("[STATUS] Inbuilt LED: OFF (GPIO 2 LOW)");
    } 
    else if (command == "TOGGLE" || command == "T") {
      int currentState = digitalRead(LED_PIN);
      digitalWrite(LED_PIN, !currentState);
      Serial.print("[STATUS] LED Toggled to: ");
      Serial.println(!currentState ? "HIGH (ON)" : "LOW (OFF)");
    } 
    else {
      Serial.println("[ERROR] Unknown command. Use ON, OFF, or TOGGLE.");
    }
  }

  // Heartbeat periodic blink cycle demonstration
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
