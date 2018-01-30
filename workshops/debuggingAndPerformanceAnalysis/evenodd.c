#include <stdio.h>

int main() {
  int x;
  x = 1;
  while (x > 0) {
    if (x % 2 == 0)
      printf("Even\n");
    else
      printf("Odd\n");
    x++;
  }
  return 0;
}
