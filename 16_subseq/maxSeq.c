#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){

  size_t ans = 0;
  if(n<=0){return ans;}
  
  size_t curMax=1;
  for(size_t i=1; i<n; i++){
    if(array[i]>array[i-1]){curMax++;}
    else{
      if(curMax>ans){
	ans = curMax;
	curMax = 1;
      }
    }
  }
  if(curMax>ans){ans=curMax;}
  return ans;
}
