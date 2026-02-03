#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

stack<char> op;
stack<long long> num;

int cmp(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
    else
        return 0;
}

void calvalue()
{
    long long a = num.top();
    num.pop();

    long long b = num.top();
    num.pop();

    long long c = op.top();
    op.pop();

    long long res = 0;

    if (c == '+')
    {
        res = a + b;
    }
    else if (c == '-')
    {
        res = b - a;
    }
    else if (c == '*')
    {
        res = b * a;
    }
    else if (c == '/')
    {
        res = b / a;
    }

    num.push(res);
}

int main()
{
    cin.tie(0);
    string exp;
    getline(cin, exp);

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] <= '9' && exp[i] >= '0')
        {
            long long a = 0;
            int j = i;
            while (j < exp.size() && exp[j] >= '0' && exp[j] <= '9')
            {
                a = a * 10 + (exp[j] - '0');
                j++;
            }
            num.push(a);
            i = j - 1;
        }
        else if (exp[i] == '(')
        {
            op.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (op.top() != '(')
            {
                calvalue();
            }
            op.pop();
        }
        else
        {
            while (op.size() && cmp(op.top()) >= cmp(exp[i]))
            {
                calvalue();
            }
            op.push(exp[i]);
        }
    }
    while (op.size())
        calvalue();            // 剩余的进行计算
    cout << num.top() << endl; // 输出结果
    return 0;
}