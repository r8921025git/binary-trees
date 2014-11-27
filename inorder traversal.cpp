#include <cassert>
#include <iostream>
#include <queue>
#include <memory>
#include <vector>


using std::cout;
using std::endl;
using std::equal;
using std::move;
using std::queue;
using std::unique_ptr;
using std::vector;

vector<vector<int>> results;
vector<int> one_line_result;

template <typename T>
struct BinaryTreeNode {
T data;
unique_ptr<BinaryTreeNode<T>> left, right;
};

// @include
void InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& root) {
}
// @exclude

int main(int argc, char* argv[]) {
  //      3
  //    2   5
  //  1    4 6
  unique_ptr<BinaryTreeNode<int>> root = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{3, nullptr, nullptr});
  root->left = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{2, nullptr, nullptr});
  root->left->left = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{1, nullptr, nullptr});
  root->right = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{5, nullptr, nullptr});
  root->right->left = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{4, nullptr, nullptr});
  root->right->right = unique_ptr<BinaryTreeNode<int>>(
      new BinaryTreeNode<int>{6, nullptr, nullptr});
  // should output 3
  //               2 5
  //               1 4 6
  InorderTraversal(root);
  return 0;
}
