#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_i2c(0x27,16,2);  //

void setup() {
  // Inicializar el LCD
  Serial.begin(9600);
  lcd_i2c.init();
  lcd_i2c.print("Temperatura:");
  lcd_i2c.backlight();
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5, OUTPUT);
  
  digitalWrite(7,HIGH);
  Serial.println("Cocina Encendida");
  delay(1000);
}

void loop() {
  float tset = analogRead(A1)*150.0/1023;
  //**********************************
  int  LecturaSensor=analogRead(A0);
  Serial.println(LecturaSensor);

  float Temperatura=(5.0 * LecturaSensor * 100.0)/1024.0;

  Serial.print("Temperatura:");
  Serial.print(Temperatura);
  Serial.println(" C");
  //**************************************
  lcd_i2c.setCursor(0, 1);  
  lcd_i2c.print("                   ");
  lcd_i2c.setCursor(0, 1);
  lcd_i2c.print( Temperatura );
  lcd_i2c.setCursor(10, 1);
  lcd_i2c.print( tset );
  
  if(Temperatura<tset){
     Serial.println("Cocina Encendida");
     digitalWrite(7,HIGH);
     digitalWrite(6,LOW);
     digitalWrite(5, HIGH);
  }else{
     Serial.println("Cocina Apagada");
     digitalWrite(5,LOW);
     digitalWrite(7,LOW);
     digitalWrite(6,HIGH);
  }
  
  
  Serial.println( Temperatura );
  delay( 1000 );
}
