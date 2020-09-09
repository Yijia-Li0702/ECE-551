#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement(int startAge,
		double initial,
		retire_info working,
		retire_info retired){
  int age = startAge;
  double savings = initial;
  while(age < working.months + startAge){
    int year = age / 12;
    int month = age % 12;
    printf("Age %3d month %2d you have $%.2lf\n", year, month, savings);
    savings  = savings + savings * working.rate_of_return + working.contribution;
    age++;
  }

  while(age < working.months + startAge + retired.months){
    int year = age / 12;
    int month = age % 12;
    printf("Age %3d month %2d you have $%.2lf\n", year, month, savings);
    savings  = savings + savings * retired.rate_of_return + retired.contribution;
    age++;
  }
  
  
  /*int year = retired.months / 12;
  int month = retired.months % 12;
  printf("Age %3d month %2d you have $%.2lf\n", month, year, initial);
  initial  = initial + initial * retired.rate_of_return + contribution;*/
}

int main(void){
  retire_info work;
  work.months = 489;
  work.contribution = 1000;
  work.rate_of_return = 0.045/12;
  retire_info retire;
  retire.months = 384;
  retire.contribution = -4000;
  retire.rate_of_return = 0.01/12;
  retirement(327, 21345, work, retire);
  return 0;
}
