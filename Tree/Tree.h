//
// Created by yaquan.zhou on 2021/5/7.
//

#ifndef DAILY_TREE_H
#define DAILY_TREE_H

#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree {
public:
    /**
     * #leetcode 102 层序遍历
     */
    vector<vector<int>> levelOrder(TreeNode *root);

    vector<int> levelOrderOne(TreeNode *root);
};


#endif //DAILY_TREE_H
