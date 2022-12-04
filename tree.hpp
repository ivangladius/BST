#ifndef TREE_HEADER
#define TREE_HEADER

#include "node.hpp"
#include <cstdio>
#include <cstdint>

class BST {
private:
  Node * root;

public:

  BST();
  BST(int);
  ~BST();

  Node * get_root() const;
  void set_root(int key);


  Node * search(Node * tree, int key);
  Node * successor(Node * node);
  Node * predecessor(Node * node);
  
  void push(int key);

  void pop();
  void remove(int key);

  void print();
  void print_succ();
  void print_pred();
  void print_helper(Node *, int offset);

  // helper functions
  bool is_left(Node *);
  bool is_right(Node *);
  bool is_child(Node *);

  bool has_left(Node *);
  bool has_right(Node *);
  bool has_parent(Node *);

  Node * min(Node * tree);
  Node * max(Node * tree);
 
};

#endif
