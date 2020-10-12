#include "pandemic.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

country_t parseLine(char * line) {
  //WRITE ME
  country_t ans;
  size_t l = strlen(line);
  size_t p = 0;
  for(int i = 0;i<l;i++){
    if(line[i] != ','){
      //check if the name is longer than 64
      if(p >=64){
	fprintf(stderr, "name is too long\n");
	exit(EXIT_FAILURE);
	//perror("name is too long");
	//return EXIT_FAILURE;
      }
      ans.name[i] = line[i];
      p++;

      //check if , didn't appear
      if(i == l-1){
	fprintf(stderr, "there's no population1\n");
	exit(EXIT_FAILURE);
	//perror("there's no population");
	//return EXIT_FAILURE;
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
	//perror("type of pop is wrong");	
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
}

void calcCumulative(unsigned * data, size_t n_days, uint64_t pop, double * cum) {
  //WRITE ME
}

void printCountryWithMax(country_t * countries,
                         size_t n_countries,
                         unsigned ** data,
                         size_t n_days) {
  //WRITE ME
}
