/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < 2 * nums.size(); i++)
        {
            while (!st.empty() && nums[i % nums.size()] > nums[st.top()])
            {
                res[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return res;
    }
};
// @lc code=end
