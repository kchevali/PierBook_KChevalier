#include <stdio.h>

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int main() {
  int x, y;
  printf("Enter two numbers:");
  scanf("%d%d", &x, &y);
  swap(&x, &y);
  printf("Swapped:%d %d\n", x, y);
}
/*
Question
Write a function that swaps the values of two variables. Write
a program that calls this function, taking input from stdin
and writing the values to stdout. Don’t print from inside the
function. Put the function in a separate file from your main.
Hint: use pointers.

Input:
4 5

Output
Swapped: 5 4
*/