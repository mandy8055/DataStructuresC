#include "stackImpl.h"
#include <stdio.h>

int main(void) {
  push(20);
  push(34);
  push(12);
  printf("Popped Element: %d\n", pop());
  printf("Element at the top of the stack: %d\n", peek());
  return 0;
}
