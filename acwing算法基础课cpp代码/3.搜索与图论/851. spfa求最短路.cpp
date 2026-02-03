#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int e[N * 2], ne[N * 2], idx, h[N], w[N]; // w为权重
int n, m, a, b, c;
bool st[N];
int dist[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa()
{
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i]; // 终点
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2)
        return -10086;
    return dist[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    memset(h, -1, sizeof(h));

    while (m--)
    {
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int t = spfa();
    if (t == -10086)
        puts("impossible");
    else
        cout << t << endl;
    return 0;
}