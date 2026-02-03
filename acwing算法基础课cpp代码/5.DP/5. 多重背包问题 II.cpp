#include <bits/stdc++.h>
using namespace std;

const int N = 101000;

int f[N][N];
int d[N];
int n, m;
int v[N], cnt, w[N], s[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            v[++cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }

        if (s)
        {
            v[++cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    for (int i = 1; i <= cnt; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            d[j] = max(d[j], d[j - v[i]] + w[i]);
        }
    }

    cout << d[m];
    return 0;
}

// O(n^3) 小规模可过
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1010;

// int f[N][N];
// int n, m;
// int v[N], cnt, w[N], s[N];

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> v[i] >> w[i] >> s[i];
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             f[i][j] = f[i - 1][j];
//             for (int k = 0; k <= s[i]; k++)
//             {
//                 if (k * v[i] <= j)
//                     f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
//             }
//         }
//     }

//     cout << f[n][m];
//     return 0;
// }