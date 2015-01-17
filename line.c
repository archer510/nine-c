// A program that takes a line number n as its argument, then echoes line n of the input
// (the first line is 1), if it exists. Otherwise, it quietly does nothing.
// (c) 2014 amelia l. archer

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int c,l,i; // declare character placeholder c, target line l, line counter i
  i = 1;
  if (argc != 2) {
    printf("Program takes one int arg > 0.");
    return(1);      
  }
  l = atoi(argv[1]);
  while (EOF != (c = fgetc(stdin))) {
    if (l == i) {
      fputc(c,stdout);
    }
    if (c == '\n') {
      i++;
    }
  }
  return 0;
}
