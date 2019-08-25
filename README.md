# Android uPnP Discovery sample
This sample uses SSDP (Simple Service Discovery Protocol) to discover UPnP devices on the current WiFi network. Sample UPnP devices are ESP8266 with preloaded firmware

# Preparation
*Hardware*
- ESP8266 NodeMCU or any other ESP8266 device

*Software*
- Android Studio (2.0 or above)
- Arduino IDE (1.6.5 or above)
- Arduino IDE ESP Board Installation

# Installation and Running

*Arduino*

1. Open the SSDPtest.ino Arduino sketch in Arduino IDE.
2. Edit defines to fit your needs:

```
//WiFi Network credentials
#define STASSID "MY_SSID"
#define STAPSK  "MY_MEGA_PASSWORD"

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
```

3. Compile SSDPtest.ino Arduino sketch, and flash it to NodeMCU. After flashing, NodeMCU is going to connect to a defined WiFi. You can check if a connection was succesful using terminal
4. You can flash a number of NodeMCU devices with different SSDP_MODELNUMBER or/and SSDP_SERIALNUMBER to identify them

*Android*

1. Open the android-upnp-discovery-sample project in Android Studio.
2. Built it.
3. Run it.
4. Once the NodeMCU devices are powered connect your smartphone to the same WiFi network and run the upnp-discovery application.
5. After the UPnP scanning process is finished you'll see the list of all NodeMCU devices.
6. Clicking on a device in the list will open a beowser with the following address: http://_device_IP_/index.html

# Links
https://github.com/custanator/android-upnp-discovery
https://en.wikipedia.org/wiki/Simple_Service_Discovery_Protocol
https://en.wikipedia.org/wiki/Universal_Plug_and_Play
