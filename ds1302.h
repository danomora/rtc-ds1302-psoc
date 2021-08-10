/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

typedef struct{
    unsigned char second;
    unsigned char  minute;
    unsigned char  hour;
    unsigned char  date;
    unsigned char  month;
    unsigned char  day_of_week;
    unsigned char  year;
}Time;
void   DS1302_Start();
void   DS1302_Write_Time(Time Time);
void   DS1302_Read_Time(Time *Time);
void   DS1302_Update_Time();

/* [] END OF FILE */
