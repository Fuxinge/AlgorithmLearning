#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

int n, m, a, b, c;
int h[N], e[N], ne[N], w[N], idx;
int cnt[N], dist[N]; // cnt[i]为从1到i的最短路径的边数
bool st[N];
queue<int> q;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa()
{
    // memset(dist, 0x3f, sizeof(dist));
    // 不能只放一个点，可能无法到达另外的部分，要把所有的点都放进去
    // dist[1] = 0;
    // q.push(1);
    // st[1] = true;
    for (int i = 1; i <= n; i++)
    {
        st[i] = true;
        q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa())
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
    return 0;
}