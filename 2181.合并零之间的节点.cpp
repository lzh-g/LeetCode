/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <iostream>

using namespace std;
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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *left = head;
        ListNode *right = head->next;
        ListNode *res = new ListNode();
        int sum = 0;
        while (left != right)
        {
            if (right->val == 0)
            {
                res->next = new ListNode(sum);
                sum = 0;
                right = right->next;
            }
            else
            {
                sum += right->val;
            }
            // 左右均为0后
            res->next = new ListNode(sum);
            sum = 0;
            left = right;
            right = left->next;
        }
        return res->next;
    }
};
// @lc code=end
