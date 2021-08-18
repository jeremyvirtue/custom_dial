#ifndef __CUSTOM_DIAL_HEAD_H
#define __CUSTOM_DIAL_HEAD_H

#include "stdint.h"


 struct _custom_dial_image//纯图片
{
  uint8_t type;
  uint16_t x;//左上角x坐标
  uint16_t y;//左上角y坐标
  uint32_t img_addr;//图片nandflash相对地址
};
typedef struct _custom_dial_image custom_dial_image;

struct _custom_dial_pointer//指针类型
{
  uint8_t  type; 
  uint8_t  data_type;//指针数据类型
  uint16_t x;   //左上角x坐标
  uint16_t y;   //左上角y坐标
  uint32_t img_addr;    //图片nandflash相对地址
  uint16_t img_heigth;  //图片高度
  uint16_t img_width;   //图片宽度
  uint16_t start_arc;   //指针开始角度
  uint16_t end_arc;     //指针结束角度
  uint16_t rotation_center_x;//指针相对旋转坐标x
  uint16_t rotation_center_y;//指针相对旋转坐标y
  
};
typedef struct _custom_dial_pointer custom_dial_pointer;

struct _custom_dial_arc_bar{ //圆形进度条
  uint8_t  type;
  uint8_t  data_type;//数据类型
  uint16_t x;//左上角x坐标
  uint16_t y;//左上角y坐标
  uint16_t width;     //圆弧宽度 有多粗
  uint8_t  bar_rgb[3];  //rgb
  uint8_t  diamater;      //直径 包括圆弧宽度
  uint16_t start_arc;   //开始角度
  uint16_t max_angle;     //最大转动角度
};
typedef struct _custom_dial_arc_bar custom_dial_arc_bar;

//条形进度条
struct _custom_dial_chart_bar
{
  uint8_t type;
  uint8_t data_type;//数据类型
  uint16_t x;//左上角x坐标
  uint16_t y;//左上角y坐标
  uint16_t width;     //条形宽度
  uint16_t heigth;    //条形高度
  uint8_t  bar_rgb[3];  //rgb
};
typedef struct _custom_dial_chart_bar custom_dial_chart_bar;

//表盘文本
struct _custom_dial_text
{
  uint8_t  type;
  uint8_t  data_type;  //数据类型
  uint16_t x;          //左上角x坐标
  uint16_t y;          //左上角y坐标
  uint8_t  text_width; //文本宽度
  uint8_t  text_rgb[3];//字体RGB
  uint8_t  text_align; //对齐方式
  uint8_t  text_size;  //字体大小
	uint8_t  text_custom[20];//自定义文本
};
typedef struct _custom_dial_text custom_dial_text;

//多图
struct _custom_dial_more_img{
  uint8_t type;
  uint8_t data_type;  //数据类型
  uint16_t x;         //左上角x坐标
  uint16_t y;         //左上角y坐标 
  uint32_t img_addr[50];    //图片nandflash相对地址
	uint8_t  data_mode;//0:保留0 位置不变 1：删除空余的0 位置左靠  2：删除空余的0 数据右靠
};
typedef struct _custom_dial_more_img custom_dial_more_img;

//
enum _enum_custom_dial_type{
	dial_type_null = 0,
	dial_type_image,
	dial_type_pointer,
	dial_type_arc_bar,
	dial_type_chart_bar,
	dial_type_text,
	dial_type_more_img,
};
typedef enum _enum_custom_dial_type enum_custom_dial_type;

enum _enum_custom_dial_data_pointer{//指针数据类型
	dial_data_pointer_null,
	dial_data_hour_pointer,
	dial_data_min_pointer,
	dial_data_sec_pointer, 
 
};
typedef enum _enum_custom_dial_data_pointer enum_custom_dial_data_pointer;

enum _enum_custom_dial_data_more_img{//多图数据类型
	dial_data_more_img_null = 0,

	dial_data_hour_high = 1,	//时钟高位
	dial_data_hour_low = 2,   //时钟低位
	dial_data_min_high = 3,		//分钟高位
	dial_data_min_low = 4,		//分钟低位 
	dial_data_img_gif = 5,		//gif

	dial_data_img_weather = 6,	//天气
	dial_data_morning_night = 7,//早上中午晚上

	dial_data_month_high = 8,//日期月十位
	dial_data_month_low = 9,//日期月个位
	dial_data_date_high = 10,//日期日个位
	dial_data_date_low = 11,//日期日个位

	dial_data_heart_hundreds = 12,//心率百位
	dial_data_heart_ten = 13,//心率十位
	dial_data_heart_one = 14,//心率个位

	dial_data_step_ten_thousands = 15,//步数万位
	dial_data_step_thousands = 16,//步数千位
	dial_data_step_hundreds = 17,//步数百位
	dial_data_step_ten = 18,//步数十位
	dial_data_step_one = 19,//步数个位


};
typedef enum _enum_custom_dial_data_more_img enum_custom_dial_data_more_img;



 enum _enum_custom_text_data//文本数据类型
 {
	dial_data_text_null = 0,
	dial_data_text_hour_high,	//时钟高位
	dial_data_text_hour_low,   //时钟低位
	dial_data_text_min_high,		//分钟高位
	dial_data_text_min_low,		//分钟低位 
	dial_data_text_heart,//心率
	dial_data_text_year,//年（数字）
	dial_data_text_month,//月 01 02 12（个位前面有个0）
	dial_data_text_day,//日 01 01 12（个位前面有个0）
	dial_data_text_week,//仅支持英文 MON FRI SUN...
	dial_data_text_week_lanuguage,//支持多语言 仅支持20 24 30文本大小 日 一 二 三 ...
	dial_data_text_high_tem,//最大温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_low_tem,//最小温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_now_tem,//当前温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_step,	 //当前步数
	dial_data_text_sleep,  //睡眠时间
	dial_data_text_run_time, //运动时间
	dial_data_text_kal,			//卡路里
	dial_data_text_power,			//当前电量 数字 后面加个%
	dial_data_text_custom,//自定义文本 20个char大小
  dial_data_text_am_pm,//am or pm
};
typedef enum _enum_custom_text_data enum_custom_text_data;


 enum _enum_custom_arc_type//圆弧数据类型
 {
	dial_data_arc_null = 0,
	dial_data_arc_step = 1,//步数
	dial_data_arc_kal = 2,//卡路里

};
typedef enum _enum_custom_arc_type enum_custom_arc_type;

enum _enum_custom_text_size//文本类型大小
{
	dial_data_text_size_null = 0,

	dial_data_16x16_ext,//不支持多语言
	dial_data_20x20_ext,
	dial_data_24x24_ext,
	dial_data_30x30_ext,
	dial_data_40x40_ext,//不支持多语言
	dial_data_50x50_ext,//不支持多语言
	dial_data_60x60_ext,//不支持多语言
	dial_data_80x80_ext,//不支持多语言
};
typedef enum _enum_custom_text_size enum_custom_text_size;




#define EXT_FLASH_BMP_BASE						(0x01bb0e00UL)
#define EXT_FLASH_PNG_BASE						(0x020ce530UL)
#define EXT_FLASH_0804_BASE           (0x03AA0000UL)			//R0.2  size:0x580000


