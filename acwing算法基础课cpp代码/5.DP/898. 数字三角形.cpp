#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int d[N][N], n, a[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(d, -0x3f, sizeof(d));

    d[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, d[n][i]);
    }

    cout << ans << endl;
    return 0;
}