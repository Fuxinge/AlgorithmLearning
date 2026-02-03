#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003; // 取质数，并且尽量离2的n次方远，可以有最少的冲突

// 拉链法
int e[N], ne[N], h[N];
int idx;

// 向哈希表中插入一个数
void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

// 在哈希表中查询某个数是否存在
bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;

    return false;
}

int main()
{
    cin.tie(0);
    memset(h, -1, sizeof(h));
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int x;
        if (s == "I")
        {
            cin >> x;
            insert(x);
        }
        else
        {
            cin >> x;
            if (find(x))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}

/*
//开放寻址法
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003,null = 0x3f3f3f3f; //取质数，且开放寻址法需要选定数据范围的2-3倍大小，不能直接*2，要选质数

int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while(h[k]!=null&&h[k]!=x)
    {
        k++;
        if(k==N) k=0;
    }
    return k;
}

int main()
{
    cin.tie(0);
    memset(h, 0x3f, sizeof(h));
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        int x;
        cin >> s>>x;

        int k = find(x);
        if (s == "I")
        {
            h[k] = x;
        }
        else
        {
            if(h[k]!=null) puts("Yes");
            else puts("No");
        }
    }

    return 0;
} */