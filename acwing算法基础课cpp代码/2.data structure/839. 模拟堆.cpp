#include <iostream>
#include <set>
#include <unordered_map>
#include <cstring>
#include <map>
using namespace std;

// //用multiset和map进行模拟
// multiset<int> p;
// unordered_map<int, int> f;

// int l = 1;

// int main()
// {
//     int n;
//     cin.tie(0);
//     cin >> n;
//     while (n--)
//     {
//         string s;
//         int k, x;
//         cin >> s;
//         if (s == "I")
//         {
//             cin >> x;
//             f[l++] = x;
//             p.insert(x);
//         }
//         else if (s == "DM")
//         {
//             p.erase(p.begin());
//         }
//         else if (s == "PM")
//         {
//             cout << *p.begin() << endl;
//         }
//         else if (s == "D")
//         {
//             cin >> k;
//             p.erase(p.find(f[k]));
//         }
//         else
//         {
//             cin >> k >> x;
//             p.erase(p.find(f[k]));
//             f[k] = x;
//             p.insert(f[k]);
//         }
//     }
//     return 0;
// }