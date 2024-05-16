//int a = 0;
//int ledPin13 = 13;
//int ledPin12 = 12;
//int ledPin11 = 11;
//int ledPin10 = 10;
//int ledPin9 = 9;
//int ledPin8 = 8;
// 
//void setup() {
//  Serial.begin(9600);
//  pinMode(ledPin13, OUTPUT);
//  pinMode(ledPin12, OUTPUT);
//  pinMode(ledPin11, OUTPUT);
//  pinMode(ledPin10, OUTPUT);
//  pinMode(ledPin9, OUTPUT);
//  pinMode(ledPin8, OUTPUT);
//}
//
//void loop() {
//    Serial.println(a);
//    digitalWrite(ledPin13, ((a & 0b100000) == 0b100000) ? HIGH : LOW);
//    digitalWrite(ledPin12, ((a & 0b10000) == 0b10000) ? HIGH : LOW);
//    digitalWrite(ledPin11, ((a & 0b1000) == 0b1000) ? HIGH : LOW);
//    digitalWrite(ledPin10, ((a & 0b100) == 0b100) ? HIGH : LOW);
//    digitalWrite(ledPin9, ((a & 0b10) == 0b10) ? HIGH : LOW);
//    digitalWrite(ledPin8, ((a & 0b1) == 0b1) ? HIGH : LOW);
//    delay(1000); 
//    a++;
//}

byte pin;
byte num[10][7] = {
                    {1,1,1,1,1,1,0},     // diplay number '0' (共陰極 '1'表示給高電壓,'0'表給低電壓)
                    {0,1,1,0,0,0,0},     // diplay number '1'
                    {1,1,0,1,1,0,1},     // diplay number '2'
                    {1,1,1,1,0,0,1},     // diplay number '3'
                    {0,1,1,0,0,1,1},     // diplay number '4'
                    {1,0,1,1,0,1,1},     // diplay number '5'
                    {1,0,1,1,1,1,1},     // diplay number '6'
                    {1,1,1,0,0,0,0},     // diplay number '7'
                    {1,1,1,1,1,1,1},     // diplay number '8'
                    {1,1,1,1,0,1,1},     // diplay number '9'
                 };
void setup() {
  for (pin = 2; pin < 9; pin++)
  {         
    pinMode(pin, OUTPUT);        //initialize digital pin 2~8 as an output       
    digitalWrite(pin, HIGH);     //單一LED測試
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }
}x

void loop() {
  for (int i = 0; i < 10; i++)    //循環顯示數字 0~9
  {
     for (int j = 0; j < 7; j++)
     {
      digitalWrite(j+2, num[i][j]);        
     }
     delay(1000);                 //每個字元顯示1秒
  }

 //以下可作為LED與Arduino腳位對接是否正確之測試確認.
 //    digitalWrite(2, HIGH);  
 //    digitalWrite(3, HIGH);
 //    digitalWrite(4, HIGH);
 //    digitalWrite(5, HIGH);
 //    digitalWrite(6, HIGH);
 //    digitalWrite(8, HIGH);
 //    digitalWrite(7, HIGH); 
}
