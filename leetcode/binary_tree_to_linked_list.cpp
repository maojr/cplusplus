// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
// 114. Flatten Binary Tree to Linked List
// Given a binary tree, flatten it to a linked list in-place
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == NULL)
      return;
    std::stack<TreeNode *> stack;

    if (root->right)
      stack.push(root->right);
    if (root->left)
      stack.push(root->left);

    while (!stack.empty()) {
      TreeNode *p = stack.top();
      stack.pop();
      root->left = NULL;
      root->right = p;
      if (p->right)
        stack.push(p->right);
      if (p->left)
        stack.push(p->left);
      root = p;
    }
  }

  void flatten2(TreeNode *root) {
    while (root) {
      if (root->left && root->right) {
        TreeNode *t = root->left;
        while (t->right)
          t = t->right;
        t->right = root->right;
      }
      if (root->left)
        root->right = root->left;
      root->left = NULL;
      root = root->right;
    }
  }
};
