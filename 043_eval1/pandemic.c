#include "pandemic.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//check if elements of line after ith are legal
int isLegal(char* line, size_t start, size_t sz){
  for(size_t i = start;i<sz;i++){
  //is a number
    if(line[i] >= 48 && line[i] <= 57){
      continue;
    } 
    else if(line[i] == '\0'|| line[i] == '\n'){
      continue;
    } else {
      printf("test!!!!! %d\n",line[i]);
      return 0;
    }
  }
  return 1;
}

country_t parseLine(char * line) {
  //WRITE ME
  country_t ans;
  //length of line
  size_t l = strlen(line);
  //length of name
  size_t p = 0;
  for(size_t i = 0;i<l;i++){
    if(line[i] != ','){
      //check if the name is longer than 64
      if(p >=64){
	fprintf(stderr, "name is too long\n");
	exit(EXIT_FAILURE);
      }
      ans.name[i] = line[i];
      p++;
      //check if , didn't appear
      if(i == l-1){
	fprintf(stderr, "there's no population1\n");
	exit(EXIT_FAILURE);
      }
    } else {
      //check if , appear at the end of the line
      if(i==l-1){
	fprintf(stderr, "there's no population2\n");
	exit(EXIT_FAILURE);	
      }
      //end of name
      ans.name[i] = '\0';
      //check isLegal
      if(isLegal(line, i+1, l) != 1){
      	fprintf(stderr, "illegal population\n");
	exit(EXIT_FAILURE);
      }
      //change the remaining to int and put it into population
      char * ptr  = line + l;
      ans.population = strtoul(line +i+1, &ptr, 10);
      if (errno == ERANGE){
         fprintf("population is overflow ");
	 exit(EXIT_FAILURE);
      }
      //if pop is signed
      if(ans.population < 0){
	fprintf(stderr, "type of pop is wrong\n");
	exit(EXIT_FAILURE);	
      }
      return ans;
    }
  }
  //ans.name[0] = '\0';
  //ans.population = 0;
  return ans;
}

void calcRunningAvg(unsigned * data, size_t n_days, double * avg) {
  //WRITE ME
  //???what if the length of avg != n_day-6
  if(n_days<7){
    fprintf(stderr, "the length of data is too short\n");
    exit(EXIT_FAILURE);
  }
  //if the length of avg != n_day-6
  //if(strlen(avg) < n_days - 6){
  //  fprintf(stderr, "the length of avg is too short\n");
  //exit(EXIT_FAILURE);
  // }
  for(size_t i = 0;i<n_days-6;i++){
    double sum = 0;
    for(int j = i;j< i+7;j++){
      sum += data[j];
    }
    double a = sum/7;
    avg[i]=a;    
  }  
}

void calcCumulative(unsigned * data, size_t n_days, uint64_t pop, double * cum) {
  //WRITE ME
  double cum_n = 0;
  double cum_per = 0;
  for(size_t i = 0; i < n_days;i++){
    cum_n += data[i];
    cum_per = (cum_n * 100000)/ pop;
    cum[i] = cum_per;    
  }
}

void printCountryWithMax(country_t * countries,
                         size_t n_countries,
                         unsigned ** data,
                         size_t n_days) {
  //WRITE ME
  unsigned max = 0;
  size_t ind = 0;
  for(size_t i = 0; i < n_days; i++){

      //data[country][day]
      for(size_t j = 0; j < n_countries;j++){
	if(data[j][i]>max){
	  max = data[j][i];
	  ind = j;
	}
      }
  }
  country_t c = countries[ind];
  char * n = c.name;
  printf("%s has the most daily cases with %u\n", n, max);
}
