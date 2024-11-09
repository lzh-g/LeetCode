/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        // 创建虚拟结点
        ListNode *v_head = new ListNode(0, head);
        ListNode *cur = v_head;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp1 = cur->next;
            ListNode *tmp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;

            cur = cur->next->next;
        }
        ListNode *res = v_head->next;
        delete v_head;
        return res;
    }
};
// @lc code=end
