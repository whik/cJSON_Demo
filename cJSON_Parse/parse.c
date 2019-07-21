#include "parse.h"   //包含示例字符串
#include "cJSON.h"
#include "json_str.h"
#include "stdio.h"

#define LOG(fmt,args...) printf(fmt,##args)

void Parse_HeWeather_Now_Json(void)
{
    cJSON *root;
    cJSON *basic, *update, *status, *now;
    char *str_tmp;

    root = cJSON_Parse(he_now_json);
    if(root)
    {
        LOG("JSON格式正确\n");
        LOG("JSON数据:\n%s\n", cJSON_Print(root));
        root = cJSON_GetObjectItem(root, "HeWeather6");//获取HeWeather6对应的值
        root = cJSON_GetArrayItem(root, 0);
        /*basic键，城市的基本信息*/
        LOG("basic键信息:\n");
        basic = cJSON_GetObjectItem(root,"basic");
        str_tmp = cJSON_GetObjectItem(basic, "cid") ->valuestring;
        LOG("cid: %s\n",str_tmp);
        str_tmp = cJSON_GetObjectItem(basic, "location") ->valuestring;
        LOG("location: %s\n",str_tmp);
        str_tmp = cJSON_GetObjectItem(basic, "parent_city") ->valuestring;
        LOG("parent_city: %s\n",str_tmp);
        str_tmp = cJSON_GetObjectItem(basic, "admin_area") ->valuestring;
        LOG("admin_area: %s\n",str_tmp);
        str_tmp = cJSON_GetObjectItem(basic, "cnty") ->valuestring;
        LOG("cnty: %s\n",str_tmp);

        str_tmp = cJSON_GetObjectItem(basic, "lat") ->valuestring;  //纬度
        LOG("lat: %s\n",str_tmp);
        str_tmp = cJSON_GetObjectItem(basic, "lon") ->valuestring;  //经度
        LOG("lon: %s\n",str_tmp);
        str_tmp = cJSON_GetObjectItem(basic, "tz") ->valuestring;   //时区
        LOG("tz: %s\n\n",str_tmp);

        /*update键，更新时间*/
        LOG("update键信息:\n");

        update = cJSON_GetObjectItem(root,"update");
        str_tmp = cJSON_GetObjectItem(update, "loc") ->valuestring; //按当地时间
        LOG("loc: %s\n",str_tmp);
        str_tmp = cJSON_GetObjectItem(update, "utc") ->valuestring; //按UTC时间
        LOG("utc: %s\n\n",str_tmp);

        /*status键，解析状态*/
        LOG("status键信息:\n");
        str_tmp = cJSON_GetObjectItem(root,"status")->valuestring;   //获取解析状态字符串
        LOG("status: %s\n\n",str_tmp);

        /*now键，实时天气*/
        LOG("now键信息:\n");
        now = cJSON_GetObjectItem(root,"now");
        str_tmp = cJSON_GetObjectItem(now, "cloud")->valuestring;
        LOG("cloud: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(now, "cond_txt")->valuestring;
        LOG("cond_txt: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(now, "tmp")->valuestring;
        LOG("tmp: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(now, "wind_dir")->valuestring;
        LOG("wind_dir: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(now, "wind_sc")->valuestring;   //
        LOG("wind_sc: %s\n\n", str_tmp);
    }
    else
    {
        LOG("Error before:\n[%s]\n",cJSON_GetErrorPtr());
    }
    cJSON_Delete(root);     //调用cJSON_Print时才需要

}

void Parse_Seniverse_Now_Json(void)
{
    cJSON *root;
    cJSON *location, *now, *last_update;
    char *str_tmp;

    root = cJSON_Parse(seniverse_now_json);
    if(root)
    {
        LOG("JSON格式正确\n");
        LOG("JSON字符:%s\n", cJSON_Print(root));
        root = cJSON_GetObjectItem(root, "results");
        root = cJSON_GetArrayItem(root, 0);

        /*location键，城市信息*/
        LOG("location键信息:\n");
        location = cJSON_GetObjectItem(root, "location");
        str_tmp = cJSON_GetObjectItem(location, "id")->valuestring;
        LOG("id: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(location, "name")->valuestring;
        LOG("name: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(location, "country")->valuestring;
        LOG("country: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(location, "path")->valuestring;
        LOG("path: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(location, "timezone")->valuestring;
        LOG("timezone: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(location, "timezone_offset")->valuestring;
        LOG("timezone_offset: %s\n\n", str_tmp);

        /*now键，实时天气*/
        LOG("now键信息:\n");
        now = cJSON_GetObjectItem(root, "now");
        str_tmp = cJSON_GetObjectItem(now, "text")->valuestring;
        LOG("text: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(now, "code")->valuestring;
        LOG("code: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(now, "temperature")->valuestring;
        LOG("temperature: %s\n", str_tmp);
        /*last_update键，更新时间*/
        str_tmp = cJSON_GetObjectItem(root, "last_update")->valuestring;
        LOG("\nlast_update: %s\n", str_tmp);
    }
    else
    {
        LOG("Error before:\n[%s]\n",cJSON_GetErrorPtr());
    }

    cJSON_Delete(root);     //调用cJSON_Print时才需要
}

void Parse_Seniverse_Forecast_Json(void)
{
    cJSON *root;
    cJSON *location, *daily, *day;
    char *str_tmp;
    int num = 0;

    root = cJSON_Parse(seniverse_forcast_json);
    if(root)
    {
        LOG("JSON格式正确\n");
        LOG("JSON数据:%s \n", cJSON_Print(root));
        /*results键*/
        root = cJSON_GetObjectItem(root, "results");
        root = cJSON_GetArrayItem(root, 0);

        /*location键，城市信息*/
        LOG("location键信息: \n");
        location = cJSON_GetObjectItem(root, "location");
        str_tmp = cJSON_GetObjectItem(location, "id")->valuestring;
        LOG("id: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(location, "name")->valuestring;
        LOG("name: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(location, "country")->valuestring;
        LOG("country: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(location, "path")->valuestring;
        LOG("path: %s\n\n", str_tmp);

        /*daily键，预报信息*/
        LOG("daily键信息: \n");
        daily = cJSON_GetObjectItem(root, "daily");
        //预报3天的天气
        for(num = 0; num <= 2; num++)
        {
            day = cJSON_GetArrayItem(daily, num);   //当日天气，第0个元素
            str_tmp = cJSON_GetObjectItem(day, "date")->valuestring;    //白天天气
            LOG("date: %s\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(day, "text_day")->valuestring;    //白天天气
            LOG("text_day: %s\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(day, "low")->valuestring;    //白天天气
            LOG("low: %s\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(day, "high")->valuestring;    //白天天气
            LOG("high: %s\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(day, "wind_direction")->valuestring;    //白天天气
            LOG("wind_direction: %s\n", str_tmp);
            str_tmp = cJSON_GetObjectItem(day, "wind_scale")->valuestring;    //白天天气
            LOG("wind_scale: %s\n\n", str_tmp);
        }
    }
    else
    {
        LOG("Error before:\n[%s]\n",cJSON_GetErrorPtr());
    }
    cJSON_Delete(root);
}

void Parse_AQI_Json(void)
{
    cJSON *root, *data;
    char *str_tmp;

    root = cJSON_Parse(AQI_json);
    if(root)
    {
        LOG("JSON格式正确");
        LOG("JSON字符串: \n%s\n", cJSON_Print(root));
        str_tmp = cJSON_GetObjectItem(root, "city")->valuestring;
        LOG("city: %s \n", str_tmp);
        str_tmp = cJSON_GetObjectItem(root, "aqi")->valuestring;
        LOG("aqi: %s \n", str_tmp);
        str_tmp = cJSON_GetObjectItem(root, "citycode")->valuestring;
        LOG("citycode: %s\n\n", str_tmp);

        data = cJSON_GetObjectItem(root, "data");
        data = cJSON_GetArrayItem(data, 3); //邮电学院
        str_tmp = cJSON_GetObjectItem(data, "add")->valuestring;
        LOG("add： %s \n", str_tmp);
        str_tmp = cJSON_GetObjectItem(data, "aqi")->valuestring;
        LOG("aqi: %s \n", str_tmp);
        str_tmp = cJSON_GetObjectItem(data, "pm25")->valuestring;
        LOG("pm25: %s \n", str_tmp);
        str_tmp = cJSON_GetObjectItem(data, "per")->valuestring;
        LOG("per: %s \n", str_tmp);
        str_tmp = cJSON_GetObjectItem(data, "lv")->valuestring;
        LOG("lv: %s \n", str_tmp);
    }
    else
    {
        LOG("Error before:\n[%s]\n",cJSON_GetErrorPtr());
    }
    cJSON_Delete(root);
}
//解析
void Parse_BJTime_Json(void)
{
    cJSON *root, *result;
    char *str_tmp;

    root = cJSON_Parse(bj_time_json);
    if(root)
    {
        LOG("JSON格式正确\n");
        LOG("JSON字符串:\n%s\n", cJSON_Print(root));

        /*success键，状态信息*/
        str_tmp = cJSON_GetObjectItem(root, "success")->valuestring;
        LOG("success: %s\n", str_tmp);

        /*result键，时间信息*/
        result = cJSON_GetObjectItem(root, "result");
        str_tmp = cJSON_GetObjectItem(result, "timestamp")->valuestring;
        LOG("timestatmp: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(result, "datetime_1")->valuestring;
        LOG("datetime_1: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(result, "datetime_2")->valuestring;
        LOG("datetime_2: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(result, "week_1")->valuestring;
        LOG("week_1: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(result, "week_2")->valuestring;
        LOG("week_2: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(result, "week_3")->valuestring;
        LOG("week_3: %s\n", str_tmp);
        str_tmp = cJSON_GetObjectItem(result, "week_4")->valuestring;
        LOG("week_4: %s\n", str_tmp);
    }
    else
    {
        LOG("Error before:\n[%s]\n",cJSON_GetErrorPtr());
    }
    cJSON_Delete(root);
}

//解析数组嵌套的JSON字符串
void Parse_Oil_Price_Json(void)
{
    cJSON *root, *data;
    cJSON *tmp;

    char *str_tmp;
    int dat_idx = 0, city_idx = 0;

    root = cJSON_Parse(oil_price_json);
    if(root)
    {
        LOG("JSON格式正确\n");
        LOG("JSON字符串:\n%s\n", cJSON_Print(root));

        str_tmp = cJSON_GetObjectItem(root, "status")->valuestring;
        LOG("status: %s\n", str_tmp);   //数据状态
        str_tmp = cJSON_GetObjectItem(root, "msg")->valuestring;
        LOG("msg: %s\n", str_tmp);   //数据状态
        str_tmp = cJSON_GetObjectItem(root, "update")->valuestring;
        LOG("update: %s\n\n", str_tmp);   //数据状态

        /*data键，城市油价信息*/
        data = cJSON_GetObjectItem(root, "data");   //是一个数组， 包含5个元素，每个元素也是数组，是一个包含了5个元素的数组

        for(dat_idx = 0; dat_idx <= 4; dat_idx++)
        {
            tmp = cJSON_GetArrayItem(data, dat_idx);  //索引信息，地区，92、95、98、0
            for(city_idx = 0; city_idx <= 4; city_idx++)
            {
                str_tmp = cJSON_GetArrayItem(tmp, city_idx)->valuestring;   //第一个数组的 第0个元素
                LOG("%s  ", str_tmp);
            }
            LOG("\n");
        }

/*
        tmp = cJSON_GetArrayItem(data, 4);  //索引信息，地区，92、95、98、0
        str_tmp = cJSON_GetArrayItem(tmp, 0)->valuestring;   //第一个数组的 第0个元素
        LOG("%s  ", str_tmp);
        str_tmp = cJSON_GetArrayItem(tmp, 1)->valuestring;   //第一个数组的 第0个元素
        LOG("%s  ", str_tmp);
        str_tmp = cJSON_GetArrayItem(tmp, 2)->valuestring;   //第一个数组的 第0个元素
        LOG("%s  ", str_tmp);
        str_tmp = cJSON_GetArrayItem(tmp, 3)->valuestring;   //第一个数组的 第0个元素
        LOG("%s  ", str_tmp);
        str_tmp = cJSON_GetArrayItem(tmp, 4)->valuestring;   //第一个数组的 第0个元素
        LOG("%s  ", str_tmp);
*/
        str_tmp = cJSON_GetObjectItem(root, "About")->valuestring;
        LOG("\nAbout: %s\n", str_tmp);   //数据状态
        str_tmp = cJSON_GetObjectItem(root, "Home")->valuestring;
        LOG("Home: %s\n", str_tmp);   //数据状态

    }
    else
    {
        LOG("Error before:\n[%s]\n",cJSON_GetErrorPtr());
    }
    cJSON_Delete(root);
}








