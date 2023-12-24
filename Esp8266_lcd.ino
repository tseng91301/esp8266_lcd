#include "bottom_func.h"
#include "oled_setup.h"
#include "touch_button.h"
#include "oled_pic.h"

Oled oled1;
TouchButton touch1(D3,1);

int pushnum=0;
int timedelay=170;

int timenow=millis();
void setup(){
    oled1.begin();
    oled1.txt("You hasen't touch yet.");
}
void loop(){
    
    if(touch1.getval()==1){
        if(millis()-timenow>timedelay){
            pushnum++;
            timenow=millis();
            oled1.txt("You touch "+String(pushnum)+" times.");
        }
    }
}