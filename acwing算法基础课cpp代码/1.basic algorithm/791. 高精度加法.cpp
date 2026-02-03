#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a, b;

vector<int> add(vector<int> a, vector<int> b)
{
    if (a.size() < b.size())
        return add(b, a);

    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i];
        if (i < b.size())
            t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }

    if (t > 0)
        c.push_back(t);

    return c;
}

bool checkIsPos(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
        return a.size() > b.size();

    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}

vector<int> sub(vector<int> a, vector<int> b)
{
    if (checkIsPos(a, b) == false)
        return sub(b, a);
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if (i < b.size())
            t -= b[i];

        c.push_back((t + 10) % 10);

        if (t < 0)
            t = 1;
        else
            t = 0;
    }

    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}

vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t = t / 10;
    }
    if (t)
        c.push_back(t);

    while (c.back() == 0 && c.size() > 1)
        c.pop_back();

    return c;
}

vector<int> div(vector<int> a, int b, int &t)
{
    vector<int> c;
    t = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        t = t * 10 + a[i];
        c.push_back(t / b);
        t = t % b;
    }

    reverse(c.begin(), c.end());

    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}

int main()
{
    string A, B;
    int m, n;

    int type = 4;

    if (type == 1)
    {
        cin >> A >> B;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            a.push_back(A[i] - '0');
        }
        for (int i = B.size() - 1; i >= 0; i--)
        {
            b.push_back(B[i] - '0');
        }

        vector<int> c = add(a, b);
        reverse(c.begin(), c.end());
        for (int i = 0; i < c.size(); i++)
            cout << c[i];
        cout << endl;
    }
    else if (type == 2)
    {
        cin >> A >> B;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            a.push_back(A[i] - '0');
        }
        for (int i = B.size() - 1; i >= 0; i--)
        {
            b.push_back(B[i] - '0');
        }

        vector<int> c = sub(a, b);
        bool ispos = checkIsPos(a, b);
        if (ispos == false)
            cout << "-";
        reverse(c.begin(), c.end());
        for (int i = 0; i < c.size(); i++)
            cout << c[i];
        cout << endl;
    }
    else if (type == 3)
    {
        cin >> A >> m;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            a.push_back(A[i] - '0');
        }

        vector<int> c = mul(a, m);
        reverse(c.begin(), c.end());
        for (int i = 0; i < c.size(); i++)
            cout << c[i];
        cout << endl;
    }
    else if (type == 4)
    {
        cin >> A >> m;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            a.push_back(A[i] - '0');
        }
        int t = 0;
        vector<int> c = div(a, m, t);
        for (int i = c.size() - 1; i >= 0; i--)
            cout << c[i];
        cout << endl;
        cout << t << endl;
    }

    return 0;
}