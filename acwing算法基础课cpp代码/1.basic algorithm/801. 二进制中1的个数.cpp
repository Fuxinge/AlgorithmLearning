#include<iostream>
using namespace std;

int n ,m;

int lowbit(int x)//9
{
    return x&-x;//1001,0111
}

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>m;
        int count = 0;
        while(m)
        {
            int p = lowbit(m);
            if(p!=0) count++;
            m-=p;
        }
        cout<<count<<" ";

    }
    return 0;
}