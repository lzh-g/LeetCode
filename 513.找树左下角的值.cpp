/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */
#include <iostream>
#include <stack>
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
    int maxDepth = INT_MIN;
    int res;
    void traversal(TreeNode *root, int depth)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                res = root->val;
            }
            return;
        }
        if (root->left)
        {
            traversal(root->left, depth + 1);
        }
        if (root->right)
        {
            traversal(root->right, depth + 1);
        }
        return;
    }

public:
    int findBottomLeftValue(TreeNode *root)
    {
        // // 迭代法
        // // 层次遍历最后一层第一个
        // stack<TreeNode *> res;
        // queue<TreeNode *> que;
        // que.push(root);
        // while (!que.empty())
        // {
        //     int size = que.size();
        //     res.push(que.front()); // 每一层的最左边元素
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
        // }

        // return res.top()->val;

        // 递归法
        traversal(root, 0);
        return res;
    }
};
// @lc code=end
