int soundPin=13; // Output PIN to Amplifier
bool pirFlag=true;
void setup() {

Serial.begin(9600);
pinMode(2,INPUT); //Input From PIR
noTone(soundPin);
}

void loop() {
 
if((digitalRead(2)==HIGH)&&(pirFlag==true)) //If PIR Senses Turn on the speaker for 5 sec
{
  tone(soundPin,40000,10000);
  noTone(soundPin);
}

while(Serial.available())
{
//  unsigned int tonefreq=Serial.read();
//  
String getfreq=Serial.readStringUntil('\n');
  //Serial.println(tonefreq);
//if (isdigit(getfreq))
{
  unsigned int tonefreq=getfreq.toInt();
  if(tonefreq==0)
  {
    noTone(soundPin);
    pirFlag=true;
  }
  else
  {
    tone(soundPin,tonefreq);
    pirFlag=false;
    Serial.println(tonefreq);
  }
}
}
}
