#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;
int a[N]; // 每个数
int q[N]; // 所有不同长度的上升子序列的最小末尾元素

int main()
{
    int len = 0; // q里存了的最大长度
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    q[1] = -2e9;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = len + 1;
        while (l < r) // 找到第一个小于a[i]的最长上升子序列中的末尾元素(q)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i])
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        len = max(len, r);
        q[r + 1] = a[i];
    }

    cout << len << endl;
}