#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int e[N], ne[N], idx, h[N], w[N], happy[N];

int f[N][2];

bool hasFather[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u)
{
    f[u][1] += happy[u];
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> happy[i];
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        hasFather[a] = true;
        add(b, a);
    }

    int root = 1;
    while (hasFather[root])
    {
        root++;
    }

    dfs(root);

    cout << max(f[root][0], f[root][1]);
}