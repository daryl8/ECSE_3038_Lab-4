#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "env.h"

const int light1 = 12;
const int light2 = 13;
const int light3 = 14;

const char * WIFI_SSID = "MonaConnect";
const char * WIFI_PASS = "";

char * endpoint = "https://ecse-three-led.netlify.app/";

void setup(){

  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  

  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASS);

  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

  if (WiFi.status() == WL_CONNECTED){
    HTTPClient http;

    String http_response;

    http.begin(endpoint);
    http.addHeader("X-API-Key","Langston#813");

    Serial.println("");
    Serial.println("");

    int httpResponseCode = http.GET();

    if(httpResponseCode>0){
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      Serial.print("Response from server: ");
      http_response = http.getString();
      Serial.println(http_response);
      

    }
    else {
      Serial.print("Error Code: ");
      Serial.println(httpResponseCode);
    }
    // free resource 
    http.end();

     StaticJsonDocument<1024> doc;

      DeserializationError error = deserializeJson(doc, http_response);

      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
      }
      bool light_switch_1 = doc["light_switch_1"]; 
      bool light_switch_2 = doc["light_switch_2"]; 
      bool light_switch_3 = doc["light_switch_3"]; 
  
      Serial.println("");
      Serial.println(light_switch_1);
      Serial.println(light_switch_2);
      Serial.println(light_switch_3);
      //led states
      digitalWrite(light1, light_switch_1);
      digitalWrite(light2,light_switch_2);
      digitalWrite(light3, light_switch_3);
      Serial.println(" Updated LED states");
      
  }
  else {
    return;
  }
}