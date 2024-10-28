/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include <vector>
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // 从起点开始遍历，若遍历途中的汽油剩余量为负数，则起点一定从下一个开始加油站开始，若总剩余量为负，则无法完成一圈
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0)
            {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0)
        {
            return -1;
        }

        return start;
    }
};
// @lc code=end
