#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * counts = malloc(sizeof(*counts));
  counts->arr = NULL;
  counts->size = 0;
  counts->unknown = 0;
  return counts;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(!name) c->unknown++;
  else{
    one_count_t * x = NULL;
    int checker = 0;
    for(size_t i=0; i<c->size; i++){
      x = c->arr[i];
      if(!strcmp(x->str, name)){
	x->count++;
	checker=1;
      }
    }
      if(!checker){
	x = NULL;
	x = malloc(sizeof(*x));
	x->str = malloc(strlen(name)+4);
	strcpy(x->str, name);
	x->count=1;
	c->arr = realloc(c->arr, (c->size+1)*sizeof(*c->arr));
	c->arr[c->size]=x;
	c->size++;
      }
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  one_count_t * x = NULL;
  for(size_t i=0; i<c->size; i++){
    x=c->arr[i];
    fprintf(outFile, "%s: %zd\n", x->str, x->count);
  }
  if(c->unknown!=0) fprintf(outFile, "<unknown>: %zd\n", c->unknown);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(size_t i=0; i<c->size; i++){
    free(c->arr[i]->str);
    free(c->arr[i]);
  }
  free(c->arr);
  free(c);
}
