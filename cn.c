// reads all integers found on the input and writes the curling number associated with that
//sequence of values

#include <stdlib.h>
#include <stdio.h>

int ncmp(int *a, int *b, int n);
int curl(int a[],int n);

int main(int argc, char **argv)
{
  int *input;
  int n;

  input = malloc(10*sizeof(int));
  n=0;
  while(scanf("%d",&input[n])==1) {
    n++;
    if (n >= sizeof(input)) {
      input = realloc(input, sizeof(input)*2);
    }
  }
  printf("%d\n",curl(input,n));
  return 0;
}

// examines first n entries of a and b and returns difference between first entry that differs, or 0
int ncmp(int *a, int *b, int n)
{
  while (n-->0) {
    if (a[n] != b[n]) {
      return a[n]-b[n];
    }
  }
  return 0;
}

int curl(int a[],int n)
{
  int i,j;
  int cn,maxcn;
  maxcn = 1; // curling number default
  for (i=1;i<=n/2;i++) {
    cn = 1;
    j = n-i;
    while (j>0) {
      j -= i;
      if (ncmp(&a[n-i],&a[j],i) != 0) break;
      cn++; // increment curling number if portions compared are equal
    }
    if(maxcn < cn) maxcn = cn; // set maxcn
  }
  return maxcn;
}
