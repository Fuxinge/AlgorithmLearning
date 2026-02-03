#include <iostream>
using namespace std;

const int N = 1000010;

int n, k;

int q[N], a[N], hh, tt;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        // 找每个滑动窗口的最小值
        // 判断队首是否已经滑出窗口，队列不为空,且，队首元素的下标还在滑动窗口的范围内
        if (hh <= tt && q[hh] < i - k + 1) // i-k+1是滑动窗口的下边界，比它小就滑出
            hh++;
        // 队列不为空，且，队尾元素大于当前元素（即将入队的这个元素）
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        tt++;
        q[tt] = i;
        if (i >= k - 1)
            cout << a[q[hh]] << " ";
    }
    cout << endl;

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        // 判断队首是否已经滑出窗口
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;
        // 队列不为空，且，队尾元素小于当前元素（即将入队的这个元素）
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        tt++;
        q[tt] = i;
        if (i >= k - 1)
            cout << a[q[hh]] << " ";
    }

    return 0;
}

// 常见模型：找出滑动窗口中的最大值 / 最小值 int hh = 0, tt = -1;
// for (int i = 0; i < n; i++)
// {
//     while (hh <= tt && check_out(q[hh]))
//         hh++; // 判断队头是否滑出窗口
//     while (hh <= tt && check(q[tt], i))
//         tt--;
//     q[++tt] = i;
// }