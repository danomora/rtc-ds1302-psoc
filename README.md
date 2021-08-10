# rtc-ds1302-psoc

System Interface :
----------------

| Pins   | Io | Notes |
| -------- | ---- | --------------------- |
| sclk | output | Syncronous software clock for data tranfer |
| dat | bidir | Input/Output for data tranfer | 
| ce | output | Chip enable |

sclk pin is a normal output pin without hardware connection.
dat pin is a bidirectional pin with open low, high drives output mode and input buffer enabled.
ce is an output pin.

connection between ds1302 dat and psoc dat pin needs an 5k resistor connected to earth.


Contains:
An entire psoc creator project called rtc .
1. ds1302.h   ---- Headers for c functions
2. ds1302.c ---- Functions in c

3. main.c ---- Example using the library.

How to use:
1. import the library #include "ds1302.h"
2. Start a new struct called Time (defined in ds1302.h)
Time Actual_Date;
    
4. Then DS1302_Start() and DS1302_Read_Time(&Actual_Date);.

The struct Time contains:
typedef struct{
    unsigned char second;
    unsigned char  minute;
    unsigned char  hour;
    unsigned char  date;
    unsigned char  month;
    unsigned char  day_of_week;
    unsigned char  year;
}Time;

If you want to update time to compiled time and date. You could do this
DS1302_Update_Time(); in your code.

Questions:
dmorang@hotmail.com

https://www.linkedin.com/in/danmorang/

Daniel Moran.
