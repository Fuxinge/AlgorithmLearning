
#include <iostream>
using namespace std;

const int N = 100;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

// 第一种搜索顺序，类似842排列数字，提炼出每行/每列/对角线不能有
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++) // 这里是从层的角度循环
        {
            puts(g[i]);
        }
        puts("");
        return;
    }

    for (int i = 0; i < n; i++) // 这里是从数的范围循环,按行枚举
    {
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = 1;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = 0;
            g[u][i] = '.';
        }
    }
}

// 第二种方式，枚举每个格子是否要放皇后。
int row[N];
void dfs(int x, int y, int s)
{
    if (y == n)
    {
        y = 0, x++;
    }

    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
            {
                puts(g[i]);
            }
            puts("");
        }
        return;
    }

    // 不放皇后
    dfs(x, y + 1, s);

    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = 1;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = 0;
        g[x][y] = '.';
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    // 第一种
    // dfs(0); // 0是层数

    // 第二种
    dfs(0, 0, 0);
    return 0;
}