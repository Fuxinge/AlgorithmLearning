#include <iostream>
using namespace std;
const int N = 100010;

int n, stk[N], tt;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (tt && stk[tt] <= x)
            tt--;
        if (tt)
            cout << stk[tt] << " ";
        else
            cout << -1 << " ";

        tt++;
        stk[tt] = x;
    }
    return 0;
}

// 常见模型：找出每个数左边离它最近的比它大 / 小的数 int tt = 0;
// for (int i = 1; i <= n; i++)
// {
//     while (tt && check(stk[tt], i))
//         tt--;
//     stk[++tt] = i;
// }