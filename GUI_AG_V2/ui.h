
#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_SpeedSlider;
extern lv_obj_t * ui_SpeedLabel;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_dashbg_png);    // assets/dashbg.png
LV_IMG_DECLARE(ui_img_artboard_png);    // assets/Artboard.png






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
