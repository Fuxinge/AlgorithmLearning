#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

typedef pair<int, int> PII;

vector<PII> v;

int a, b, n;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());

    int sum = 1;
    int st = v[0].second, ed = v[0].first;
    for (int i = 0; i < n; i++)
    {
        int s = v[i].second, e = v[i].first;
        if (ed >= s)
            continue;
        else
        {
            ed = e;
            sum++;
        }
    }

    cout << sum << endl;
    return 0;
}