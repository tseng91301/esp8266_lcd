#include "bottom_func.h"
#include "oled_setup.h"
#include "touch_button.h"
#include "oled_pic.h"

Oled oled1;
//TouchButton touch1(D3,1);

int shorttimedelay=170;
int timedelay1=2000;
int timedelay2=4000;
int timedelay3=25000;

int timenow;
void setup(){
    Serial.begin(115200);
    oled1.txt("Welcome!");
    oled1.show();
    delay(1000);
    timenow=millis();
}
void loop(){
    oled1.show();
    int delta=millis()-timenow;
    if(range(delta,0,timedelay1)){
        oled1.txt("text1");
    }else if(range(delta,timedelay1,timedelay2)){
        oled1.txt("text2\nA normal string.");
    }else if(range(delta,timedelay2,timedelay3)){
        oled1.txt("text3\nThis is a string with a very long length, sometimes this will happen");
    }else if(range(delta,timedelay3)){
        timenow=millis();
    }
}