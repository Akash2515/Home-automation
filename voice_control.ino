#include<SoftwareSerial.h>
 String voice;

#define tubelight 9 // initialize to port 9
#define bulb 8      //initialize to port 8 


    

void setup() 
{
  Serial.begin(9600);
  pinMode(tubelight, OUTPUT); //tubelight is the output
  pinMode(bulb, OUTPUT);    //bulb is the output
         
   analogWrite( 10,255);
   digitalWrite(8,HIGH);
}

void loop() {
 
  while (Serial.available())  
  {                            
    delay(10);                   
    char c = Serial.read();      //reads the voice and store it in c
    if (c == '#') {break;}       
      voice += c;                  
  } 

  if (voice.length() > 0) {
    Serial.println(voice);
  
    if(voice == "all off")                            
      {
         setoff(); //make both the bulb and tubelight to off
      }  
    else if(voice == "tubelight on ")                              
      {
         analogWrite(tubelight,255); //makes tubrlight to on
     
     
      } 

    else if( voice =="tube light off")             
      {
         analogWrite(tubelight,0); //make the tube light to off
     
    
      }
    else if( voice =="bulb off")
      {
        digitalWrite(bulb,LOW); // make the bulb to off
      }
    else if(voice == "bulb")
      {
        digitalWrite(bulb,HIGH); //make the bulb to on
      }
      }

       
  
    voice="";                                                       //Reset the variable after initiating
  }

  void setoff()
    {
      
      alogWrite(tubelight,0); 
      
      digitalWrite(bulb,LOW);
    }
