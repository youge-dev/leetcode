//
// Created by yaquan.zhou on 2021/5/7.
//

#include <complex>
#include "LinkedList.h"
#include "math.h"

ListNode *LinkedList::getIntersectionNode(ListNode *headA, ListNode *headB) {
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

ListNode *LinkedList::reverseList(ListNode *head) {
    ListNode *cur = head, *pre = nullptr;
    while (cur != nullptr) {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

// 把链表中所有元素保存到vector，以k为步长进行判断
ListNode *LinkedList::reverseKGroup(ListNode *head, int k) {
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

}