#define      alarm_start_icon_160x154_png                                                                         (EXT_FLASH_BMP_BASE+0x00)
#define      call_button_answer_150x60_png                                                                      (EXT_FLASH_BMP_BASE+0xC084)
#define      call_button_reject_150x60_png                                                                     (EXT_FLASH_BMP_BASE+0x106D8)
#define      connect_button_cancel_150x60_png                                                                  (EXT_FLASH_BMP_BASE+0x14D2C)
#define      connect_button_define_150x60_png                                                                  (EXT_FLASH_BMP_BASE+0x19380)
#define      connect_icon_failed_152x210_png                                                                   (EXT_FLASH_BMP_BASE+0x1D9D4)
#define      connect_icon_success_152x210_png                                                                  (EXT_FLASH_BMP_BASE+0x2D338)
#define      ota_icon_40x40_png                                                                                (EXT_FLASH_BMP_BASE+0x3CC9C)
#define      remind_customize_200x200_png                                                                      (EXT_FLASH_BMP_BASE+0x3D920)
#define      reminder_icon_goal_calorise_200x200_png                                                           (EXT_FLASH_BMP_BASE+0x511A4)
#define      reminder_icon_goal_distance_200x200_png                                                           (EXT_FLASH_BMP_BASE+0x64A28)
#define      reminder_icon_goal_step_200x200_png                                                               (EXT_FLASH_BMP_BASE+0x782AC)
#define      reminder_icon_goal_times_200x200_png                                                              (EXT_FLASH_BMP_BASE+0x8BB30)
#define      reminder_icon_low_power_200x200_png                                                               (EXT_FLASH_BMP_BASE+0x9F3B4)
#define      reminder_icon_meal_200x200_png                                                                    (EXT_FLASH_BMP_BASE+0xB2C38)
#define      reminder_icon_medicine_200x200_png                                                                (EXT_FLASH_BMP_BASE+0xC64BC)
#define      reminder_icon_rest_time_200x200_png                                                               (EXT_FLASH_BMP_BASE+0xD9D40)
#define      reminder_icon_sedentary_200x200_png                                                               (EXT_FLASH_BMP_BASE+0xED5C4)
#define      reminder_icon_sleep_200x200_png                                                                  (EXT_FLASH_BMP_BASE+0x100E48)
#define      reminder_icon_work_rest_200x200_png                                                              (EXT_FLASH_BMP_BASE+0x1146CC)
#define      reminder_icon_workout_200x200_png                                                                (EXT_FLASH_BMP_BASE+0x127F50)
#define      workout_icon_climb_60x60_png                                                                     (EXT_FLASH_BMP_BASE+0x13B7D4)
#define      workout_icon_hike_60x60_png                                                                      (EXT_FLASH_BMP_BASE+0x13D3F8)
#define      workout_icon_indoorcycle_60x60_png                                                               (EXT_FLASH_BMP_BASE+0x13F01C)
#define      workout_icon_indoorwalk_60x60_png                                                                (EXT_FLASH_BMP_BASE+0x140C40)
#define      workout_icon_oudoorcycle_60x60_png                                                               (EXT_FLASH_BMP_BASE+0x142864)
#define      workout_icon_outdoorwalk_60x60_png                                                               (EXT_FLASH_BMP_BASE+0x144488)
#define      workout_icon_strenght_60x60_png                                                                  (EXT_FLASH_BMP_BASE+0x1460AC)
#define      workout_icon_Trailrunning_60x60_png                                                              (EXT_FLASH_BMP_BASE+0x147CD0)
#define      workout_iconindoorrun_60x60_png                                                                  (EXT_FLASH_BMP_BASE+0x1498F4)
#define      workout_iocn_outdoorrun_60x60_png                                                                (EXT_FLASH_BMP_BASE+0x14B518)
#define      workout_records_icon_avg_cadence_50x50_png                                                       (EXT_FLASH_BMP_BASE+0x14D13C)
#define      workout_records_icon_avg_pace_50x50_png                                                          (EXT_FLASH_BMP_BASE+0x14E4C8)
#define      workout_records_icon_avg_speed_50x50_png                                                         (EXT_FLASH_BMP_BASE+0x14F854)
#define      workout_records_icon_avg_stride_50x50_png                                                        (EXT_FLASH_BMP_BASE+0x150BE0)
#define      workout_records_icon_Calories_50x50_png                                                          (EXT_FLASH_BMP_BASE+0x151F6C)
#define      workout_records_icon_distance_50x50_png                                                          (EXT_FLASH_BMP_BASE+0x1532F8)
#define      workout_records_icon_fastest_50x50_png                                                           (EXT_FLASH_BMP_BASE+0x154684)
#define      workout_records_icon_max_20x20_png                                                               (EXT_FLASH_BMP_BASE+0x155A10)
#define      workout_records_icon_min_20x20_png                                                               (EXT_FLASH_BMP_BASE+0x155D34)
#define      workout_records_icon_step_50x50_png                                                              (EXT_FLASH_BMP_BASE+0x156058)
#define      workout_records_icon_time_50x50_png                                                              (EXT_FLASH_BMP_BASE+0x1573E4)
#define      workout_icon_heart_rate_icon_40x40_png                                                           (EXT_FLASH_BMP_BASE+0x158770)
#define      workout_start_climb_120x120_png                                                                  (EXT_FLASH_BMP_BASE+0x1593F4)
#define      workout_start_exercise_120x120_png                                                               (EXT_FLASH_BMP_BASE+0x160478)
#define      workout_start_fail_button_cancel_60x60_png                                                       (EXT_FLASH_BMP_BASE+0x1674FC)
#define      workout_start_fail_button_define_60x60_png                                                       (EXT_FLASH_BMP_BASE+0x169120)
#define      workout_start_hike_120x120_png                                                                   (EXT_FLASH_BMP_BASE+0x16AD44)
#define      workout_start_icon_gps_bad_40x40_png                                                             (EXT_FLASH_BMP_BASE+0x171DC8)
#define      workout_start_icon_gps_good_40x40_png                                                            (EXT_FLASH_BMP_BASE+0x172A4C)
#define      workout_start_icon_gps_normal_40x40_png                                                          (EXT_FLASH_BMP_BASE+0x1736D0)
#define      workout_start_icon_gps_nosignal_40x40_png                                                        (EXT_FLASH_BMP_BASE+0x174354)
#define      workout_start_indoorcycle_120x120_png                                                            (EXT_FLASH_BMP_BASE+0x174FD8)
#define      workout_start_indoorrun_120x120_png                                                              (EXT_FLASH_BMP_BASE+0x17C05C)
#define      workout_start_indoorwalk_120x120_png                                                             (EXT_FLASH_BMP_BASE+0x1830E0)
#define      workout_start_oudoorcycle_120x120_png                                                            (EXT_FLASH_BMP_BASE+0x18A164)
#define      workout_start_outdoorrun_120x120_png                                                             (EXT_FLASH_BMP_BASE+0x1911E8)
#define      workout_start_outdoorwalk_120x120_png                                                            (EXT_FLASH_BMP_BASE+0x19826C)
#define      workout_start_pused_bg_320x320_png                                                               (EXT_FLASH_BMP_BASE+0x19F2F0)
#define      workout_start_Trailrunning_120x120_png                                                           (EXT_FLASH_BMP_BASE+0x1D12F4)
#define      wf1_bg_320x320_png                                                                               (EXT_FLASH_BMP_BASE+0x1D8378)
#define      breath_finish_icon_60x60_png                                                                     (EXT_FLASH_BMP_BASE+0x20A37C)
#define      activity_all_320x320_png                                                                         (EXT_FLASH_BMP_BASE+0x20BFA0)
#define      activity_bg_320x320_png                                                                          (EXT_FLASH_BMP_BASE+0x23DFA4)
#define      detail_icon_Calories_50x50_png                                                                   (EXT_FLASH_BMP_BASE+0x26FFA8)
#define      detail_icon_distance_50x50_png                                                                   (EXT_FLASH_BMP_BASE+0x271334)
#define      detail_icon_step_50x50_png                                                                       (EXT_FLASH_BMP_BASE+0x2726C0)
#define      detail_icon_time_50x50_png                                                                       (EXT_FLASH_BMP_BASE+0x273A4C)
#define      stopwatch_button_cancel_150x60_png                                                               (EXT_FLASH_BMP_BASE+0x274DD8)
#define      stopwatch_button_start_150x60_png                                                                (EXT_FLASH_BMP_BASE+0x27942C)
#define      timer_option_png                                                                                 (EXT_FLASH_BMP_BASE+0x27DA80)
#define      timer_button_cancel_60x60_png                                                                    (EXT_FLASH_BMP_BASE+0x285784)
#define      timer_button_pause_60x60_png                                                                     (EXT_FLASH_BMP_BASE+0x2873A8)
#define      timer_start_60x60_png                                                                            (EXT_FLASH_BMP_BASE+0x288FCC)
#define      timer_tab_custom_280x50_png                                                                      (EXT_FLASH_BMP_BASE+0x28ABF0)
#define      load_00000_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x291954)
#define      load_00001_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x294B58)
#define      load_00002_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x297D5C)
#define      load_00003_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x29AF60)
#define      load_00004_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x29E164)
#define      load_00005_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2A1368)
#define      load_00006_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2A456C)
#define      load_00007_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2A7770)
#define      load_00008_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2AA974)
#define      load_00009_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2ADB78)
#define      load_00010_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2B0D7C)
#define      load_00011_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2B3F80)
#define      load_00012_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2B7184)
#define      load_00013_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2BA388)
#define      load_00014_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2BD58C)
#define      load_00015_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2C0790)
#define      load_00016_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2C3994)
#define      load_00017_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2C6B98)
#define      load_00018_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2C9D9C)
#define      load_00019_80x80_png                                                                             (EXT_FLASH_BMP_BASE+0x2CCFA0)
#define      battery_icon_0_40x40_png                                                                         (EXT_FLASH_BMP_BASE+0x2D01A4)
#define      battery_icon_30_40x40_png                                                                        (EXT_FLASH_BMP_BASE+0x2D0E28)
#define      battery_icon_50_40x40_png                                                                        (EXT_FLASH_BMP_BASE+0x2D1AAC)
#define      battery_icon_80_40x40_png                                                                        (EXT_FLASH_BMP_BASE+0x2D2730)
#define      battery_icon_100_40x40_png                                                                       (EXT_FLASH_BMP_BASE+0x2D33B4)
#define      blue_teeth_off_icon_40x40_png                                                                    (EXT_FLASH_BMP_BASE+0x2D4038)
#define      blue_teeth_on_icon_40x40_png                                                                     (EXT_FLASH_BMP_BASE+0x2D4CBC)
#define      quick_alarm_100x80_png                                                                           (EXT_FLASH_BMP_BASE+0x2D5940)
#define      quick_brightness_100x80_png                                                                      (EXT_FLASH_BMP_BASE+0x2D97C4)
#define      quick_findphone_100x80_png                                                                       (EXT_FLASH_BMP_BASE+0x2DD648)
#define      quick_nodisturb_100x80_png                                                                       (EXT_FLASH_BMP_BASE+0x2E14CC)
#define      quick_nodisturb_on_100x80_png                                                                    (EXT_FLASH_BMP_BASE+0x2E5350)
#define      quick_setting_100x80_png                                                                         (EXT_FLASH_BMP_BASE+0x2E91D4)
#define      weather_icon_clear_40x40_png                                                                     (EXT_FLASH_BMP_BASE+0x2ED058)
#define      weather_icon_clear_night_40x40_png                                                               (EXT_FLASH_BMP_BASE+0x2EDCDC)
#define      weather_icon_cloudy_40x40_png                                                                    (EXT_FLASH_BMP_BASE+0x2EE960)
#define      weather_icon_gloomy_40x40_png                                                                    (EXT_FLASH_BMP_BASE+0x2EF5E4)
#define      weather_icon_heavy_rain_40x40_png                                                                (EXT_FLASH_BMP_BASE+0x2F0268)
#define      weather_icon_light_snow_40x40_png                                                                (EXT_FLASH_BMP_BASE+0x2F0EEC)
#define      weather_icon_moderate_rain_40x40_png                                                             (EXT_FLASH_BMP_BASE+0x2F1B70)
#define      weather_icon_moderate_snow_40x40_png                                                             (EXT_FLASH_BMP_BASE+0x2F27F4)
#define      weather_icon_showers_dizzle_40x40_png                                                            (EXT_FLASH_BMP_BASE+0x2F3478)
#define      weather_icon_thunderstorm_40x40_png                                                              (EXT_FLASH_BMP_BASE+0x2F40FC)
#define      stopwatch_iocn_png                                                                               (EXT_FLASH_BMP_BASE+0x2F4D80)
#define      stopwatch_button_mark_png                                                                        (EXT_FLASH_BMP_BASE+0x2F69A4)
#define      stopwatch_button_pause_png                                                                       (EXT_FLASH_BMP_BASE+0x2FAFF8)
#define      stopwatch_button_restart_png                                                                     (EXT_FLASH_BMP_BASE+0x2FF64C)
#define      stopwatch_button_satrt_png                                                                       (EXT_FLASH_BMP_BASE+0x303CA0)
#define      alarm_button_close_40x40_png                                                                     (EXT_FLASH_BMP_BASE+0x3082F4)
#define      alarm_button_open_40x40_png                                                                      (EXT_FLASH_BMP_BASE+0x308F78)
#define      brightness_button_60x60_png                                                                      (EXT_FLASH_BMP_BASE+0x309BFC)
#define      brightness_button__60x60_png                                                                     (EXT_FLASH_BMP_BASE+0x30B820)
#define      brightness_button__disabled_60x60_png                                                            (EXT_FLASH_BMP_BASE+0x30D444)
#define      brightness_button_disabled_60x60_png                                                             (EXT_FLASH_BMP_BASE+0x30F068)
#define      Dial_settings_big1_160x160_png                                                                   (EXT_FLASH_BMP_BASE+0x310C8C)
#define      Dial_settings_big2_160x160_png                                                                   (EXT_FLASH_BMP_BASE+0x31D490)
#define      Dial_settings_big3_160x160_png                                                                   (EXT_FLASH_BMP_BASE+0x329C94)
#define      Dial_settings_little1_120x120_png                                                                (EXT_FLASH_BMP_BASE+0x336498)
#define      Dial_settings_little2_120x120_png                                                                (EXT_FLASH_BMP_BASE+0x33D51C)
#define      Dial_settings_little3_120x120_png                                                                (EXT_FLASH_BMP_BASE+0x3445A0)
#define      reset_button_cancel_png                                                                          (EXT_FLASH_BMP_BASE+0x34B624)
#define      reset_button_define_png                                                                          (EXT_FLASH_BMP_BASE+0x34D248)
#define      rest_sceen_button_60x60_png                                                                      (EXT_FLASH_BMP_BASE+0x34EE6C)
#define      rest_sceen_button__60x60_png                                                                     (EXT_FLASH_BMP_BASE+0x350A90)
#define      rest_sceen_button__disabled_60x60_png                                                            (EXT_FLASH_BMP_BASE+0x3526B4)
#define      rest_sceen_button_disabled_60x60_png                                                             (EXT_FLASH_BMP_BASE+0x3542D8)
#define      rest_sceen_icon_50x50_png                                                                        (EXT_FLASH_BMP_BASE+0x355EFC)
#define      setting_option_icon_more_png                                                                     (EXT_FLASH_BMP_BASE+0x357288)
#define      setting_reboot_button_80x80_png                                                                  (EXT_FLASH_BMP_BASE+0x357F0C)
#define      setting_shut_down_button_80x80_png                                                               (EXT_FLASH_BMP_BASE+0x35B110)
#define      stteting_icon_aboutus_60x60_png                                                                  (EXT_FLASH_BMP_BASE+0x35E314)
#define      stteting_icon_Long_press_60x60_png                                                               (EXT_FLASH_BMP_BASE+0x35FF38)
#define      stteting_icon_Reboot_60x60_png                                                                   (EXT_FLASH_BMP_BASE+0x361B5C)
#define      stteting_icon_reset_60x60_png                                                                    (EXT_FLASH_BMP_BASE+0x363780)
#define      stteting_icon_screen_60x60_png                                                                   (EXT_FLASH_BMP_BASE+0x3653A4)
#define      stteting_icon_shut_down_60x60_png                                                                (EXT_FLASH_BMP_BASE+0x366FC8)
#define      stteting_icon_time_60x60_png                                                                     (EXT_FLASH_BMP_BASE+0x368BEC)
#define      Menstrual_Cycle_bg_320x320_png                                                                   (EXT_FLASH_BMP_BASE+0x36A810)
#define      Menstrual_Cycle_date_blue_8x8_png                                                                (EXT_FLASH_BMP_BASE+0x39C814)
#define      Menstrual_Cycle_date_gray_8x8_png                                                                (EXT_FLASH_BMP_BASE+0x39C898)
#define      Menstrual_Cycle_date_pink_8x8_png                                                                (EXT_FLASH_BMP_BASE+0x39C91C)
#define      Menstrual_Cycle_icon_120x120_png                                                                 (EXT_FLASH_BMP_BASE+0x39C9A0)
#define      Menstrual_Cycle_today_blue_24x24_png                                                             (EXT_FLASH_BMP_BASE+0x3A3A24)
#define      Menstrual_Cycle_today_gray_24x24_png                                                             (EXT_FLASH_BMP_BASE+0x3A3EA8)
#define      Menstrual_Cycle_today_pink_24x24_png                                                             (EXT_FLASH_BMP_BASE+0x3A432C)
#define      sleep_bg_320x320_png                                                                             (EXT_FLASH_BMP_BASE+0x3A47B0)
#define      sleep_detail_icon_awake_60x60_png                                                                (EXT_FLASH_BMP_BASE+0x3D67B4)
#define      sleep_detail_icon_deep_60x60_png                                                                 (EXT_FLASH_BMP_BASE+0x3D83D8)
#define      sleep_detail_icon_light_60x60_png                                                                (EXT_FLASH_BMP_BASE+0x3D9FFC)
#define      sleep_detail_icon_nap_60x60_png                                                                  (EXT_FLASH_BMP_BASE+0x3DBC20)
#define      sleep_detail_icon_REM_60x60_png                                                                  (EXT_FLASH_BMP_BASE+0x3DD844)
#define      sleep_icon_50x50_png                                                                             (EXT_FLASH_BMP_BASE+0x3DF468)
#define      wearth_bg_snow_320_161_png                                                                       (EXT_FLASH_BMP_BASE+0x3E07F4)
#define      wearth_bg_cloud_320x121_png                                                                      (EXT_FLASH_BMP_BASE+0x3F9A78)
#define      wearth_bg_cloud_night_320x121_png                                                                (EXT_FLASH_BMP_BASE+0x40C8FC)
#define      wearth_bg_rain_320x194_png                                                                       (EXT_FLASH_BMP_BASE+0x41F780)
#define      wearth_bg_snow_320x161_png                                                                       (EXT_FLASH_BMP_BASE+0x43DC84)
#define      wearth_bg_sunny_day_320x209_png                                                                  (EXT_FLASH_BMP_BASE+0x456F08)
#define      wearth_bg_sunny_night_320x197_png                                                                (EXT_FLASH_BMP_BASE+0x47798C)
#define      weather_icon_Clear_40x40_png                                                                     (EXT_FLASH_BMP_BASE+0x496610)
#define      weather_icon_Clear_nightr_40x40_png                                                              (EXT_FLASH_BMP_BASE+0x497294)
#define      weather_icon_cloudyr_40x40_png                                                                   (EXT_FLASH_BMP_BASE+0x497F18)
#define      weather_icon_Dizzle_night_40x40_png                                                              (EXT_FLASH_BMP_BASE+0x498B9C)
#define      weather_icon_Dizzler_40x40_png                                                                   (EXT_FLASH_BMP_BASE+0x499820)
#define      weather_icon_gloomyr_40x40_png                                                                   (EXT_FLASH_BMP_BASE+0x49A4A4)
#define      weather_icon_heavy_rain_4040_png                                                                 (EXT_FLASH_BMP_BASE+0x49B128)
#define      weather_icon_heavy_rain_night_40x40_png                                                          (EXT_FLASH_BMP_BASE+0x49BDAC)
#define      weather_icon_heavy_snow_40x40_png                                                                (EXT_FLASH_BMP_BASE+0x49CA30)
#define      weather_icon_heavy_snow_night_40x40_png                                                          (EXT_FLASH_BMP_BASE+0x49D6B4)
#define      weather_icon_light_snow_night_40x40_png                                                          (EXT_FLASH_BMP_BASE+0x49E338)
#define      weather_icon_light_snowr_40x40_png                                                               (EXT_FLASH_BMP_BASE+0x49EFBC)
#define      weather_icon_moderate_rain_night_40x40_png                                                       (EXT_FLASH_BMP_BASE+0x49FC40)
#define      weather_icon_moderate_rainr_40x40_png                                                            (EXT_FLASH_BMP_BASE+0x4A08C4)
#define      weather_icon_moderate_snow_nightr_40x40_png                                                      (EXT_FLASH_BMP_BASE+0x4A1548)
#define      weather_icon_moderate_snowr_40x40_png                                                            (EXT_FLASH_BMP_BASE+0x4A21CC)
#define      weather_icon_sleet_nightr_40x40_png                                                              (EXT_FLASH_BMP_BASE+0x4A2E50)
#define      weather_icon_sleetr_40x40_png                                                                    (EXT_FLASH_BMP_BASE+0x4A3AD4)
#define      weather_icon_thunderstorm_nightr_40x40_png                                                       (EXT_FLASH_BMP_BASE+0x4A4758)
#define      weather_icon_thunderstormr_40x40_png                                                             (EXT_FLASH_BMP_BASE+0x4A53DC)
#define      massage_iocn_more_60x60_png                                                                      (EXT_FLASH_BMP_BASE+0x4A6060)
#define      massage_lists_button_delete_80x159_png                                                           (EXT_FLASH_BMP_BASE+0x4A7C84)
#define      masssge_icon_delete_60x60_png                                                                    (EXT_FLASH_BMP_BASE+0x4ADFE8)
#define      spo2_heart_rate_icon_30x30_png                                                                   (EXT_FLASH_BMP_BASE+0x4AFC0C)
#define      music_wave_00000_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4B0318)
#define      music_wave_00001_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4B2194)
#define      music_wave_00002_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4B4010)
#define      music_wave_00003_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4B5E8C)
#define      music_wave_00004_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4B7D08)
#define      music_wave_00005_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4B9B84)
#define      music_wave_00006_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4BBA00)
#define      music_wave_00007_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4BD87C)
#define      music_wave_00008_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4BF6F8)
#define      music_wave_00009_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4C1574)
#define      music_wave_00010_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4C33F0)
#define      music_wave_00011_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4C526C)
#define      music_wave_00012_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4C70E8)
#define      music_wave_00013_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4C8F64)
#define      music_wave_00014_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4CADE0)
#define      music_wave_00015_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4CCC5C)
#define      music_wave_00016_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4CEAD8)
#define      music_wave_00017_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4D0954)
#define      music_wave_00018_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4D27D0)
#define      music_wave_00019_78x50_png                                                                       (EXT_FLASH_BMP_BASE+0x4D464C)
#define      music_bg_320x150_png                                                                             (EXT_FLASH_BMP_BASE+0x4D64C8)
#define      music_wave_icon_default_78x50_png                                                                (EXT_FLASH_BMP_BASE+0x4EDBCC)
#define      apps_icon_Activity_record_60x60_png                                                              (EXT_FLASH_BMP_BASE+0x4EFA48)
#define      apps_icon_alarm_60x60_png                                                                        (EXT_FLASH_BMP_BASE+0x4F166C)
#define      apps_icon_breath_60x60_png                                                                       (EXT_FLASH_BMP_BASE+0x4F3290)
#define      apps_icon_Camera_60x60_png                                                                       (EXT_FLASH_BMP_BASE+0x4F4EB4)
#define      apps_icon_exercise_60x60_png                                                                     (EXT_FLASH_BMP_BASE+0x4F6AD8)
#define      apps_icon_exercise_record_60x60_png                                                              (EXT_FLASH_BMP_BASE+0x4F86FC)
#define      apps_icon_Find_my_phone_60x60_png                                                                (EXT_FLASH_BMP_BASE+0x4FA320)
#define      apps_icon_flashlight_60x60_png                                                                   (EXT_FLASH_BMP_BASE+0x4FBF44)
#define      apps_icon_heart_rate_60x60_png                                                                   (EXT_FLASH_BMP_BASE+0x4FDB68)
#define      apps_icon_massage_60x60_png                                                                      (EXT_FLASH_BMP_BASE+0x4FF78C)
#define      apps_icon_Menstrual_Cycle_60x60_png                                                              (EXT_FLASH_BMP_BASE+0x5013B0)
#define      apps_icon_music_60x60_png                                                                        (EXT_FLASH_BMP_BASE+0x502FD4)
#define      apps_icon_pressure_60x60_png                                                                     (EXT_FLASH_BMP_BASE+0x504BF8)
#define      apps_icon_setting_60x60_png                                                                      (EXT_FLASH_BMP_BASE+0x50681C)
#define      apps_icon_sleep_60x60_png                                                                        (EXT_FLASH_BMP_BASE+0x508440)
#define      apps_icon_spo2_60x60_png                                                                         (EXT_FLASH_BMP_BASE+0x50A064)
#define      apps_icon_stop_watch_60x60_png                                                                   (EXT_FLASH_BMP_BASE+0x50BC88)
#define      apps_icon_timer_60x60_png                                                                        (EXT_FLASH_BMP_BASE+0x50D8AC)
#define      apps_icon_weather_60x60_png                                                                      (EXT_FLASH_BMP_BASE+0x50F4D0)
#define      Camera_button_120x120_png                                                                        (EXT_FLASH_BMP_BASE+0x5110F4)
#define      camera_delay_button_define_60x60_png                                                             (EXT_FLASH_BMP_BASE+0x518178)
#define      Camera_icon_delay_40x40_png                                                                      (EXT_FLASH_BMP_BASE+0x519D9C)
#define      Connecting_icon_144x40_png                                                                       (EXT_FLASH_BMP_BASE+0x51AA20)





