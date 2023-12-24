//I2C setup
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define SDA D1
#define SCL D2

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);     // 0.91吋長型螢幕使用

class Oled:public U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C{
    private:
        int addr;
        int scl_pin;
        int sda_pin;
        int width;
        int height;
    public:
        Oled(const int sda_p=D1,const int scl_p=D2,int w=128,int h=32):
            U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ scl_p, /* data=*/ sda_p)     // 0.91吋長型螢幕使用
        {
            width=w;
            height=h;
            sda_pin=sda_p;
            scl_pin=scl_p;
            begin();
        }
        void pic(const unsigned char input_pic[],int start_x=0,int start_y=0){
            clearBuffer();                    // clear the internal memory
            drawXBMP(start_x,start_y, width, height, input_pic);    //繪圖
            sendBuffer();                    // transfer internal memory to the display
        }
        void txt(String wordin,int start_x=0,int start_y=10){
            String wordin_arr[charnum(wordin,'\n')+1];
            fillarray(wordin_arr,wordin,'\n');

            clearBuffer();                    // clear the internal memory
            setFont(u8g2_font_ncenB08_tr);  // choose a suitable font
            int arrlen=sizeof(wordin_arr)/sizeof(wordin_arr[0]);
            for(int a=0;a<arrlen;a++){
                drawStr(start_x,start_y,wordin_arr[a].c_str());
                start_y+=11;
            }
            sendBuffer();                    // transfer internal memory to the display
        }
};