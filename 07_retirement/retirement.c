#include<stdio.h>
#include<stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement (int startAge, double initial, retire_info working, \
		 retire_info retired){
  double tmp = initial;

  for(int i = 0; i < working.months; i++, startAge++){
    printf("Age %3d month %2d you have $%.2lf\n", startAge/12, startAge%12, tmp);
    tmp = tmp*(1+working.rate_of_return) + working.contribution;
  }

  for(int i = 0; i < retired.months; i++, startAge++){
    printf("Age %3d month %2d you have $%.2lf\n", startAge/12, startAge%12, tmp);
    tmp = tmp*(1+retired.rate_of_return) + retired.contribution;
  }
  
}

int main(void){
  // Working Info 
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  // Retired Info
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  int age = 327;
  double initial = 21345;
  retirement(age, initial, working, retired);

  return EXIT_SUCCESS;

}
