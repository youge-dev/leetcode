//
// Created by yaquan.zhou on 2021/5/7.
//

#ifndef DAILY_LINKEDLIST_H
#define DAILY_LINKEDLIST_H

#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
public:
    /**
     * 求两个链表的第一个公共节点
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

    /**
     * 反转链表
     */
    ListNode *reverseList(ListNode *head);

    /**
     *  K个一组翻转链表
     * @param head
     * @param k
     * @return
     */
    ListNode *reverseKGroup(ListNode *head, int k);

    /**
     * 判断链表有环(快慢指针)
     * @param head
     * @return
     */
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};


#endif //DAILY_LINKEDLIST_H
