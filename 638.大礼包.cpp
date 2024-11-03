/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;
// @lc code=start
class Solution
{
public:
    map<vector<int>, int> dp;

    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int n = price.size();

        // 过滤无效礼包，包括总体价格更贵的
        vector<vector<int>> filterSpecial;
        for (auto &&sp : special)
        {
            int totalCount = 0; // 礼包中物品的数量
            int totalPrice = 0; // 礼包总价格
            // 计算每个礼包中的物品中数量以及总价格
            for (int i = 0; i < n; i++)
            {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            // 过滤出有效的礼包，礼包中有物品且价格更低
            if (totalCount > 0 && totalPrice > sp[n])
            {
                filterSpecial.emplace_back(sp);
            }
        }

        return dfs(price, filterSpecial, needs, n);
    }

    int dfs(vector<int> &price, vector<vector<int>> &special, vector<int> &needs, int n)
    {
        if (!dp.count(needs))
        {
            int minPrice = 0;
            // 不购买礼包，原价购买
            for (int i = 0; i < n; i++)
            {
                minPrice += needs[i] * price[i];
            }
            // 购买礼包
            for (auto &&sp : special)
            {
                int spPrice = sp[n];
                vector<int> nextNeeds;
                for (int i = 0; i < n; i++)
                {
                    // 如果礼包中某个物品的个数超出了所需数，则不行
                    if (sp[i] > needs[i])
                    {
                        break;
                    }
                    // 购买礼包，则下次所需的物品数量就是needs[i]-sp[i]
                    nextNeeds.emplace_back(needs[i] - sp[i]);
                }
                // 上面的break一旦执行，这里的if一定无法通过
                if (nextNeeds.size() == n)
                {
                    minPrice = min(minPrice, dfs(price, special, nextNeeds, n) + spPrice);
                }
            }
            dp[needs] = minPrice;
        }
        return dp[needs];
    }
};
// @lc code=end
