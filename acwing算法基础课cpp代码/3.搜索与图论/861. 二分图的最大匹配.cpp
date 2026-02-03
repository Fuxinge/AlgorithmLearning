#include <bits/stdc++.h>
using namespace std;

const int M = 100010, N = 510;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
bool st[N];
int match[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool find(int x) // 判断男生可否找到合适的妹子
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || find(match[j])) // 如果当前妹子没有匹配的男生，或者能给她找到下家？
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n1 >> n2 >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof(st));
        if (find(i))
            res++;
    }

    cout << res << endl;
    return 0;
}