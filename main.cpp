#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>

Servo myservo;
LiquidCrystal_I2C lcd(32, 16, 2); // Endereço do LCD no Tinkercad: 0x27

#define Password_Length 7 // Dê espaço suficiente para seis caracteres + caractere NULL

int pos = 0; // Variável para armazenar a posição do servo
char Data[Password_Length]; // 6 é o número de caracteres que pode conter + caractere NULL = 7
char Master[Password_Length] = "123456";
byte data_count = 0;
char customKey;

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
bool porta_fechada = true;

byte rowPins[ROWS] = {2, 3, 4, 5}; // Conecte aos pinos de linha do teclado
byte colPins[COLS] = {6, 7, 8}; // Conecte aos pinos de coluna do teclado

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); // Inicialize uma instância da classe Keypad

void setup()
{
  myservo.attach(9);
  ServoClose();
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.print(" Arduino Door");
  lcd.setCursor(0, 1);
  lcd.print("--Projeto RFID--");
  delay(3000);
  lcd.clear();
}

void loop()
{
  if (porta_fechada == false)
  {
    customKey = customKeypad.getKey();
    if (customKey == '#')
    {
      lcd.clear();
      ServoClose();
      lcd.print("  A porta fechou!");
      delay(3000);
      porta_fechada = true;
    }
  }
  else
  {
    Open();
  }
}

void clearData()
{
  while (data_count != 0)
  {
    Data[data_count--] = 0;
  }
  return;
}

void ServoOpen()
{
  for (pos = 180; pos >= 0; pos -= 5)
  {
    myservo.write(pos);
    delay(15);
  }
}

void ServoClose()
{
  for (pos = 0; pos <= 180; pos += 5)
  {
    myservo.write(pos);
    delay(15);
  }
}

void Open()
{
  lcd.setCursor(0, 0);
  lcd.print(" Insira a senha");
  customKey = customKeypad.getKey();
  
  if (customKey)
  {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  if (data_count == Password_Length - 1)
  {
    if (strcmp(Data, Master) == 0)
    {
      lcd.clear();
      ServoOpen();
      lcd.print(" Porta aberta");
      porta_fechada = false;
    }
    else
    {
      lcd.clear();
      lcd.print("  Senha Errada!");
      delay(1000);
      porta_fechada = true;
    }
    clearData();
  }
}