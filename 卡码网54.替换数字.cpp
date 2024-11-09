#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    while (cin >> s)
    {
        int sOldIndex = s.size() - 1;
        // 统计数字字符个数
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                count++;
            }
        }
        // 扩充字符串长度
        s.resize(s.size() + 5 * count);
        int sNewIndex = s.size() - 1;
        while (sOldIndex >= 0)
        {
            // 字母挪过去
            if (s[sOldIndex] >= 'a' && s[sOldIndex] <= 'z')
            {
                s[sNewIndex--] = s[sOldIndex];
            }
            else
            {
                s[sNewIndex--] = 'r';
                s[sNewIndex--] = 'e';
                s[sNewIndex--] = 'b';
                s[sNewIndex--] = 'm';
                s[sNewIndex--] = 'u';
                s[sNewIndex--] = 'n';
            }
            sOldIndex--;
        }
    }
    cout << s << endl;

    return 0;
}
