/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // if (root == NULL)
        // {
        //     return root;
        // }
        // // 当前节点小于low，递归右子结点中符合条件的头节点，
        // if (root->val < low)
        // {
        //     TreeNode *right = trimBST(root->right, low, high);
        //     return right;
        // }
        // if (root->val > high)
        // {
        //     TreeNode *left = trimBST(root->left, low, high);
        //     return left;
        // }
        // root->left = trimBST(root->left, low, high);
        // root->right = trimBST(root->right, low, high);
        // return root;

        // 迭代法
        if (root == NULL)
        {
            return root;
        }
        while (root != NULL && (root->val < low || root->val > high))
        {
            if (root->val < low)
            {
                root = root->right;
            }
            if (root->val > high)
            {
                root = root->left;
            }
        }
        TreeNode *cur = root;
        while (cur != NULL)
        {
            while (cur->left && cur->left->val < low)
            {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }

        cur = root;
        while (cur != NULL)
        {
            while (cur->right && cur->right->val > high)
            {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};
// @lc code=end
