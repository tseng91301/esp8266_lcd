#include "bottom_func.h"
#include "oled_setup.h"
#include "touch_button.h"
#include "oled_pic.h"

Oled oled1;
TouchButton touch1(D3,1);

int shorttimedelay=170;
int timedelay1=1000;
int timedelay2=2000;
int timedelay3=3000;

int timenow;
void setup(){
    oled1.txt("You hasen't touch yet.");
    timenow=millis();
}
void loop(){
    int delta=millis()-timenow;
    oled1.txt("Push duration: "+String(delta));
    if(touch1.getval()==1){
        if(millis()-timenow>timedelay3){
            timenow=millis();
            oled1.txt("You touch for 3 seconds.");
            delay(1000);
            setup();
        }
    }else{
        
        if(delta<shorttimedelay){
            timenow=millis();
        }
        if(delta>=shorttimedelay&&delta<timedelay1){
            oled1.txt("You touch short time.");
            delay(1000);
            setup();
        }
        if(delta>=timedelay1&&delta<timedelay2){
            oled1.txt("You touch for 1 second.");
            delay(1000);
            setup();
        }
        if(delta>=timedelay2&&delta<timedelay3){
            oled1.txt("You touch for 2 seconds.");
            delay(1000);
            setup();
        }
    }
}