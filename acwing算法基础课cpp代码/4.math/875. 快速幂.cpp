#include <bits/stdc++.h>
using namespace std;

int n;
long long a, b, p;
long long qmi(long long m, long long k, long long p)
{
    long long res = 1 % p, t = m;
    while (k)
    {
        if (k % 2 == 1)
            res = res * t % p;
        t = t * t % p;
        k /= 2;
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }
    return 0;
}