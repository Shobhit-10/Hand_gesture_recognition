#include <HardwareSerial.h>
#include <String.h>
#include <RBDdimmer.h>//https://github.com/RobotDynOfficial/RBDDimmer
//Parameters
const int zeroCrossPin 	= 2;
const int acdPin 	= 3;

int a=7;
int b =5;
int c = 4;

dimmerLamp acd(acdPin);
void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(acdPin,OUTPUT);
 
 
  Serial.begin(9600);

}

void loop() {
  //put your main code here, to run repeatedly:
   if (Serial.available()){
    
    String inputString = Serial.readStringUntil('\n');
   
    int number1 = inputString.substring(0, inputString.indexOf(',')).toInt();
    inputString.remove(0, inputString.indexOf(',') + 1);
    int number2 = inputString.substring(0, inputString.indexOf(',')).toInt();
    inputString.remove(0, inputString.indexOf(',') + 1);
    int number3 = inputString.toInt();
    
    if(number2==0){
      digitalWrite(a,HIGH);
      digitalWrite(c,LOW);
    }else{
      digitalWrite(a,LOW);
      digitalWrite(c,HIGH);
    }
    analogWrite(b,number1);
    
    if(number3==1){
      digitalWrite(acdPin,HIGH);
    }
    else{
      digitalWrite(acdPin,LOW); 
    }   
  
    
  }
  

}


