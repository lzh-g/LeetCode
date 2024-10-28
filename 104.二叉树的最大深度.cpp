/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
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
    int res;
    void getDepth(TreeNode *node, int depth)
    {
        res = depth > res ? depth : res;

        if (node->left == NULL && node->right == NULL)
        {
            return;
        }
        if (node->left)
        {
            depth++;
            getDepth(node->left, depth);
            depth--; // 回溯
        }
        if (node->right)
        {
            depth++;
            getDepth(node->right, depth);
            depth--;
        }
        return;
    }
    int maxDepth(TreeNode *root)
    {
        // 迭代法：层序遍历
        // int res = 0;
        // queue<TreeNode *> que;
        // if (root != NULL)
        // {
        //     que.push(root);
        // }
        // while (!que.empty())
        // {
        //     int size = que.size();
        //     for (int i = 0; i < size; i++)
        //     {
        //         TreeNode *node = que.front();
        //         que.pop();
        //         if (node->left)
        //         {
        //             que.push(node->left);
        //         }
        //         if (node->right)
        //         {
        //             que.push(node->right);
        //         }
        //     }
        //     res++;
        // }
        // return res;

        // 递归法：前序遍历
        res = 0;
        if (root == NULL)
        {
            return res;
        }
        getDepth(root, 1);
        return res;
    }
};
// @lc code=end
