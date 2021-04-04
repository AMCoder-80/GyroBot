#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

String command = "";
const char* ssid = "GYRO ROBOT";
const char* pass = "GYROSCOPE";

IPAddress IP (192,168,4,1);
IPAddress sub (255,255,255,0);

void setup() {
  
 pinMode(0,OUTPUT);
 pinMode(1,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 digitalWrite(0,LOW);
 digitalWrite(1,LOW);
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 

 
 WiFi.softAPdisconnect(true);
 WiFi.disconnect();
 WiFi.softAPConfig(IP,IP,sub);
 WiFi.softAP(ssid,pass);
 delay(1500);

 //Serial.begin(115200);
 
 server.on("/f",forward);
 server.on("/fr",forright);
 server.on("/fl",forleft);
 server.on("/b",back);
 server.on("/dr",baright);
 server.on("/dl",baleft);
 server.on("/r",right);
 server.on("/l",left);
 server.on("/s",Stop);
 server.begin();
 
 }

void loop() {
server.handleClient();
}

void forward(){
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  delay(150);
  digitalWrite(0,0);
  digitalWrite(2,0);
  digitalWrite(1,1);
  digitalWrite(3,1);
  
  server.send(200,"text/plain","Forward");
  
 // Serial.println("Forward");
  
}

void forleft(){
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  delay(150);
  digitalWrite(0,0);
  digitalWrite(2,0);
  digitalWrite(1,0);
  digitalWrite(3,1);  
  server.send(200,"text/plain","Front Left");  
}

void forright(){
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  delay(150);
  digitalWrite(0,0);
  digitalWrite(2,0);
  digitalWrite(1,1);
  digitalWrite(3,0);    
  server.send(200,"text/plain","Front Right");
}

void back(){
  
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);  
  digitalWrite(3,0);
  delay(150);
  digitalWrite(0,1);
  digitalWrite(2,1);
  digitalWrite(1,0);
  digitalWrite(3,0);

  server.send(200,"text/plain","Backward");
  
 // Serial.println("Back");
}

void baright(){
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  delay(150);
  digitalWrite(0,1);
  digitalWrite(2,0);
  digitalWrite(1,0);
  digitalWrite(3,0);  
  server.send(200,"text/plain","Back Right");
}

void baleft(){
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  delay(150);
  digitalWrite(0,0);
  digitalWrite(2,1);
  digitalWrite(1,0);
  digitalWrite(3,0);  
  server.send(200,"text/plain","Back Left");
}

void left(){
  
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  delay(150);
  digitalWrite(0,0);
  digitalWrite(2,1);
  digitalWrite(1,0);
  digitalWrite(3,1);
  
  server.send(200,"text/plain","Left");
  
  //Serial.println("Left");
}

void right(){
  
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  delay(150);
  digitalWrite(0,1);
  digitalWrite(2,0);
  digitalWrite(1,1);
  digitalWrite(3,0);

  server.send(200,"text/plain","Right");
  
  //Serial.println("Right");

}

void Stop(){
  
  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  server.send(200,"text/plain","Stop");
  
  //Serial.println("Stop");
}
