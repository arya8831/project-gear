float adcvoltage1=0.0;//initialisation of voltage sensor1
int sensorpin1=A0;
int sensorvalue1=0.0;
float involtage1=0.0;
float r11=30000.00;
float r12=7500.00;
float refvoltage1=5.0;
float involtagedisplay1=0.0;
float adcvoltage2=0.0;//initialisation of voltage senor2
float sensorpin2=A1;
int sensorvalue2=0.0;
float involtage2=0.0;
float r21=30000.00;
float r22=7500.00;
float refvoltage2=5.0;
float involtagedisplay2=0.0;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);//voltage senor of system1
  pinMode(A1,INPUT);//voltage sensor of system2
  pinMode(11,OUTPUT);//O/P of system1
  pinMode(10,OUTPUT);//o/p of system2
  pinMode(2,OUTPUT);//DC TO AC converted o/p or input to transformer
  pinMode(3,OUTPUT);
  
}
void loop()
{
  sensorvalue1=analogRead(sensorpin1);
  adcvoltage1=(sensorvalue1*refvoltage1);
  involtage1=adcvoltage1*(r12/(r11+r12));
  involtagedisplay1=involtage1/1000;
  Serial.println(involtagedisplay1);
  delay(1000);
  sensorvalue2=analogRead(sensorpin2);
  adcvoltage2=(sensorvalue2*refvoltage2);
  involtage2=adcvoltage2*(r21/(r21+r22));
  involtagedisplay2=involtage2/1000;
  Serial.println(involtagedisplay2);
  delay(1000);
  if(involtagedisplay1<=1.35)
  {
    digitalWrite(10,HIGH);//power supplied from system2
  }
  if(involtagedisplay2<=1.35)
  {
    digitalWrite(11,HIGH);//power supplied from system1
  }
  else
  {
    digitalWrite(10,LOW);//loadshedding
    digitalWrite(11,LOW);//loadshedding
  }
  //delay(50000)
  //digitalWrite(2,HIGH);
  //digitalWrite(3,LOW);//
  //delay(9);//
  //digitalWrite(2,LOW);//
  //digitalWrite(3,LOW);//
  //delay(1);//
  //digitalWrite(2,LOW);//
  //digitalWrite(3,HIGH);//
  //delay(1);//
  //digitalWrite(2,LOW);//
  //digitalWrite(3,HIGH);//
  //delay(9);//
  //digitalWrite(2,LOW);//
  //digitalWrite(3,LOW);//
  //delay(1);//
}
