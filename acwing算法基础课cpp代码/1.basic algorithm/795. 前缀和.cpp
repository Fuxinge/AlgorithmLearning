#include<iostream>

#include<vector>

using namespace std;

int a[100010],b[100010];

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 0;i<n;i++) 
        cin>>a[i];
    b[0] =a[0];
    for(int i = 1;i<n;i++)
    {
        b[i] = a[i] + b[i - 1];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        if(l == 1) cout<<b[r-1]<<endl;
        else 
            cout<<b[r-1]-b[l-2]<<endl;
    }
    return 0;
}