#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = N * 2;

int e[M], h[N], idx, ne[M], dist[N];
bool st[N];
int n, m;
queue<int> q;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    memset(dist, -1, sizeof(dist));
    q.push(1);
    dist[1] = 0;
    while (q.size())
    {
        auto t = q.front();
        int distance = dist[t];
        if (t == n)
        {
            return dist[n];
        }
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!st[j])
            {
                st[j] = 1;
                dist[j] = distance + 1;
                q.push(j);
            }
        }
    }

    return -1;
}

int main()
{
    cin.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;
    return 0;
}