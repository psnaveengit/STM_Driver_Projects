//Custom GPIO LED Driver Source


#include "gpio.h"

void gpio_init(void) {
    // Enable clock for GPIOB
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;

    // Configure PB7 as output (MODER = 01)
    LED_PORT->MODER &= ~(3U << (LED_PIN * 2)); // Clear bits
    LED_PORT->MODER |=  (1U << (LED_PIN * 2)); // Set to output

    // Set push-pull type
    LED_PORT->OTYPER &= ~(1U << LED_PIN);

    // Set low speed
    LED_PORT->OSPEEDR &= ~(3U << (LED_PIN * 2));

    // No pull-up, pull-down
    LED_PORT->PUPDR &= ~(3U << (LED_PIN * 2));
}

void led_on(void) {
    LED_PORT->BSRR = LED_MASK;
}

void led_off(void) {
    LED_PORT->BSRR = (LED_MASK << 16);
}

void led_toggle(void) {
    LED_PORT->ODR ^= LED_MASK;
}
