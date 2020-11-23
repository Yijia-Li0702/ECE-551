#include <cstdlib>

#include "bstset.h"

int main() {
  BstSet<int> bstset;
  bstset.add(60);
  bstset.add(19);
  bstset.add(93);
  bstset.add(4);
  bstset.add(25);
  bstset.add(84);
  bstset.add(1);
  bstset.add(11);
  bstset.add(21);
  bstset.add(35);
  bstset.add(70);
  bstset.add(86);
  bstset.printBstset();
  int v1 = bstset.contains(80);
  int v2 = bstset.contains(11);
  std::cout << "v1 = " << v1 << "\n";
  std::cout << "v2 = " << v2 << "\n";
  bstset.remove(19);
  bstset.printBstset();
  bstset.remove(11);
  bstset.printBstset();
  return EXIT_SUCCESS;
}