#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k, a[100010];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (k--)
    {
        int x;
        cin >> x;

        int l = 0, r = n - 1;
        while (l < r) // 找起点
        {
            int mid = l + r >> 1;
            if (a[mid] >= x) // check函数
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (a[l] != x)
        {
            cout << "-1 -1" << endl;
        }
        else
        {
            cout << l << " ";
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (a[mid] <= x)
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cout << l << endl;
        }
    }
    return 0;
}