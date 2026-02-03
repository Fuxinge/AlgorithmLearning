#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int h[N], e[N], ne[N], idx;
int color[N], n, m;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c))
                return false;
        }
        else if (color[j] == c)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!color[i]) // 没染过色
        {
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}