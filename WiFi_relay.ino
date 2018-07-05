//char ssid[] = "" //"ASUS-8B3C";
//char pass[] = "" //"123456789";

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <EEPROM.h>
#include <ESP8266mDNS.h>
   
   //https://github.com/igor269/upd
   
#include <ESP8266Ping.h>          //https://github.com/dancol90/ESP8266Ping
//#include <ESP8266httpUpdate.h>
//#include <FS.h>
//#include "Wire.h"
//#include <ESP8266SSDP.h>

/*
IPAddress apIP(192,168,4,1); //IP адрес точки доступа
String _ssidAP = "socket";   // SSID AP точки доступа
String _passwordAP = ""; // пароль точки доступа
*/
/*  В EEPROM
 * adr0      AP_ST если TYPE_WiFi = 1 значит ESP "Access Point" (без роутера)          1byte
 *                              если =2 значит ESP = Station; 
 *                              если =3 значит ESP = Access Point + Station
 * adr 1-16  AP_SSID            имя точки доступа  (без роутера)                      16byte
 * adr17-32  AP_Password        PAS пароль точки доступа  (без роутера)               16byte
 * adr33-36  AP_IP:192.168.5.1  IP_toch точки доступа (без роутера)                    4byte
 * adr37-44                     НЕИСПОЛЬЗУЮТСЯ (РЕЗЕРВ)                                8byte   ***РЕЗЕРВ***
 * adr45-60  ST_SSID            ssid роутера                                          16byte
 * adr61-76  ST_Password        pass роутера                                          16byte
 * adr77-80  ST_IP              IP_server сервера (через роутер)                       4byte
 * adr81-104 Name_device        Name device                                           24byte
* adr105-120 setup_pass         setup_pass                                           16byte
 */
 
  /**** Глобальные переменные ***/
  int AP_ST = 0;
  String AP_SSID="", AP_Password="", ST_SSID="", ST_Password="", Name_device="", setup_pass="";
  IPAddress AP_IP, ST_IP;

 

// DNS server
const byte DNS_PORT = 53;
DNSServer dnsServer;
  
  // Web интерфейс для устройства
  ESP8266WebServer HTTP(80);
  ESP8266HTTPUpdateServer httpUpdater;  
  
  #define LedBl 2  //"D4" GPIO2 синий светодиод на модуле (для индикации процессов)
  String  ONOFrel="false";
  HTTPClient http;

void loop () {
/* pWebConfig->ProcessHTTP();
  yield();*/
  
  //DNS
  dnsServer.processNextRequest();

 HTTP.handleClient();
    
delay(30);
}   //************    конец loop  ************************************


