#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

#include "bstmap.h"
#include "map.h"

int main() {
  BstMap<int, int> bstmap;
  bstmap.add(60, 1);
  bstmap.add(19, 2);
  bstmap.add(93, 3);
  bstmap.add(4, 4);
  bstmap.add(25, 5);
  bstmap.add(84, 6);
  bstmap.add(1, 7);
  bstmap.add(11, 8);
  bstmap.add(21, 9);
  bstmap.add(35, 10);
  bstmap.add(70, 11);
  bstmap.add(86, 12);
  bstmap.printBstmap();
  int v1 = bstmap.lookup(60);
  int v2 = bstmap.lookup(11);
  std::cout << "v1 = " << v1 << "\n";
  std::cout << "v2 = " << v2 << "\n";
  bstmap.remove(19);
  //bstmap.printBstmap();
  bstmap.remove(11);
  //bstmap.printBstmap();
  return EXIT_SUCCESS;
}