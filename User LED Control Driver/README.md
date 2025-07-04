

# GPIO OUT DRIVER to Blink User LED on STM32L4R5ZI-P (Without HAL)

## Project Title

GPIO LED Blink on STM32L4R5ZI-P Using Register-Level (CMSIS) Programming

## Objective

To blink the onboard LD2 (blue) LED connected to PB7 on the STM32L4R5ZI-P Nucleo board using CMSIS-based register-level programming. This is achieved without using STM32 HAL or CubeMX drivers. A custom GPIO driver is created, and a delay is implemented using the SysTick timer interrupt.

## Hardware Used

* Microcontroller: STM32L4R5ZIT6P (Cortex-M4)
* Development Board: NUCLEO-L4R5ZI-P
* Onboard LED: LD2 (Blue) connected to GPIO pin PB7

## Development Tools

* STM32CubeIDE
* ARM GNU toolchain (arm-none-eabi-gcc)
* Register-level (CMSIS) programming
* No use of HAL or LL peripheral libraries

## Project Description

This project demonstrates low-level embedded programming by toggling an onboard user LED using register-level access. The application includes custom GPIO control functions and a SysTick-based delay method that uses a global tick counter. The LED toggles every 500 milliseconds based on this delay.

## File Descriptions

### gpio.h (located in Core/Inc)

This file contains macro definitions for the LED pin and port. It declares the following functions:

* gpio\_init: Initializes PB7 as a general-purpose push-pull output.
* led\_on: Turns the LED on by setting the appropriate GPIO bit.
* led\_off: Turns the LED off by resetting the GPIO bit.
* led\_toggle: Toggles the LED state using the output data register.

### gpio.c (located in Core/Src)

This file implements the GPIO initialization and LED control functions declared in gpio.h. It uses direct CMSIS register access to:

* Enable the GPIOB clock via RCC AHB2 peripheral
* Set PB7 to output mode
* Configure output type as push-pull
* Disable pull-up and pull-down resistors
* Toggle the output state of PB7 using ODR and BSRR registers

### main.c (located in Core/Src)

This is the entry point of the application. It:

* Declares and defines a global variable tick of type volatile uint32\_t
* Configures the SysTick timer to interrupt every 1 millisecond using SysTick\_Config
* Implements a delay\_ms function that waits based on the tick counter
* Calls gpio\_init once and toggles the LED in an infinite loop with a 500 ms delay using led\_toggle

### stm32l4xx\_it.c (located in Core/Src)

This file contains the interrupt service routines. The default SysTick\_Handler was modified:

* The HAL\_IncTick function was removed
* A custom tick counter increment (tick++) was added
* To access the tick variable defined in main.c, the line extern volatile uint32\_t tick; was added at the top of this file

No globals.h file was used; the global variable was accessed using the extern keyword directly in the interrupt source file.

## Key Modifications

* Default HAL tick handler was disabled in favor of a custom tick variable
* SysTick\_Handler was rewritten to increment tick manually
* No HAL or auto-generated peripheral drivers were used
* All GPIO configuration and control was done through CMSIS register-level access
* All LED operations are isolated through a reusable driver structure

## Conclusion

This project serves as a clean, minimal, and modular example of embedded driver development on STM32 microcontrollers using CMSIS. It teaches hardware-level control of GPIO, interrupt-driven timing, and separation of hardware abstraction logic into a driver structure. It is suitable for learning, prototyping, and performance-critical applications where HAL overhead is undesirable.


