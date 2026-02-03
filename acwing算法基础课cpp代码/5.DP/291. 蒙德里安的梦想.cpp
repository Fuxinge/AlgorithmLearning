#include <bits/stdc++.h>
using namespace std;

const int N = 12, M = 1 << N;

long long f[N][M], n, m, st[M]; // 前i-1列已经摆好，且从第i-1列伸出到第i列的状态为j的所有方案数
vector<int> state[M];

int main()
{
    while (cin >> n >> m, m || n) // 读入棋盘尺寸，n行m列；m||n保证读到0 0时结束
    {
        memset(f, 0, sizeof f); // 清空DP数组，防止上一组数据干扰

        /* ---------- 第1步：检查单行状态合法性 ---------- */
        for (int i = 0; i < 1 << n; i++) // 枚举所有2^n种“单行轮廓”状态
        {
            int cnt = 0;          // 连续空位（0）计数器
            bool is_valid = true; // 是否合法

            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1) // 当前位是1（放砖/有插头）
                {
                    if (cnt % 2) // 前面连续0的个数是奇数→无法横向配对
                    {
                        is_valid = false;
                        break;
                    }
                    cnt = 0; // 清空连续0计数
                }
                else
                    cnt++; // 遇到0，连续空位+1
            }
            if (cnt & 1)
                is_valid = false; // 尾部剩余奇数空位→非法
            st[i] = is_valid;     // 记录本行状态是否合法
        }

        /* ---------- 第2步：预处理兼容状态对 ---------- */
        for (int i = 0; i < 1 << n; i++)
        {
            state[i].clear(); // 清空上一组残留
            for (int j = 0; j < 1 << n; j++)
            {
                if ((i & j) == 0 && st[i | j]) // i与j无重叠且合并后单行合法
                {
                    state[i].push_back(j); // j可作为“下一行”伸出状态
                }
            }
        }

        /* ---------- 第3步：轮廓线DP转移 ---------- */
        memset(f, 0, sizeof f); // 再次清空DP数组
        f[0][0] = 1;            // 第0列之前无伸出，方案数为1

        for (int i = 1; i <= m; i++) // 逐列推进
        {
            for (int j = 0; j < 1 << n; j++) // 当前列的伸出状态j
            {
                for (auto k : state[j]) // 所有与j兼容的“上一列”状态k
                {
                    f[i][j] += f[i - 1][k]; // 累加方案数
                }
            }
        }
        cout << f[m][0] << endl; // 前m列完成且伸出状态为0（无伸出）的总方案
    }

    return 0;
}