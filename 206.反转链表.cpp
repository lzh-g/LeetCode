/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

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
    ListNode *reverseList(ListNode *head)
    {
        // ListNode *pre = nullptr;
        // ListNode *cur = head;
        // while (cur != nullptr)
        // {
        //     ListNode *tmp = cur->next;
        //     cur->next = pre;

        //     pre = cur;
        //     cur = tmp;
        // }
        // return pre;
        // 递归法
        return reverse(nullptr, head);
    }

    ListNode *reverse(ListNode *pre, ListNode *cur)
    {
        if (cur == nullptr)
        {
            return pre;
        }
        ListNode *tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
};
// @lc code=end
