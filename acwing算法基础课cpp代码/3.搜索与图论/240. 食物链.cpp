#include <bits/stdc++.h>
using namespace std;

const int N = 50010;

int p[N], d[N];
int n, k, d0, x, y;

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        // 父节点等于父节点的根节点
        d[x] += d[p[x]];
        p[x] = t;
    }

    return p[x];
}

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    int res = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> d0 >> x >> y;
        if (x > n || y > n)
        {
            res++;
            continue;
        }
        else
        {
            int px = find(x), py = find(y);
            if (d0 == 1)
            {
                if (px == py && (d[x] - d[y]) % 3 != 0)
                {
                    res++;
                }
                else if (px != py) // 不在一个树上
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3)
                {
                    res++;
                }
                else
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}