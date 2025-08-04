/*************************************************************************************
*  Robot Control with Android App and NodeMCU
*
*  Differential Robot using H-Bridget L293D
*   
*  Voice activation and response
*  
************************************************************************************/
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
const char* ssid = "CSE_B_6";
const char* password = "123444444";
String  command =""; // Command received from Android device

// Set Motor Control Pins
int rightMotor2 = D3;    // D7 - right Motor -
int rightMotor1 = D4;    // D8 - right Motor +
int leftMotor2 = D5;    // D3 - left Motor - 
int leftMotor1 = D6;    // D4 - left Motor +


void setup()
{
  Serial.begin(115200);

 
  pinMode(leftMotor1, OUTPUT); 
  pinMode(leftMotor2, OUTPUT);  
  pinMode(rightMotor1, OUTPUT);  
  pinMode(rightMotor2, OUTPUT);  

  
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,HIGH);
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,HIGH);
      
  connectWiFi();
  server.begin();
}

void loop()
{
    client = server.available();  
    if (!client) return; 
    command = checkClient ();

         if (command == "light%20on"  ||command == "relay%201%20on"  || command == "VOICE1"          || command == "a frente") VOICE1();
    else if (command == "light%20off" ||command == "relay%20one%20of"|| command == "relay%20one%20of"|| command == "voltar")  VOICE2();
    else if (command == "fan%20on"   ||command == "relate%20to%20on"|| command == "relay%20to%20on" ||command == "esquerda") VOICE3();    
    else if (command == "fan%20off"  ||command == "relay%20to%20off"|| command == "relay%20to%20off"||command == "direita")VOICE4();  
    else if (command == "device%20on"||command == "relay%203%20on"  || command == "VOICE5"          ||command == "Esquerda") VOICE5();    
    else if (command == "device%20off"||command == "relay%203%20of" || command == "VOICE6"          || command == "Direita")  VOICE6(); 
    else if (command == "charger%20on"||command == "relay%204%20on" || command == "relay%20four%20on"||command == "esquerdA") VOICE7();    
    else if (command == "charger%20off"||command =="relay%204%20of" || command == "relay%204%20off"  || command == "direitA")  VOICE8(); 
       
    else if (command == "stop"    || command == "all%20relays%20of" || command == "parar" || command == "parando")     stopMotor();     
    Serial.println(command);
    sendBackEcho(command); // send command echo back to android device
    command = "";   
} 

/* command motor forward */
void VOICE1(void)   
{
  digitalWrite(leftMotor1,LOW);
}
void VOICE2(void)   
{
  digitalWrite(leftMotor1,HIGH);
}
/* command motor backward */
void VOICE3(void)   
{
  digitalWrite(leftMotor2,LOW);
}
void VOICE4(void)   
{
  digitalWrite(leftMotor2,HIGH);
}
/* command motor turn left */
void VOICE5(void)   
{
  digitalWrite(rightMotor1,LOW); 
}
void VOICE6(void)   
{
  digitalWrite(rightMotor1,HIGH); 
}
/* command motor turn right */
void VOICE7(void)   
{
  digitalWrite(rightMotor2,LOW);
}
void VOICE8(void)   
{
  digitalWrite(rightMotor2,HIGH);
}
/* command motor stop */
void stopMotor(void)   
{
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,HIGH);
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,HIGH);
}

/* connecting WiFi */
void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}

/* check command received from Android Device */
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}

/* send command echo back to android device */
void sendBackEcho(String echo) 
{
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println(echo);
  client.println("</html>");
  client.stop();
  delay(1);
}
