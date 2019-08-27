#define trigPin 13                 
#define echoPin 12                
#define BUZZER 6
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int r;
int b;


void setup()
{
  Serial.begin (9600);       
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);   
}

void loop()
{
  long duration, distance;                   

  digitalWrite(trigPin, LOW);                
  delayMicroseconds(2);                
  digitalWrite(trigPin, HIGH);            
  delayMicroseconds(10);               

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);   
  distance = duration * 17 / 1000;
  
  if (distance >= 200 || distance <= 0){
    Serial.println("Unable to measure distance");
  } else                                           
  {
    Serial.print(distance);                      
    Serial.println(" cm");                       
  
  if(distance<=40){
    tone(BUZZER,600);
    delay(distance*10);
    noTone(BUZZER);
    delay(distance*10);
  }else{
    delay(500);
  }

  //r= 220 - distance;
  //b = 220 + distance;
  r= 220 - (distance^3);
  b = 220 + (distance^3);
  
 setColor(r,200,b);
  } 
}
void setColor(int red,int green,int blue)
{
  analogWrite(redPin,red);
  analogWrite(greenPin,green);
  analogWrite(bluePin,blue);
}
//setColor(r,255,b);
//}
