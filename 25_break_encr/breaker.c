#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int decrypt(FILE *f){
  int c, arr[26]={0};

  //get char freq count
  while((c=fgetc(f))!=EOF){
    if(isalpha(c)){
      c = tolower(c);
      c -= 'a';
      arr[c]++;
    }
  }

  //get highest frequency char
  int hfc, cnt=0;
  for(int i=0; i<26; i++){
    if(arr[i]>cnt){
      cnt = arr[i];
      hfc = i;
    }
  }

  //get decryption
  if(hfc>=5) return  hfc;
  else return 26 + hfc - 5;

}

int main(int argc, char ** argv){

  //check cml args
  if(argc != 2){
    fprintf(stderr, "Please just provide an input file for decrption.\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");

  if(f==NULL){
    perror("invalid input file");
    return EXIT_FAILURE;
  }

  int ans = decrypt(f);
  printf("%d", ans);

  //close file
  if(fclose(f)!=0){
    perror("Fail to close the input file");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
