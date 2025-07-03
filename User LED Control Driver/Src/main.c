/*
 * Toggle LD2 (Blue LED) on PB7
 * Board: NUCLEO-L4R5ZI-P
 * LED: LD2 - Blue - Connected to PB7
 * Method: CMSIS Register-level (No HAL)
 */

#include "stm32l4r5xx.h"

void delay(volatile uint32_t t) {
    while (t--);
}

int main(void) {
    // Enable clock for GPIOB
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    // Set PB7 as General Purpose Output
    GPIOB->MODER &= ~(3U << (7 * 2)); // Clear bits
    GPIOB->MODER |=  (1U << (7 * 2)); // Set as Output (01)

    // Set Output Type to Push-Pull
    GPIOB->OTYPER &= ~(1U << 7);

    // Set Output Speed to Low (optional)
    GPIOB->OSPEEDR &= ~(3U << (7 * 2));

    // No Pull-up / Pull-down
    GPIOB->PUPDR &= ~(3U << (7 * 2));

    while (1) {
        // Toggle PB7 (LD2)
        GPIOB->ODR ^= (1U << 7);
        delay(500000); // crude delay
    }
}
