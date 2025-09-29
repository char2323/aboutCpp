#include <cstdio>
#include <stdio.h>

// void try_const() {
//   int a = 10;
//   const int &b = 10;
//   int &&t = 10;
// }
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("input file error\n");
    printf("usage:./out srcfile destfile\n");
    return -1;
  }
  FILE *srcfp = NULL;
  FILE *destfp = NULL;
  if ((srcfp = fopen(argv[1], "r")) == NULL) {
    perror("srcfile open error\n");
    return -1;
  }
  if ((destfp = fopen(argv[2], "w")) == NULL) {
    perror("destfile open error\n");
    return -1;
  }

  char ch = 0;
  while (1) {
    ch = fgetc(srcfp);
    if (ch == EOF)
      break;
    fputc(ch, destfp);
  }
  fclose(srcfp);
  fclose(destfp);
  printf("copy successfully\n");
  return 0;
}
