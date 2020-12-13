#include <stdio.h>

int readFile(const char* fileName) {
  FILE* fp = fopen(fileName, "r");
  int num;
  fscanf(fp, "%d", &num);
  fclose(fp);
  return num;
}

void writeFile(const char* fileName, int num) {
  FILE* fp = fopen(fileName, "w");
  fprintf(fp, "%d", num);
  fclose(fp);
}

int main() {
  const char* fileName = "q1.txt";
  int num = readFile(fileName) + 1;
  writeFile(fileName, num);
  printf("%d\n", num);
}
/*
Question
Write a program that prints the number of times you have run it.
The first time you run it, it should print “1”. The next time it
should print “2”, etc. Hint: how can you store information when
the program is not running?

Output
5
*/