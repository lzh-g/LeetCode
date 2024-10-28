/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

#include <iostream>
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
    int sumOfLeftLeaves(TreeNode *root)
    {

        // // 递归法
        // if (root == NULL)
        // {
        //     return 0;
        // }
        // if (root->left == NULL && root->right == NULL)
        // {
        //     return 0;
        // }

        // int leftValue = sumOfLeftLeaves(root->left);
        // // 左叶子节点
        // if (root->left && !root->left->left && !root->left->right)
        // {
        //     leftValue = root->left->val;
        // }

        // int rightValue = sumOfLeftLeaves(root->right);

        // return leftValue + rightValue;

        // 迭代法
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return 0;
        }
        int res = 0;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top(); // 中
            st.pop();

            if (node->left && node->left->left == NULL && node->left->right == NULL)
            {
                res += node->left->val;
            }

            if (node->left)
            {
                st.push(node->left);
            }
            if (node->right)
            {
                st.push(node->right);
            }
        }

        return res;
    }
};
// @lc code=end
