#include <bits/stdc++.h>
using namespace std;

string str;
queue<string> q;

unordered_map<string, int> dis;

int bfs(string str)
{
    q.push(str);
    int dx[4] = {0, 0, 1, -1}, dy[4] = {-1, 1, 0, 0}; // 上下右左
    dis[str] = 0;
    string end = "12345678x";

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int distance = dis[t];
        if (t == end)
        {
            return distance;
        }
        int k = t.find("x");
        int x = k / 3, y = k % 3;

        for (int i = 0; i < 4; i++)
        {
            // 转移后的位置
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[3 * a + b]);
                // 如果当前的状态没有保存过
                if (dis.count(t) == 0)
                {
                    dis[t] = distance + 1;
                    q.push(t);
                }
                // 还原状态，为下一次循环做准备
                swap(t[k], t[3 * a + b]);
            }
        }
    }

    // 无法转换到目标状态，返回-1
    return -1;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        char s;
        cin >> s;
        str.push_back(s);
    }
    cout << bfs(str) << endl;
    return 0;
}