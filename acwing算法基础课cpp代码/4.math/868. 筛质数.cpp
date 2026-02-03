#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
vector<int> nums;
bool st[N];
void isPrime(int n)
{
    memset(st, 1, sizeof(st));
    st[2] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (st[i])
        {
            for (int j = i + i; j <= n; j += i)
            {
                st[j] = 0;
            }
            nums.push_back(i);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    isPrime(n);

    cout << nums.size() << endl;
    return 0;
}