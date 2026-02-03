#include<iostream>

#include<vector>

using namespace std;

int a[100010],b[100010];

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n ;i++) 
        cin>>a[i];
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1];
    while(m--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        b[l] += x;
        b[r+1] -= x;
    }
    for(int i = 1;i<=n;i++)
    {
        a[i] = a[i-1] + b[i];
        cout<<a[i]<<" ";
    }
    
    return 0;
}