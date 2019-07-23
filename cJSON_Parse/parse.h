#ifndef PARSE_H
#define PARSE_H

#include <stdlib.h>
#include <stdio.h>

void Parse_HeWeather_Now_Json(void);
void Parse_Seniverse_Now_Json(void);
void Parse_Seniverse_Forecast_Json(void);
void Parse_AQI_Json(void);
void Parse_BJTime_Json(void);
void Parse_Oil_Price_Json(void);
void Parse_File_Json(void);
char* textFileRead(char* filename);
int get_file_line_number(char *filename);


#endif // PARSE_H
