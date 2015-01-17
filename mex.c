// Method mex returns the minimum excluded int in a list
// (c) 2014 amelia l. archer

#include <stdio.h>
#include <stdlib.h>

int int_cmp(const void *a, const void *b);
int mex(int n, int *data);

int main(int argc, char **argv)
{
  int i; // i is counter
  char buffer [256]; //buffer for reading in data
  int *data;
  data = malloc(sizeof(int));
  
  i = 0;
  while(NULL != fgets(buffer, 256, stdin)){
    if (buffer[0] == '\n') continue;
    data[i]=atoi(buffer);
    data = realloc(data, (i+2)*sizeof(int)); //expand array
    i++;
  }
  printf("%d\n",mex(i, data));
  free(data);
  return 0;
}
/* qsort int comparison function copied from http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml*/ 
int int_cmp(const void *a, const void *b) 
{ 
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
	/* integer comparison: returns negative if b > a 
	and positive if a > b */ 
}

int mex(int n, int *data)
{
  int c,i;
  qsort(data, n, sizeof(int), int_cmp);
  //skip all negatives
  if (data[n-1] <= 0) return 1; //if whole list <=0, return 1
  for (c=0; c<n; c++){
    if (data[c] >=0) break;
  }
  i = data[c];
  for (c; c<n; c++){
    if (i != data[c]) return i;
    //check for duplicates
    if (i != data[c+1]) i++;
  }
  return 0;
}
