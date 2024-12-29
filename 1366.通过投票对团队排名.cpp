/*
 * @lc app=leetcode.cn id=1366 lang=cpp
 *
 * [1366] 通过投票对团队排名
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    string rankTeams(vector<string> &votes)
    {
        // 使用hash表对各团队进行排名，key表示参赛团队字母，value是一个整数数组，表示各团队所得各名次的次数
        int n = votes.size();
        // 初始化hash表
        unordered_map<char, vector<int>> ranking;
        for (char vid : votes[0])
        {
            ranking[vid].resize(votes[0].size());
        }

        // 统计
        for (const string &vote : votes)
        {
            for (int i = 0; i < vote.size(); i++)
            {
                ranking[vote[i]][i]++;
            }
        }

        // 取出所有键值对
        using PCV = pair<char, vector<int>>;
        vector<PCV> rankingVec(ranking.begin(), ranking.end());
        // 排序，先根据排名，再根据字母
        sort(rankingVec.begin(), rankingVec.end(), [](const PCV &a, const PCV &b)
             { return a.second > b.second || (a.second == b.second && a.first < b.first); });

        string ans;
        for (auto &&[vid, rank] : rankingVec)
        {
            ans.push_back(vid);
        }
        return ans;
    }
};
// @lc code=end
