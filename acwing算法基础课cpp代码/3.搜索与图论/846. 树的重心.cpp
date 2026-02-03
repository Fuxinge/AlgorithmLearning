#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N * 2;
int n, m, ans = N;

int h[N], e[M], idx, ne[M];
// e[j] 表示第 j 条边的终点节点编号。
// ne[j] 存储的是编号为 j 的边的下一条边在 e 数组中的索引。
// 如果 ne[j]为-1，表示编号为 j 的边是该节点链表的最后一条边。
bool st[N] = {false};

// 添加从a到b的一条边
void add(int a, int b)
{
    e[idx] = b;     // 将当前边（编号为 idx）的终点设为节点 b
    ne[idx] = h[a]; // 将当前边（编号为 idx）的下一条边的索引设为原来节点 a 的链表的头节点的索引。
    h[a] = idx++;   // 将节点 a 的链表的头节点的索引更新为当前边的编号 idx
}

// dfs 框架
/*
void dfs(int u){
    st[u]=true; // 标记一下，记录为已经被搜索过了，下面进行搜索过程
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]) {
            dfs(j);
        }
    }
}
*/

int dfs(int u) // 返回以u为根的子树中点的数量
{
    st[u] = 1;

    int sum = 1, res = 0;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);

    ans = min(ans, res); // ans为全局变量，存储最终的结果

    return sum; // sum是以u为根的子树的点的数量
}

int main()
{
    memset(h, -1, sizeof(h));

    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}