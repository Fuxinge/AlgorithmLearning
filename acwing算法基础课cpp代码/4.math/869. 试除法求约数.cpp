#include <bits/stdc++.h>
using namespace std;

int n;

void yue(int x)
{
    vector<int> s;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            s.push_back(i);
            if (i != x / i)
            {
                s.push_back(x / i);
            }
        }
    }
    sort(s.begin(), s.end());
    for (auto a : s)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        yue(a);
    }
}