//png
#define      workout_finish_80x80_png                                                                             (EXT_FLASH_PNG_BASE+0x00)
#define      workout_start_80x80_png                                                                            (EXT_FLASH_PNG_BASE+0x4B04)
#define      workout_start_pused_button_finish_60x60_png                                                        (EXT_FLASH_PNG_BASE+0x9608)
#define      workout_start_pused_button_start_60x60_png                                                         (EXT_FLASH_PNG_BASE+0xC03C)
#define      workout_Trajectory_icon_end_24x36_png                                                              (EXT_FLASH_PNG_BASE+0xEA70)
#define      workout_Trajectory_icon_start_22x22_png                                                            (EXT_FLASH_PNG_BASE+0xF494)
#define      main_1_bg_320x320_png                                                                              (EXT_FLASH_PNG_BASE+0xFA44)
#define      main1_hour_26x87_c80_png                                                                          (EXT_FLASH_PNG_BASE+0x5AA48)
#define      main1_min_22x109_c98_png                                                                          (EXT_FLASH_PNG_BASE+0x5C4CE)
#define      main_2_bg_320x320_png                                                                             (EXT_FLASH_PNG_BASE+0x5E0EC)
#define      main_2_hour_16x106_c98_png                                                                        (EXT_FLASH_PNG_BASE+0xA90F0)
#define      main_2_min_28x136_c124_png                                                                        (EXT_FLASH_PNG_BASE+0xAA4D4)
#define      main_2_sec_22x168_c128_png                                                                        (EXT_FLASH_PNG_BASE+0xAD178)
#define      main_3_bg_320x320_png                                                                             (EXT_FLASH_PNG_BASE+0xAFCCC)
#define      main_3_hour_12x58_c58_png                                                                         (EXT_FLASH_PNG_BASE+0xFACD0)
#define      main_3_min_10x123_c123_png                                                                        (EXT_FLASH_PNG_BASE+0xFB4FC)
#define      main_4_bg_320x320_png                                                                             (EXT_FLASH_PNG_BASE+0xFC36A)
#define      main_4_hour_10x109_c92_png                                                                       (EXT_FLASH_PNG_BASE+0x14736E)
#define      main_4_min_24x144_c121_png                                                                       (EXT_FLASH_PNG_BASE+0x148038)
#define      main_4_sec_12x158_c136_png                                                                       (EXT_FLASH_PNG_BASE+0x14A8BC)
#define      main_5_num_0_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x14BEF8)
#define      main_5_num_1_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x14DEF4)
#define      main_5_num_2_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x14FEF0)
#define      main_5_num_3_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x151EEC)
#define      main_5_num_4_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x153EE8)
#define      main_5_num_5_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x155EE4)
#define      main_5_num_6_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x157EE0)
#define      main_5_num_7_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x159EDC)
#define      main_5_num_8_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x15BED8)
#define      main_5_num_9_44x62_png                                                                           (EXT_FLASH_PNG_BASE+0x15DED4)
#define      main_5_bg_320x320_png                                                                            (EXT_FLASH_PNG_BASE+0x15FED0)
#define      main_6_num_0_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1AAED4)
#define      main_6_num_1_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1ABA6C)
#define      main_6_num_2_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1AC604)
#define      main_6_num_3_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1AD19C)
#define      main_6_num_4_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1ADD34)
#define      main_6_num_5_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1AE8CC)
#define      main_6_num_6_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1AF464)
#define      main_6_num_7_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1AFFFC)
#define      main_6_num_8_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1B0B94)
#define      main_6_num_9_26x38_png                                                                           (EXT_FLASH_PNG_BASE+0x1B172C)
#define      main_6_bg_320x320_png                                                                            (EXT_FLASH_PNG_BASE+0x1B22C4)
#define      main_6_num_colon_26x38_png                                                                       (EXT_FLASH_PNG_BASE+0x1FD2C8)
#define      main_6_sec_6x136_c0_png                                                                          (EXT_FLASH_PNG_BASE+0x1FDE60)
#define      main_7_bg_320x320_png                                                                            (EXT_FLASH_PNG_BASE+0x1FE7F4)
#define      main_7_hour_10x79_c79_png                                                                        (EXT_FLASH_PNG_BASE+0x2497F8)
#define      main_7_min_18x142_c133_png                                                                       (EXT_FLASH_PNG_BASE+0x24A13E)
#define      main_7_sec_4x106_c106_png                                                                        (EXT_FLASH_PNG_BASE+0x24BF36)
#define      main_default_bg_320x320_png                                                                      (EXT_FLASH_PNG_BASE+0x24C432)
#define      main_default_hour_16x89_c81_png                                                                  (EXT_FLASH_PNG_BASE+0x297436)
#define      main_default_min_8x109_c108_png                                                                  (EXT_FLASH_PNG_BASE+0x2984EA)
#define      main_default_sec_10x162_c142_png                                                                 (EXT_FLASH_PNG_BASE+0x298F26)
#define      dial_setting_main1_big_160x160_png                                                               (EXT_FLASH_PNG_BASE+0x29A226)
#define      dial_setting_main1_little_120x120_png                                                            (EXT_FLASH_PNG_BASE+0x2ACE2A)
#define      dial_setting_main2_big_160x160_png                                                               (EXT_FLASH_PNG_BASE+0x2B76EE)
#define      dial_setting_main2_little_120x120_png                                                            (EXT_FLASH_PNG_BASE+0x2CA2F2)
#define      dial_setting_main3_big_160x160_png                                                               (EXT_FLASH_PNG_BASE+0x2D4BB6)
#define      dial_setting_main3_little_120x120_png                                                            (EXT_FLASH_PNG_BASE+0x2E77BA)
#define      dial_setting_main4_big_160x160_png                                                               (EXT_FLASH_PNG_BASE+0x2F207E)
#define      dial_setting_main4_little_120x120_png                                                            (EXT_FLASH_PNG_BASE+0x304C82)
#define      dial_setting_main5_big_160x160_png                                                               (EXT_FLASH_PNG_BASE+0x30F546)
#define      dial_setting_main5_little_120x120_png                                                            (EXT_FLASH_PNG_BASE+0x32214A)
#define      dial_setting_main6_big_160x160_png                                                               (EXT_FLASH_PNG_BASE+0x32CA0E)
#define      dial_setting_main6_little_120x120_png                                                            (EXT_FLASH_PNG_BASE+0x33F612)
#define      dial_setting_main7_big_160x160_png                                                               (EXT_FLASH_PNG_BASE+0x349ED6)
#define      dial_setting_main7_little_120x120_png                                                            (EXT_FLASH_PNG_BASE+0x35CADA)
#define      dial_setting_main8_big_160x160_png                                                               (EXT_FLASH_PNG_BASE+0x36739E)
#define      dial_setting_main8_little_120x120_png                                                            (EXT_FLASH_PNG_BASE+0x379FA2)
#define      factory_0_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x384866)
#define      factory_1_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x385B2A)
#define      factory_2_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x386DEE)
#define      factory_3_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x3880B2)
#define      factory_4_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x389376)
#define      factory_5_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x38A63A)
#define      factory_6_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x38B8FE)
#define      factory_7_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x38CBC2)
#define      factory_8_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x38DE86)
#define      factory_9_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x38F14A)
#define      factory_backspace_40x40_png                                                                      (EXT_FLASH_PNG_BASE+0x39040E)
#define      factory_define_40x40_png                                                                         (EXT_FLASH_PNG_BASE+0x3916D2)
#define      charge_00000_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x392996)
#define      charge_00001_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x3DD99A)
#define      charge_00002_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x42899E)
#define      charge_00003_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x4739A2)
#define      charge_00004_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x4BE9A6)
#define      charge_00005_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x5099AA)
#define      charge_00006_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x5549AE)
#define      charge_00007_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x59F9B2)
#define      charge_00008_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x5EA9B6)
#define      charge_00009_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x6359BA)
#define      charge_00010_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x6809BE)
#define      charge_00011_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x6CB9C2)
#define      charge_00012_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x7169C6)
#define      charge_00013_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x7619CA)
#define      charge_00014_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x7AC9CE)
#define      charge_00015_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x7F79D2)
#define      charge_00016_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x8429D6)
#define      charge_00017_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x88D9DA)
#define      charge_00018_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x8D89DE)
#define      charge_00019_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x9239E2)
#define      charge_00020_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x96E9E6)
#define      charge_00021_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0x9B99EA)
#define      charge_00022_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0xA049EE)
#define      charge_00023_320x320_png                                                                         (EXT_FLASH_PNG_BASE+0xA4F9F2)
#define      update_failed_40x40_png                                                                          (EXT_FLASH_PNG_BASE+0xA9A9F6)
#define      update_success_40x40_png                                                                         (EXT_FLASH_PNG_BASE+0xA9BCBA)
#define      breath_button_define_60x60_png                                                                   (EXT_FLASH_PNG_BASE+0xA9CF7E)
#define      breath_icon_speed_40x40_png                                                                      (EXT_FLASH_PNG_BASE+0xA9F9B2)
#define      breath_icon_time_40x40_png                                                                       (EXT_FLASH_PNG_BASE+0xAA0C76)
#define      breath_restar_button_60x60_png                                                                   (EXT_FLASH_PNG_BASE+0xAA1F3A)
#define      rreath_00000_png                                                                                 (EXT_FLASH_PNG_BASE+0xAA496E)
#define      rreath_00001_png                                                                                 (EXT_FLASH_PNG_BASE+0xAAF232)
#define      rreath_00002_png                                                                                 (EXT_FLASH_PNG_BASE+0xAB9AF6)
#define      rreath_00003_png                                                                                 (EXT_FLASH_PNG_BASE+0xAC43BA)
#define      rreath_00004_png                                                                                 (EXT_FLASH_PNG_BASE+0xACEC7E)
#define      rreath_00005_png                                                                                 (EXT_FLASH_PNG_BASE+0xAD9542)
#define      rreath_00006_png                                                                                 (EXT_FLASH_PNG_BASE+0xAE3E06)
#define      rreath_00007_png                                                                                 (EXT_FLASH_PNG_BASE+0xAEE6CA)
#define      rreath_00008_png                                                                                 (EXT_FLASH_PNG_BASE+0xAF8F8E)
#define      rreath_00009_png                                                                                 (EXT_FLASH_PNG_BASE+0xB03852)
#define      rreath_00010_png                                                                                 (EXT_FLASH_PNG_BASE+0xB0E116)
#define      rreath_00011_png                                                                                 (EXT_FLASH_PNG_BASE+0xB189DA)
#define      rreath_00012_png                                                                                 (EXT_FLASH_PNG_BASE+0xB2329E)
#define      rreath_00013_png                                                                                 (EXT_FLASH_PNG_BASE+0xB2DB62)
#define      rreath_00014_png                                                                                 (EXT_FLASH_PNG_BASE+0xB38426)
#define      rreath_00015_png                                                                                 (EXT_FLASH_PNG_BASE+0xB42CEA)
#define      rreath_00016_png                                                                                 (EXT_FLASH_PNG_BASE+0xB4D5AE)
#define      rreath_00017_png                                                                                 (EXT_FLASH_PNG_BASE+0xB57E72)
#define      rreath_00018_png                                                                                 (EXT_FLASH_PNG_BASE+0xB62736)
#define      rreath_00019_png                                                                                 (EXT_FLASH_PNG_BASE+0xB6CFFA)
#define      rreath_00020_png                                                                                 (EXT_FLASH_PNG_BASE+0xB778BE)
#define      rreath_00021_png                                                                                 (EXT_FLASH_PNG_BASE+0xB82182)
#define      rreath_00022_png                                                                                 (EXT_FLASH_PNG_BASE+0xB8CA46)
#define      rreath_00023_png                                                                                 (EXT_FLASH_PNG_BASE+0xB9730A)
#define      rreath_00024_png                                                                                 (EXT_FLASH_PNG_BASE+0xBA1BCE)
#define      rreath_00025_png                                                                                 (EXT_FLASH_PNG_BASE+0xBAC492)
#define      rreath_00026_png                                                                                 (EXT_FLASH_PNG_BASE+0xBB6D56)
#define      rreath_00027_png                                                                                 (EXT_FLASH_PNG_BASE+0xBC161A)
#define      rreath_00028_png                                                                                 (EXT_FLASH_PNG_BASE+0xBCBEDE)
#define      rreath_00029_png                                                                                 (EXT_FLASH_PNG_BASE+0xBD67A2)
#define      rreath_00030_png                                                                                 (EXT_FLASH_PNG_BASE+0xBE1066)
#define      rreath_00031_png                                                                                 (EXT_FLASH_PNG_BASE+0xBEB92A)
#define      rreath_00032_png                                                                                 (EXT_FLASH_PNG_BASE+0xBF61EE)
#define      rreath_00033_png                                                                                 (EXT_FLASH_PNG_BASE+0xC00AB2)
#define      rreath_00034_png                                                                                 (EXT_FLASH_PNG_BASE+0xC0B376)
#define      rreath_00035_png                                                                                 (EXT_FLASH_PNG_BASE+0xC15C3A)
#define      rreath_00036_png                                                                                 (EXT_FLASH_PNG_BASE+0xC204FE)
#define      rreath_00037_png                                                                                 (EXT_FLASH_PNG_BASE+0xC2ADC2)
#define      rreath_00038_png                                                                                 (EXT_FLASH_PNG_BASE+0xC35686)
#define      rreath_00039_png                                                                                 (EXT_FLASH_PNG_BASE+0xC3FF4A)
#define      rreath_00040_png                                                                                 (EXT_FLASH_PNG_BASE+0xC4A80E)
#define      rreath_00041_png                                                                                 (EXT_FLASH_PNG_BASE+0xC550D2)
#define      rreath_00042_png                                                                                 (EXT_FLASH_PNG_BASE+0xC5F996)
#define      rreath_00043_png                                                                                 (EXT_FLASH_PNG_BASE+0xC6A25A)
#define      rreath_00044_png                                                                                 (EXT_FLASH_PNG_BASE+0xC74B1E)
#define      rreath_00045_png                                                                                 (EXT_FLASH_PNG_BASE+0xC7F3E2)
#define      rreath_00046_png                                                                                 (EXT_FLASH_PNG_BASE+0xC89CA6)
#define      rreath_00047_png                                                                                 (EXT_FLASH_PNG_BASE+0xC9456A)
#define      rreath_00048_png                                                                                 (EXT_FLASH_PNG_BASE+0xC9EE2E)
#define      rreath_00049_png                                                                                 (EXT_FLASH_PNG_BASE+0xCA96F2)
#define      rreath_00050_png                                                                                 (EXT_FLASH_PNG_BASE+0xCB3FB6)
#define      rreath_00051_png                                                                                 (EXT_FLASH_PNG_BASE+0xCBE87A)
#define      rreath_00052_png                                                                                 (EXT_FLASH_PNG_BASE+0xCC913E)
#define      rreath_00053_png                                                                                 (EXT_FLASH_PNG_BASE+0xCD3A02)
#define      rreath_00054_png                                                                                 (EXT_FLASH_PNG_BASE+0xCDE2C6)
#define      rreath_00055_png                                                                                 (EXT_FLASH_PNG_BASE+0xCE8B8A)
#define      rreath_00056_png                                                                                 (EXT_FLASH_PNG_BASE+0xCF344E)
#define      rreath_00057_png                                                                                 (EXT_FLASH_PNG_BASE+0xCFDD12)
#define      rreath_00058_png                                                                                 (EXT_FLASH_PNG_BASE+0xD085D6)
#define      rreath_00059_png                                                                                 (EXT_FLASH_PNG_BASE+0xD12E9A)
#define      rreath_00060_png                                                                                 (EXT_FLASH_PNG_BASE+0xD1D75E)
#define      rreath_00061_png                                                                                 (EXT_FLASH_PNG_BASE+0xD28022)
#define      rreath_00062_png                                                                                 (EXT_FLASH_PNG_BASE+0xD328E6)
#define      rreath_00063_png                                                                                 (EXT_FLASH_PNG_BASE+0xD3D1AA)
#define      rreath_00064_png                                                                                 (EXT_FLASH_PNG_BASE+0xD47A6E)
#define      rreath_00065_png                                                                                 (EXT_FLASH_PNG_BASE+0xD52332)
#define      rreath_00066_png                                                                                 (EXT_FLASH_PNG_BASE+0xD5CBF6)
#define      rreath_00067_png                                                                                 (EXT_FLASH_PNG_BASE+0xD674BA)
#define      rreath_00068_png                                                                                 (EXT_FLASH_PNG_BASE+0xD71D7E)
#define      rreath_00069_png                                                                                 (EXT_FLASH_PNG_BASE+0xD7C642)
#define      rreath_00070_png                                                                                 (EXT_FLASH_PNG_BASE+0xD86F06)
#define      rreath_00071_png                                                                                 (EXT_FLASH_PNG_BASE+0xD917CA)
#define      rreath_00072_png                                                                                 (EXT_FLASH_PNG_BASE+0xD9C08E)
#define      rreath_00073_png                                                                                 (EXT_FLASH_PNG_BASE+0xDA6952)
#define      rreath_00074_png                                                                                 (EXT_FLASH_PNG_BASE+0xDB1216)
#define      rreath_00075_png                                                                                 (EXT_FLASH_PNG_BASE+0xDBBADA)
#define      rreath_00076_png                                                                                 (EXT_FLASH_PNG_BASE+0xDC639E)
#define      rreath_00077_png                                                                                 (EXT_FLASH_PNG_BASE+0xDD0C62)
#define      rreath_00078_png                                                                                 (EXT_FLASH_PNG_BASE+0xDDB526)
#define      rreath_00079_png                                                                                 (EXT_FLASH_PNG_BASE+0xDE5DEA)
#define      rreath_00080_png                                                                                 (EXT_FLASH_PNG_BASE+0xDF06AE)
#define      rreath_00081_png                                                                                 (EXT_FLASH_PNG_BASE+0xDFAF72)
#define      rreath_00082_png                                                                                 (EXT_FLASH_PNG_BASE+0xE05836)
#define      rreath_00083_png                                                                                 (EXT_FLASH_PNG_BASE+0xE100FA)
#define      rreath_00084_png                                                                                 (EXT_FLASH_PNG_BASE+0xE1A9BE)
#define      rreath_00085_png                                                                                 (EXT_FLASH_PNG_BASE+0xE25282)
#define      rreath_00086_png                                                                                 (EXT_FLASH_PNG_BASE+0xE2FB46)
#define      rreath_00087_png                                                                                 (EXT_FLASH_PNG_BASE+0xE3A40A)
#define      rreath_00088_png                                                                                 (EXT_FLASH_PNG_BASE+0xE44CCE)
#define      rreath_00089_png                                                                                 (EXT_FLASH_PNG_BASE+0xE4F592)
#define      rreath_00090_png                                                                                 (EXT_FLASH_PNG_BASE+0xE59E56)
#define      rreath_00091_png                                                                                 (EXT_FLASH_PNG_BASE+0xE6471A)
#define      rreath_00092_png                                                                                 (EXT_FLASH_PNG_BASE+0xE6EFDE)
#define      rreath_00093_png                                                                                 (EXT_FLASH_PNG_BASE+0xE798A2)
#define      rreath_00094_png                                                                                 (EXT_FLASH_PNG_BASE+0xE84166)
#define      rreath_00095_png                                                                                 (EXT_FLASH_PNG_BASE+0xE8EA2A)
#define      rreath_00096_png                                                                                 (EXT_FLASH_PNG_BASE+0xE992EE)
#define      rreath_00097_png                                                                                 (EXT_FLASH_PNG_BASE+0xEA3BB2)
#define      rreath_00098_png                                                                                 (EXT_FLASH_PNG_BASE+0xEAE476)
#define      rreath_00099_png                                                                                 (EXT_FLASH_PNG_BASE+0xEB8D3A)
#define      rreath_00100_png                                                                                 (EXT_FLASH_PNG_BASE+0xEC35FE)
#define      rreath_00101_png                                                                                 (EXT_FLASH_PNG_BASE+0xECDEC2)
#define      rreath_00102_png                                                                                 (EXT_FLASH_PNG_BASE+0xED8786)
#define      rreath_00103_png                                                                                 (EXT_FLASH_PNG_BASE+0xEE304A)
#define      rreath_00104_png                                                                                 (EXT_FLASH_PNG_BASE+0xEED90E)
#define      rreath_00105_png                                                                                 (EXT_FLASH_PNG_BASE+0xEF81D2)
#define      rreath_00106_png                                                                                 (EXT_FLASH_PNG_BASE+0xF02A96)
#define      rreath_00107_png                                                                                 (EXT_FLASH_PNG_BASE+0xF0D35A)
#define      rreath_00108_png                                                                                 (EXT_FLASH_PNG_BASE+0xF17C1E)
#define      rreath_00109_png                                                                                 (EXT_FLASH_PNG_BASE+0xF224E2)
#define      Calories_icon_16x16_png                                                                          (EXT_FLASH_PNG_BASE+0xF2CDA6)
#define      distance_icon_16x16_png                                                                          (EXT_FLASH_PNG_BASE+0xF2D0AA)
#define      step_icon_16x16_png                                                                             (EXT_FLASH_PNG_BASE+0xF2D3AE)
#define      time_icon_16x16_png                                                                              (EXT_FLASH_PNG_BASE+0xF2D6B2)
#define      LOGO_00003_png                                                                                   (EXT_FLASH_PNG_BASE+0xF2D9B6)
#define      LOGO_00004_png                                                                                   (EXT_FLASH_PNG_BASE+0xF510EA)
#define      LOGO_00005_png                                                                                   (EXT_FLASH_PNG_BASE+0xF7481E)
#define      LOGO_00006_png                                                                                   (EXT_FLASH_PNG_BASE+0xF97F52)
#define      LOGO_00007_png                                                                                   (EXT_FLASH_PNG_BASE+0xFBB686)
#define      LOGO_00008_png                                                                                   (EXT_FLASH_PNG_BASE+0xFDEDBA)
#define      LOGO_00009_png                                                                                  (EXT_FLASH_PNG_BASE+0x10024EE)
#define      LOGO_00010_png                                                                                  (EXT_FLASH_PNG_BASE+0x1025C22)
#define      LOGO_00011_png                                                                                  (EXT_FLASH_PNG_BASE+0x1049356)
#define      LOGO_00012_png                                                                                  (EXT_FLASH_PNG_BASE+0x106CA8A)
#define      LOGO_00013_png                                                                                  (EXT_FLASH_PNG_BASE+0x10901BE)
#define      LOGO_00014_png                                                                                  (EXT_FLASH_PNG_BASE+0x10B38F2)
#define      LOGO_00015_png                                                                                  (EXT_FLASH_PNG_BASE+0x10D7026)
#define      LOGO_00016_png                                                                                  (EXT_FLASH_PNG_BASE+0x10FA75A)
#define      LOGO_00017_png                                                                                  (EXT_FLASH_PNG_BASE+0x111DE8E)
#define      LOGO_00018_png                                                                                  (EXT_FLASH_PNG_BASE+0x11415C2)
#define      LOGO_00019_png                                                                                  (EXT_FLASH_PNG_BASE+0x1164CF6)
#define      timer_bg_260x260_png                                                                            (EXT_FLASH_PNG_BASE+0x118842A)
#define      loading_00000_png                                                                               (EXT_FLASH_PNG_BASE+0x11B9C5E)
#define      loading_00001_png                                                                               (EXT_FLASH_PNG_BASE+0x11BE762)
#define      loading_00002_png                                                                               (EXT_FLASH_PNG_BASE+0x11C3266)
#define      loading_00003_png                                                                               (EXT_FLASH_PNG_BASE+0x11C7D6A)
#define      loading_00004_png                                                                               (EXT_FLASH_PNG_BASE+0x11CC86E)
#define      loading_00005_png                                                                               (EXT_FLASH_PNG_BASE+0x11D1372)
#define      loading_00006_png                                                                               (EXT_FLASH_PNG_BASE+0x11D5E76)
#define      loading_00007_png                                                                               (EXT_FLASH_PNG_BASE+0x11DA97A)
#define      loading_00008_png                                                                               (EXT_FLASH_PNG_BASE+0x11DF47E)
#define      loading_00009_png                                                                               (EXT_FLASH_PNG_BASE+0x11E3F82)
#define      loading_00010_png                                                                               (EXT_FLASH_PNG_BASE+0x11E8A86)
#define      loading_00011_png                                                                               (EXT_FLASH_PNG_BASE+0x11ED58A)
#define      loading_00012_png                                                                               (EXT_FLASH_PNG_BASE+0x11F208E)
#define      loading_00013_png                                                                               (EXT_FLASH_PNG_BASE+0x11F6B92)
#define      loading_00014_png                                                                               (EXT_FLASH_PNG_BASE+0x11FB696)
#define      loading_00015_png                                                                               (EXT_FLASH_PNG_BASE+0x120019A)
#define      brightness_bg_0_180x180_png                                                                     (EXT_FLASH_PNG_BASE+0x1204C9E)
#define      brightness_bg_25_180x180_png                                                                    (EXT_FLASH_PNG_BASE+0x121C852)
#define      brightness_bg_50_180x180_png                                                                    (EXT_FLASH_PNG_BASE+0x1234406)
#define      brightness_bg_75_180x180_png                                                                    (EXT_FLASH_PNG_BASE+0x124BFBA)
#define      brightness_bg_100_180x180_png                                                                   (EXT_FLASH_PNG_BASE+0x1263B6E)
#define      airbnb_40x40_png                                                                                (EXT_FLASH_PNG_BASE+0x127B722)
#define      booking_40x40_png                                                                               (EXT_FLASH_PNG_BASE+0x127C9E6)
#define      default_40x40_png                                                                               (EXT_FLASH_PNG_BASE+0x127DCAA)
#define      deliveroo_40x40_png                                                                             (EXT_FLASH_PNG_BASE+0x127EF6E)
#define      Dropbox_40x40_png                                                                               (EXT_FLASH_PNG_BASE+0x1280232)
#define      facebook_40x40_png                                                                              (EXT_FLASH_PNG_BASE+0x12814F6)
#define      flipboard_40x40_png                                                                             (EXT_FLASH_PNG_BASE+0x12827BA)
#define      line_40x40_png                                                                                  (EXT_FLASH_PNG_BASE+0x1283A7E)
#define      lyft_40x40_png                                                                                  (EXT_FLASH_PNG_BASE+0x1284D42)
#define      pandora_40x40_png                                                                               (EXT_FLASH_PNG_BASE+0x1286006)
#define      phone_40x40_png                                                                                 (EXT_FLASH_PNG_BASE+0x12872CA)
#define      qq_40x40_png                                                                                    (EXT_FLASH_PNG_BASE+0x128858E)
#define      Shazam_40x40_png                                                                                (EXT_FLASH_PNG_BASE+0x1289852)
#define      Skype_40x40_png                                                                                 (EXT_FLASH_PNG_BASE+0x128AB16)
#define      slack_40x40_png                                                                                 (EXT_FLASH_PNG_BASE+0x128BDDA)
#define      sms_40x40_png                                                                                   (EXT_FLASH_PNG_BASE+0x128D09E)
#define      Spotify_40x40_png                                                                               (EXT_FLASH_PNG_BASE+0x128E362)
#define      twitter_40x40_png                                                                               (EXT_FLASH_PNG_BASE+0x128F626)
#define      waze_40x40_png                                                                                  (EXT_FLASH_PNG_BASE+0x12908EA)
#define      WeChat_40x40_png                                                                                (EXT_FLASH_PNG_BASE+0x1291BAE)
#define      heart_rate_icon_50x50_png                                                                       (EXT_FLASH_PNG_BASE+0x1292E72)
#define      hr_00000_png                                                                                    (EXT_FLASH_PNG_BASE+0x1294BC2)
#define      hr_00001_png                                                                                    (EXT_FLASH_PNG_BASE+0x1296912)
#define      hr_00002_png                                                                                    (EXT_FLASH_PNG_BASE+0x1298662)
#define      hr_00003_png                                                                                    (EXT_FLASH_PNG_BASE+0x129A3B2)
#define      hr_00004_png                                                                                    (EXT_FLASH_PNG_BASE+0x129C102)
#define      hr_00005_png                                                                                    (EXT_FLASH_PNG_BASE+0x129DE52)
#define      hr_00006_png                                                                                    (EXT_FLASH_PNG_BASE+0x129FBA2)
#define      hr_00007_png                                                                                    (EXT_FLASH_PNG_BASE+0x12A18F2)
#define      hr_00008_png                                                                                    (EXT_FLASH_PNG_BASE+0x12A3642)
#define      hr_00009_png                                                                                    (EXT_FLASH_PNG_BASE+0x12A5392)
#define      hr_00010_png                                                                                    (EXT_FLASH_PNG_BASE+0x12A70E2)
#define      hr_00011_png                                                                                    (EXT_FLASH_PNG_BASE+0x12A8E32)
#define      hr_00012_png                                                                                    (EXT_FLASH_PNG_BASE+0x12AAB82)
#define      hr_00013_png                                                                                    (EXT_FLASH_PNG_BASE+0x12AC8D2)
#define      hr_00014_png                                                                                    (EXT_FLASH_PNG_BASE+0x12AE622)
#define      hr_00015_png                                                                                    (EXT_FLASH_PNG_BASE+0x12B0372)
#define      hr_00016_png                                                                                    (EXT_FLASH_PNG_BASE+0x12B20C2)
#define      hr_00017_png                                                                                    (EXT_FLASH_PNG_BASE+0x12B3E12)
#define      hr_00018_png                                                                                    (EXT_FLASH_PNG_BASE+0x12B5B62)
#define      hr_00019_png                                                                                    (EXT_FLASH_PNG_BASE+0x12B78B2)
#define      hr_00020_png                                                                                    (EXT_FLASH_PNG_BASE+0x12B9602)
#define      hr_00021_png                                                                                    (EXT_FLASH_PNG_BASE+0x12BB352)
#define      hr_00022_png                                                                                    (EXT_FLASH_PNG_BASE+0x12BD0A2)
#define      hr_00023_png                                                                                    (EXT_FLASH_PNG_BASE+0x12BEDF2)
#define      hr_zone_bg_300x8_png                                                                            (EXT_FLASH_PNG_BASE+0x12C0B42)
#define      spo2_restar_button_60x60_png                                                                    (EXT_FLASH_PNG_BASE+0x12C2766)
#define      warning_icon_40x40_png                                                                          (EXT_FLASH_PNG_BASE+0x12C519A)
#define      spo2_00000_png                                                                                  (EXT_FLASH_PNG_BASE+0x12C645E)
#define      spo2_00001_png                                                                                  (EXT_FLASH_PNG_BASE+0x12D3B8A)
#define      spo2_00002_png                                                                                  (EXT_FLASH_PNG_BASE+0x12E12B6)
#define      spo2_00003_png                                                                                  (EXT_FLASH_PNG_BASE+0x12EE9E2)
#define      spo2_00004_png                                                                                  (EXT_FLASH_PNG_BASE+0x12FC10E)
#define      spo2_00005_png                                                                                  (EXT_FLASH_PNG_BASE+0x130983A)
#define      spo2_00006_png                                                                                  (EXT_FLASH_PNG_BASE+0x1316F66)
#define      spo2_00007_png                                                                                  (EXT_FLASH_PNG_BASE+0x1324692)
#define      spo2_00008_png                                                                                  (EXT_FLASH_PNG_BASE+0x1331DBE)
#define      spo2_00009_png                                                                                  (EXT_FLASH_PNG_BASE+0x133F4EA)
#define      spo2_00010_png                                                                                  (EXT_FLASH_PNG_BASE+0x134CC16)
#define      spo2_00011_png                                                                                  (EXT_FLASH_PNG_BASE+0x135A342)
#define      spo2_00012_png                                                                                  (EXT_FLASH_PNG_BASE+0x1367A6E)
#define      spo2_00013_png                                                                                  (EXT_FLASH_PNG_BASE+0x137519A)
#define      spo2_00014_png                                                                                  (EXT_FLASH_PNG_BASE+0x13828C6)
#define      spo2_00015_png                                                                                  (EXT_FLASH_PNG_BASE+0x138FFF2)
#define      spo2_00016_png                                                                                  (EXT_FLASH_PNG_BASE+0x139D71E)
#define      spo2_00017_png                                                                                  (EXT_FLASH_PNG_BASE+0x13AAE4A)
#define      spo2_00018_png                                                                                  (EXT_FLASH_PNG_BASE+0x13B8576)
#define      spo2_00019_png                                                                                  (EXT_FLASH_PNG_BASE+0x13C5CA2)
#define      spo2_00020_png                                                                                  (EXT_FLASH_PNG_BASE+0x13D33CE)
#define      spo2_00021_png                                                                                  (EXT_FLASH_PNG_BASE+0x13E0AFA)
#define      spo2_00022_png                                                                                  (EXT_FLASH_PNG_BASE+0x13EE226)
#define      spo2_00023_png                                                                                  (EXT_FLASH_PNG_BASE+0x13FB952)
#define      spo2_00024_png                                                                                  (EXT_FLASH_PNG_BASE+0x140907E)
#define      spo2_00025_png                                                                                  (EXT_FLASH_PNG_BASE+0x14167AA)
#define      spo2_00026_png                                                                                  (EXT_FLASH_PNG_BASE+0x1423ED6)
#define      spo2_00027_png                                                                                  (EXT_FLASH_PNG_BASE+0x1431602)
#define      spo2_00028_png                                                                                  (EXT_FLASH_PNG_BASE+0x143ED2E)
#define      spo2_00029_png                                                                                  (EXT_FLASH_PNG_BASE+0x144C45A)
#define      spo2_00030_png                                                                                  (EXT_FLASH_PNG_BASE+0x1459B86)
#define      spo2_00031_png                                                                                  (EXT_FLASH_PNG_BASE+0x14672B2)
#define      spo2_00032_png                                                                                  (EXT_FLASH_PNG_BASE+0x14749DE)
#define      spo2_00033_png                                                                                  (EXT_FLASH_PNG_BASE+0x148210A)
#define      spo2_00034_png                                                                                  (EXT_FLASH_PNG_BASE+0x148F836)
#define      spo2_00035_png                                                                                  (EXT_FLASH_PNG_BASE+0x149CF62)
#define      spo2_00036_png                                                                                  (EXT_FLASH_PNG_BASE+0x14AA68E)
#define      spo2_00037_png                                                                                  (EXT_FLASH_PNG_BASE+0x14B7DBA)
#define      spo2_00038_png                                                                                  (EXT_FLASH_PNG_BASE+0x14C54E6)
#define      spo2_00039_png                                                                                  (EXT_FLASH_PNG_BASE+0x14D2C12)
#define      spo2_00040_png                                                                                  (EXT_FLASH_PNG_BASE+0x14E033E)
#define      spo2_00041_png                                                                                  (EXT_FLASH_PNG_BASE+0x14EDA6A)
#define      spo2_00042_png                                                                                  (EXT_FLASH_PNG_BASE+0x14FB196)
#define      spo2_00043_png                                                                                  (EXT_FLASH_PNG_BASE+0x15088C2)
#define      spo2_00044_png                                                                                  (EXT_FLASH_PNG_BASE+0x1515FEE)
#define      spo2_00045_png                                                                                  (EXT_FLASH_PNG_BASE+0x152371A)
#define      spo2_00046_png                                                                                  (EXT_FLASH_PNG_BASE+0x1530E46)
#define      spo2_00047_png                                                                                  (EXT_FLASH_PNG_BASE+0x153E572)
#define      spo2_00048_png                                                                                  (EXT_FLASH_PNG_BASE+0x154BC9E)
#define      spo2_00049_png                                                                                  (EXT_FLASH_PNG_BASE+0x15593CA)
#define      spo2_00050_png                                                                                  (EXT_FLASH_PNG_BASE+0x1566AF6)
#define      spo2_00051_png                                                                                  (EXT_FLASH_PNG_BASE+0x1574222)
#define      spo2_00052_png                                                                                  (EXT_FLASH_PNG_BASE+0x158194E)
#define      spo2_00053_png                                                                                  (EXT_FLASH_PNG_BASE+0x158F07A)
#define      spo2_00054_png                                                                                  (EXT_FLASH_PNG_BASE+0x159C7A6)
#define      spo2_00055_png                                                                                  (EXT_FLASH_PNG_BASE+0x15A9ED2)
#define      spo2_00056_png                                                                                  (EXT_FLASH_PNG_BASE+0x15B75FE)
#define      spo2_00057_png                                                                                  (EXT_FLASH_PNG_BASE+0x15C4D2A)
#define      spo2_00058_png                                                                                  (EXT_FLASH_PNG_BASE+0x15D2456)
#define      spo2_00059_png                                                                                  (EXT_FLASH_PNG_BASE+0x15DFB82)
#define      spo2_00060_png                                                                                  (EXT_FLASH_PNG_BASE+0x15ED2AE)
#define      spo2_00061_png                                                                                  (EXT_FLASH_PNG_BASE+0x15FA9DA)
#define      spo2_00062_png                                                                                  (EXT_FLASH_PNG_BASE+0x1608106)
#define      spo2_00063_png                                                                                  (EXT_FLASH_PNG_BASE+0x1615832)
#define      spo2_00064_png                                                                                  (EXT_FLASH_PNG_BASE+0x1622F5E)
#define      spo2_00065_png                                                                                  (EXT_FLASH_PNG_BASE+0x163068A)
#define      spo2_00066_png                                                                                  (EXT_FLASH_PNG_BASE+0x163DDB6)
#define      spo2_00067_png                                                                                  (EXT_FLASH_PNG_BASE+0x164B4E2)
#define      spo2_00068_png                                                                                  (EXT_FLASH_PNG_BASE+0x1658C0E)
#define      spo2_00069_png                                                                                  (EXT_FLASH_PNG_BASE+0x166633A)
#define      spo2_00070_png                                                                                  (EXT_FLASH_PNG_BASE+0x1673A66)
#define      spo2_00071_png                                                                                  (EXT_FLASH_PNG_BASE+0x1681192)
#define      spo2_00072_png                                                                                  (EXT_FLASH_PNG_BASE+0x168E8BE)
#define      spo2_00073_png                                                                                  (EXT_FLASH_PNG_BASE+0x169BFEA)
#define      spo2_00074_png                                                                                  (EXT_FLASH_PNG_BASE+0x16A9716)
#define      spo2_00075_png                                                                                  (EXT_FLASH_PNG_BASE+0x16B6E42)
#define      spo2_00076_png                                                                                  (EXT_FLASH_PNG_BASE+0x16C456E)
#define      spo2_00077_png                                                                                  (EXT_FLASH_PNG_BASE+0x16D1C9A)
#define      spo2_00078_png                                                                                  (EXT_FLASH_PNG_BASE+0x16DF3C6)
#define      spo2_00079_png                                                                                  (EXT_FLASH_PNG_BASE+0x16ECAF2)
#define      spo2_00080_png                                                                                  (EXT_FLASH_PNG_BASE+0x16FA21E)
#define      spo2_00081_png                                                                                  (EXT_FLASH_PNG_BASE+0x170794A)
#define      spo2_00082_png                                                                                  (EXT_FLASH_PNG_BASE+0x1715076)
#define      spo2_00083_png                                                                                  (EXT_FLASH_PNG_BASE+0x17227A2)
#define      spo2_00084_png                                                                                  (EXT_FLASH_PNG_BASE+0x172FECE)
#define      spo2_00085_png                                                                                  (EXT_FLASH_PNG_BASE+0x173D5FA)
#define      spo2_00086_png                                                                                  (EXT_FLASH_PNG_BASE+0x174AD26)
#define      spo2_00087_png                                                                                  (EXT_FLASH_PNG_BASE+0x1758452)
#define      spo2_00088_png                                                                                  (EXT_FLASH_PNG_BASE+0x1765B7E)
#define      spo2_00089_png                                                                                  (EXT_FLASH_PNG_BASE+0x17732AA)
#define      spo2_00090_png                                                                                  (EXT_FLASH_PNG_BASE+0x17809D6)
#define      spo2_00091_png                                                                                  (EXT_FLASH_PNG_BASE+0x178E102)
#define      spo2_00092_png                                                                                  (EXT_FLASH_PNG_BASE+0x179B82E)
#define      spo2_00093_png                                                                                  (EXT_FLASH_PNG_BASE+0x17A8F5A)
#define      spo2_00094_png                                                                                  (EXT_FLASH_PNG_BASE+0x17B6686)
#define      spo2_00095_png                                                                                  (EXT_FLASH_PNG_BASE+0x17C3DB2)
#define      spo2_00096_png                                                                                  (EXT_FLASH_PNG_BASE+0x17D14DE)
#define      spo2_00097_png                                                                                  (EXT_FLASH_PNG_BASE+0x17DEC0A)
#define      spo2_00098_png                                                                                  (EXT_FLASH_PNG_BASE+0x17EC336)
#define      spo2_00099_png                                                                                  (EXT_FLASH_PNG_BASE+0x17F9A62)
#define      pressure_icon_50x50_png                                                                         (EXT_FLASH_PNG_BASE+0x180718E)
#define      music_bg_300x120_png                                                                            (EXT_FLASH_PNG_BASE+0x1808EDE)
#define      music_last_button_48x48_png                                                                     (EXT_FLASH_PNG_BASE+0x18234C2)
#define      music_last_icon_48x48_png                                                                       (EXT_FLASH_PNG_BASE+0x1824FC6)
#define      music_next_button_48x48_png                                                                     (EXT_FLASH_PNG_BASE+0x1826ACA)
#define      music_next_icon_48x48_png                                                                       (EXT_FLASH_PNG_BASE+0x18285CE)
#define      music_pause_button_100x100_png                                                                  (EXT_FLASH_PNG_BASE+0x182A0D2)
#define      music_play_button_100x100_png                                                                   (EXT_FLASH_PNG_BASE+0x1831606)
#define      music_play_icon_100x100_png                                                                     (EXT_FLASH_PNG_BASE+0x1838B3A)
#define      music_stop_icon_100x100_png                                                                     (EXT_FLASH_PNG_BASE+0x184006E)
#define      music_volum_icon_40x40_png                                                                      (EXT_FLASH_PNG_BASE+0x18475A2)
#define      music_volume__button_30x30_png                                                                  (EXT_FLASH_PNG_BASE+0x1848866)
#define      music_volume_a_icon_30x30_png                                                                   (EXT_FLASH_PNG_BASE+0x18492F6)
#define      music_volume_bg_240x48_png                                                                      (EXT_FLASH_PNG_BASE+0x1849D86)
#define      music_volume_button_30x30_png                                                                   (EXT_FLASH_PNG_BASE+0x185248A)
#define      music_volume_r_icon_30x30_png                                                                   (EXT_FLASH_PNG_BASE+0x1852F1A)
#define      fdmp_00000_png                                                                                  (EXT_FLASH_PNG_BASE+0x18539AA)
#define      fdmp_00001_png                                                                                  (EXT_FLASH_PNG_BASE+0x18665AE)
#define      fdmp_00002_png                                                                                  (EXT_FLASH_PNG_BASE+0x18791B2)
#define      fdmp_00003_png                                                                                  (EXT_FLASH_PNG_BASE+0x188BDB6)
#define      fdmp_00004_png                                                                                  (EXT_FLASH_PNG_BASE+0x189E9BA)
#define      fdmp_00005_png                                                                                  (EXT_FLASH_PNG_BASE+0x18B15BE)
#define      fdmp_00006_png                                                                                  (EXT_FLASH_PNG_BASE+0x18C41C2)
#define      fdmp_00007_png                                                                                  (EXT_FLASH_PNG_BASE+0x18D6DC6)
#define      fdmp_00008_png                                                                                  (EXT_FLASH_PNG_BASE+0x18E99CA)
#define      fdmp_00009_png                                                                                  (EXT_FLASH_PNG_BASE+0x18FC5CE)
#define      fdmp_00010_png                                                                                  (EXT_FLASH_PNG_BASE+0x190F1D2)
#define      fdmp_00011_png                                                                                  (EXT_FLASH_PNG_BASE+0x1921DD6)
#define      fdmp_00012_png                                                                                  (EXT_FLASH_PNG_BASE+0x19349DA)
#define      fdmp_00013_png                                                                                  (EXT_FLASH_PNG_BASE+0x19475DE)
#define      fdmp_00014_png                                                                                  (EXT_FLASH_PNG_BASE+0x195A1E2)
#define      fdmp_00015_png                                                                                  (EXT_FLASH_PNG_BASE+0x196CDE6)
#define      fdmp_00016_png                                                                                  (EXT_FLASH_PNG_BASE+0x197F9EA)
#define      fdmp_00017_png                                                                                  (EXT_FLASH_PNG_BASE+0x19925EE)
#define      fdmp_00018_png                                                                                  (EXT_FLASH_PNG_BASE+0x19A51F2)
#define      fdmp_00019_png                                                                                  (EXT_FLASH_PNG_BASE+0x19B7DF6)


 

