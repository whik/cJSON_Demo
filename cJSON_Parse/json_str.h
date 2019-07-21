#ifndef JSON_STR_H
#define JSON_STR_H

/* json数据解析，示例字符串 */

/*和风天气实况数据*/
char he_now_json[] = "{\"HeWeather6\":[{\"basic\":{\"cid\":\"CN101010700\",\"location\":\"昌平\",\"parent_city\":\"北京\",\"admin_area\":\"北京\",\"cnty\":\"中国\",\"lat\":\"40.21808624\",\"lon\":\"116.23590851\",\"tz\":\"+8.00\"},\"update\":{\"loc\":\"2019-07-20 10:21\",\"utc\":\"2019-07-20 02:21\"},\"status\":\"ok\",\"now\":{\"cloud\":\"96\",\"cond_code\":\"104\",\"cond_txt\":\"阴\",\"fl\":\"28\",\"hum\":\"86\",\"pcpn\":\"0.0\",\"pres\":\"995\",\"tmp\":\"25\",\"vis\":\"4\",\"wind_deg\":\"100\",\"wind_dir\":\"东风\",\"wind_sc\":\"1\",\"wind_spd\":\"4\"}}]}";

/*心知天气实况数据*/
char const seniverse_now_json[] = "{\"results\":[{\"location\":{\"id\":\"WX4FBXXFKE4F\",\"name\":\"北京\",\"country\":\"CN\",\"path\":\"北京,北京,中国\",\"timezone\":\"Asia/Shanghai\",\"timezone_offset\":\"+08:00\"},\"now\":{\"text\":\"晴\",\"code\":\"1\",\"temperature\":\"-7\"},\"last_update\":\"2018-12-06T22:05:00+08:00\"}]}";
/*心知天气3天预报*/
char const seniverse_forcast_json[] = "{\"results\":[{\"location\":{\"id\":\"WS10730EM8EV\",\"name\":\"深圳\",\"country\":\"CN\",\"path\":\"深圳,深圳,广东,中国\",\"timezone\":\"Asia/Shanghai\",\"timezone_offset\":\"+08:00\"},\"daily\":[{\"date\":\"2018-12-06\",\"text_day\":\"阴\",\"code_day\":\"9\",\"text_night\":\"阴\",\"code_night\":\"9\",\"high\":\"25\",\"low\":\"16\",\"precip\":\"\",\"wind_direction\":\"无持续风向\",\"wind_direction_degree\":\"\",\"wind_speed\":\"10\",\"wind_scale\":\"2\"},{\"date\":\"2018-12-07\",\"text_day\":\"阴\",\"code_day\":\"9\",\"text_night\":\"小雨\",\"code_night\":\"13\",\"high\":\"20\",\"low\":\"15\",\"precip\":\"\",\"wind_direction\":\"北\",\"wind_direction_degree\":\"0\",\"wind_speed\":\"15\",\"wind_scale\":\"3\"},{\"date\":\"2018-12-08\",\"text_day\":\"小雨\",\"code_day\":\"13\",\"text_night\":\"小雨\",\"code_night\":\"13\",\"high\":\"17\",\"low\":\"12\",\"precip\":\"\",\"wind_direction\":\"东北\",\"wind_direction_degree\":\"45\",\"wind_speed\":\"15\",\"wind_scale\":\"3\"}],\"last_update\":\"2018-12-06T18:00:00+08:00\"}]}";

/*空气质量，AQI，数据接口:http://api.help.bj.cn/apis/aqi/?id=101060101*/
char const AQI_json[] = "{\"status\": \"0\",\"citye\":\"changchun\",\"city\":\"长春\",\"citycode\":\"101060101\",\"aqi\":\"50\",\"data\": [{\"add\": \"长春\",\"aqi\": \"50\",\"pm25\": \"22\",\"per\": \"优\",\"lv\": \"1\"},{\"add\": \"食品厂\",\"aqi\": \"54\",\"pm25\": \"18\",\"per\": \"良\",\"lv\": \"2\"},{\"add\": \"客车厂\",\"aqi\": \"52\",\"pm25\": \"20\",\"per\": \"良\",\"lv\": \"2\"},{\"add\": \"邮电学院\",\"aqi\": \"35\",\"pm25\": \"24\",\"per\": \"优\",\"lv\": \"1\"},{\"add\": \"劳动公园\",\"aqi\": \"45\",\"pm25\": \"19\",\"per\": \"优\",\"lv\": \"1\"},{\"add\": \"园林处\",\"aqi\": \"45\",\"pm25\": \"21\",\"per\": \"优\",\"lv\": \"1\"},{\"add\": \"净月潭\",\"aqi\": \"46\",\"pm25\": \"30\",\"per\": \"优\",\"lv\": \"1\"},{\"add\": \"甩湾子\",\"aqi\": \"51\",\"pm25\": \"24\",\"per\": \"良\",\"lv\": \"2\"},{\"add\": \"经开区环卫处\",\"aqi\": \"48\",\"pm25\": \"25\",\"per\": \"优\",\"lv\": \"1\"},{\"add\": \"高新区管委会\",\"aqi\": \"51\",\"pm25\": \"16\",\"per\": \"良\",\"lv\": \"2\"},{\"add\": \"岱山公园\",\"aqi\": \"49\",\"pm25\": \"19\",\"per\": \"优\",\"lv\": \"1\"}]}";

/*北京时间同步，数据接口:http://api.k780.com:88/?app=life.time&appkey=10003&sign=b59bc3ef6191eb9f747dd4e83c99f2a4&format=json */
char const bj_time_json[] = "{\"success\":\"1\",\"result\":{\"timestamp\":\"1542456793\",\"datetime_1\":\"2018-11-17 20:13:13\",\"datetime_2\":\"2018年11月17日 20时13分13秒\",\"week_1\":\"6\",\"week_2\":\"星期六\",\"week_3\":\"周六\",\"week_4\":\"Saturday\"}}";

char const oil_price_json[] = "{\"status\":\"0\",\"msg\": \"全国各省份汽柴油价格信息\",\"update\": \"2019-07-21\",\"data\": [[\"地区\", \"92号\", \"95号\", \"98号\", \"0号柴油\"],[\"北京\", \"6.78\", \"7.21\", \"8.19\", \"6.45\"],[\"上海\", \"6.74\", \"7.17\", \"7.87\", \"6.39\"],[\"江苏\", \"6.75\", \"7.18\", \"8.06\", \"6.37\"],[\"天津\", \"6.77\", \"7.15\", \"8.07\", \"6.41\"]],\"About\": \"wcc\",\"Home\": \"www.wangchaochao.top\"}";

#endif // JSON_STR_H
