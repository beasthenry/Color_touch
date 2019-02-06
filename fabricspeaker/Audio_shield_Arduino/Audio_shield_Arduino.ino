#include <CytronEZMP3.h>
#include <SoftwareSerial.h>

CytronEZMP3 mp3;

int touchSensor0 = 4;
//int touchSensor1 = 3;
//int touchSensor2 = 4;
//int touchSensor3 = 5;
int touchSensor4 = 6;

boolean toggle = true;


void setup() {// put your setup code here, to run once:
  Serial.begin(9600);
  if (!mp3.begin(2, 3))
 
  mp3.setDevice(2);
  mp3.setVolume(25);

  pinMode(touchSensor0, INPUT_PULLUP);
  //pinMode(touchSensor1, INPUT_PULLUP);
  //pinMode(touchSensor2, INPUT_PULLUP);
  //pinMode(touchSensor3, INPUT_PULLUP);
  pinMode(touchSensor4, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {// put your main code here, to run repeatedly:

  if (digitalRead(touchSensor0) == LOW)
  {
    if (toggle)
    {
      mp3.playTrack(1);
      digitalWrite(13,HIGH);
      //delay(50000);
      while (digitalRead(touchSensor0) == LOW);  
    }
 }

  /*if (digitalRead(touchSensor2) == LOW)
  {
    if (toggle)
    {
      mp3.playTrack(2);
      digitalWrite(13,HIGH);
      delay(8000);
      while (digitalRead(touchSensor2) == LOW);
      delay(20);
    }
  }

  if (digitalRead(touchSensor3) == LOW)
  {
    if (toggle)
    {
      mp3.playTrack(3);
      digitalWrite(13,HIGH);
      delay(8000);
      while (digitalRead(touchSensor3) == LOW);
      delay(20);
    }
  }

  if (digitalRead(touchSensor4) == LOW)
  {
    if (toggle)
    {
      mp3.playTrack(4);
      digitalWrite(13,HIGH);
      delay(8000);
      while (digitalRead(touchSensor4) == LOW);
      delay(20);
    }
  }*/
  if (digitalRead(touchSensor4) == LOW)
  {
    if (toggle)
    {
      mp3.playTrack(2);
      digitalWrite(13,HIGH);
      //delay(50000);
      while (digitalRead(touchSensor4) == LOW);
      //delay(20);
    }
  }
  else {digitalWrite(13,LOW);}
  //delay(20);
  Serial.print(touchSensor4);
}