//0804新增<R0.2>
#define      main_30_001_320x320_png                                                                           (EXT_FLASH_0804_BASE+0x00)
#define      main_30_002_320x320_png                                                                           (EXT_FLASH_0804_BASE+0x4B004)
#define      main_30_003_320x320_png                                                                           (EXT_FLASH_0804_BASE+0x96008)
#define      main_30_004_320x320_png                                                                           (EXT_FLASH_0804_BASE+0xE100C)
#define      main_30_005_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x12C010)
#define      main_30_006_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x177014)
#define      main_30_007_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x1C2018)
#define      main_30_008_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x20D01C)
#define      main_30_009_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x258020)
#define      main_30_010_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x2A3024)
#define      main_30_011_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x2EE028)
#define      main_30_012_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x33902C)
#define      main_30_013_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x384030)
#define      main_30_014_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x3CF034)
#define      main_30_015_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x41A038)
#define      main_30_016_320x320_png                                                                          (EXT_FLASH_0804_BASE+0x46503C)
#define      main_61_volon_png                                                                                (EXT_FLASH_0804_BASE+0x4B0040)
#define      main_61_num_0_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4B09A4)
#define      main_61_num_1_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4B4578)
#define      main_61_num_2_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4B814C)
#define      main_61_num_3_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4BBD20)
#define      main_61_num_4_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4BF8F4)
#define      main_61_num_5_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4C34C8)
#define      main_61_num_6_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4C709C)
#define      main_61_num_7_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4CAC70)
#define      main_61_num_8_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4CE844)
#define      main_61_num_9_58x88_png                                                                          (EXT_FLASH_0804_BASE+0x4D2418)
#define      main_61_bg_320x320_png                                                                           (EXT_FLASH_0804_BASE+0x4D5FEC)
#define      main_61_cal_40x40_png                                                                            (EXT_FLASH_0804_BASE+0x520FF0)
#define      main_61_step_40x40_png                                                                           (EXT_FLASH_0804_BASE+0x5222B4)
#define      main_61_weather_Clear_16x16_png                                                                  (EXT_FLASH_0804_BASE+0x523578)
#define      main_61_weather_cloudy_16x16_png                                                                 (EXT_FLASH_0804_BASE+0x52387C)
#define      main_61_weather_Drizzle_16x16_png                                                                (EXT_FLASH_0804_BASE+0x523B80)
#define      main_61_weather_gloomy_16x16_png                                                                 (EXT_FLASH_0804_BASE+0x523E84)
#define      main_61_weather_heavy_rain_16x16_png                                                             (EXT_FLASH_0804_BASE+0x524188)
#define      main_61_weather_heavy_snow_16x16_png                                                             (EXT_FLASH_0804_BASE+0x52448C)
#define      main_61_weather_light_snow_16x16_png                                                             (EXT_FLASH_0804_BASE+0x524790)
#define      main_61_weather_moderate_rain_16x16_png                                                          (EXT_FLASH_0804_BASE+0x524A94)
#define      main_61_weather_moderate_snow_16x16_png                                                          (EXT_FLASH_0804_BASE+0x524D98)
#define      main_61_weather_sleet_16x16_png                                                                  (EXT_FLASH_0804_BASE+0x52509C)
#define      main_61_weather_thunderstorm_16x16_png                                                           (EXT_FLASH_0804_BASE+0x5253A0)
#define      dial_setting_main30_little_120x120_1_png                                                         (EXT_FLASH_0804_BASE+0x5256A4)
#define      dial_setting_main61_little_120x120_1_png                                                         (EXT_FLASH_0804_BASE+0x52FF68)
#define      code_0726_220x220_png                                                                            (EXT_FLASH_0804_BASE+0x53A82C)
#define      hr_alarm_hi_icon_80x80_png                                                                       (EXT_FLASH_0804_BASE+0x55DF60)
#define      hr_alarm_low_icon_80x80_png                                                                      (EXT_FLASH_0804_BASE+0x562A64)




enum {
    LV_LABEL_ALIGN_LEFT, /**< Align text to left */
    LV_LABEL_ALIGN_CENTER, /**< Align text to center */
    LV_LABEL_ALIGN_RIGHT, /**< Align text to right */
    LV_LABEL_ALIGN_AUTO, /**< Use LEFT or RIGHT depending on the direction of the text (LTR/RTL)*/
};




















#endif
