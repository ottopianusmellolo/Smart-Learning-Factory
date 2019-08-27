#define LIGHT A3
#define LED 9
#define BUZZER 6
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LIGHT, INPUT);
pinMode(LED,OUTPUT);
pinMode(BUZZER,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int value = analogRead(LIGHT);
int data = map(value, 0, 1023, 1023,0);
//int BUZZER=6;
Serial.print(" LIGHT : ");
Serial.println(data);
analogWrite(LED, value);
delay(100);
if(data<840){
  tone(BUZZER,600);
  delay(data*10);
  noTone(BUZZER);
  delay(data*10);
}
  else{
delay(500);
}
}
//map(value, fromLow,fromHigh, toLow, toHigh);
//change the dynamic range of value
