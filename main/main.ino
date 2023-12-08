//#include <gsm_a6.h>
//
//
//
//#define RX 7
//#define TX 8
//#define RESET 2
//#define BAUD 9600
//
//
//GSMSim gsm;
//
///*
// * Also you can this types:
// * GSMSim gsm(RX, TX);
// * GSMSim gsm(RX, TX, RESET);
// * GSMSim gsm(RX, TX, RESET, LED_PIN, LED_FLAG);
// */
//
//void setup() {
//  // put your setup code here, to run once:
//  
//  Serial.begin(9600);
//
//  Serial.println("GSMSim Library - Call Example");
//  Serial.println("");
//  delay(1000);
//
//  gsm.start(); // baud default 9600
//  //gsm.start(BAUD);
//
//  char* phone_no = "xxxxxxxx";
//
//  Serial.println("Calling the number " + String(phone_no));
//  Serial.println(gsm.call(phone_no));
//  delay(100000);
//  Serial.println("Call hang off");
//  gsm.callHangoff();
//
//  
//
//  
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//}

#include <SoftwareSerial.h>

//Create software serial object to communicate with A6
SoftwareSerial mySerial(2, 4); //A6 Tx & Rx is connected to Arduino #2 & #4

void setup()
{
//Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
Serial.begin(115200);

//Begin serial communication with Arduino and A6
mySerial.begin(115200);

Serial.println("Initializing...");
delay(1000);

mySerial.println("AT"); //Once the handshake test is successful, i t will back to OK
updateSerial();

mySerial.println("ATD+852xxxxxxxx"); // change ZZ with country code and xxxxxxxxxxx with phone number to dial
updateSerial();
delay(20000); // wait for 20 seconds...
mySerial.println("ATH"); //hang up
updateSerial();
}

void loop()
{
}

void updateSerial()
{
delay(500);
while (Serial.available())
{
mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
}
while(mySerial.available())
{
Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
}
}
