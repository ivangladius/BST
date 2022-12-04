
#ifndef NODE_HEADER
#define NODE_HEADER

class Node {

public:
  int key;
  Node * left;
  Node * right;
  Node * parent;

public:
  Node();
  Node(int);
  ~Node();
 
  void set_null();
};



#endif
