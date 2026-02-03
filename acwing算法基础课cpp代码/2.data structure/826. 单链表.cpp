#include <iostream>

using namespace std;

const int N = 100010;

int e[N], nex[N];

int m, idx, head;

void init()
{
    head = -1;
    idx = 0;
}

void addtohead(int x) // 插入到头结点
{
    e[idx] = x;
    nex[idx] = head;
    head = idx;
    idx++;
}

void insert(int x, int k) // 插入到第k个后面；
{
    e[idx] = x;
    nex[idx] = nex[k];

    nex[k] = idx;
    idx++;
    // e[idx] = x, nex[idx] = nex[k], nex[k] = idx++;
}

void del(int k) // 删除第k个数后面的一个数
{
    nex[k] = nex[nex[k]];
}

void printList()
{
    for (int i = head; i != -1; i = nex[i])
    {
        cout << e[i] << " ";
    }
    cout << endl;
}

int main()
{
    scanf("%d", &m);
    init();
    while (m--)
    {
        int x, k;
        char op;
        scanf(" %c", &op);
        switch (op)
        {
        case 'H':
            scanf("%d", &x);
            addtohead(x);
            break;
        case 'D':
            scanf("%d", &k);
            if (k == 0)
                head = nex[head];
            else
                del(k - 1);
            break;
        default:
            scanf("%d%d", &k, &x);
            insert(x, k - 1);
            break;
        }
    }
    printList();
    return 0;
}