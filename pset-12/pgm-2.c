#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char finalString[1000] = "";
  for (int i = 0; i < argc; i++) {
    printf("arg %02d :: %s\n", i, argv[i]);
    strcat(finalString, argv[i]);
  }
  printf("combined: %s\n", finalString);
  return 0;
}