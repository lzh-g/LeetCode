/*
 * @lc app=leetcode.cn id=2931 lang=cpp
 *
 * [2931] 购买物品的最大开销
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    long long maxSpending(vector<vector<int>> &values)
    {
        vector<int> goods;
        // 计算总共有几个物品
        for (auto &&value : values)
        {
            for (auto &&v : value)
            {
                goods.push_back(v);
            }
        }
        sort(goods.begin(), goods.end());
        long long index = 1;
        long long res = 0;
        for (auto &&good : goods)
        {
            res += good * index;
            index++;
        }
        return res;
    }
};
// @lc code=end
