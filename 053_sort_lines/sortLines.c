#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void helper(void * f) {
  char ** lines = NULL;
  char * curr = NULL;
  size_t i = 0;
  size_t sz;
  while (getline(&curr, &sz, f) >= 0) {
    lines = realloc(lines, (1+i) * sizeof(*lines));
    lines[i] = curr;
    curr = NULL;
    i++;
  }

  sortData(lines, i);
  for (size_t k = 0; k < i; k++) {
    printf("%s", lines[k]);
    free(lines[k]);
  }
  free(curr);
  free(lines);
}

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if(argc == 1){
    helper(stdin);
  }
  if(argc > 1){
    for (int i = 0; i < argc - 1; i++) {
      FILE * f = fopen(argv[i+1], "r");
      if (f == NULL) {
	fprintf(stderr, "empty file\n");
	exit(EXIT_FAILURE);
    }
    helper(stdin);
    if (fclose(f) != 0) {
      fprintf(stderr, "Failed to close the input file!");
      exit(EXIT_FAILURE);
    }
  }
}
return EXIT_SUCCESS;
}
