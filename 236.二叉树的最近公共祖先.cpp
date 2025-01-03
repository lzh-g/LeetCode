/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include <iostream>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 后序遍历，左右中
        if (root == q || root == p || root == NULL)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);   // 左
        TreeNode *right = lowestCommonAncestor(root->right, p, q); // 右
        if (left != NULL && right != NULL)
        {
            return root;
        }

        if (left == NULL && right != NULL)
        {
            return right;
        }
        else if (left != NULL && right == NULL)
        {
            return left;
        }
        else
        {
            return NULL;
        }
    }
};
// @lc code=end
