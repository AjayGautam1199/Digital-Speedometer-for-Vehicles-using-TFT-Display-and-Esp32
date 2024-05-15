#include <lvgl.h>
#include <LovyanGFX.hpp>
#include "ui.h"

class LGFX : public lgfx::LGFX_Device
{
lgfx::Panel_ILI9341    _panel_instance; //9341
lgfx::Bus_SPI       _bus_instance;  
lgfx::Light_PWM     _light_instance;
//lgfx::Touch_XPT2046     _touch_instance;

public:
  LGFX(void)
  {
    { 
      auto cfg = _bus_instance.config();  
      cfg.spi_host = SPI3_HOST;  // VSPI_HOST; 
      cfg.spi_mode = 0;             
      cfg.freq_write = 40000000;    
      cfg.freq_read  = 16000000;    
      cfg.spi_3wire  = false;       
      cfg.use_lock   = true;        
      cfg.dma_channel = 1;        
      cfg.pin_sclk = D8;    //18  14      
      cfg.pin_mosi = D10;      //23    13
      cfg.pin_miso = D9;          //19  12
      cfg.pin_dc   = D5;         //2    
      _bus_instance.config(cfg);    
      _panel_instance.setBus(&_bus_instance);    
    }

    { 
      auto cfg = _panel_instance.config();   
      cfg.pin_cs           =   D7;   //15
      cfg.pin_rst          =    D6;    //4
      cfg.pin_busy         =    -1;  
      // cfg.memory_width     =   240; 
      // cfg.memory_height    =   320; 
      cfg.panel_width      =   240; 
      cfg.panel_height     =   320; 
      cfg.offset_x         =     0;  
      cfg.offset_y         =     0; 
      cfg.offset_rotation  =     0; 
      cfg.dummy_read_pixel =     8; 
      cfg.dummy_read_bits  =     1;  
      cfg.readable         =  true;  
      cfg.invert           = false;  
      cfg.rgb_order        = false;  
      cfg.dlen_16bit       = false; 
      cfg.bus_shared       =  true;  

      _panel_instance.config(cfg);
    }
    
    { 
      auto cfg = _light_instance.config();   

      //cfg.pin_bl = 21;          
      cfg.invert = false;         
      cfg.freq   = 44100;         
      cfg.pwm_channel = 7;         

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance); 
    }

    // { 
    //   auto cfg = _touch_instance.config();
    //   cfg.x_min      = 0;   
    //   cfg.x_max      = 239;  
    //   cfg.y_min      = 0;   
    //   cfg.y_max      = 319; 
    //   cfg.pin_int    = -1; 
    //   cfg.bus_shared = true;
    //   cfg.offset_rotation = 0;
    //   cfg.spi_host = VSPI_HOST;
    //   cfg.freq = 1000000;    
    //   cfg.pin_sclk = 18;   
    //   cfg.pin_mosi = 23;     
    //   cfg.pin_miso = 19;    
    //   cfg.pin_cs   = 5;     //0
    //   _touch_instance.config(cfg);
    //   _panel_instance.setTouch(&_touch_instance);  
    // }
    setPanel(&_panel_instance); 
  }
};

static LGFX tft;
/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320; 
static const uint16_t screenHeight = 240;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];
//TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    //tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
// void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
// {
//     uint16_t touchX = 0, touchY = 0;

//     bool touched = false;//tft.getTouch( &touchX, &touchY, 600 );

//     if( !touched )
//     {
//         data->state = LV_INDEV_STATE_REL;
//     }
//     else
//     {
//         data->state = LV_INDEV_STATE_PR;

//         /*Set the coordinates*/
//         data->point.x = touchX;
//         data->point.y = touchY;

//         Serial.print( "Data x " );
//         Serial.println( touchX );

//         Serial.print( "Data y " );
//         Serial.println( touchY );
//     }
// }

void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */
    tft.begin();          /* TFT init */
    tft.setRotation( 3 ); /* Landscape orientation, flipped */
    lv_init();

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth *10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    // static lv_indev_drv_t indev_drv;
    // lv_indev_drv_init( &indev_drv );
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // indev_drv.read_cb = my_touchpad_read;
    // lv_indev_drv_register( &indev_drv );


    ui_init();
    Serial.println( "Setup done Bro!" );
}
void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}