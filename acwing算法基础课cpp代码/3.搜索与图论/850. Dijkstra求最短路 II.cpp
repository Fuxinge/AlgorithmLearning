#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int e[N * 2], ne[N * 2], idx, h[N], w[N]; // w为权重
int n, m, a, b, c;
bool st[N];
int dist[N];
priority_queue<PII, vector<pair<int, int>>, greater<PII>> heap;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra2()
{

    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    heap.push({0, 1}); // 距离+编号

    while (!heap.empty())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver])
            continue;
        st[ver] = true; // 标记该节点已处理
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
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

    cout << dijkstra2() << endl;
    return 0;
}