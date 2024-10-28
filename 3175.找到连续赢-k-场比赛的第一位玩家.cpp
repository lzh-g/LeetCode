/*
 * @lc app=leetcode.cn id=3175 lang=cpp
 *
 * [3175] 找到连续赢 K 场比赛的第一位玩家
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int findWinningPlayer(vector<int> &skills, int k)
    {
        int n = skills.size();
        int i = 0;
        int cnt = 0;
        int res;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && skills[i] > skills[j] && cnt < k)
            {
                cnt++;
                j++;
            }
            if (cnt == k)
            {
                return i;
            }
            cnt = 1;
            res = i;
            i = j;
        }
        return res;
    }
};
// @lc code=end
