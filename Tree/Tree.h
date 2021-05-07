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

    /**
     * 二叉树的前序遍历(迭代)
     */

    vector<int> preorderTraversal(TreeNode *root);

    /**
    * 二叉树的前序遍历(递归)
    */
    vector<int> preorderTraversalRecursive(TreeNode *root);

    /**
    * 二叉树的中序遍历（迭代）
    */
    vector<int> inorderTraversal(TreeNode *root);

    /**
    * 二叉树的中序遍历(递归)
    */
    vector<int> inorderTraversalRecursive(TreeNode *root);

    /**
    * 二叉树的后序遍历(迭代)
    */
    vector<int> postorderTraversal(TreeNode *root);

    /**
    * 二叉树的后序遍历(递归)
    */
    vector<int> postorderTraversalRecursive(TreeNode *root);
};


#endif //DAILY_TREE_H
