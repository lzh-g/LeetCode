/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
        {
            return list1;
        }

        if (list1 != NULL && list2 == NULL)
        {
            return list1;
        }

        if (list1 == NULL && list2 != NULL)
        {
            return list2;
        }

        ListNode *p = list1;
        ListNode *q = list2;
        while (p != NULL && q != NULL)
        {
            if (p->val >= q->val)
            {
                ListNode *temp = q;
                q = q->next;
                temp->next = p;
                p = p->next;
            }
            else
            {
                ListNode *temp = p;
                p = p->next;
                temp->next = q;
                q = q->next;
            }
        }
        if (p == NULL)
        {
        }

        return list1->val < list2->val ? list1 : list2;
    }
};
// @lc code=end
