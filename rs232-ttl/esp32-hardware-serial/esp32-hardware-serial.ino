/*
 * Board: ESP32 Dev Module
 * Author: Gary Namestnik
 * Date: 31/05/2020
 * Design: To enable communication via Pins 16 and 17 with the hardware serial, to legacy hardware, 
 * also utilising a RS232 to TTL UART converter.
 * This script allows bi-directional comms, being able to send commands, as well as recieve commands
 * 
 * Outputs: 2x Serial Connections
 *          - Serial  - USB Serial to Computer
 *          - Serial1 - RS232 interface with legacy hardware
 *          
 * Github: https://github.com/gazzenger/esp32-projects/rs232-ttl/
 */
#include <HardwareSerial.h>
#define RXD2 16
#define TXD2 17

String readString;
String readStringUSB;

/* Baud-rates available: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200, 256000, 512000, 962100
 *  
 *  Protocols available:
 * SERIAL_5N1   5-bit No parity 1 stop bit
 * SERIAL_6N1   6-bit No parity 1 stop bit
 * SERIAL_7N1   7-bit No parity 1 stop bit
 * SERIAL_8N1 (the default) 8-bit No parity 1 stop bit
 * SERIAL_5N2   5-bit No parity 2 stop bits 
 * SERIAL_6N2   6-bit No parity 2 stop bits
 * SERIAL_7N2   7-bit No parity 2 stop bits
 * SERIAL_8N2   8-bit No parity 2 stop bits 
 * SERIAL_5E1   5-bit Even parity 1 stop bit
 * SERIAL_6E1   6-bit Even parity 1 stop bit
 * SERIAL_7E1   7-bit Even parity 1 stop bit 
 * SERIAL_8E1   8-bit Even parity 1 stop bit 
 * SERIAL_5E2   5-bit Even parity 2 stop bit 
 * SERIAL_6E2   6-bit Even parity 2 stop bit 
 * SERIAL_7E2   7-bit Even parity 2 stop bit  
 * SERIAL_8E2   8-bit Even parity 2 stop bit  
 * SERIAL_5O1   5-bit Odd  parity 1 stop bit  
 * SERIAL_6O1   6-bit Odd  parity 1 stop bit   
 * SERIAL_7O1   7-bit Odd  parity 1 stop bit  
 * SERIAL_8O1   8-bit Odd  parity 1 stop bit   
 * SERIAL_5O2   5-bit Odd  parity 2 stop bit   
 * SERIAL_6O2   6-bit Odd  parity 2 stop bit    
 * SERIAL_7O2   7-bit Odd  parity 2 stop bit    
 * SERIAL_8O2   8-bit Odd  parity 2 stop bit    
*/

void setup() {
 Serial.begin(19200);
 Serial.println("start");
 Serial1.begin(19200, SERIAL_7E1, RXD2, TXD2);
}

void loop() {
 //code to receive information from Serial1
  while (Serial1.available()) {
    char c = Serial1.read();  //gets one byte from serial buffer
    readString += c; //makes the String readString
  }
  if (readString.length() >0) {
    Serial.print("<-- ");
    Serial.println(readString);  //so you can see the captured String
    readString="";
  } 
  //code to receive information from Serial
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readStringUSB += c; //makes the String readString
  }
  if (readStringUSB.length() >0) {
    Serial.print("--> ");
    Serial.println(readStringUSB);
    Serial1.println(readStringUSB);  //so you can see the captured String
    readStringUSB="";
  } 
}
