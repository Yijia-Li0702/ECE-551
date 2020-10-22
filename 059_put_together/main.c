#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t * cnt = createCounts();

  FILE * f = fopen(filename, "r");
  char * line = NULL;
  size_t sz = 0;
  ssize_t len = 0;
  while ((len = getline(&line, &sz, f)) >= 0) {
    char * p = strchr(line, '\n');
    *p = '\0';
    addCount(cnt,lookupValue(kvPairs,line));
  }
  
  free(line);
  if (fclose(f) != 0) {
    fprintf(stderr, "File closed failure");
  }
  return cnt;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc <= 2){
    fprintf(stderr, "error");
    return EXIT_FAILURE;
  }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);

 //count from 2 to argc (call the number you count i)
  for(int i =2;i<argc;i++){
    counts_t * c = countFile(argv[i],kv);
    char * outName = computeOutputFileName(argv[i]);
    FILE * f = fopen(outName, "w");
    printCounts(c, f);
    free(outName);
    freeCounts(c);
    if (fclose(f) != 0) {
      fprintf(stderr, "fail to close file");
      return EXIT_FAILURE;
    }
  }
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)

    //compute the output file name from argv[i] (call this outName)


    //open the file named by outName (call that f)

    //print the counts from c into the FILE f

    //close f

    //free the memory for outName and c
 


 //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
