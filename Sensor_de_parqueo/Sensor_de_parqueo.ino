/*
  Fundacion Kinal
  Centro Educativo Tecnico Laborla Kinal
  Electronica
  Grado: Quinto
  Seccion: A
  Curso: Taller de eleectronica digital y reparacion de computadoras I
  Nombre: Juan Manuel Sebastian Ixen Coy
  Carne: 2019519
  Fecha: 05/05
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define direccion_lcd 0x27
#define filas A5
#define columnas A4
#define trigger A0
#define echo A1
#define buzzer 12
int a;
int distancia;
int Fre=260;
long tiempo;
LiquidCrystal_I2C LCD_Jixen(direccion_lcd, columnas, filas);
byte bloque[] = {
  B00000,
  B00000,
  B01110,
  B11101,
  B10101,
  B11111,
  B01010,
  B00000
};
void setup()
{
Serial.begin(9600);
for(int i=2; i<=11;i++){
pinMode(i, OUTPUT);
}
  pinMode(buzzer ,OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  LCD_Jixen.init();
  LCD_Jixen.backlight();
  LCD_Jixen.createChar(1, bloque);
}
void loop()
{
  Serial.println(a);
  medicion();
  distancia = a;
  alerta();
}
int medicion(){
 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  tiempo = pulseIn(echo, HIGH);
  a = tiempo/59;
  delay(50);
  return a;
}
void alerta(){
    if (distancia > 30 && distancia <= 50) {
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print("                ");
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.setCursor(7,0);
    LCD_Jixen.print("50");
    LCD_Jixen.setCursor(13,0);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("     libre   ");
    tone(buzzer, Fre, 260);
    delay(1000);
    noTone(buzzer);
  }

  if (distancia > 10 && distancia <= 30) {
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print("                ");
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.setCursor(7,0);
    LCD_Jixen.print("30");
    LCD_Jixen.setCursor(11,0);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("  Precaucion  ");
    tone(buzzer, Fre, 500);
    delay(750);
    noTone(buzzer);
  }

  if (distancia > 00 && distancia <= 10) {
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.print("                ");
    LCD_Jixen.setCursor(0,0);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.setCursor(7,0);
    LCD_Jixen.print("10");
    LCD_Jixen.setCursor(9,0);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.write(1);
    LCD_Jixen.setCursor(0,1);
    LCD_Jixen.print("    CUIDADO    ");
    tone(buzzer, Fre, 650);
    delay(500);
    noTone(buzzer);
  }
  }
  
