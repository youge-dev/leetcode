//
// Created by yaquan.zhou on 2021/5/7.
//

#include "Tree.h"
#include  "queue"
#include "stack"

// 输出每层时，通过一次性输出队列中元素
vector<vector<int>> Tree::levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr)return res;
    queue < TreeNode * > queue;
    queue.push(root);
    while (!queue.empty()) {
        int size = queue.size();
        res.push_back(vector<int>());
        for (int i = 0; i < size; i++) {
            TreeNode *node = queue.front();
            res.back().push_back(node->val);
            queue.pop();
            if (node->left != nullptr) queue.push(node->left);
            if (node->right != nullptr) queue.push(node->right);
        }
    }
    return res;
}

vector<int> Tree::levelOrderOne(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) return res;
    queue < TreeNode * > queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode *node = queue.front();
        res.push_back(node->val);
        queue.pop();
        if (node->left != nullptr) queue.push(node->left);
        if (node->right != nullptr) queue.push(node->right);
    }
    return res;
}

vector<int> Tree::preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)return res;
    stack < TreeNode * > stack;
    stack.push(root);
    while (!stack.empty()) {
        TreeNode *top = stack.top();
        stack.pop();
        res.push_back(top->val);
        if (top->right != nullptr) stack.push(top->right);
        if (top->left != nullptr)stack.push(top->left);
    }
    return res;
}

void preorderTraversalRecur(TreeNode *root, vector<int> &input) {
    if (root == nullptr)return;
    input.push_back(root->val);
    if (root->left != nullptr) preorderTraversalRecur(root->left, input);
    if (root->right != nullptr) preorderTraversalRecur(root->right, input);
}

vector<int> Tree::preorderTraversalRecursive(TreeNode *root) {
    vector<int> res;
    preorderTraversalRecur(root, res);
    return res;
}

vector<int> Tree::inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack < TreeNode * > stack;
    TreeNode *rt = root;
    while (rt != nullptr || !stack.empty()) {
        while (rt != nullptr) {
            stack.push(rt);
            rt = rt->left;
        }
        TreeNode *top = stack.top();
        stack.pop();
        res.push_back(top->val);
        rt = top->right;
    }
    return res;
}

void inorderTraversalRecur(TreeNode *root, vector<int> &input) {
    if (root == nullptr)return;
    if (root->left != nullptr) inorderTraversalRecur(root->left, input);
    input.push_back(root->val);
    if (root->right != nullptr) inorderTraversalRecur(root->right, input);
}

vector<int> Tree::inorderTraversalRecursive(TreeNode *root) {
    vector<int> res;
    inorderTraversalRecur(root, res);
    return res;
}

void postorderTraversalRecur(TreeNode *root, vector<int> &input) {
    if (root == nullptr)return;
    if (root->left != nullptr) postorderTraversalRecur(root->left, input);
    if (root->right != nullptr) postorderTraversalRecur(root->right, input);
    input.push_back(root->val);
}

vector<int> Tree::postorderTraversalRecursive(TreeNode *root) {
    vector<int> res;
    postorderTraversalRecur(root, res);
    return res;
}

vector<int> Tree::postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)return res;
    stack < TreeNode * > stack;
    stack.push(root);
    while (!stack.empty()) {
        TreeNode *top = stack.top();
        stack.pop();
        res.push_back(top->val);
        if (top->left != nullptr)stack.push(top->left);
        if (top->right != nullptr) stack.push(top->right);
    }
    reverse(res.begin(),res.end());
    return res;
}