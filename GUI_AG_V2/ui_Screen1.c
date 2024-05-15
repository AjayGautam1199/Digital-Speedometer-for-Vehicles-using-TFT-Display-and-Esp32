#include "ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image1 = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Image1, &ui_img_dashbg_png);
    lv_obj_set_width(ui_Image1, 320);
    lv_obj_set_height(ui_Image1, 240);
    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SpeedSlider = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_SpeedSlider, 0, 150);
    lv_slider_set_value(ui_SpeedSlider, 100, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_SpeedSlider) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_SpeedSlider, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_SpeedSlider, 292);
    lv_obj_set_height(ui_SpeedSlider, 68);
    lv_obj_set_x(ui_SpeedSlider, 0);
    lv_obj_set_y(ui_SpeedSlider, -4);
    lv_obj_set_align(ui_SpeedSlider, LV_ALIGN_CENTER);
    lv_obj_set_style_radius(ui_SpeedSlider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SpeedSlider, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SpeedSlider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_SpeedSlider, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SpeedSlider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SpeedSlider, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_SpeedSlider, &ui_img_artboard_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_SpeedSlider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SpeedSlider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SpeedSlider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_SpeedLabel = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_SpeedLabel, 95);
    lv_obj_set_height(ui_SpeedLabel, 50);
    lv_obj_set_x(ui_SpeedLabel, -46);
    lv_obj_set_y(ui_SpeedLabel, 62);
    lv_obj_set_align(ui_SpeedLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SpeedLabel, "100");
    lv_obj_set_style_text_color(ui_SpeedLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SpeedLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SpeedLabel, &lv_font_montserrat_44, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SpeedLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SpeedLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SpeedLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

}
