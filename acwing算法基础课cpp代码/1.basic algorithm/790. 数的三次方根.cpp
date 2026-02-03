#include <iostream>
using namespace std;

double x;
int main()
{
    cin >> x;
    double l = -10000, r = 10000;
    while (r - l > 1e-10)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid > x)
            r = mid;
        else
            l = mid;
    }
    printf("%.6lf", l);
    return 0;
}
