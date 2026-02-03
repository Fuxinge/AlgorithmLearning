#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;

int a[N], b[N];

int n, m;

int main()
{
    cin.tie(0);
    cin >> n >> m;
    // bool flag = true;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    int i, j;
    for (i = 1, j = 1; i <= m; i++)
    {
        if (j <= n && a[j] == b[i])
            j++;
    }
    if (j == n + 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}