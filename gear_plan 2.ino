float adcvoltage=0.0;
int sensorPin=A0;
int sensorValue=0;
float involtage=0.0;
float r1=30000.00;
float r2=7500.00;
float refvoltage=5.0;

void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

 void loop()
 {sensorValue=analogRead(sensorPin);
 adcvoltage=(sensorValue*refvoltage);
 involtage=adcvoltage/(r2/(r1+r2));
  Serial.println(involtage);
  delay(1000);
}
