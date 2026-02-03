#include <iostream>
#include <cmath>
using namespace std;

void divide(int x)
{
    if (x <= 2)
    {
        cout << x << " " << "1" << endl;
        cout << endl;
        return;
    }
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0)
            {
                s++;
                x /= i;
            }

            cout << i << " " << s << endl;
        }
    }
    if (x > 1)
    {
        cout << x << " 1" << endl;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        divide(x);
    }

    return 0;
}