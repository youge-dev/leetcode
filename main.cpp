#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    static ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *res = new ListNode(0);
        vector<int> queue;
        if (head == nullptr) { return nullptr; }
        ListNode *tmp = head;
        while (tmp != nullptr) {
            queue.push_back(tmp->val);
            tmp = tmp->next;
        }
        tmp = res;
        for (int i = 0; i < queue.size();) {
            for (int j = k + i - 1; j >= i; j--) {
//                cout <<"j is "<<k + i -1<<endl;
                if (j >= queue.size()) {
                    for (int ii = j - k + 1; ii < queue.size(); ii++) {
                        tmp->next = new ListNode(queue[ii]);
                        tmp = tmp->next;
                    }
                    return res->next;
                }
                tmp->next = new ListNode(queue[j]);
                tmp = tmp->next;
            }
            i += k;
        }
        return res->next;
    }

    static int findKthLargest(vector<int> &nums, int k) {
        heapSort(nums);
//        for (auto i:nums)cout << i << "\t";
        return nums.at(nums.size() - k);
    }

    static ListNode *reverseList(ListNode *head) {
        ListNode *cur = head, *pre = nullptr;
        while (cur != nullptr) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    static void heapSort(vector<int> &input) {
        //初始化最大堆
        for (int i = input.size() / 2 - 1; i >= 0; i--) {
            modifyHeap(input, input.size(), i);
        }
        //堆顶放于堆尾
        for (int i = input.size() - 1; i >= 1; i--) {
            swap(input, 0, i);
            modifyHeap(input, i, 0);
        }

    }

    static void modifyHeap(vector<int> &input, int len, int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int maxIndex = index;
        if (left < len && input[left] > input[maxIndex]) maxIndex = left;
        if (right < len && input[right] > input[maxIndex]) maxIndex = right;
        if (index != maxIndex) {
            swap(input, index, maxIndex);
            modifyHeap(input, len, maxIndex);
        }
    }

    static void swap(vector<int> &input, int i, int j) {
        int tmp = input[j];
        input[j] = input[i];
        input[i] = tmp;
    }

    static void nextPermutation(vector<int> &nums) {
        int k = 0;
        int i = nums.size() - 1;
        for (; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                k = i - 1;
                break;
            }
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int j = nums.size() - 1; j >= k + 1; j--) {
            if (nums[j] > nums[k]) {
                swap(nums, j, k);
                reverse(nums.begin() + k+1, nums.end());
                break;
            }
        }
    }

    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)return nullptr;
        int lenA = 0, lenB = 0;
        ListNode *A = headA, *B = headB;
        while (A != nullptr) {
            lenA++;
            A = A->next;
        }
        while (B != nullptr) {
            lenB++;
            B = B->next;
        }
        int diff = abs(lenA - lenB);
        if (lenA > lenB) {
            while (diff-- > 0) {
                headA = headA->next;
            }
        } else {
            while (diff-- > 0) {
                headB = headB->next;
            }
        }
        while (headA != nullptr) {
            if (headA == headB)
                break;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

int main() {
//    Solution::ListNode *a = new Solution::ListNode(1);
//    a->next = new Solution::ListNode(2);
//    a->next->next = new Solution::ListNode(3);
//    a->next->next->next = new Solution::ListNode(4);
//    a->next->next->next->next = new Solution::ListNode(5);
    vector<int> input = {3, 2, 1};
    Solution::nextPermutation(input);
    for (auto i:input) {
        cout << i << "\t";
    }
    return 0;
}
