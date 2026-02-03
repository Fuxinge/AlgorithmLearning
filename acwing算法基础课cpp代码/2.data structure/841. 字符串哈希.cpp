#include <iostream>
using namespace std;

// P为P进制,经验值131/13331，mod的值为2^64 取unsigned long long 存储正好可以移除
// 本种字符串哈希我们认为不会发生冲突，
const int N = 100010, P = 131;

string s;
int n, m;
unsigned long long h[N], p[N];

unsigned long long cal(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        h[i] = h[i - 1] * P + s[i];
        p[i] = p[i - 1] * P;
    }
    while (m--)
    {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (cal(l1, r1) == cal(l2, r2))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}
