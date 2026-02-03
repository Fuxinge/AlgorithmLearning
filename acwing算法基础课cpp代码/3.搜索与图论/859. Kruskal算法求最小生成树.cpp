#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, m;
int p[N]; // 并查集

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edges[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    int res = 0, cnt = 0;

    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        if (find(a) != find(b))
        {
            p[find(a)] = find(b);
            cnt++;
            res += w;
        }
    }

    if (cnt < n - 1)
        return -10086;
    return res;
}

int main()
{
    cin >> n >> m;

    // 并查集初始化
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    sort(edges, edges + m);

    int t = kruskal();

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