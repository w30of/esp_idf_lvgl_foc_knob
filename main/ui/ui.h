// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: dial

#ifndef _DIAL_UI_H
#define _DIAL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ui_helpers.h"
#include "ui_events.h"
#include "../usb_device/usb_device.h"
#include "../dial_power/dial_power.h"
#include "../dial/dial.h"

#define DIAL_STA_NUM 10
enum {
    UI_NULL,
    UI_MENU_INTERFACE,            /*!< Main menu select different interface */
    UI_HID_INTERFACE,            /*!< USB menu Control PC or Phone */
};
enum
{
    DIAL_STA_RELEASE,
    DIAL_STA_PRESS,
    DIAL_STA_R,
    DIAL_STA_L,
    DIAL_STA_CLICK,
    DIAL_STA_DOUBLE_CLICK,
    DIAL_STA_LONG_PRESS,
    DIAL_STA_LONG_PRESS_UP,
    DIAL_STA_P_R,
    DIAL_STA_P_L
};
typedef struct{
    uint8_t index;//current ui screen index
}_ui_state;
struct DIAL_STA_DATA {
    uint8_t hid_data[6];
};
typedef struct 
{
    uint8_t icon_id; //图标的id
    uint8_t hid_id; //hid设备id
    struct DIAL_STA_DATA dial_sta[DIAL_STA_NUM];
}UI_HID_INFO;

extern _ui_state ui_state;
extern int16_t enc_num;
extern int16_t enc_click;
void ui_send_hid_command(uint8_t hid_id,uint8_t keycode[6]);
// SCREEN:
void ui_Screen1_dial_event(uint8_t state);
void ui_Screen1_screen_init(void);
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_Screen2;
void ui_Screen2_hid_event(uint8_t state);
void ui_Screen2_screen_init(void);
extern lv_indev_t* encoder_indev;

LV_IMG_DECLARE(ui_img_bg1_png);    // assets\bg1.png
LV_IMG_DECLARE(ui_img_pc_png);    // assets\pc.png
LV_IMG_DECLARE(ui_img_poweroff_png);    // assets\poweroff.png
LV_IMG_DECLARE(ui_img_setting_png);    // assets\setting.png
LV_IMG_DECLARE(ui_img_l_r_png);    // assets\L_R.png
LV_IMG_DECLARE(ui_img_video_png);    // assets\video.png
LV_IMG_DECLARE(ui_img_dial_png);    // assets\dial.png
LV_IMG_DECLARE(ui_img_music_png);    // assets\music.png
LV_IMG_DECLARE(ui_img_wheel_png);    // assets\wheel.png
LV_IMG_DECLARE(ui_img_pointer_png);    // assets\pointer.png

LV_FONT_DECLARE(ui_font_SmileySansOblique16);
LV_FONT_DECLARE(ui_font_SmileySansOblique20);
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
