/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>

using namespace std;
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
    // 0:无覆盖  1:有覆盖    2:有摄像头
    int res;
    int traversal(TreeNode *cur)
    {
        // 空节点，有覆盖
        if (cur == NULL)
        {
            return 1;
        }

        // 左
        int left = traversal(cur->left);
        // 右
        int right = traversal(cur->right);
        // 中
        if (left == 1 && right == 1)
        {
            return 0;
        }

        // 左节点或右节点无覆盖，那么该节点要有摄像头
        if (left == 0 || right == 0)
        {
            res++;
            return 2;
        }
        if (left == 2 || right == 2)
        {
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode *root)
    {
        res = 0;
        if (traversal(root) == 0)
        {
            res++;
        }
        return res;
    }
};
// @lc code=end
