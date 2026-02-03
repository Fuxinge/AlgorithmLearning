#include <iostream>
using namespace std;

const int N = 100010;

int stk[N], tt;

void init()
{
    tt = -1;
}

// 判空
bool isempty()
{
    return tt == -1;
}

// 栈内元素数量
int size()
{
    return tt + 1;
}

// 取出顶部元素
int query()
{
    if (!isempty())
        return stk[tt];
    else
        return -1;
}

void push(int x)
{
    tt++;
    stk[tt] = x;
}

// 弹出栈顶元素
void pop()
{
    if (tt > -1)
        tt--;
    else
        cout << "栈为空" << endl;
}

int main()
{
    int m;
    cin >> m;
    init();
    while (m--)
    {
        string a;
        cin >> a;
        int b;
        if (a == "push")
        {
            cin >> b;
            push(b);
        }
        else if (a == "pop")
        {
            pop();
        }
        else if (a == "query")
        {
            int t = query();
            cout << t << endl;
        }
        else if (a == "empty")
        {
            if (isempty() == true)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}