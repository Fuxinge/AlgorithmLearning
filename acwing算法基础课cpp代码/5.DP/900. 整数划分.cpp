#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7, N = 100010;

int n, f[N];

int main()
{
    cin >> n;
    f[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            f[j] = (f[j] + f[j - i]) % M;
        }
    }

    cout << f[n];
    return 0;
}