/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 思路：双指针，先统计长度
        int count_A = 0, count_B = 0;
        ListNode *cur_A = headA;
        ListNode *cur_B = headB;
        while (cur_A != nullptr)
        {
            cur_A = cur_A->next;
            count_A++;
        }

        while (cur_B != nullptr)
        {
            cur_B = cur_B->next;
            count_B++;
        }

        // 让长的链表指针先走
        cur_A = headA;
        cur_B = headB;
        if (count_A > count_B)
        {
            int cnt = count_A - count_B;
            while (cnt--)
            {
                cur_A = cur_A->next;
            }
        }
        else
        {
            int cnt = count_B - count_A;
            while (cnt--)
            {
                cur_B = cur_B->next;
            }
        }
        while (cur_A != nullptr)
        {
            if (cur_A == cur_B)
            {
                return cur_A;
            }
            cur_A = cur_A->next;
            cur_B = cur_B->next;
        }
        return NULL;
    }
};
// @lc code=end
