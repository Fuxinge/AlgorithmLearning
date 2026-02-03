#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int h[N], sizeH;
int hp[N]; // 第K个插入的节点在堆中的位置
int ph[N]; // 下标为K的节点是第几个插入的

void down(int u)
{
    int t = u;
    if (u * 2 <= sizeH && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= sizeH && h[u * 2 + 1] < h[t])
        t = 2 * u + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    sizeH = n;
    // 建堆
    for (int i = n / 2; i; i--)
        down(i);

    while (m--)
    {
        cout << h[1] << " ";
        h[1] = h[sizeH];
        sizeH--;
        down(1);
    }

    return 0;
}