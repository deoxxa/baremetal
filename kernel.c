/*
  C-Library stubs introduced for newlib
*/

#include <string.h>
#include <stdlib.h>

#include "rpi-gpio.h"

/** GPIO Register set */
volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;

/** Main function - we'll never return from here */
void kernel_main(unsigned int r0, unsigned int r1, unsigned int atags) {
  int loop;
  /* Allocate a block of memory for counters */
  unsigned int* counters;

  gpio[GPIO_GPFSEL1] |= (1 << 18);
  gpio[GPIO_GPSET0] = (1 << 16);

  counters = malloc(1024 * sizeof(unsigned int));

  /* Failed to allocate memory! */
  if (counters == NULL) {
    while(1) {
      /* Trap here */
    }
  }

  for (loop=0;loop<1024;loop++) {
    counters[loop] = 0;
  }

  /* Write 1 to the GPIO16 init nibble in the Function Select 1 GPIO
     peripheral register to enable GPIO16 as an output */
  gpio[GPIO_GPFSEL1] |= (1 << 18);

  /* Never exit as there is no OS to exit to! */
  while (1) {
    /* Set the GPIO16 output high (Turn OK LED off) */
    gpio[GPIO_GPSET0] = (1 << 16);

    for (counters[0]=0;counters[0]<500000;counters[0]++) {
    }

    /* Set the GPIO16 output low (Turn OK LED on) */
    gpio[GPIO_GPCLR0] = (1 << 16);

    for (counters[1]=0;counters[1]<500000;counters[1]++) {
    }
  }
}
