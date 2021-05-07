#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
#include <unordered_set>
#include "Sort/Sort.h"
#include "LinkedList/LinkedList.h"
#include "Tree/Tree.h"

using namespace std;

int main() {
    TreeNode *a = new TreeNode(3);
    a->left = new TreeNode(9);
    a->right = new TreeNode(20);
    a->right->left = new TreeNode(15);
    a->right->right = new TreeNode(7);

    Tree *test = new Tree;
    vector<vector<int>> res = test->levelOrder(a);
    for (int i = 0; i < res.size(); i++) {
        int ii = res[i].size();
        cout << endl;
        cout << "[";
        for (int j = 0; j < ii; j++) {
            cout << res[i][j] << "\t";
        }
        cout << "]";
    }
    vector<int> aa = test->levelOrderOne(a);
    cout << endl;
    for (auto i:aa) {
        cout << i << "\t";
    }
    return 0;
}
