import processing.serial.*;
import processing.sound.*;

Serial port;
float r,g,b,c;
int lf=10;
String myString;
String[] data;

SoundFile file1, file2, file3, file4, file5, file6, file7;

void setup(){
 size(200,200);
 port = new Serial(this, "/dev/cu.usbmodem14201", 115200); //remember to replace COM20 with the appropriate serial port on your computer
 port.bufferUntil(lf);
 file1 = new SoundFile(this, "files/a.wav");
}
 
void draw(){
  background(r, g, b);
  if(g<=50){
   file1.play(); 
  }
}

void serialEvent(Serial port){
  //String myString = port.readStringUntil(lf);
 myString = port.readString();
  // String dataInput=myString.trim();
   //r = myString[0];
     data= splitTokens(myString, ",");
    //float[] colorValue= float(data);
  //print(myString);
 // print(data);
  //float r = float(myString);
  if(myString != null){
    //if(data[1] != null){
    //print(data[1]);
    //}
    
    if(data.length>1){
      r= float(data[0]);
      g= float(data[1]);
      b= float(data[2]);
      c= float(data[3]);
      r = r/c*256;
      g = g/c*256;
      b = b/c*256;
    print(r);
    print(",");
    print(g);
    print(",");
    print(b);
    println();
    }
  }
}
