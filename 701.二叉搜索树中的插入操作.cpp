/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    // TreeNode *pre = NULL;
    // void traversal(TreeNode *cur, int val)
    // {
    //     if (cur == NULL)
    //     {
    //         TreeNode *node = new TreeNode(val);
    //         if (val > pre->val)
    //         {
    //             pre->right = node;
    //         }
    //         else
    //         {
    //             pre->left = node;
    //         }
    //         return;
    //     }
    //     pre = cur;
    //     if (val < cur->val)
    //     {
    //         traversal(cur->left, val);
    //     }

    //     if (val > cur->val)
    //     {
    //         traversal(cur->right, val);
    //     }
    //     return;
    // }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // if (root == NULL)
        // {
        //     return new TreeNode(val);
        // }

        // traversal(root, val);
        // return root;

        // 迭代法
        if (root == NULL)
        {
            return new TreeNode(val);
        }
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        while (cur)
        {
            pre = cur;
            if (val < cur->val)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        TreeNode *node = new TreeNode(val);
        if (val < pre->val)
        {
            pre->left = node;
        }
        else
        {
            pre->right = node;
        }
        return root;
    }
};
// @lc code=end
