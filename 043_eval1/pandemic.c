#include "pandemic.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

country_t parseLine(char * line) {
  //WRITE ME
  //strtoul!!!!!
  country_t ans;
  size_t l = strlen(line);
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
	//perror("there's no population");
      }
      //end of name
      ans.name[i] = '\0';
      //change the remaining to int and put it into population
      ans.population = atoi(line+i+1);
      //if pop is unsigned
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
  //???don't we need to check if n_days <7
  //???what if the length of avg != n_day-6
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
