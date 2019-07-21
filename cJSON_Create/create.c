#include "create.h"
#include "cJSON.h"
#include "json_str.h"
#include "stdio.h"

void Create_Simple_JSON(void)
{
/*
{
	"CSDN": "https://blog.csdn.net/whik1194",
	"cnblogs": "https://home.cnblogs.com/u/whik/",
	"Github": "https://github.com/whik/",
	"Blog": "http://www.wangchaochao.top/"
}
*/
    cJSON *root;

    root = cJSON_CreateObject();//创建一个json对象

    cJSON_AddItemToObject(root, "CSDN", cJSON_CreateString("https://blog.csdn.net/whik1194"));
    cJSON_AddItemToObject(root, "cnblogs", cJSON_CreateString("https://home.cnblogs.com/u/whik/"));
    cJSON_AddItemToObject(root, "Github", cJSON_CreateString("https://github.com/whik/"));
    cJSON_AddStringToObject(root, "Blog", "http://www.wangchaochao.top/");

    printf("构建的JSON:\n%s\n", cJSON_Print(root));
    cJSON_Delete(root);
}

void Create_BJTime_JSON(void)
{
/*
{
	"status": "success",
	"result": {
		"timestamp": "ok",
		"datetime_1": "2019-07-21 10:46:57",
		"datetime_2": "2019年07月21日 10时46分57秒",
		"week_1": "0",
		"week_2": "星期日",
		"week_3": "周日",
		"week_4": "Sunday"
	},
	"Blog": "www.wangchaochao.top"
}
*/
    cJSON *root;
    cJSON *result;

    root = cJSON_CreateObject();//创建一个json对象

    result = cJSON_CreateObject();
    //result构建

    cJSON_AddItemToObject(result, "timestamp", cJSON_CreateString("ok"));
//等效于下面
//    cJSON_AddStringToObject(result, "timestamp", "ok");

    cJSON_AddItemToObject(result, "datetime_1", cJSON_CreateString("2019-07-21 10:46:57"));
    cJSON_AddItemToObject(result, "datetime_2", cJSON_CreateString("2019年07月21日 10时46分57秒"));
    cJSON_AddItemToObject(result, "week_1", cJSON_CreateString("0"));
    cJSON_AddItemToObject(result, "week_2", cJSON_CreateString("星期日"));
    cJSON_AddItemToObject(result, "week_3", cJSON_CreateString("周日"));
    cJSON_AddItemToObject(result, "week_4", cJSON_CreateString("Sunday"));

    //等效于cJSON_AddNumberToObject(root, "ok", 1);

    cJSON_AddItemToObject(root, "status", cJSON_CreateString("success"));
    cJSON_AddItemToObject(root, "result", result);
    cJSON_AddStringToObject(root, "Blog", "www.wangchaochao.top");

    printf("构建的JSON:\n%s\n", cJSON_Print(root));
    cJSON_Delete(root);
}

