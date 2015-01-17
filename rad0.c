// A program that reads integers and prints each integer's intger radical
// (c) 2014 amelia l. archer

#include <stdio.h>

int main(int argc, char **argv)
{
  int n,f,r;

  while (scanf("%d", &n)==1) {
    if (n<2) continue;
    r = 1;
    f = 2;

    while (f<=n) {
      while (n%f == 0) {
	if (r%f !=0) {
	  r *=f;
	}
	n /= f;
      }
      f++;
    }
    printf("%d\n",r);
   }
  return 0;
}
