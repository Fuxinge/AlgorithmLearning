#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
long long ans;

int n;
int t[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }

    sort(t + 1, t + 1 + n);

    for (int i = 1; i <= n; i++)
    {
        ans += (n - i) * t[i];
    }

    cout << ans << endl;

    return 0;
}