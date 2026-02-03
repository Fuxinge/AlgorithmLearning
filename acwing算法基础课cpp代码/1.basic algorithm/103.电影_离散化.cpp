#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> s, a, b, c;
int ans[600010], res[600010];

// 对 s 向量进行排序并去重
void sortAndUnique()
{
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
}

// 二分查找 x 在 s 中的离散化位置
int find(int x)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (s[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l + 1;
}

int n, m;

int main()
{
    cin >> n;

    // 读取科学家懂得的语言编号
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        a.push_back(t);
        s.push_back(t);
    }

    cin >> m;

    // 读取电影的语音语言编号
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        b.push_back(t);
        s.push_back(t);
    }

    // 读取电影的字幕语言编号
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        c.push_back(t);
        s.push_back(t);
    }

    sortAndUnique();

    // 初始化 ans 数组
    memset(ans, 0, sizeof(ans));

    // 统计每种语言对应的科学家数量
    for (int i = 0; i < n; i++)
    {
        int t = find(a[i]);
        ans[t]++;
    }

    int ans0 = 0, ans1 = 0, ans2 = 0;

    // 遍历每部电影，计算得分并选择最优电影
    for (int i = 0; i < m; i++)
    {
        int index1 = find(b[i]);
        int index2 = find(c[i]);

        if (ans[index1] > ans1 || (ans[index1] == ans1 && ans[index2] > ans2))
        {
            ans0 = i + 1; // 电影编号从 1 开始
            ans1 = ans[index1];
            ans2 = ans[index2];
        }
    }

    // 如果所有电影的语音和字幕语言科学家都不懂，选第一部电影
    if (ans0 == 0)
    {
        printf("%d\n", 1);
    }
    else
    {
        printf("%d\n", ans0);
    }

    return 0;
}
