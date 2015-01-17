// takes numerator and denominator of non-negative fraction as command line
// args. Output of program is the binary representation of the value with the
// first portion of the repeated fractional digits printed in brackets.
// (c) 2014 amelia l. archer

#include <stdio.h>
#include <stdlib.h>

void print(int n);

int main (int argc, char **argv) {
  int n,d;
  int i,j;
  int *lastseen;
  char *rep;
  n = atoi(argv[1]);
  d = atoi(argv[2]);
  i = 1;
  print(n/d);
  putchar('.');
  n = n-(n/d)*d;
  i=0;
  lastseen = malloc(d*sizeof(int));
  for (j=0;j<d*sizeof(int);j++) {
    lastseen[j] = -1;
  }
  rep = malloc(d*sizeof(char));
  while(lastseen[n] < 0) {
    lastseen[n] = i;
    n *= 2;
    rep[i]='0'+n/d;
    if(n/d) {
      n -= d;
    }
    i++;
  }
  
  for(j=0;j<i;j++) {
    if (j == lastseen[n]) {
      putchar('[');
    }
    putchar(rep[j]);
  }
  putchar(']');
  putchar('\n');


  return 0;
}

void print(int num) {
  if (num>=2) print(num/2);
  putchar('0'+num%2);
  return;
}
