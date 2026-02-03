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
        v.push_back({b, a}); // 右端点，左端点
    }
    sort(v.begin(), v.end());

    int sum = 0;
    int ed = -0x3f3f3f3f;
    for (int i = 0; i < n; i++)
    {
        int s = v[i].second, e = v[i].first;
        if (ed < s)
        {
            sum++;
            ed = e;
        }
    }

    cout << sum << endl;
    return 0;
}