/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
private:
    // 小根堆
    class MyComparison
    {
    public:
        // 小于号是大根堆，大于号是小根堆
        // 小于号规定队列后面的元素小于前面的元素，所以是大根堆；lhs可以认为是父节点，父节点与新增节点就行比较，如果小于则交换，就是小的节点是父节点的子结点，所以是大根堆
        // 大于号规定队列后面的元素大于前面的元素，所以是小根堆；lhs可以认为是父节点，父节点与新增节点就行比较，如果大于则交换，就是大的节点是父节点的子结点，所以是小根堆
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m_count;
        for (int i = 0; i < nums.size(); i++)
        {
            m_count[nums[i]]++;
        }

        // 优先队列，小根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparison> m_q;
        for (unordered_map<int, int>::iterator it = m_count.begin(); it != m_count.end(); it++)
        {
            m_q.push(*it);

            // 限定队列大小
            if (m_q.size() > k)
            {
                m_q.pop();
            }
        }

        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = m_q.top().first;
            m_q.pop();
        }
        return res;
    }
};
// @lc code=end
