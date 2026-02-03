#include <iostream>
#include <cmath>

using namespace std;

int a[100010], b[100010];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        b[a[i]]++;
        while (j <= i && b[a[i]] > 1)
        {
            b[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res;

    return 0;
}