// A program that reads integers and prints each integer's integer radical. Very Rough.
// (c) 2014 amelia archer

#include <stdio.h>

int main( int argc, char **argv)
{
  int n,f,r;

  while (1) {
    scanf("%d",&n);	// read input
    if (n < 2) continue;	// ignore n < 2
    r = 1;			// r is integer radical
    f = 2;			// check factors starting with 2

    while (f <= n) {
      while (n%f == 0) {
	if (r%f != 0) {
	  r *= f;
	}
	n /=f;
      }
      f++;
    }
    printf("%d\n", r);
  }
  return 0;
}
