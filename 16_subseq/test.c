#include <stdio.h>
#include <stdlib.h>
#include "maxSeq.c"

int main (void){

  int arr[]={};
  size_t ans=maxSeq(arr,0);
  if (ans != 0) return EXIT_FAILURE;

  int arr1[]={ 1, 2, 1, 3, 5, 7, 2, 4, 6, 9};
  ans=maxSeq(arr1,10);
  if (ans != 4 ) return EXIT_FAILURE;

  int arr2[]={1,2,3,4};
  ans=maxSeq(arr2,4);
  if (ans != 4) return EXIT_FAILURE;

  int arr5[]={1,3,3,5};
  ans=maxSeq(arr5,4);
  if (ans != 2 ) return EXIT_FAILURE;

  int ar[]={5,-6,7,8};
  ans=maxSeq(ar,4);
  if (ans != 3) return EXIT_FAILURE;

  int ar1[]={10,9,7,6};
  ans=maxSeq(ar1,4);
  if (ans != 1) return EXIT_FAILURE;

  return EXIT_SUCCESS;


}
