/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        // 满足0.5*ages[x]+7<ages[y]<=ages[x]就可以发送好友请求
        // x最小为15
        vector<int> cnt(121);
        for (auto &&age : ages)
        {
            cnt[age]++;
        }

        // 前缀和，pre存储的是age：1-age的年龄数
        vector<int> pre(121);
        for (int i = 1; i < 121; i++)
        {
            pre[i] = pre[i - 1] + cnt[i];
        }
        int res = 0;
        for (int i = 15; i <= 120; i++)
        {
            if (cnt[i])
            {
                int bound = i * 0.5 + 8;
                // 前缀和中满足年龄的用户数量再减去自己
                res += cnt[i] * (pre[i] - pre[bound - 1] - 1);
            }
        }
        return res;
    }
};
// @lc code=end
