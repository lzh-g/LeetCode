/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
        // // 二叉搜索树，有序数组，中的值一定介于pq之间
        // if (root->val > p->val && root->val > q->val)
        // {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // else if (root->val < p->val && root->val < q->val)
        // {
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // else
        // {
        //     return root;
        // }

        // 迭代法
        while (root)
        {
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val)
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
