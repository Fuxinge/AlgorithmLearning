#include <iostream>
using namespace std;

const int N = 100010;

int q[N], ll, rr;

void init()
{
    ll = rr = 0;
}

// 队尾插入
void push(int x)
{
    q[rr] = x;
    rr++;
}

// 队头弹出
void pop()
{
    if (rr > ll)
        ll++;
}

// 队头取出
int query()
{

    return q[ll];
}

// size
int size()
{
    return rr - ll;
}

// 判空
bool isempty()
{
    return ll == rr;
}

int main()
{
    ios::sync_with_stdio(false);
    // ios::sync_with_stdio(false);
    int m;
    cin >> m;
    while (m--)
    {
        string k;
        int x;
        cin >> k;
        if (k == "push")
        {
            cin >> x;
            push(x);
        }
        else if (k == "pop")
        {
            pop();
        }
        else if (k == "query")
        {
            int t = query();
            cout << t << endl;
        }
        else if (k == "empty")
        {
            if (isempty() == true)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    // for (int i = ll; i <= rr; i++)
    // {
    //     cout << q[i] << " ";
    // }
    return 0;
}