#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int g[N][N];
int n, m;
int dist[N];
bool st[N];

int dijkstra1()
{
    memset(dist, 0x3f, sizeof(dist)); // 按字节存储的,每个字节0x3f，总共0x3f3f3f3f
    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1; // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }

        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }

        st[t] = 1;
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    memset(g, 0x3f, sizeof(g));

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra1() << endl;
    return 0;
}