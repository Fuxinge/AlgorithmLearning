#include <bits/stdc++.h>
using namespace std;

int a, b;
int num[10];

int dgt(int x)
{
    int res = 0;
    while (x)
    {
        res++;
        x /= 10;
    }

    return res;
}

int cnt(int s, int i) // 1-s,i出现的次数
{
    int len = dgt(s), res = 0; // 最高位数len，结果res
    for (int j = 1; j <= len; j++)
    {
        // abc  d  efg,,,j = 4 ,p = 1000,
        int p = pow(10, j - 1), l = s / p / 10, r = s % p;
        int dj = s / p % 10;

        // 然后开始分类讨论

        // 本代码块是计算的 l < 真实的abc 的情况
        // 如果i不为0，，加上abc部分
        res += (i != 0) * l * p;
        // 否则,i为0时要保证l不为0
        res += (i == 0 && l != 0) * (l - 1) * p;

        // 如果dj大于i的话，i是我想要统计的数字，dj是当前位置的数字
        if (dj > i && (i || l))
            res += p;

        // 如果dj小于i的话
        // res += 0;

        // 如果dj等于i的话
        if (dj == i && (i || l))
            res += r + 1;
    }

    return res;
}

int main()
{
    while (cin >> a >> b, a || b)
    {
        if (a > b)
            swap(a, b);
        for (int i = 0; i <= 9; i++)
        {
            cout << cnt(b, i) - cnt(a - 1, i) << " ";
        }
        cout << endl;
    }

    return 0;
}