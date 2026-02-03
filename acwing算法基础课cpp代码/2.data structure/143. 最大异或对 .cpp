#include <iostream>
using namespace std;

const int N = 100010, M = N * 31;

int son[M][2], a[N], idx, n;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1; // 取X的第i位的二进制数(前面的模板)
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            p = son[p][!u];
            res = res * 2 + 1;
        }
        else
        {
            p = son[p][u];
            res = res * 2;
        }
    }

    return res;
}

int main()
{
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, query(a[i]));
    }
    cout << res << endl;
    return 0;
}