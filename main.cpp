#include <iostream>
#include <string>
#include <vector>

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "tree.hpp"

int main() {

  BST bst(10);
  bst.push(6);
  bst.push(17);
  bst.push(14);
  bst.push(13);
  bst.push(12);
  bst.push(11);
  bst.push(19);
  bst.push(3);
  bst.push(7);
  bst.push(15);
  bst.push(18);
  bst.push(20);

  bst.print_succ();
  bst.print_pred();


  Node * p = bst.search(bst.get_root(), 77);
  if (p)
    std::printf("search: %d\n", p->key);

  Node * succ = bst.predecessor(p);
  if (succ)
    std::printf("pred = %d\n", succ->key);
  else
    std::printf("has no predecessor\n");


  bst.print();


  return 0;
}
