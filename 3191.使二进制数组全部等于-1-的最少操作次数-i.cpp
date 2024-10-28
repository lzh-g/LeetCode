/*
 * @lc app=leetcode.cn id=3191 lang=cpp
 *
 * [3191] 使二进制数组全部等于 1 的最少操作次数 I
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (i > nums.size() - 3)
                {
                    return -1;
                }

                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
