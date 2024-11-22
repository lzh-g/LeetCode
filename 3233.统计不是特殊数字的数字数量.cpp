/*
 * @lc app=leetcode.cn id=3233 lang=cpp
 *
 * [3233] 统计不是特殊数字的数字数量
 */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
// @lc code=start
class Solution
{
public:
    int nonSpecialCount(int l, int r)
    {
        // 质数筛，满足特殊数的一定是质数的平方数，使用质数筛找到质数，若其平方数在[l,r]中，则减1
        int n = sqrt(r);
        vector<int> filter(n + 1, 1);
        int res = r - l + 1;
        for (int i = 2; i <= n; i++)
        {
            if (filter[i] == 1)
            {
                if (i * i >= l && i * i <= r)
                {
                    res--;
                }
                // 埃氏筛，如果x是质数，那么，x的倍数序列一定不是质数
                for (int j = i * 2; j <= n; j += i)
                {
                    filter[j] = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end