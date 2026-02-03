#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int a[N], n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int t = a[n / 2 + 1];

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += abs(a[i] - t);
    }
    // cout<<t<<endl;
    cout << sum << endl;
    return 0;
}