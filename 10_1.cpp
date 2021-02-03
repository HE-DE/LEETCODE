#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p)
{ //动态规划解决正则匹配
    int m = s.size();
    int n = p.size();

    //状态转移方程的定义
    auto matches = [&](int i, int j) {
        if (i == 0)
        {
            return false;
        }
        if (p[j - 1] == '.')
        {
            return true;
        }
        return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> f(m + 1, vector<int>(n + 1)); //f[i][j] 表示 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配
    f[0][0] = true;                                   //边界条件
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*')
            {
                f[i][j] |= f[i][j - 2];
                if (matches(i, j - 1))
                {
                    f[i][j] |= f[i - 1][j];
                }
            }
            else
            {
                if (matches(i, j))
                {
                    f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
    }
    return f[m][n];
}
