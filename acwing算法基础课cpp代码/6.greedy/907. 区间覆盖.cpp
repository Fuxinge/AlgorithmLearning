#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

typedef pair<int, int> PII;

PII lr[N];

int n, r, l, t, s;

int main()
{
    cin >> s >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        lr[i] = {l, r};
    }

    sort(lr + 1, lr + 1 + n);

    int st = s, ed = t;
    int res = 0;
    for (int i = 1; i <= n;)
    {
        int j = i, r = -2e9;
        while (j <= n && lr[j].first <= st)
        {
            r = max(r, lr[j].second);
            j++;
        }

        if (r < st)
        {
            res = -1;
            break;
        }

        st = r;
        res++;

        if (st >= ed)
        {
            break;
        }

        i = j;
    }

    // 检查是否成功覆盖
    if (st < ed)
    {
        res = -1;
    }

    cout << res << endl;

    return 0;
}
