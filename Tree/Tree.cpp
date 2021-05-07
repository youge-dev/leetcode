//
// Created by yaquan.zhou on 2021/5/7.
//

#include "Tree.h"
#include  "queue"

// 输出每层时，通过一次性输出队列中元素
vector<vector<int>> Tree::levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr)return res;
    queue<TreeNode *> queue;
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
    queue<TreeNode *> queue;
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