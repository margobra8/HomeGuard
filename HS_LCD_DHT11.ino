/* 

	Módulo de lectura y mostrado de los valores proporcionados por el sensor DHT11
	en la LCD de la unidad principal.
	
	Proyecto HomeStation V2
	(c) 2017 Marcos Gómez | BSD-3-CLAUSE
	
	Módulo Arduino: UNO R3
	
*/

#include <LiquidCrystal.h>
#include <DHT.h>



// pines de conexión
int SENSOR = 2; // sensor DHT11 con VCC, DATA, GND; DATA -> D2 en arduino

// LCD
int VO = 3; // pin del contraste de la pantalla controlado por PWM, se puede colocar un potenciómetro en su lugar
int RS = 4; // Register State (cmd or write)
int E = 5; // Enable
// Bits de informacion y serial
int D4 = 6;
int D5 = 7;
int D6 = 8;
int D7 = 9;

// Variables DHT11
int temp;
int humedad;

DHT dht (SENSOR, DHT11); //definimos sensor
LiquidCrystal lcd (RS, E, D4, D5 ,D6, D7); //definimos lcd

void setup(){
  dht.begin(); //preparar instancia del DHT11
  
  lcd.begin(16, 2); //tamaño de la pantalla (columnas, filas)
  analogWrite(VO, 50); //contraste de pantalla en pin PWM
}

void loop(){
    humedad = dht.readHumidity();
    temp = dht.readTemperature();

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperatura: ");
    lcd.print(temp);
    lcd.print(" ºC");
    lcd.setCursor(0,1);
    lcd.print("Humedad: ");
    lcd.print(humedad);
    lcd.print(" %");

    delay(15000);
}
