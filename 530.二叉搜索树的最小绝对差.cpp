/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include <iostream>
#include <queue>
#include <stack>
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
    // int res = INT_MAX;
    // TreeNode *pre = NULL;
    // void traversal(TreeNode *cur)
    // {
    //     if (cur == NULL)
    //     {
    //         return;
    //     }
    //     traversal(cur->left); // 左
    //     if (pre != NULL)
    //     {
    //         res = min(res, cur->val - pre->val); // 中序遍历，pre小于cur
    //     }
    //     pre = cur;
    //     traversal(cur->right); // 右
    // }
    int getMinimumDifference(TreeNode *root)
    {
        // // 中序遍历，左中右
        // traversal(root);
        // return res;

        // 迭代
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        int res = INT_MAX;
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left; // 左
            }
            else
            {
                cur = st.top(); // 中
                st.pop();

                if (pre != NULL)
                {
                    res = min(res, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right; // 右
            }
        }
        return res;
    }
};
// @lc code=end
