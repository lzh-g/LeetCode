/**
 * 卡玛网 58区间和
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<int> sum(n, 0);
    int presum = 0;
    int a, b;

    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
        presum += ans[i];
        sum[i] = presum;
    }

    while (cin >> a >> b)
    {
        if (a == 0)
        {
            cout << sum[b] << endl;
        }
        else
        {
            cout << sum[b] - sum[a - 1] << endl;
        }
    }
}