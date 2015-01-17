// A program that reads its input (stdin) and echoes strings of printable characters
// (as defined by isprint(c)) that are at least four characters long.
// (c) 2014 amelia l. archer

#include <stdio.h>
#include <ctype.h>

int main (int argc, char **argv)
{
  int c,i;
  char s[5];
  
  i = 0;
  while (EOF != (c = fgetc(stdin))) {
    if (isprint(c)) {
      if (i < 4) {
	s[i] = c;
	i++;
	if (i == 4) {
	  s[4] = '\0';
	  fputc('\n',stdout);
	  fputs(s,stdout);
	}
      } else {
	fputc(c,stdout);
      }
    } else {
      i = 0;
    }    
  }
  return 0;
}
