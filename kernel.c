#include <stddef.h>

volatile unsigned char * const UART0_PTR = (unsigned char *)0x0101f1000;

void print(const char *string, size_t len) {
  for (size_t i=0;i<len;i++) {
    *UART0_PTR = string[i];
  }
}

const char msg[] = "Hello, world!";

void main() {
  print(msg, sizeof(msg));
}
