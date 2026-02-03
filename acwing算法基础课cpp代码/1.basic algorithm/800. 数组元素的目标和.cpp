#include<iostream>
using namespace std;


int a[100010],b[100010];


int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j = 0;j<m;j++)
    {
        cin>>b[j];
    }
    
    for(int i = 0,j=m-1;i<n;i++)
    {
        while(j>=0&&a[i]+b[j]>x)
        {
            j--;
            
        }
        if(a[i]+b[j]==x)
        {
            cout<<i<<" "<<j<<endl;
            return 0;
        }
    }
    return 0;
}