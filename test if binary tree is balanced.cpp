// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <utility>


using std::boolalpha;
using std::cout;
using std::endl;
using std::max;
using std::pair;
using std::unique_ptr;

template<typename T>
struct BinaryTreeNode {
    T data;
    std::unique_ptr<BinaryTreeNode<T>> left, right;
};

int findDepth(unique_ptr<BinaryTreeNode<T>> node) {
    
}

bool IsBalancedBinaryTree(unique_ptr<BinaryTreeNode<T>> node) {
    depth_L = findDepth(node->left);
    depth_R = findDepth(node->riht);
    if (std::abs(depth_L - depth_R)>1)
        return false;
        
    return true;
}

int main(int argc, char* argv[]) {
  //  balanced binary tree test
  //      3
  //    2   5
  //  1    4 6
  unique_ptr<BinaryTreeNode<int>> root =
      unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  root->left = unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  root->left->left = unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  root->right = unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  root->right->left =
      unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  root->right->right =
      unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  assert(IsBalancedBinaryTree(root) == true);
  cout << boolalpha << IsBalancedBinaryTree(root) << endl;
  // Non-balanced binary tree test.
  root = unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  root->left = unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  root->left->left = unique_ptr<BinaryTreeNode<int>>(new BinaryTreeNode<int>());
  assert(IsBalancedBinaryTree(root) == false);
  cout << boolalpha << IsBalancedBinaryTree(root) << endl;
  return 0;
}
