/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode *deleteOneNode(TreeNode *node)
    {
        if (node == NULL)
        {
            return node;
        }
        if (node->right == NULL)
        {
            return node->left;
        }
        TreeNode *cur = node->right;
        while (cur->left)
        {
            cur = cur->left;
        }
        cur->left = node->left;
        return node->right;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // if (root == NULL)
        // {
        //     return root;
        // }
        // if (root->val == key)
        // {
        //     if (root->left == NULL && root->right == NULL)
        //     {
        //         delete root;
        //         return NULL;
        //     }
        //     else if (root->left == NULL)
        //     {
        //         auto reNode = root->right;
        //         delete root;
        //         return reNode;
        //     }
        //     else if (root->right == NULL)
        //     {
        //         auto reNode = root->left;
        //         delete root;
        //         return reNode;
        //     }
        //     // 左右子树都不为空，将左子树移动到右子树最左边的节点
        //     else
        //     {
        //         TreeNode *cur = root->right;
        //         while (cur->left != NULL)
        //         {
        //             cur = cur->left;
        //         }
        //         cur->left = root->left;
        //         auto reNode = root->right;
        //         delete root;
        //         return reNode;
        //     }
        // }
        // if (key < root->val)
        // {
        //     root->left = deleteNode(root->left, key);
        // }
        // if (key > root->val)
        // {
        //     root->right = deleteNode(root->right, key);
        // }
        // return root;

        // 迭代法
        if (root == NULL)
        {
            return root;
        }
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        while (cur)
        {
            if (cur->val == key)
            {
                break;
            }
            pre = cur;
            if (key < cur->val)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        // 只有头节点
        if (pre == NULL)
        {
            return deleteOneNode(cur);
        }
        if (pre->left && pre->left->val == key)
        {
            pre->left = deleteOneNode(pre->left);
        }
        if (pre->right && pre->right->val == key)
        {
            pre->right = deleteOneNode(pre->right);
        }
        return root;
    }
};
// @lc code=end
