// #include <iostream>
// #include <string>
// using namespace std;

// const int N = 100010, M = 1000010;

// int n, m;
// int ne[N];
// char s[M], p[N];

// void get_next()
// {
//     for (int i = 2, j = 0; i <= n; i++)
//     {
//         while (j && p[i] != p[j + 1])
//             j = ne[j];
//         if (p[i] == p[j + 1])
//             j++;
//         ne[i] = j;
//     }
// }

// void pipei()
// {
//     for (int i = 1, j = 0; i <= m; i++)
//     {
//         while (j && s[i] != p[j + 1])
//             j = ne[j];
//         if (s[i] == p[j + 1])
//             j++;
//         if (j == n)
//         {
//             cout << i - j << " ";
//             j = ne[j];
//         }
//     }
// }

// int main()
// {
//     cin >> n >> p + 1 >> m >> s + 1;

//     get_next();

//     pipei();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, m;
string s, p;

int ne[N];

void get_next(string s)
{
    int n = s.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && s[i] != s[j])
        {
            j = ne[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }

        ne[i] = j;
    }
}

void kmp(string s, string p)
{
    int n = s.size(), m = p.size();
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j && s[i] != p[j])
        {
            j = ne[j - 1];
        }
        if (s[i] == p[j])
            j++;
        if (j == m)
        {
            cout << i - j + 1 << " ";
            j = ne[j - 1];
        }
    }
}

int main()
{
    cin >> n >> p >> m >> s;
    get_next(p);

    kmp(s, p);

    return 0;
}