float adcvoltage1=0.0;
int sensorPin1=A0;
int sensorValue1=0.0;
float involtage1=0.0;
float r11=30000.00;
float r12=7500.00;
float refvoltage1=5.0;
float involtagedisplay1=0;

float adcvoltage2=0.0;
int sensorPin2=A0;
int sensorValue2=0.0;
float involtage2=0.0;
float r21=30000.00;
float r22=7500.00;
float refvoltage2=5.0;
float involtagedisplay2=0;


void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

 void loop()
 {
 sensorValue1=analogRead(sensorPin1);
 adcvoltage1=(sensorValue1*refvoltage1);
 involtage1=adcvoltage1/(r12/(r11+r12));
 involtagedisplay1=involtage1/1000;
  Serial.println(involtagedisplay1);
  delay(1000)  ;

  sensorValue2=analogRead(sensorPin2);
 adcvoltage2=(sensorValue2*refvoltage2);
 involtage2=adcvoltage2/(r21/(r21+r22));
 involtagedisplay2=involtage2/1000;
  Serial.println(involtagedisplay2);
  delay(1000)  ;

  if (involtagedisplay1<=1.4 )
  {
      digitalWrite(  11 ,HIGH);
  if(involtagedisplay2<= 1.4 )
  {
     digitalWrite(  10,HIGH);
  }
  }
  else
  {
    digitalWrite(   11 ,LOW);
    digitalWrite(    10 ,LOW);
  }
    
  }
