#include <stdio.h>

int main() {
  const char *helloStr = "Hello World";

  fprintf(stdout, "%s\n", helloStr);

  FILE *textFile = fopen("hello.txt", "w");
  if (textFile == NULL) {
    fclose(textFile);
    return 1;
  }
  fprintf(textFile, "%s\n", helloStr);
  fclose(textFile);

  FILE *binaryFile = fopen("hello.bin", "wb");
  if (binaryFile == NULL) {
    fclose(binaryFile);
    return 1;
  }
  fprintf(binaryFile, "%s\n", helloStr);
  fclose(binaryFile);

  return 0;
}