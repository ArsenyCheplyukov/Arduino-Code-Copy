//  HC-05 universal test sketch to enter AT-commands
//  Uses hardware serial to talk to the host computer and software serial for communication with the bluetooth module
//
//  Pins
//  BT VCC to Arduino 5V out.
//  BT GND to GND
//  Arduino D11 to BT RX
//  Arduino D10 BT TX
//  Key Pin D9
//
//  When a command is entered in the serial monitor on the computer
//  the Arduino will relay it to the bluetooth module and display the result.
//
//  The HC-05 modules require both CR and NL

#include<SoftwareSerial.h>
SoftwareSerial BTSerial(3, 2);

void setup() {
  
  Serial.begin(9600);
  Serial.println("Sketch HC-05");
  Serial.println("Arduino with HC-05 is ready");
  Serial.println("Make sure Both NL & CR are set");
  Serial.println("");

  //Set to HC-05 default baud rate, found using AT+UART.  It is usually 38400.
  BTSerial.begin(9600);
  Serial.println("BTserial started at 115200");
  Serial.println("");

}

void loop() {
  
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }

  // Read from the Serial Monitor and send to the Bluetooth module
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
