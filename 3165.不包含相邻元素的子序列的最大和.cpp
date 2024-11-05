/*
 * @lc app=leetcode.cn id=3165 lang=cpp
 *
 * [3165] 不包含相邻元素的子序列的最大和
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start

/*
对于queries[i] 每次操作会将nums[posi]的值修改为xi
对于nums[posi]有以下两种情况
（下面把posi看做第i个位置, 数组长度为n）
选nums[i]：那么相邻的位置i-1 和 i+1均不能被选择
左右两侧变成nums[0 到 i - 2] 和 nums[i + 2 到 n-1]
不选nums[i]: 那么相邻的位置i-1 和 i+1 没有任何限制
左右两侧变成nums[0 到 i - 1] 和 nums[i + 1, n - 1]

因为要频繁的修改查询所以要用线段树
对于每个结点t[l,r]，表示区间为[l,r]
对于nums[l] 到 nums[r]这个子数组
假设区间t[l,r]，其中x，y取值为0或1
x 表示左边界的选择情况；
y 表示右边界的选择情况；
0 表示对应的边界元素一定没有被选择；
1 表示对应的边界元素可能被选择，也就是没有任何要求。

如果(l = r) 即单个值
那么x = 0 或者y = 0时
即l 或 r一定有一个没有被选择，因为只有一个元素
所以就是没选择任何元素即 值=0
那么x = 1 并且 y = 1时就是这个元素可选可不选
没有任何要求 所有值为 max{nums[l], 0}

如果(l != r) 即一个区间
那么有以下四种情况
以下t[l, r]代表区间[l, r]的最大值
区间是闭区间，m = [l + r] / 2

对于t[l, r] (l = 0, r = 0):
它表示左右边界l 与 r一定没有被选择，在线段树中
该区间[l, r]，由左子区间[l, m] 和 右子区间[m + 1, r]组成
当左子区间是(0, 0)时，右子区间一定要满足右边界元素一定没有被选择
因为右子区间左边界没有限制，同时为了使结果尽可能大所以右侧是(1, 0)
此时的值为l[0, 0] + r[1, 0];
当左侧区间是(0, 1)时，右子区间一定要满足右边界元素一定没有被选择
因为右子区间左边界有限制(因为左子区间右边界m=1)所以右侧是(0, 0)
此时的值为l[0, 1] + r[0, 0];
所以：t[l,r] = max(l[0, 0] + r[1, 0], l[0, 1] + r[0, 0])

对于t[l,r] (l = 0, r = 1):
它表示左右边界 l一定没有被选择 与 r没有限制(可选可不选)，在线段树中
该区间[l, r]，由左子区间[l, m] 和 右子区间[m + 1, r]组成
当左子区间是(0, 0)时，右子区间一定要满足右边界元素没有限制(即r=1)
因为右子区间左边界没有限制，同时为了使结果尽可能大所以右侧是(1, 1)
此时的值为l[0, 0] + r[1, 1];
当左侧区间是(0, 1)时，右子区间一定要满足右边界元素没有限制(即r=1)
因为右子区间左边界有限制(因为左子区间右边界m=1)所以右侧是(0, 1)
此时的值为l[0, 1] + r[0, 1];
所以：t[l,r] = max(l[0, 0] + r[1, 1], l[0, 1] + r[0, 1])

给出结论
对于t[l, r] (l = 1, r = 0)
t[l,r] = max(l[1, 0] + r[1, 0], l[1, 1] + r[0, 0])
对于t[l, r] (l = 1, r = 1)
t[l,r] = max(l[1, 0] + r[1, 1], l[1, 1] + r[0, 1])

所以：
t[l,r](0,0)=max{L(0,0)+R(1,0),L(0,1)+R(0,0)}
t[l,r](0,1)=max{L(0,0)+R(1,1),L(0,1)+R(0,1)}
t[l,r](1,0)=max{L(1,0)+R(1,0),L(1,1)+R(0,0)}
t[l,r](1,1)=max{L(1,0)+R(1,1),L(1,1)+R(0,1)}

*/
struct SegNode
{
    SegNode()
    {
        v00 = v01 = v10 = v11 = 0;
    }
    void set(long long v)
    {
        v00 = v01 = v10 = 0;
        v11 = max(v, 0LL);
    }
    long long best()
    {
        return v11;
    }

    long long v00, v01, v10, v11;
};

class SegTree
{
public:
    SegTree(int n) : n(n), tree(n * 4 + 1) {}

    // 建树
    void init(const vector<int> &nums)
    {
        internal_init(nums, 1, 1, n);
    }
    void update(int x, int v)
    {
        internal_update(1, 1, n, x + 1, v);
    }
    long long query()
    {
        return tree[1].best();
    }

private:
    void internal_init(const vector<int> &nums, int x, int l, int r)
    {
        // 当左边界与有边界相等时，为叶子结点
        if (l == r)
        {
            tree[x].set(nums[l - 1]);
            return;
        }
        int mid = (l + r) / 2;
        internal_init(nums, x * 2, l, mid);
        internal_init(nums, x * 2 + 1, mid + 1, r);
        pushup(x);
    }
    void internal_update(int x, int l, int r, int pos, int v)
    {
        if (l > pos || r < pos)
        {
            return;
        }
        if (l == r)
        {
            tree[x].set(v);
            return;
        }
        int mid = (l + r) / 2;
        internal_update(x * 2, l, mid, pos, v);
        internal_update(x * 2 + 1, mid + 1, r, pos, v);
        pushup(x);
    }
    void pushup(int x)
    {
        int l = x * 2, r = x * 2 + 1;
        tree[x].v00 = max(tree[l].v00 + tree[r].v10, tree[l].v01 + tree[r].v00);
        tree[x].v01 = max(tree[l].v00 + tree[r].v11, tree[l].v01 + tree[r].v01);
        tree[x].v10 = max(tree[l].v10 + tree[r].v10, tree[l].v11 + tree[r].v00);
        tree[x].v11 = max(tree[l].v10 + tree[r].v11, tree[l].v11 + tree[r].v01);
    }

private:
    int n;
    vector<SegNode> tree; // 使用数组保存线段树
};

class Solution
{
public:
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
    {
        // 线段树在 OI 里面扮演的都是降低时间复杂度工具的角色，常见但不限于，DP优化。
        // 所以当你发现你超时了并且代码中有类似于区间维护之类的部分，就可以考虑线段树优化了
        int n = nums.size();
        SegTree tree(n);
        tree.init(nums);

        int ans = 0;
        for (const auto &q : queries)
        {
            tree.update(q[0], q[1]);
            ans = ((long long)ans + tree.query()) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
// @lc code=end
