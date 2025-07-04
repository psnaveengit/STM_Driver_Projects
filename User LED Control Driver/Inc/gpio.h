//Custom GPIO LED Driver Header


#ifndef GPIO_H_
#define GPIO_H_

#include "stm32l4r5xx.h"

// LED pin configuration
#define LED_PORT       GPIOB
#define LED_PIN        7
#define LED_MASK       (1U << LED_PIN)

void gpio_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);

#endif /* GPIO_H_ */
