/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <vector>
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candyVec(ratings.size(), 1);
        // 从前向后
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }

        // 从后向前
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }

        int res = 0;
        for (int i = 0; i < candyVec.size(); i++)
        {
            res += candyVec[i];
        }

        return res;
    }
};
// @lc code=end
