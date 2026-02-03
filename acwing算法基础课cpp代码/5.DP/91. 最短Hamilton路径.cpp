// 汉密尔顿路径从0到n-1，不重不漏的经历所有点，有且仅经过一次
#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 1 << N;

int f[M][N]; // 所有从0到j，走过的点是i的所有路径的集合，属性是min
int w[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof(f));

    f[1][0] = 0;

    // 状态
    for (int i = 0; i < 1 << n; i++)
    {
        // 循环j,表示走到哪一个点
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1) // 走到过第j位
                // k表示走到j这个点之前,以k为终点的最短距离
                for (int k = 0; k < n; k++)
                {
                    if (i >> k & 1)
                    {
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                    }
                }
        }
    }

    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}