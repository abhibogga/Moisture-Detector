const int trigPin = 9;  
const int echoPin = 10;  
long duration;  
int distanceCm, distanceInch;  

 #include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs =8 , en = 7, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 void setup() {
  // put your setup code here, to run once:

pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(trigPin, OUTPUT);  
   pinMode(echoPin, INPUT); 
   lcd.begin(16, 2); 
  
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(trigPin, LOW);  
   delayMicroseconds(2);  
   digitalWrite(trigPin, HIGH);  
   delayMicroseconds(10);  
   digitalWrite(trigPin, LOW);  
   duration = pulseIn(echoPin, HIGH);  
   distanceCm= duration*0.034/2;  
   distanceInch = duration*0.0133/2; 
int soil_moisture = analogRead(A0);
int soil_moisture_2 = analogRead(A1);
int soil_moisture_3 = analogRead(A2);
Serial.print(soil_moisture);
Serial.print("      ");
Serial.print(soil_moisture_2);
Serial.print("      ");
Serial.println(soil_moisture_3);

int z= map(soil_moisture, 0, 1023, 100, 0);
int z_2= map(soil_moisture_2, 0, 1023, 100, 0);
int z_3= map(soil_moisture_3, 0, 1023, 100, 0);
//Serial.print(z);
//Serial.print(" %");
//Serial.print("   ");
 //Serial.print("Distance: ");  
 int a = map(distanceCm, 0, 17, 20, 0);
   //Serial.print(distanceCm); 
   //Serial.println(" Cm"); 
   lcd.clear();
   lcd.setCursor(0, 0);
    lcd.print("SM1");
    lcd.setCursor(0, 1);
   lcd.print(z);
   lcd.setCursor(3, 1);
   lcd.print("%");
    lcd.setCursor(6, 0);
    lcd.print("SM2");
    lcd.setCursor(6, 1);
   lcd.print(z_2);
   lcd.setCursor(9, 1);
   lcd.print("%");
    lcd.setCursor(13, 0);
    lcd.print("SM3");
    lcd.setCursor(12, 1);
   lcd.print(z_3);
   lcd.setCursor(15, 1);
   lcd.print("%");
   delay(300);
    lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("WATER LEVEL");
   lcd.setCursor(12, 0);
   lcd.print(a);
   lcd.setCursor(14, 0);
   lcd.print("Cm");
   delay(300);

if(soil_moisture>500)
{
  digitalWrite(2,LOW);
  }
  else
  {
    digitalWrite(2,HIGH); 
  }
if(soil_moisture_2>280)
{
  digitalWrite(11,LOW);
  }
  else
  {
    digitalWrite(11,HIGH); 
  }

  if(soil_moisture_3>700)
{
  digitalWrite(12,LOW);
  }
  else
  {
    digitalWrite(12,HIGH); 
  }

}
