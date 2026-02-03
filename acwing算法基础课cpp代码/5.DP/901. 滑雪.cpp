#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int g[N][N], f[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m, res;

int dfs(int x, int y)
{
    if (f[x][y] != -1)
        return f[x][y];

    f[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && b >= 1 && a <= n && b <= m && g[x][y] > g[a][b])
        {
            f[x][y] = max(f[x][y], dfs(a, b) + 1);
        }
    }

    return f[x][y];
}

int main()
{
    memset(g, 0x3f, sizeof(g));
    memset(f, -1, sizeof(f));
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res = max(res, dfs(i, j));
        }
    }

    cout << res << endl;
    return 0;
}