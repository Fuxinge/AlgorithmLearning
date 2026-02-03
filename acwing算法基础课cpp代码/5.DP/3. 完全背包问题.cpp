#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int f[N];
int n, m;
int v[N], w[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    // 三重循环做法，会超时
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         for (int k = 0; k * v[i] <= j; k++)
    //         {
    //             f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
    //         }
    //     }
    // }

    // 可以过的一版，空间复杂度稍微高一点
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         f[i][j] = f[i - 1][j];
    //         if (j >= v[i])
    //         {
    //             f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        // 这样写是错误的，因为可以买多次同一个物品，所以需要保证后者是在本轮循环中最新的状态
        //  for (int j = m; j >= v[i]; j--)
        for (int j = v[i]; j <= m; j++)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m];
    return 0;
}