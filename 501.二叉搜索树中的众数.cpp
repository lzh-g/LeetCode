/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include <iostream>
#include <queue>
#include <stack>
#include <map>
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
    // int maxCount = 0;
    // int cnt = 0;
    // TreeNode *pre = NULL;
    // vector<int> res;
    // void searchBST(TreeNode *cur)
    // {
    //     if (cur == NULL)
    //     {
    //         return;
    //     }
    //     searchBST(cur->left); // 左
    //     if (pre == NULL)
    //     {
    //         cnt = 1;
    //     }
    //     else if (cur->val == pre->val)
    //     {
    //         cnt++;
    //     }
    //     else
    //     {
    //         cnt = 1;
    //     }
    //     if (cnt == maxCount)
    //     {
    //         res.push_back(cur->val);
    //     }
    //     if (cnt > maxCount)
    //     {
    //         maxCount = cnt;
    //         res.clear();
    //         res.push_back(cur->val);
    //     }

    //     pre = cur;
    //     searchBST(cur->right); // 右
    //     return;
    // }
    vector<int> findMode(TreeNode *root)
    {
        // // 中序遍历，左中右
        // cnt = 0;
        // maxCount = 0;
        // pre = NULL;
        // res.clear();

        // searchBST(root);

        // return res;

        // 迭代法
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        int cnt = 0;
        int maxCount = 0;
        vector<int> res;
        res.clear();

        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left; // 左
            }
            else
            {
                cur = st.top();
                st.pop();
                if (pre == NULL)
                {
                    cnt = 1;
                }
                else if (cur->val == pre->val)
                {
                    cnt++;
                }
                else
                {
                    cnt = 1;
                }

                if (cnt == maxCount)
                {
                    res.push_back(cur->val);
                }

                if (cnt > maxCount)
                {
                    maxCount = cnt;
                    res.clear();
                    res.push_back(cur->val);
                }

                pre = cur;
                cur = cur->right; // 右
            }
        }

        return res;
    }
};
// @lc code=end
