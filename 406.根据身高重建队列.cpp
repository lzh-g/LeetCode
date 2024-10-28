/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        list<vector<int>> que;
        // 1.按身高排序，从高到低
        sort(people.begin(), people.end(), cmp);
        // 2.根据第二个属性依次插队，前面比他高的人数已经确定
        for (auto &&it : people)
        {
            int position = it[1];
            list<vector<int>>::iterator index = que.begin();
            while (position--)
            {
                index++;
            }
            que.insert(index, it);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};
// @lc code=end
