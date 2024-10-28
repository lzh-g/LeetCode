/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool compare(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q != NULL)
        {
            return false;
        }
        else if (p != NULL && q == NULL)
        {
            return false;
        }
        else if (p == NULL && q == NULL)
        {
            return true;
        }
        else
        {
            if (p->val != q->val)
            {
                return false;
            }
        }
        bool leftRes = compare(p->left, q->left);
        bool rightRes = compare(p->right, q->right);
        bool res = leftRes && rightRes;
        return res;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        bool res = false;
        TreeNode *cur = root;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            if (node->val == subRoot->val)
            {
                res = compare(node, subRoot);
                if (res == true)
                {
                    return res;
                }
            }
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
        }
        return res;
    }
};
// @lc code=end
