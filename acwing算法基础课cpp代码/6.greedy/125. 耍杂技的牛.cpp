#include <bits/stdc++.h>
using namespace std;

const int N = 50010;

int n, l, s;

typedef pair<int, int> PII;

PII cow[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> s; // l 重量，s身体强度
        int w = l + s;
        cow[i] = {w, s};
    }

    sort(cow + 1, cow + n + 1);

    int sum = 0, res = -2222222;
    for (int i = 1; i <= n; i++)
    {
        sum -= cow[i].second;
        res = max(res, sum);
        sum += cow[i].first;
    }

    cout << res << endl;

    return 0;
}