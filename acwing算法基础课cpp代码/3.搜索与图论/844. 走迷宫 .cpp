#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, m;
int a[N][N];
int d[N][N]; // 当前点到起点的距离
queue<pair<int, int>> q;
pair<int, int> pre[N][N];

int bfs()
{
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    q.push({0, 0});

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0 && d[x][y] == -1)
            {
                // 距离++
                d[x][y] = d[t.first][t.second] + 1;
                // 记录当前的这个点{x,y}由t点过来
                pre[x][y] = t;
                q.push({x, y});
            }
        }
    }

    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int p = bfs();
    cout << p << endl;
    return 0;
}