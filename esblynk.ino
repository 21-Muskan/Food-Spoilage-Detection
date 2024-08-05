#define BLYNK_TEMPLATE_ID "TMPL3htE4UPns"
#define BLYNK_TEMPLATE_NAME "ES project"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

// #define BLYNK_TEMPLATE_ID "TMPL3htE4UPns"
// #define BLYNK_TEMPLATE_NAME "ES project"
//#define BLYNK_AUTH_TOKEN "z4Wc_iYR4rjQERdIYMLSv6qn2OB__KkQ"

String sdata;
char auth[] = "z4Wc_iYR4rjQERdIYMLSv6qn2OB__KkQ";

// Your WIFI credentials.
// Set password to "" for open networks.
char ssid[] = "Muskan";
char pass[] = "jayh3599";

BlynkTimer timer;

String myString;  // complete message from Arduino, which consists of sensors data
char rdata;       // received characters


// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent() {
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
}



void setup() {
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, sensorvalue1);
}

void loop() {
  if (Serial.available() == 0) {
    Blynk.run();
    timer.run();  // Initiates BlynkTimer
  }

  if (Serial.available() > 0) {
    rdata = Serial.read();
    myString = myString + rdata;
  }
}

void sensorvalue1() {
  sdata = myString;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V12, sdata);
  myString = "";
}
