
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 64
char str[BUF_SIZE]="";

void getWord(char *p, int bufsize){
  char c;
  //Serial.print("read: ");
  while(Serial1.available() > 0){
    *p= c= Serial1.read();
    //Serial.print((int)c);
    p++;
    if(isspace(c)) {
      //Serial.println("isspace");
      break;}
    if(c=='\0') {
      //Serial.println("\\0is end");
      break;}
    if(--bufsize==1) {
      //Serial.println("bufsize 0");
      break;}
    delay(1);
  }
  *p='\0';
}

#include <Servo86.h>
Servo myservo1; 
Servo myservo2;
 
int pos1 = 80;
int pos2 = 80;    
int ch=0;


void motorControl(){
  int val;
  getWord(str,BUF_SIZE);
  if(strcmp(str,"turn")==0){
    Serial.print("turn:");
    getWord(str,BUF_SIZE);
    
    val = atoi(str);
    if(val==0) val=80;
    else if(val>0)val+=85;
    else val+=75;

    myservo1.write(val);
    Serial.print("val");Serial.println(val);
  }
  
  else if(strcmp(str,"move")==0){
    Serial.print("move:");
    getWord(str,BUF_SIZE);
    
    val = atoi(str);
    if(val==0) val=80;
    else if(val>0)val=75-val;
    else val=85-val;

    myservo2.write(val);
    Serial.print("val");Serial.println(val);
  }
  delay(10);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial.println("ready");
  //motor setup
  myservo1.attach(6);
  myservo2.attach(9);
}

void loop() {
  
  if(Serial1.available() >0){
    getWord(str,BUF_SIZE);
    //Serial.print(str);
    
    if(strcmp(str,"esp32_start")==0){
      Serial.println("\nOK Let's Go!");
    }
    else if (strcmp(str,"esp32_cmd")==0){
      Serial.print("\ncommand:  ");
      motorControl();
    }
    else if(strcmp(str,"esp32_print")==0){
      Serial.print("\nesp32_print: ");
    }
    else{
      Serial.print(str);
    }
  }
}
