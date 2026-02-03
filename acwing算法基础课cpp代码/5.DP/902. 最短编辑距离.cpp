#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
char a[N], b[N];
int n, m, f[N][N]; // a字符串1-i编程b字符串1-j的区别

int main()
{
    cin >> n >> a + 1 >> m >> b + 1;

    for (int i = 0; i <= n; i++)
        f[i][0] = i; // 删除
    for (int i = 0; i <= m; i++)
        f[0][i] = i; // 插入

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    }

    cout << f[n][m] << endl;
    return 0;
}