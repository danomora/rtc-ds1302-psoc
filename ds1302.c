#include "ds1302.h"


char data_read(unsigned char data_out)
{
    char tmp;
    char tmp2;
    char data_in = 0;
    uint8 i;
    uint8 j;
    dat_Write(1);
    ce_Write(1);
    sclk_Write(0);
    for(i=8;i>=1;i--)
        {
         tmp2 = (data_out >> (8-i)) & 0x01;
         dat_Write(tmp2);
         CyDelay(1); 
         sclk_Write(1);
         CyDelayUs(10);
         dat_Write(0);
         CyDelay(1);
         sclk_Write(0);
        }
    for(j=8;j>=1;j--)
        {
        tmp = dat_Read();
        data_in |= (tmp << (8-j)); 
        CyDelay(1);
        sclk_Write(1);
        CyDelay(1);
        sclk_Write(0);
        }
    ce_Write(0);
    sclk_Write(0);
    CyDelayUs(10);
    dat_Write(0);
    i=0;
    j=0;
    return data_in;
}
void data_write(unsigned char reg_add, unsigned char data_out)
{
    char tmp;
    char tmp2;
    uint8 i;
    uint8 j;
    ce_Write(1);
    sclk_Write(0);
    for(i=8;i>=1;i--)
        {
         tmp2 = (reg_add >> (8-i)) & 0x01;
         dat_Write(tmp2);
         CyDelayUs(10);
         sclk_Write(1);
         CyDelay(1);
         dat_Write(0); 
         sclk_Write(0);
         CyDelay(1); 
        }

    for(j=8;j>=1;j--)
        {
        tmp = (data_out >> (8-j)) & 0x01;
        dat_Write(tmp);
        CyDelayUs(10);
        sclk_Write(1);
        CyDelay(1);
        dat_Write(0);
        sclk_Write(0);
        CyDelay(1); 
        }
    ce_Write(0);
    CyDelayUs(10);
    sclk_Write(0);
    dat_Write(0);
    i=0;
    j=0;
}
void DS1302_Start(){
data_write(0x80,0x00);
data_write(0x8E,0x80);
}
void DS1302_Write_Time(Time Time){
    data_write(0x8E,0x00);
    data_write(0x80,Time.second);
    data_write(0x82,Time.minute);
    data_write(0x84,Time.hour);
    data_write(0x86,Time.date);
    data_write(0x88,Time.month);
    data_write(0x8a,Time.day_of_week);
    data_write(0x8c,Time.year);
    data_write(0x8E,0x80);
}

void DS1302_Read_Time(Time *Time){
    Time -> second = data_read(0x81);
    Time -> minute = data_read(0x83);
    Time -> hour = data_read(0x85) & 0x7f ;
    Time -> date = data_read(0x87);
    Time -> month = data_read(0x89);
    Time -> day_of_week = data_read(0x8b);
    Time -> year = data_read(0x8d);
}

void DS1302_Update_Time(){
    Time Time;
    Time.hour = ((__TIME__[0]) - '0') << 4  ;
    Time.hour |= __TIME__[1] - '0';
    Time.minute = ((__TIME__[3]) - '0') << 4  ;
    Time.minute |= __TIME__[4] - '0';
    Time.second = ((__TIME__[6]) - '0') << 4  ;
    Time.second |= __TIME__[7] - '0';
    Time.date = ((__DATE__[4]) - '0') << 4  ;
    Time.date |= __DATE__[5] - '0';
    Time.year = ((__DATE__[9]) - '0') << 4  ;
    Time.year |= ((__DATE__[10]) - '0');
    
    if (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n'){
    Time.month = 1;
    }
    else if (__DATE__[0] == 'F'){
    Time.month = 2;
    }
    else if (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r'){
    Time.month = 3;
    }
    else if (__DATE__[0] == 'A' && __DATE__[1] == 'p'){
    Time.month = 4;
    }
    else if(__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y'){
    Time.month = 5;
    }
    else if(__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n'){
    Time.month = 6;
    }
    else if (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l'){
    Time.month = 7;
    }
    else if (__DATE__[0] == 'A' && __DATE__[1] == 'u'){
    Time.month = 8;
    }
    else if (__DATE__[0] == 'S'){
    Time.month = 9;
    }
    else if (__DATE__[0] == 'O'){
    Time.month = 10;
    }
    else if (__DATE__[0] == 'N'){
    Time.month = 11;
    }
    else if (__DATE__[0] == 'D'){
    Time.month = 12;
    }
    data_write(0x8E,0x00);
    data_write(0x80,Time.second);
    data_write(0x82,Time.minute);
    data_write(0x84,Time.hour);
    data_write(0x86,Time.date);
    data_write(0x88,Time.month);
    data_write(0x8c,Time.year);
    data_write(0x8E,0x80);
    
}