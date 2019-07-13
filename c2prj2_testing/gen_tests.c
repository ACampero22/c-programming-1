#include <stdio.h>
#include <stdlib.h>


char gen_num(void){
  int r = rand()%13+2;
  char ans;

  if(r>=2&&r<=9){
    ans = r + '0';
  }
  else{
    switch(r){
    case 10: {ans = '0';break;}
    case 11: {ans = 'J';break;}
    case 12: {ans = 'Q';break;}
    case 13: {ans = 'K';break;}
    case 14: {ans = 'A';break;}
    }
  }
  return ans;
}


char gen_suit(void){
  int r = rand()%4;
  char ans;
  switch(r){
  case 0: {ans = 's';break;}
  case 1: {ans = 'h';break;}
  case 2: {ans = 'd';break;}
  case 3: {ans = 'c';break;}
  }

  return ans;
}

int main(int argc, char *agrv[]){
  int count = 0;
  int n = atoi(agrv[1]);
    
  for(int i=1; i<14*n+1; i++){
    count++;
    
    char num = gen_num();
    char suit = gen_suit();
    printf("%c%c", num, suit);
    if(i%7!=0){
      printf(" ");
    }
    else{
      if(count!=14){
	printf("; ");
      }
    }
    if(count==14){
      printf("\n");
      count = 0;
    }
  }
  
  return EXIT_SUCCESS;
}
