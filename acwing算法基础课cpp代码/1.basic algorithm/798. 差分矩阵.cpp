#include <iostream>

#include <vector>

using namespace std;

int a[1010][1010], b[1010][1010];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &b[i][j]); // 原始矩阵
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 逆用前缀和，构造的差分矩阵
            // b[i][j] +=  b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
            a[i][j] = b[i][j] + b[i - 1][j - 1] - b[i][j - 1] - b[i - 1][j];
        }
    }

    while (q--)
    {
        int x1, y1, x2, y2, x;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &x);
        a[x1][y1] += x;
        a[x1][y2 + 1] -= x;
        a[x2 + 1][y1] -= x;
        a[x2 + 1][y2 + 1] += x;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // b[i][j] += b[i][j-1] + b[i-1][j] + a[i][j] - b[i-1][j-1];
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}