/**
 * 卡码网55.右旋字符串
 */
#include <iostream>
#include <string>

using namespace std;

void reverse(string &s, int start, int end)
{
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

int main(int argc, char const *argv[])
{
    int k;
    string s;
    cin >> k >> s;
    reverse(s, 0, s.size() - 1);
    reverse(s, 0, k - 1);
    reverse(s, k, s.size() - 1);

    cout << s << endl;

    return 0;
}
