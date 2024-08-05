#define BLYNK_TEMPLATE_ID "TMPL3htE4UPns"
#define BLYNK_TEMPLATE_NAME "ES project"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

#define BLYNK_TEMPLATE_ID "TMPL3htE4UPns"
#define BLYNK_TEMPLATE_NAME "ES project"
//#define BLYNK_AUTH_TOKEN "z4Wc_iYR4rjQERdIYMLSv6qn2OB__KkQ"

String sdata; 
char auth[] = "z4Wc_iYR4rjQERdIYMLSv6qn2OB__KkQ";

// Your WIFI credentials.
// Set password to "" for open networks.
char ssid[] = "OPPO A5s";
char pass[] = "123123123";

BlynkTimer timer;

String  myString; // complete message from Arduino, which consists of sensors data
char rdata; // received characters


// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
  
}



void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, sensorvalue1); 

}

void loop()
{
   if (Serial.available() == 0) 
   {
  Blynk.run();
  timer.run(); // Initiates BlynkTimer

   }
   
  if (Serial.available() > 0) 
  {
    rdata = Serial.read(); 
    myString = myString + rdata; 
  
  }

}

void sensorvalue1()
{
sdata = myString ;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V10, sdata);
   myString = "";
}
// #include <SoftwareSerial.h>


// SoftwareSerial nodemcu(8, 9);



// int pinRedLed = 12;

// int pinGreenLed = 11;

// int pinSensor = A5;

// int THRESHOLD = 250;

// int buzzer = 10;


 


// int rdata = 0;

// String mystring;

// void setup()

// {

// Serial.begin(9600);

// nodemcu.begin(9600);



// pinMode(buzzer, OUTPUT);

// pinMode(pinRedLed, OUTPUT);

// pinMode(pinGreenLed, OUTPUT);

// pinMode(pinSensor, INPUT);




// }


// void loop()

// {


//     // put your main code here, to run repeatedly:


// int rdata  =  analogRead(pinSensor);



// Serial.print("Methane Range: ");

// Serial.println(rdata);


// if(rdata >= THRESHOLD){

//    digitalWrite(pinRedLed, HIGH);

//    digitalWrite(pinGreenLed, LOW);

//    digitalWrite(buzzer, HIGH);  

 

//    delay(50);

 

// }else

//   {

//     digitalWrite(pinRedLed, LOW);

//     digitalWrite(pinGreenLed, HIGH);

//     digitalWrite(buzzer, LOW);

   

//   }

 

//   if (nodemcu.available() > 0)

//   {

//   char data;

//  data = nodemcu.read();

//   Serial.println(data);

//   }

//   if(rdata < 250){

//   mystring = mystring + "Methane Range: " + rdata;

//   nodemcu.println(mystring);

//   Serial.println(mystring);

 

//   }else

// {

//     mystring = "Food Spoiled";

//     nodemcu.println(mystring);

//     Serial.println(mystring);

 

//   }


//  mystring = "";

// delay(1000);

 

// }