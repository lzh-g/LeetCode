/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include <iostream>

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
    int countNodes(TreeNode *root)
    {
        // 层次遍历,所有二叉树通用
        // if (root == NULL)
        // {
        //     return 0;
        // }
        // int res = 0;
        // queue<TreeNode *> que;
        // que.push(root);
        // while (!que.empty())
        // {
        //     int size = que.size();
        //     for (int i = 0; i < size; i++)
        //     {
        //         TreeNode *node = que.front();
        //         que.pop();
        //         res++;
        //         if (node->left)
        //         {
        //             que.push(node->left);
        //         }
        //         if (node->right)
        //         {
        //             que.push(node->right);
        //         }
        //     }
        // }
        // return res;

        // 使用完全二叉树性质,若左子树深度与右子树相同，则为满二叉树，否则为完全二叉树
        if (root == NULL)
        {
            return 0;
        }
        TreeNode *leftNode = root->left;
        TreeNode *rightNode = root->right;
        int leftDepth = 0, rightDepth = 0;
        while (leftNode)
        {
            leftNode = leftNode->left;
            leftDepth++;
        }
        while (rightNode)
        {
            rightNode = rightNode->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth)
        {
            return (2 << leftDepth) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end
