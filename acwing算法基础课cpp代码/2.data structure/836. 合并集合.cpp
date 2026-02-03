#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int p[N];

int find(int x) // 加上路径压缩的优化
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        // string op;
        char op[2];
        int a, b;
        cin >> op;
        cin >> a >> b;
        if (op[0] == 'M')
        {
            p[find(a)] = find(b); // a的祖宗节点的父亲，设为b的祖宗节点
        }
        else
        {
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}