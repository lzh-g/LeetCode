/*
 * @lc app=leetcode.cn id=3208 lang=cpp
 *
 * [3208] 交替组 II
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        // 滑动窗口并记录已交替颜色数
        int res = 0, cnt = 1;
        int n = colors.size();
        // 以当前遍历的数为第k个数，需要知道前k-1个数的交替情况，而这k-1个数的交替情况，只需要从前k-2个数开始判断，所以 遍历起点往前推k-2步
        // 如实例1:要知道以colors[0]为第k个数的交替情况，只需要知道前k-2=1，即下标(-1+5)%5=4开始矩形交替情况判断，因为进行了(i+n)%n与(i-1+n)%n{环形中的前一个数}的比较
        for (int i = -k + 2; i < n; i++)
        {
            if (colors[(i + n) % n] != colors[(i - 1 + n) % n])
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            if (cnt >= k)
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
