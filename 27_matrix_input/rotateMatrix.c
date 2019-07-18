#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int checkinput(int argc, char ** argv){
  if(argc != 2){
    fprintf(stderr, "incorrect number of arguement\n");
    return 0;
  }

  FILE * f = fopen(argv[1],"r");
  if(!f){
    perror("Fail to open file, please check file name");
    return 0;
  }
  
  int c, col=0;
  c = fgetc(f);

  while(c!=EOF){
    for(int i=0; i<10; i++){
      if(c=='\n'){
	fprintf(stderr, "char error");
	return 0;
      }
      c = fgetc(f);
    }

    if(c!='\n'){
      fprintf(stderr, "row error");
      return 0;
    }
    c = fgetc(f);
    col++;
  }

  if(fclose(f)!=0){
    perror("Fail to close the file");
    return 0;
  }
  
  if(col == 10) return 1;
  fprintf(stderr, "column error");
  return 0;
}

void rotate(char mat[10][10]){
  int N = 10;
  for(int i=0; i<3; i++){
    for (int x = 0; x < N / 2; x++){
      for (int y = x; y < N-x-1; y++){
	char temp = mat[x][y];
	mat[x][y] = mat[y][N-1-x];
	mat[y][N-1-x] = mat[N-1-x][N-1-y];
	mat[N-1-x][N-1-y] = mat[N-1-y][x];
	mat[N-1-y][x] = temp;
      }
    }
  }
}

int main(int argc, char ** argv){
  int check = checkinput(argc, argv);
  if(check == 0) return EXIT_FAILURE;
  
  FILE *f = fopen(argv[1],"r");

  char matrix[10][10];
  int c = 0;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      c = fgetc(f);
      if(c=='\n') c=fgetc(f);
      matrix[i][j] = c;
    }
  }

  rotate(matrix);

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }

  if(fclose(f)!=0){
    perror("Fail to close the file");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
