// 适用于稠密图，朴素prim算法
#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int g[N][N];
int dist[N];
bool st[N];
int n, m, a, b, c;

int prim()
{
    memset(dist, 0x3f, sizeof(dist));

    int res = 0; // 最小生成树的总长度
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        // 如果不是第一个点且为正无穷，说明当前最近的点为正无穷，即，不联通，即不存在最小生成树
        if (i && dist[t] == INF)
            return INF;

        if (i)              // 防止负数自环，所以要先加入，再更新其他点到集合的距离
            res += dist[t]; // 不是第一个点就加入总长度

        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], g[t][j]); // 到集合的距离
        }

        st[t] = true;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    memset(g, 0x3f, sizeof(g));

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF)
        puts("impossible");
    else
        cout << t << endl;
}