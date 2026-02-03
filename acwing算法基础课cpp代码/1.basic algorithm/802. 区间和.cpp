#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

vector<int> alls;
vector<PII> query, add;

void sortAndUnique()
{
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
}

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1; // 映射到下标从1开始，与题目相关
}

int s[300010], a[300010]; // s为前缀和，a为元素

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sortAndUnique();

    // 处理插入
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= alls.size(); i++)
    {
        s[i] = a[i] + s[i - 1];
    }

    // 处理询问
    for (auto item : query)
    {
        int l = find(item.first);
        int r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}