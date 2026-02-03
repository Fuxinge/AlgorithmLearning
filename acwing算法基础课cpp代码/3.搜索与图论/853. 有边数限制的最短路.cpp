#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010;

struct Edge
{
    int a, b, w;
} edges[M];

int n, m, k, a, b, w;

int dist[N], backup[N];

int bellmanford()
{
    memset(dist, 0x3f, sizeof(dist));

    dist[1] = 0;

    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof(dist));

        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;

            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2)
        return -10086;
    return dist[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int t = bellmanford();

    if (t == -10086)
    {
        puts("impossible");
    }
    else
    {
        cout << t << endl;
    }
    return 0;
}