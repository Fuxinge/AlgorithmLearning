#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

vector<PII> seg;

vector<PII> merge(vector<PII> &seg)
{
    if (seg.size() == 0)
        return seg;

    sort(seg.begin(), seg.end());
    seg.erase(unique(seg.begin(), seg.end()), seg.end());

    vector<PII> ans;

    int st = -2e9, ed = -2e9;

    for (auto s : seg)
    {
        if (s.first > ed)
        {
            if (st != -2e9)
                ans.push_back({st, ed});
            st = s.first, ed = s.second;
        }
        else
        {
            ed = max(s.second, ed);
        }
    }
    if (st != -2e9)
        ans.push_back({st, ed});

    seg = ans;
    return seg;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        seg.push_back({a, b});
    }

    auto res = merge(seg);

    cout << seg.size() << endl;
    return 0;
}