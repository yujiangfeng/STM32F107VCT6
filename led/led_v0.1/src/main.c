/**
 * @file     main.c
 * @brief    1个LED闪烁范例
 * @author   王晓荣
 * @version 
 * @date     2014-10-26
 */ 
               
int main(void)
{    
    int           i;
    unsigned int* p_sfr;   
    
    p_sfr  = (void*)0x40021018;
    *p_sfr = 0x0020;                
    p_sfr  = (void*)0x40011400;
    *p_sfr = 0x0200;               
    
    while(1)
    {
        p_sfr  = (void*)0x40011410;
        *p_sfr = 0x0004;            
        for(i = 0; i < 5000000; i++);  		
        p_sfr  = (void*)0x40011414;
        *p_sfr = 0x0004;         
        for(i = 0; i < 5000000; i++);  
    }
}
