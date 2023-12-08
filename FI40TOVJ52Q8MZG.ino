#include <SoftwareSerial.h>
SoftwareSerial mSerial(3, 2);
char phone_no[] = "##########"; // put your phone number here

int callPin = 7; // 10k pullup resistor
int hangPin = 6; // 10k pullup resistor
int GledPin = 11;
int BledPin = 12;
long waittime = 60000;// ms max call duration
long calltime = 0;
long starttime = 0;


void setup()
{
  //Serial.begin(115200);  uncommment this to use a serial port to your PC
  delay(1000);
  pinMode(callPin, INPUT);
  pinMode(hangPin, INPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  digitalWrite(BledPin, LOW);
  digitalWrite(GledPin, LOW);
  for (int i = 0; i < 10; i++) // in this startup time the led blinks and the A6 module starts up
  {
    digitalWrite(GledPin, HIGH);
    delay(500);
    digitalWrite(GledPin, LOW);
    delay(500);
  }
  digitalWrite(GledPin, HIGH);
  mSerial.begin(115200);
  delay(1000);
  mSerial.println("AT");
  delay(1000);
}

void loop()
{
  /* // uncomment this part to communicatie via serial port
    if (mSerial.available()) {
      Serial.write(mSerial.read());
    }
    if (Serial.available()) {
      mSerial.write(Serial.read());
    }
  */
  if (digitalRead(callPin) == LOW) // If button is pressed, switchPin is LOW
  {
    digitalWrite(BledPin, HIGH);
    digitalWrite(GledPin, LOW);
    mSerial.print("ATD");
    mSerial.println(phone_no); // call number
    starttime = (long)millis();

    while (digitalRead(hangPin) == HIGH && calltime < waittime) // loop for the call, ended by pressing hang up button or timer
    {
      delay(500);
      calltime = (long) millis() - starttime;
      // Serial.println(digitalRead(hangPin));
      //Serial.println(millis());
      //Serial.println(calltime);
      digitalRead(hangPin);

    }
    mSerial.println("ATH"); // hang up
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
  }
  delay(100);
}
