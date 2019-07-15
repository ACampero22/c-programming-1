#include <stdio.h>
#include <stdlib.h>

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
