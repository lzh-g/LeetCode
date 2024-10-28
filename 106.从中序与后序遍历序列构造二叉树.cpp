/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <vector>

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
    // 左开右闭
    TreeNode *traversal(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &postorder, int postorderBegin, int postorderEnd)
    {
        // 数组为空
        if (postorderBegin == postorderEnd)
        {
            return NULL;
        }

        // 后序数组的末尾元素，就是根节点
        int rootVal = postorder[postorderEnd - 1];
        TreeNode *root = new TreeNode(rootVal);

        if (postorderEnd - postorderBegin == 1)
        {
            return root;
        }

        // 通过后序数组最后一个找到中序的切割点
        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootVal)
            {
                break;
            }
        }

        // 切割中序
        //  左中序区间
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;

        // 右中序区间
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 再根据中序切后序
        int leftPostorderBegin = postorderBegin;
        int leftPostorderEnd = postorderBegin + (delimiterIndex - inorderBegin); // 加上中序分割长度

        int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderEnd = postorderEnd - 1;

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 中序：左中右
        // 后序：左右中
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return NULL;
        }
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
// @lc code=end
