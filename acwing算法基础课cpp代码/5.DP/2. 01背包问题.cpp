#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int f[N];

int v[N], w[N];

int main()
{
    int n, V;
    cin >> n >> V;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = a, w[i] = b;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= v[i]; j--)
        {
            if (j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= V; j++)
    //     {
    //         f[i][j] = f[i - 1][j];
    //         if (j >= v[i])
    //             f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
    //     }
    // }

    cout << f[V];
}