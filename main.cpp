#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
#include <unordered_set>
#include "Sort/Sort.h"
#include "LinkedList/LinkedList.h"
#include "Tree/Tree.h"
#include "Tree/Tree.cpp"
using namespace std;

int main() {
    TreeNode *a = new TreeNode(1);
    a->right = new TreeNode(2);
    a->right->left = new TreeNode(3);

    Tree *test = new Tree;

    vector<int> aa = test->preorderTraversal(a);
    cout << endl;
    for (auto i:aa) {
        cout << i << "\t";
    }
    return 0;
}
