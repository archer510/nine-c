//Program that takes as its sole argument a CS lab access code as a decimal number
// and writes out each of the access codes that are equivalent.
// (c) 2014 amelia archer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* variation (char *code, int combo, int len);
char switchChar (char c, int swap);

int main(int argc, char *argv[])
{
  int i, j; //counters
  int len, combo; //len of code, int to hold the different combinations
  char *code, *temp;

  if (argc > 2) {
    printf("access takes one integer argument.");
    return 1;
  }
  if (argc == 1) return 0;
  code = malloc(sizeof(char));
  i = 0;
  code[i] = argv[1][i];
  while (code[i] != '\0') {
    i++;
    temp = realloc(code, (i+2)*sizeof(char)); //expand array
    if (temp != NULL ) {
      code = temp;
    } else {
      free(code);
      printf("Error allocating memory.\n");
      return 1;
    }
    code[i] = argv[1][i];
  }
  // need to get code as STRING and get its len
  len = i+1;
  combo = 1;
  for (j=1; j<len; j++) {
    combo *= 2;
  }
  for (j=0; j<combo; j++) {
    temp = variation(code, j, len);
    printf("%s\n", temp);
  }
  return 0;
}

char* variation (char *code, int combo, int len)
{
  int i,c;
  char *temp;

  temp = malloc(len*sizeof(char));
  strcpy(temp, code);
  i = 1;
  c = 0;
  for (c=0; c<(len-1); c++) {
    temp[c] = switchChar(code[c], (i & combo));
    i *= 2;
  } 
  return temp;
}

char switchChar (char c, int swap)
{
  if (c == '1') {
    if (swap) return '2';
    return '1';
  } else if (c == '2') {
    if (swap) return '1';
    return '2';
  } else if (c == '3') {
    if (swap) return '4';
    return '3';
  } else if (c == '4') {
    if (swap) return '3';
    return '4';
  } else if (c == '5') {
    if (swap) return '6';
    return '5';
  } else if (c == '6') {
    if (swap) return '5';
    return '6';
  } else if (c == '7') {
    if (swap) return '8';
    return '7';
  } else if (c == '8') {
    if (swap) return '7';
    return '8';
  } else if (c == '9') {
    if (swap) return '0';
    return '9';
  } else {
    if (swap) return '9';
    return '0';
  }
}
