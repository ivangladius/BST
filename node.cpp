
#include "node.hpp"

void Node::set_null() {
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

Node::Node() {
  set_null();
}

Node::~Node() { }

Node::Node(int key) {
  set_null();
  this->key = key;
}
