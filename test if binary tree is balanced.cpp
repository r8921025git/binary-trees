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



template<typename T>
pair<bool,int> Helper(unique_ptr<BinaryTreeNode<T>> & node) {
    if (node==nullptr)
        return pair<bool,int>{true,0};

    pair<bool,int> L = Helper(node->left);
    pair<bool,int> R = Helper(node->right);
    if (L.first&&R.first&& abs(L.second-R.second)<=1)
        return pair<bool,int>{true,1+max(L.second,R.second)};
    return pair<bool,int>{false,-1};
}


template<typename T>
bool IsBalancedBinaryTree(unique_ptr<BinaryTreeNode<T>> & node) {
    pair<bool,int> res = Helper(node);
    return res.first;
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
