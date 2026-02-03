#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int res, n, a, b;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> q;
    for (auto [l, r] : v)
    {
        // v 是按左端点排序的，所以如果堆顶的右端点大于当前点的左端点，那么二者必有重叠
        if (q.size() == 0 || q.top() >= l)
        {
            q.push(r);
        }
        else
        {
            q.pop();
            q.push(r);
        }
    }

    cout << q.size();
    return 0;
}