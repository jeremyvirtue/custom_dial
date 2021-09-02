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
  int16_t start_arc;   //指针开始角度
  int16_t end_arc;     //指针结束角度
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
  uint32_t img_addr[20];    //图片nandflash相对地址
	uint8_t  data_mode;//0:保留0 位置不变 1：删除空余的0 位置左靠  2：删除空余的0 数据右靠
};
typedef struct _custom_dial_more_img custom_dial_more_img;



//GIF
struct _custom_dial_gif{
  uint8_t type;
  uint8_t data_type;  //数据类型
  uint16_t x;         //左上角x坐标
  uint16_t y;         //左上角y坐标 
  uint32_t img_addr[100];    //图片nandflash相对地址
};
typedef struct _custom_dial_gif custom_dial_gif;

//大类型
enum _enum_custom_dial_type{
	dial_type_null = 0,
	dial_type_image,
	dial_type_pointer,
	dial_type_arc_bar,
	dial_type_chart_bar,
	dial_type_text,
	dial_type_more_img,
	dial_type_gif,
};
typedef enum _enum_custom_dial_type enum_custom_dial_type;

enum _enum_custom_dial_data_pointer{//指针数据类型
	dial_data_pointer_null,
	dial_data_hour_pointer = 1,
	dial_data_min_pointer = 2,
	dial_data_sec_pointer = 3, 
	dial_data_power_pointer = 4, 
	dial_data_week_pointer = 5, 
	dial_data_month_pointer = 6, 
 
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

	dial_data_img_blue 		= 20,			//是否有蓝牙 0关 1开		
	dial_data_img_alarm 	= 21,			//是否有闹钟 0无 1有		
	dial_data_img_disturb = 22,		//是否开勿扰 0关 1开		
	dial_data_img_power 	= 23,			//电池电量等级 0：0~4 1：5~29 	2：30~49	3：50~79		4：80~100		


};
typedef enum _enum_custom_dial_data_more_img enum_custom_dial_data_more_img;

enum _enum_custom_dial_data_gif{//gif数据类型
	dial_data_gif_null,
	dial_data_gif_normal,
	dial_data_gif_single,
};
typedef enum _enum_custom_dial_data_gif enum_custom_dial_data_gif;

 enum _enum_custom_text_data//文本数据类型
 {
	dial_data_text_null = 0,
	dial_data_text_hour_high= 1,	//时钟高位
	dial_data_text_hour_low= 2,   //时钟低位
	dial_data_text_min_high= 3,		//分钟高位
	dial_data_text_min_low= 4,		//分钟低位 
	dial_data_text_heart= 5,//心率
	dial_data_text_year= 6,//年（数字）
	dial_data_text_month= 7,//月 01 02 12（个位前面有个0）
	dial_data_text_day=8,//日 01 01 12（个位前面有个0）
	dial_data_text_week=9,//仅支持英文 MON FRI SUN...
	dial_data_text_week_lanuguage=10,//支持多语言 仅支持20 24 30文本大小 日 一 二 三 ...
	dial_data_text_high_tem=11,//最大温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_low_tem=12,//最小温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_now_tem=13,//当前温度 （个位前面有个0） oC/oF(单位根据当前状态)
	dial_data_text_step=14,	 //当前步数
	dial_data_text_sleep=15,  //睡眠时间
	dial_data_text_run_time=16, //运动时间
	dial_data_text_kal=17,			//卡路里
	dial_data_text_power=18,			//当前电量 数字 后面加个%
	dial_data_text_custom=19,//自定义文本 20个char大小
  dial_data_text_am_pm=20,//am or pm
	dial_data_text_power2=21,			//当前电量 数字 后面不加%
	dial_data_text_sec=22,			//秒 两位数
	dial_data_text_distance = 23,//运动距离

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

	dial_data_16x16_ext=1,//不支持多语言
	dial_data_20x20_ext=2,
	dial_data_24x24_ext=3,
	dial_data_30x30_ext=4,
	dial_data_40x40_ext=5,//不支持多语言
	dial_data_50x50_ext=6,//不支持多语言
	dial_data_60x60_ext=7,//不支持多语言
	dial_data_80x80_ext=8,//不支持多语言
};
typedef enum _enum_custom_text_size enum_custom_text_size;


 


enum {
    LV_LABEL_ALIGN_LEFT, /**< Align text to left */
    LV_LABEL_ALIGN_CENTER, /**< Align text to center */
    LV_LABEL_ALIGN_RIGHT, /**< Align text to right */
    LV_LABEL_ALIGN_AUTO, /**< Use LEFT or RIGHT depending on the direction of the text (LTR/RTL)*/
};




















#endif
