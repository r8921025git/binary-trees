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

pair<bool, int> CheckBalanced(const unique_ptr<BinaryTreeNode<int>>&);

// @include
bool IsBalancedBinaryTree(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return CheckBalanced(tree).first;
}

// First value of the return value indicates if tree is balanced, and if
// balanced the second value of the return value is the height of tree.
pair<bool, int> CheckBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
    pair<bool, int> tmp;
    if (!tree->left) {
        tmp.first = true;
        tmp.second = 0;
    }
    else {
        tmp = CheckBalanced( tree->left );
    }
    
    pair<bool, int> tmp2;
    if (!tree->right) {
        tmp2.first = true;
        tmp2.second = 0;
    }
    else {
        tmp2 = CheckBalanced( tree->right );
    }
    printf("tmp.second=%d, tmp2.second=%d\n", tmp.second, tmp2.second);
    
    pair<bool, int> tmp3;
    if (tmp.first && tmp2.first && std::abs(tmp.second-tmp2.second)<=1) {
        tmp3.first = true;
        tmp3.second =  1+tmp.second;
    }
    else {
        tmp3.first = false;
    }
    return tmp3;
}
// @exclude

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
