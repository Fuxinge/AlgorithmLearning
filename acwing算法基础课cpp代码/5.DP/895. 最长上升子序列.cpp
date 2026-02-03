#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;
int a[N];
int f[N];
int p[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 初始化 p 数组，用于回溯
    memset(p, -1, sizeof p);

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1; // 只有 a[i] 一个数
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {
                if (f[i] < f[j] + 1)
                {
                    f[i] = f[j] + 1;
                    p[i] = j;
                }
            }
        }
    }

    int res = 0;
    int end_index = 0; // 记录最长上升子序列的最后一个元素的索引
    for (int i = 1; i <= n; i++)
    {
        if (res < f[i])
        {
            res = f[i];
            end_index = i;
        }
    }

    cout << res << endl;

    // 回溯找出最长上升子序列
    vector<int> lis;
    for (int i = end_index; i != -1; i = p[i])
    {
        lis.push_back(a[i]);
    }

    // 反转结果，因为是倒序存储的
    reverse(lis.begin(), lis.end());

    // 输出最长上升子序列
    for (int num : lis)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}