void Create_Array_Str_JSON(void)
{
/*
["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
*/
    cJSON *root;
    const char *strings[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

	root=cJSON_CreateStringArray(strings,7);

	printf("%s\n",cJSON_Print(root));
	cJSON_Delete(root);
}

void Create_Array_JSON(void)
{
    cJSON *root;
    cJSON *forceast;
    cJSON *day1, *day2, *day3;  //数组

    day1 = cJSON_CreateObject();
    day2 = cJSON_CreateObject();
    day3 = cJSON_CreateObject();

    cJSON_AddStringToObject(day1, "date", "2019-07-21");    //日期
    cJSON_AddStringToObject(day1, "cond_txt", "多云");      //天气状况
    cJSON_AddStringToObject(day1, "cond_code", "101");      //天气代码
    cJSON_AddStringToObject(day1, "hum", "23");             //湿度
    cJSON_AddStringToObject(day1, "tmp_H", "31");           //最高温度
    cJSON_AddStringToObject(day1, "tmp_L", "25");           //最低温度

    cJSON_AddStringToObject(day2, "date", "2019-07-22");
    cJSON_AddStringToObject(day2, "cond_txt", "晴");
    cJSON_AddStringToObject(day2, "cond_code", "100");
    cJSON_AddStringToObject(day2, "hum", "20");
    cJSON_AddStringToObject(day2, "tmp_H", "33");
    cJSON_AddStringToObject(day2, "tmp_L", "26");

    cJSON_AddStringToObject(day3, "date", "2019-07-23");
    cJSON_AddStringToObject(day3, "cond_txt", "阵雨");
    cJSON_AddStringToObject(day3, "cond_code", "107");
    cJSON_AddStringToObject(day3, "hum", "45");
    cJSON_AddStringToObject(day3, "tmp_H", "32");
    cJSON_AddStringToObject(day3, "tmp_L", "25");

    forceast = cJSON_CreateArray();
    //注意顺序，索引依次递增
    cJSON_AddItemToArray(forceast, day1);   //元素0
    cJSON_AddItemToArray(forceast, day2);   //元素1
    cJSON_AddItemToArray(forceast, day3);   //元素2

    root = cJSON_CreateObject();    //创建一个json对象

    cJSON_AddStringToObject(root, "status", "ok");
    cJSON_AddItemToObject(root, "weather", forceast);
    cJSON_AddStringToObject(root, "update", "2019-07-21 11:00");
    cJSON_AddStringToObject(root, "Blog", "www.wangchaochao.top");
   //等效于:cJSON_AddItemToObject(root, "update", cJSON_CreateString("2019-07-21 11:00");

    printf("构建的JSON:\n%s\n", cJSON_Print(root));
    cJSON_Delete(root);
}
/*
{
	"status": "ok",
	"weather": [{
		"date": "2019-07-21",
		"cond_txt": "多云",
		"cond_code": "101",
		"hum": "23",
		"tmp_H": "31",
		"tmp_L": "25"
	}, {
		"date": "2019-07-22",
		"cond_txt": "晴",
		"cond_code": "100",
		"hum": "20",
		"tmp_H": "33",
		"tmp_L": "26"
	}, {
		"date": "2019-07-23",
		"cond_txt": "阵雨",
		"cond_code": "107",
		"hum": "45",
		"tmp_H": "32",
		"tmp_L": "25"
	}],
	"update": "2019-07-21 11:00",
	"Blog": "www.wangchaochao.top"
}
*/

//构建包含多个数组的JSON字符串
void Create_Array_Nest_JSON(void)
{
    struct oil_stu{
        char *city;          //城市名称
        char *oil_92_price;  //92号汽油价格
        char *oil_95_price;
        char *oil_98_price;
        char *oil_0_price;
    };

    cJSON *root;
    cJSON *data;  //包含多个数组
    cJSON *table, *data_bj, *data_sh, *data_js, *data_tj;

    const char *bj_str[5] = {"北京", "6.78", "7.21", "8.19", "6.45"};
    const char *sh_str[5] = {"上海", "6.74", "7.17", "7.87", "6.39"};
    const char *js_str[5] = {"江苏", "6.75", "7.18", "8.06", "6.37"};
    const char *tj_str[5] = {"天津", "6.77", "7.15", "8.07", "6.41"};
    const char *talbe_str[5] = {"地区", "92号汽油", "95号汽油", "98号汽油", "0号柴油"};

    data_bj = cJSON_CreateStringArray(bj_str, 5);   //只包含5个字符串的数组
    data_sh = cJSON_CreateStringArray(sh_str, 5);
    data_js = cJSON_CreateStringArray(js_str, 5);
    data_tj = cJSON_CreateStringArray(tj_str, 5);
    table = cJSON_CreateStringArray(talbe_str, 5);

    data = cJSON_CreateArray();
    cJSON_AddItemToArray(data, table);
    cJSON_AddItemToArray(data, data_bj);
    cJSON_AddItemToArray(data, data_sh);
    cJSON_AddItemToArray(data, data_js);
    cJSON_AddItemToArray(data, data_tj);

    root = cJSON_CreateObject();

    cJSON_AddStringToObject(root, "status", "ok");
    cJSON_AddStringToObject(root, "msg", "2019-07-21 11:00");
    cJSON_AddStringToObject(root, "update", "2019-07-21 11:00");
    cJSON_AddItemToObject(root, "data", data);
    cJSON_AddStringToObject(root, "About", "wcc");
    cJSON_AddStringToObject(root, "Blog", "www.wangchaochao.top");

    printf("构建的JSON:\n%s\n", cJSON_Print(root));
    cJSON_Delete(root);
}
/*
{
	"status": "ok",
	"msg": "全国各省份汽柴油价格信息",
	"update": "2019-07-21",
	"data": [
		["地区", "92号汽油", "95号汽油", "98号汽油", "0号柴油"],
		["北京", "6.78", "7.21", "8.19", "6.45"],
		["上海", "6.74", "7.17", "7.87", "6.39"],
		["江苏", "6.75", "7.18", "8.06", "6.37"],
		["天津", "6.77", "7.15", "8.07", "6.41"]
	],
	"About": "wcc",
	"Blog": "www.wangchaochao.top"
}
*/
