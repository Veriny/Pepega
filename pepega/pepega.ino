#include "Seeed_BMP280.h"
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

File fortnite;
BMP280 minecraft;
float pepegahands = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
    }
     Serial.print("Initializing SD card...");
    if(!minecraft.init()) {
        Serial.println("Device not connected or broken!");
     }
    if (!SD.begin(4)) {
      Serial.println("initialization failed!");
      while (1);
    }
    fortnite = SD.open("fortnite.txt", FILE_WRITE);
    if (fortnite) {
      Serial.print("Writing to test.txt...");
      fortnite.println("Fortnite bad, minecraft good.");
      // close the file:
      fortnite.close();
      Serial.println("done.");
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }
    
 }

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  write();
  
}

//void wait(int seconds){
//  clock_t endwait;
//  endwait=clock()+seconds*CLOCKS_PER_SEC;
//  while (clock()<endwait);
//}

void write(){
  Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
    }
     Serial.print("Pepega Clap");

    if (!SD.begin(4)) {
      Serial.println("initialization failed!");
      while (1);
    }
    fortnite = SD.open("fortnite.txt", FILE_WRITE);
    if (fortnite) {
      Serial.print("Writing to test.txt...");
      Serial.print(minecraft.getPressure());
      fortnite.println("Fortnite bad, minecraft good.");
      fortnite.println("Pressure:");
      fortnite.println(minecraft.getPressure());
      fortnite.println("Temp:");
      fortnite.println(minecraft.getTemperature());
      fortnite.println("Altitude:");
      fortnite.println(minecraft.calcAltitude(minecraft.getPressure()));
      if (minecraft.calcAltitude(minecraft.getPressure()) > pepegahands) {
        pepegahands =  minecraft.calcAltitude(minecraft.getPressure());
      }
      fortnite.println("Max Altitude:");
      fortnite.println(pepegahands);
      // close the file:
      fortnite.close();
      Serial.println("done.");
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }
}
