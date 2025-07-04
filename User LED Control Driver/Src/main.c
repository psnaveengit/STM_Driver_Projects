/*
 * Toggle LD2 (Blue LED) on PB7
 * Board: NUCLEO-L4R5ZI-P
 * LED: LD2 - Blue - Connected to PB7
 * Method: CMSIS Register-level (No HAL)
 */

#include "gpio.h"

// Global tick counter
volatile uint32_t tick = 0;

// Millisecond delay function
void delay_ms(uint32_t ms) {
    uint32_t start = tick;
    while ((tick - start) < ms);
}

int main(void) {
    gpio_init();

    // Configure SysTick to trigger every 1 ms
    // SystemCoreClock is defined by CMSIS to match your system (typically 80 MHz)
    SysTick_Config(SystemCoreClock / 1000);  // 1ms tick

    while (1) {
        led_toggle();
        delay_ms(5000);  // 5000 ms delay
    }
}
