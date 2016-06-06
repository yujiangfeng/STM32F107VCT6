/**
 * @file   led.c
 * @brief  led驱动程序
 * @author 王晓荣
 * @version 
 * @date 2014-03-19
 */

#include "led.h"

const struct LED led[] =
{
    GPIOD, GPIO_PIN_2,
    GPIOD, GPIO_PIN_3,
    GPIOD, GPIO_PIN_4,
    GPIOD, GPIO_PIN_7,
};

#define NUM_LEDS (sizeof(led)/sizeof(struct LED))


/**
 * @brief  点亮多个LED 
 * @param val 多个LED组合
 * 例如： led_on(LED_0 | LED_1)
 */
void led_on(uint16_t val) 
{
    uint8_t n;
    for(n = 0; n < NUM_LEDS; n++)
    {
        if (val & (1 << n)) 
        {
            HAL_GPIO_WritePin(led[n].port, led[n].pin, GPIO_PIN_SET);        
        }        
    }    
}

/**
 * @brief  关闭多个LED 
 * @param val 多个LED组合
 * 例如： led_off(LED_0 | LED_1)
 */
void led_off(uint16_t val) 
{
    uint8_t n;
    for(n = 0; n < NUM_LEDS; n++)
    {
        if (val & (1 << n)) 
        {
            HAL_GPIO_WritePin(led[n].port, led[n].pin, GPIO_PIN_RESET);        
        }        
    }     
}



