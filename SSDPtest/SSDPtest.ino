#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266SSDP.h>
#include "index.h"

//WiFi Network credentials
#ifndef STASSID
#define STASSID "WIFI_SSID"
#define STAPSK  "PASSWORD"
#endif

//SSDP defines
#define SSDP_HTTPPORT 80
#define SSDP_NAME "My mega device"
#define SSDP_SERIALNUMBER "001122334455"
#define SSDP_URL "index.html"
#define SSDP_MODELNAME "MegaDevice 2019"
#define SSDP_MODELNUMBER "555444333222"
#define SSDP_MODELURL "https://sites.google.com/site/safrrc/easytotrack"
#define SSDP_MANUFACTURER "SafrRC"
#define SSDP_MANUFACTURERURL "https://sites.google.com/site/safrrc/"


const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer HTTP(80);

//
// Setup function. Runs once
//
void setup() {
  //Serial port initialization
  Serial.begin(115200);
  Serial.println();
  Serial.println("Starting WiFi...");
  
  //WiFi Mode is station
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() == WL_CONNECTED) {
    Serial.printf("Starting HTTP...\n");
    HTTP.on("/", handleRoot);                       //Which routine to handle at root location
    
    HTTP.on("/index.html", HTTP_GET, []() {         //How to handle /index.html request 
      HTTP.send(200, "text/plain", "Hello World!");
    });
    HTTP.on("/description.xml", HTTP_GET, []() {    //How to handle /description.xml request
      SSDP.schema(HTTP.client());
    });
    HTTP.begin();

    Serial.printf("Starting SSDP...\n");
    
    //Fill in the SSDP profile
    SSDP.setSchemaURL("description.xml");
    SSDP.setHTTPPort(SSDP_HTTPPORT);
    SSDP.setName(SSDP_NAME);
    SSDP.setSerialNumber(SSDP_SERIALNUMBER);
    SSDP.setURL(SSDP_URL);
    SSDP.setModelName(SSDP_MODELNAME);
    SSDP.setModelNumber(SSDP_MODELNUMBER);
    SSDP.setModelURL(SSDP_MODELURL);
    SSDP.setManufacturer(SSDP_MANUFACTURER);
    SSDP.setManufacturerURL(SSDP_MANUFACTURERURL);
    SSDP.begin();

    Serial.printf("Ready!\n");
  } else {
    Serial.printf("WiFi Failed\n");
    while (1) {
      delay(100);
    }
  }
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 HTTP.send(200, "text/html", s); //Send web page
}

void loop() {
  HTTP.handleClient();
  delay(1);
}
