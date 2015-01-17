// prints little if machine is little endian, big if machine is big endian
// (c) amelia l. archer

#include <stdio.h>

int main(int argc, char **argv){
  int i=1;
  int *p = &i;
  if( *(char*)p == 1){
    printf("little\n");
  } else printf("big\n");
  return 0;
}
