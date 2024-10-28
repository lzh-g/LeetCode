/*
 * @lc app=leetcode.cn id=3181 lang=cpp
 *
 * [3181] 执行操作可获得的最大总奖励 II
 */
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int maxTotalReward(vector<int> &rewardValues)
    {
        // 动规+位运算
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        // 初始化位集f0和f1，分别表示上一次和当前的奖励可达数组情况
        bitset<100000> f0, f1;
        f0[0] = 1;
        int cur = 0; // 当前处理的和
        int res = 0; // 最大和
        for (int x : rewardValues)
        {
            // 当前和小于x，表示不加x的情况，直接从f0处往下复制
            while (cur < x)
            {
                f1[cur] = f0[cur];
                if (f0[cur] == 1)
                {
                    res = cur + x;
                }

                cur++;
            }
            // 当前和大于x，这里是加x的情况，等价于dp[j]|=dp[j-x]，位运算让f1左移x位
            f0 |= f1 << x;
        }
        return res;
    }
};
// @lc code=end
