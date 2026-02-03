#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;

int x, n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        heap.push(x);
    }

    int ans = 0;
    while (heap.size() > 1)
    {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();

        int t = a + b;
        ans += t;
        heap.push(t);
    }

    // ans += heap.top();

    cout << ans << endl;
    return 0;
}