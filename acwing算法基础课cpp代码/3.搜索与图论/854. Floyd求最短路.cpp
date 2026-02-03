#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int d[N][N];
int n, m, a, b, w, k, q;

void Floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = 0x3f3f3f3f;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> w;
        d[a][b] = min(w, d[a][b]);
    }

    Floyd();

    for (int i = 1; i <= q; i++)
    {
        cin >> a >> b;
        if (d[a][b] >= 0x3f3f3f3f / 2)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << d[a][b] << endl;
        }
    }
}