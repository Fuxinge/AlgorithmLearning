#include <iostream>

using namespace std;

const int N = 100010; // 字符串总长度

// cnt以当前节点为结尾的字符串有多少个，idx当前的索引
int son[N][26], cnt[N], idx; // 下标为0的点既是根节点，也是空节点

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        // 如果p不存在u这个儿子，创建
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }

    cnt[p]++; // 以当前点结尾的数++
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }

    return cnt[p];
}

char str[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char op[2];
        cin >> op >> str;
        if (op[0] == 'I')
        {
            insert(str);
        }
        else
            cout << query(str) << endl;
    }
    return 0;
}