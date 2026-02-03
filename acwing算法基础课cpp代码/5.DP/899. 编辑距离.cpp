#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int m, n, a, b, c;

char s[N][N];

int dp[N][N];

int edit_distance(char a[], char b[]) // dp[i][j],a前i个变成b前j个要多少步
{
    int lena = strlen(a + 1), lenb = strlen(b + 1);
    for (int i = 1; i <= lenb; i++)
        dp[0][i] = i; // 插入
    for (int i = 1; i <= lena; i++)
        dp[i][0] = i; // 删除

    for (int i = 1; i <= lena; i++)
    {
        for (int j = 1; j <= lenb; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }

    return dp[lena][lenb];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] + 1;
    }

    while (m--)
    {
        int res = 0;
        int k;
        char p[N];
        cin >> p + 1 >> k;
        for (int i = 1; i <= n; i++)
        {
            if (edit_distance(s[i], p) <= k)
                res++;
        }

        cout << res << endl;
    }
    return 0;
}