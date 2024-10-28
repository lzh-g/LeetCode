/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string> &res)
    {
        // n条边，n+1个节点
        if (res.size() == ticketNum + 1)
        {
            return true;
        }
        for (pair<const string, int> &target : targets[res[res.size() - 1]])
        {
            if (target.second > 0)
            {
                res.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, res))
                {
                    return true;
                }
                res.pop_back();
                target.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        targets.clear();
        vector<string> res;
        // 记录映射关系
        for (const vector<string> &vec : tickets)
        {
            targets[vec[0]][vec[1]]++;
        }
        res.push_back("JFK");
        backtracking(tickets.size(), res);
        return res;
    }
};
// @lc code=end
