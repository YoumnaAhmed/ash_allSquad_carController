// C++ code
//Project was done in a zoom meeting with the entire squad 
#define forward 13
#define backward 12
#define rightRotate 8
#define leftRotate 7
#define leftIn1 11
#define leftIn2 10
#define rightIn1 6
#define rightIn2 4
#define enLeft 5
#define enRight 3

void setup()
{
 pinMode(forward,INPUT_PULLUP); // INPUT_PULLUP : to prevent floating
 pinMode(backward,INPUT_PULLUP);
 pinMode(rightRotate,INPUT_PULLUP);
 pinMode(leftRotate,INPUT_PULLUP);
 pinMode(leftIn1,OUTPUT);
 pinMode(leftIn2,OUTPUT);
 pinMode(rightIn1,OUTPUT);
 pinMode(rightIn2,OUTPUT);
 pinMode(enLeft,OUTPUT);
 pinMode(enRight,OUTPUT);
}

void loop()
{
 while(!digitalRead(forward)) //while button is low both motors rotate counter clockwise
 { delay(10);   // delay for debouncing
  digitalWrite(leftIn1,HIGH);
  digitalWrite(rightIn1,HIGH);
  digitalWrite(leftIn2,LOW);
  digitalWrite(rightIn2,LOW);
  analogWrite(enLeft,255);
  analogWrite(enRight,255);
  
 }
 while(!digitalRead(backward))//while button is low both motors rotate clockwise
 { delay(10);
  digitalWrite(leftIn1,LOW);
  digitalWrite(rightIn1,LOW);
  digitalWrite(leftIn2,HIGH);
  digitalWrite(rightIn2,HIGH);
  analogWrite(enLeft,255);
  analogWrite(enRight,255);
 }
  while(!digitalRead(rightRotate))//while button is low,left motor is on and the right motor is off
 { delay(10);
  digitalWrite(leftIn1,HIGH);
  digitalWrite(rightIn1,LOW);
  digitalWrite(leftIn2,LOW);
  digitalWrite(rightIn2,LOW);
  analogWrite(enLeft,255);
  analogWrite(enRight,0);
 }
  while(!digitalRead(leftRotate))//while button is low,right motor is on and the left motor is off
 { delay(10);
  digitalWrite(leftIn1,LOW);
  digitalWrite(rightIn1,HIGH);
  digitalWrite(leftIn2,LOW);
  digitalWrite(rightIn2,LOW);
  analogWrite(enLeft,0);
  analogWrite(enRight,255);
 }
  analogWrite(enLeft,0);  //to stop all motors after button release
  analogWrite(enRight,0);


 

}
