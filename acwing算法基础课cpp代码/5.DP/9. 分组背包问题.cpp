#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int s[N], v[N][N], w[N][N];
int d[N];

int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k <= s[i]; k++)
            {
                if (j >= v[i][k])
                {
                    d[j] = max(d[j], d[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    cout << d[m] << endl;
    return 0;
}