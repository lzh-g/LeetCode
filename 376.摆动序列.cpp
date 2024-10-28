/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        // // 1.贪心，记录摆动即记录局部峰值
        // if (nums.size() <= 1)
        // {
        //     return nums.size();
        // }
        // int curDiff = 0;
        // int preDiff = 0;
        // int res = 1; // 默认最右边有一个摆动
        // for (int i = 0; i < nums.size() - 1; i++)
        // {
        //     curDiff = nums[i + 1] - nums[i];
        //     if ((preDiff >= 0 && curDiff < 0) || (preDiff <= 0 && curDiff > 0)) // 出现峰值
        //     {
        //         res++;
        //         preDiff = curDiff;
        //     }
        // }
        // return res;

        // 2.动规
        // dp[i][0]表示第i个数作为山峰时的最长子序列长度
        // dp[i][1]表示第i个数作为山谷时的最长子序列长度
        // 转移方程：dp[i][0]=max(dp[i][0],dp[j][1]+1),0<j<i,nums[j]<nums[i],将nums[j]作为山谷时，nums[i]作为山峰
        // dp[i][1]=max(dp[i][1],dp[j][0]+1),0<j<i,nums[j]>nums[i],将nums[j]作为山峰时，nums[i]作为山谷
        vector<vector<int>> dp(1005, vector<int>(2, 0));
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > nums[i])
                {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
// @lc code=end
