#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}


int sort_print_free(FILE * f, char **arr, int i){
  sortData(arr, i);
  for(int j=0; j<i; j++){
    printf("%s", arr[j]);
    free(arr[j]);
  }
  free(arr);
  if(f!=NULL && fclose(f)!=0){
    perror("Failed to close the input file");
    return 0;
  }
  return 1;
}

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if(argc==0){
    fprintf(stderr, "no arguement\n");
    return EXIT_FAILURE;
  }

  char ** arr = NULL;
  char * line = NULL;
  size_t sz = 0;
  int i = 0;
  
  if(argc==1){
    while(getline(&line, &sz, stdin)>=0){
      arr = realloc(arr, (i+1)*sizeof(*arr));
      arr[i] = line;
      line = NULL;
      i++;
    }
    free(line);
    if(sort_print_free(NULL, arr, i)==0) return EXIT_FAILURE;
  }

  else{
    for(int n=1; n<argc; n++){
      FILE * f = fopen(argv[n], "r");
      if(!f){
	perror("Could not open file");
	return EXIT_FAILURE;
      }

      while(getline(&line, &sz, f)>=0){
	arr = realloc(arr, (i+1)*sizeof(*arr));
	arr[i] = line;
	line = NULL;
	i++;
      }
      free(line);
      if(sort_print_free(f, arr, i)==0) return EXIT_FAILURE;
    }
  }

  
  return EXIT_SUCCESS;
}
