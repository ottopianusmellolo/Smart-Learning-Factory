#include<Servo.h>
Servo myServo;
int angle=0,count;
float hasil,average;
float simpan[12];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(3);
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
