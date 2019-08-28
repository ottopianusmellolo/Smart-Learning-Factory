#include <Servo.h>
#include <WiFi.h>
#include<IoTStarterKit_WiFi.h>
#include<OneWire.h>
IoTMakers g_im;


#define deviceID    "o21107D1566958121033"
#define authnRqtNo  "f3uqscafp"
#define extrSysID   "OPEN_TCP_001PTL001_1000007625"

#define WIFI_SSID   "ICT-LAB-2.4G"
#define WIFI_PASS   "12345678"

#define ONE_WIRE_BUS 2


#define TAG_ID "Moser"
Servo myServo;
int angle=0,count;
float hasil,average;
float simpan[12];
OneWire ourWire(ONE_WIRE_BUS);
//DallasTemperature sensors(&ourWire);

void init_iotmakers()
{
  while(1)
  {
    Serial.print(F("Connect to AP..."));
    while(g_im.begin(WIFI_SSID, WIFI_PASS) < 0)
    {
      Serial.println(F("retrying"));
      delay(100);
    }

    Serial.println(F("Success"));

    g_im.init(deviceID, authnRqtNo, extrSysID);
  
    Serial.print(F("Connect to platform..."));
   
    while(g_im.connect() < 0)
    {
      Serial.println(F("retrying."));
      delay(100);
    }
    Serial.println(F("Success"));
      Serial.print(F("Auth..."));
      
    if(g_im.auth_device() >= 0)
    {
      Serial.println(F("Success..."));
      return;
    }
  }
}




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(3);
init_iotmakers();
}

void loop() {
  // put your main code here, to run repeatedly:
  //move from 0 to 180 degrees
  static unsigned long tick = millis();
  
  for(angle=0;angle<180;angle++){
    myServo.write(angle);
    delay(20);
   
  }
//move in reverse direction, from 180 to 0 degrees
  for(angle=180;angle>0;angle--){
    myServo.write(angle);
    delay(20);
  }

  count++;
  hasil=(millis()-tick);
  
  simpan[count]=hasil/360;
  Serial.print("data - ");
  Serial.print(count);
  Serial.print(" : ");
  Serial.print(simpan[count]);
  Serial.println(" ms/deg ");
  
  if(count>10){
    average = (simpan[1]+simpan[2]+simpan[3]+simpan[4]+simpan[5]+simpan[6]+simpan[7]+simpan[8]+simpan[9]+simpan[10])/10;
    count=0;
      Serial.print(" average : ");
  Serial.print(average);
  Serial.println(" ms/deg ");
  
  }
  

  tick=millis();


}
