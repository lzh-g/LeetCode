/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <iostream>
#include <vector>

using namespace std;
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
    ListNode *detectCycle(ListNode *head)
    {
        // 思路：快慢指针加上数学知识，关于环形长度、快慢指针交点与起点的关系
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                ListNode *index1 = head;
                ListNode *index2 = fast;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }

                return index2;
            }
        }

        return NULL;
    }
};
// @lc code=end
