#include "Global.h"



/* This code sets up the essentials for your circuit to work. It runs first every time your circuit is powered with electricity. */
void setup() {
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    Serial.println("start");
    
    dht.begin();
}

/* This code is the main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop. */
void loop() {
    // Reading humidity in %
    float dhtHumidity = dht.readHumidity();
    // Read temperature in Celsius, for Fahrenheit use .readTempF()
    float dhtTempC = dht.readTempC();
    
    
    
    if (dhtHumidity > 70 || dhtTempC > 28 )
    {
        // The LCD Screen will display the text of your choice. For more serLCD functions see http://playground.arduino.cc/Code/SerLCD 
        serlcd.clear();                          // 1. Clear LCD screen.
        serlcd.print("Arduino");                 // 2. Print print String to LCD
        serlcd.selectLine(2);                    // 3. Set cursor at the begining of line 2
        serlcd.print("    Rocks!");              // 4. print String to LCD
        delay(1000);                             // 5. waits 1000 milliseconds (1 sec). Change the value in the brackets (1000) for a longer or shorter delay in milliseconds.
        serlcd.clear();                          // 6. Clear LCD screen.
        delay(1000);                             // 7. waits 1000 milliseconds (1 sec). Change the value in the brackets (1000) for a longer or shorter delay in milliseconds.                        
    }
    
}
