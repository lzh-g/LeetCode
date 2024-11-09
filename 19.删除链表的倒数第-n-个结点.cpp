/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *v_head = new ListNode(0, head);
        // 思路：双指针
        ListNode *cur = v_head;
        ListNode *del = v_head; // 这里的del结点实际上是待删除结点的前一个结点
        for (int i = -1; i < n; i++)
        {
            cur = cur->next;
        }

        while (cur != nullptr)
        {
            cur = cur->next;
            del = del->next;
        }

        del->next = del->next->next;

        return v_head->next;
    }
};
// @lc code=end
