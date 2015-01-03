#include <stddef.h>

extern int putchar(int c);

void print(const char *string, size_t len) {
  for (size_t i=0;i<len;i++) {
    putchar(string[i]);
  }
}

const char msg[] = "Hello, world!\n";

void main() {
  print(msg, sizeof(msg));
}
