#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * get_kvpair(char * str){
  char * val = strchr(str, '=');
  *val = '\0';
  val++;

  char * n = strchr(val, '\n');
  if(n!=NULL) *n = '\0';

  //malloc pair
  kvpair_t * pair = malloc(sizeof(*pair));
  pair->key = str;
  pair->value = val;
  return pair;
}


kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname, "r");
  if(!f){
    perror("Could not open file");
    return NULL;
  }

  char * line = NULL;
  size_t sz = 0;
  kvpair_t * curr = NULL;

  kvarray_t * kv_array = malloc(sizeof(*kv_array));
  kv_array->size = 0;
  kv_array->arr = NULL;

  while(getline(&line, &sz, f) >=0){
    //read kv
    curr = get_kvpair(line);

    //resize
    kv_array->arr = realloc(kv_array->arr,
			    (kv_array->size+1)*sizeof(*kv_array->arr));
    kv_array->arr[kv_array->size] = curr;
    kv_array->size++; //increase array sz
    line = NULL; //reset line
  }

  free(line);
  if(fclose(f)!=0){perror("Fail to close file"); return NULL;}
  return kv_array;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0; i<pairs->size; i++){
    //free each key and value individually
    free(pairs->arr[i]->key);
    free(pairs->arr[i]);
  }
  //free arrs and pairs in the respective order
  free(pairs->arr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  kvpair_t * pair;
  for(int i=0; i<pairs->size; i++){
    pair = pairs->arr[i];
    printf("Key = '%s' value = '%s'\n", pair->key, pair->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  kvpair_t * pair;
  for(int i=0; i<pairs->size; i++){
    pair = pairs->arr[i];
    if(strcmp(pair->key,key)==0) return pair->value;
  }
  return NULL;
}
