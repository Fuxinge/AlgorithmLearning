#include <iostream>
using namespace std;

const int N = 100010;

int sizeP[N], p[N], n, m;

int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        sizeP[i] = 1;
    }
    while (m--)
    {
        string op;
        int a, b;
        cin >> op;

        if (op == "C")
        {
            cin >> a >> b;
            if (find(a) != find(b))
                sizeP[find(b)] += sizeP[(find(a))];
            p[find(a)] = find(b);
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << sizeP[find(a)] << endl;
        }
    }
    return 0;
}