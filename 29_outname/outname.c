#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * outName = malloc((strlen(inputName)+4) * sizeof(*outName));
  strcopy(outName, inputName);
  outName = realloc(outName, (strlen(inputName)+14) * sizeof(*outName));
  strcat(outName, ".counts");
  return outName;
}
