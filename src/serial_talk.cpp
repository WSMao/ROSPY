#include "serial_talk.h"

/*communication between ESP32 & 86duino*/
#include <stdarg.h>
void espSend(int type, ...){
  va_list ap;
  va_start(ap,type);  
  char *p;
  
  if(type == esp32_start){
      Serial.print("esp32_start");Serial.write('\0');
  }
  else if (type == esp32_cmd){
      Serial.print("esp32_cmd");Serial.write('\0');
      for(int i=0;i<2;i++){  //key & value
          p = va_arg(ap,char*);
          do{Serial.write(*p);}while(*p++!='\0');
      }
  }
  else if (type == esp32_print){
      Serial.print("esp32_print");Serial.write('\0');
      p = va_arg(ap,char*);
      do{Serial.write(*p);}while(*p++!='\0');
  }
  va_end(ap);
}
/*=========================================*/
