/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // 递归法
        // if (root == NULL || root->val == val)
        // {
        //     return root;
        // }
        // TreeNode *res = NULL;
        // if (root->val > val)
        // {
        //     res = searchBST(root->left, val);
        // }
        // if (root->val < val)
        // {
        //     res = searchBST(root->right, val);
        // }
        // return res;

        while (root != NULL)
        {
            if (root->val > val)
            {
                root = root->left;
            }
            else if (root->val < val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return NULL;
    }
};
// @lc code=end
