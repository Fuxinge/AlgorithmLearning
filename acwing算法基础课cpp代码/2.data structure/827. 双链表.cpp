#include <iostream>
using namespace std;

const int N = 100010;

int n, idx, e[N], r[N], l[N];

void init()
{
    idx = 2;
    l[1] = 0;
    r[0] = 1;
}

void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    r[k] = idx;
    l[r[idx]] = idx;
    idx++; // 本行必须分开写
}
void del(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    init();
    while (n--)
    {
        string op;
        int x, k;
        cin >> op;
        if (op == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else if (op == "IR")
        {
            cin >> k >> x;
            add(k + 1, x);
        }
        else if (op == "D")
        {
            cin >> k;
            del(k + 1);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
    {
        cout << e[i] << " ";
    }
    cout << endl;
    return 0;
}