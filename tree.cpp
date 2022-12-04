
#include "node.hpp"
#include "tree.hpp"

#include <exception>
#include <cstdio>

void BST::set_root(int key) {
  root = new (std::nothrow) Node{ key };
}

Node * BST::get_root() const {
  return root;
}

BST::BST() {
  root = nullptr;
}

BST::BST(int key) {
  set_root(key);
}

BST::~BST() {}

// #################################################
Node * BST::search(Node * root, int key) {

  if (key < root->key && root->left)
    return search(root->left, key);
  else if (root->key < key && root->right)
    return search(root->right, key);
  
  return root;
}

Node * BST::successor(Node * node) {


  if (node == max(root))
    return nullptr;

  else if (is_child(node) && is_left(node)) 
    return node->parent;

  else if (has_right(node)) {
    node = node->right;
    for (;has_left(node); node = node->left);
    return node;
  }

  else if (!has_right(node) && has_parent(node)) {

    for (;!is_left(node); node = node->parent);
    if (has_parent(node))
      return node->parent;
  }
  else
    return nullptr;

  return nullptr;
}

Node * BST::predecessor(Node * node) {

  if (node == min(root))
    return nullptr;

  else if (has_left(node)) {
    node = node->left;
    for (;has_right(node); node = node->right);
    return node;
  }
  else if (!has_left(node)) {
    for (;is_left(node); node = node->parent);
    return node->parent;
  }

  return nullptr;

}

//################################################

void BST::push(int key) {

  if (!root) {
    set_root(key);
    return;
  }

  Node * new_node = new (std::nothrow) Node{ key };
  if (!new_node)
    return;
  
  Node * target = search(root, key);
  if (!target)
    return;

  if (key < target->key)
    target->left = new_node;
  else if (target->key < key)
    target->right = new_node;

  new_node->parent = target;

}

void BST::remove(int key) {

  Node * to_delete = search(root, key);
  if (!to_delete) {
    std::printf("key not found!");
    return;
  }

  Node * pred = predecessor(to_delete);

  std::uint8_t flag = (is_left(to_delete)) ? 0 : 1;
  to_delete = to_delete->parent;

  if (is_child(to_delete)) {
    if (!flag) {
      delete to_delete->left;
      to_delete->left = nullptr;
    } else {
      delete to_delete->right;
      to_delete->right = nullptr;
    }
  }
  else if (has_right(pred)) {
    to_delete->key = pred->key;
    delete pred->right;
    pred->right = nullptr;
  }
  
}
// ####################################################

void BST::print_pred() {
  Node * start = max(root);
  while (start) {
      std::printf("%d ", start->key);
      start = predecessor(start);
  }
  std::printf("\n\n");

}

void BST::print_succ() {
  Node * start = min(root);
  while (start) {
      std::printf("%d ", start->key);
      start = successor(start);
    }

  std::printf("\n\n");
}

void BST::print() {
  print_helper(root, -10);
}

void BST::print_helper(Node * root, int offset) {

  if (!root)
    return;

  offset += 10;

  print_helper(root->right, offset);

  for (int i = 0; i < offset; ++i)
    std::printf(" ");
  std::printf("%d\n", root->key);

  print_helper(root->left, offset);

}
// #################################################


bool BST::is_left(Node * node) {
  return (node == node->parent->left) ? true : false;
}

bool BST::is_right(Node * node) {
  return (node == node->parent->right) ? true : false;
}

bool BST::is_child(Node * node) {
  return (!node->left && !node->right) ? true : false;
}

// #################################################


bool BST::has_left(Node * node) {
  return (node->left) ? true : false;
}


bool BST::has_right(Node * node) {
  return (node->right) ? true : false;
}

bool BST::has_parent(Node * node) {
  return (node->parent) ? true : false;
}

// ##################################################

Node * BST::min(Node * tree) {
  Node * cur;
  for (cur = tree; cur->left; cur = cur->left);
  return cur;
}


Node * BST::max(Node * tree) {
  Node * cur;
  for (cur = tree; cur->right; cur = cur->right);
  return cur;
}
