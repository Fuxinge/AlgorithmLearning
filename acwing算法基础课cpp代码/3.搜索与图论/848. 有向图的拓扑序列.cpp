#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int e[N * 2], ne[N * 2], idx, n, m, h[N];
int q[N], d[N]; // 入度

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i; // 将入度为零的点入队
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;        // 删除点t指向点j的边
            if (d[j] == 0) // 如果点j的入度为零了,就将点j入队
                q[++tt] = j;
        }
    }
    return tt == n - 1;
    // 表示如果n个点都入队了话,那么该图为拓扑图,返回true,否则返回false
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[a]++;
    }

    if (topsort())
    {
        for (int i = 0; i < n; i++)
        {
            cout << q[i] << " ";
        }
    }
    else
    {
        puts("-1");
    }

    return 0;
}