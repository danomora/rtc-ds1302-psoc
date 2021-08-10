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
#include "ds1302.h"

uint8 count;

uint8 count1;
int main(void)

{
     /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    CyGlobalIntEnable;
    
    Time Actual_Date;
    DS1302_Start();
    
    for(;;){
        
        
        DS1302_Read_Time(&Actual_Date);
        count = Actual_Date.second;
        count = Actual_Date.hour;
        count = Actual_Date.minute;
        count = Actual_Date.year;
        count1 = __DATE__[0];
        
        
        count = 2;
    }
}





/* [] END OF FILE */
