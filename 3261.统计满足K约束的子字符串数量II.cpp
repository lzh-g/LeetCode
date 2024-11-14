/*
 * @lc app=leetcode.cn id=3261 lang=cpp
 *
 * [3261] 统计满足K约束的子字符串数量II
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> count(2, 0);
        // right[i]表示l为i时，首次不满足K约束的右边界下标
        vector<int> right(n, n);
        vector<long long> prefix(n + 1, 0);
        int i = 0;
        for (int j = 0; j < n; ++j)
        {
            count[s[j] - '0']++;
            while (count[0] > k && count[1] > k)
            {
                count[s[i] - '0']--;
                right[i] = j;
                i++;
            }
            prefix[j + 1] = prefix[j] + j - i + 1;
        }

        vector<long long> res;
        for (auto &query : queries)
        {
            int l = query[0], r = query[1];
            int i = min(right[l], r + 1);
            long long part1 = 1LL * (i - l + 1) * (i - l) / 2;
            long long part2 = prefix[r + 1] - prefix[i];
            res.push_back(part1 + part2);
        }
        return res;
    }
};
// @lc code=end