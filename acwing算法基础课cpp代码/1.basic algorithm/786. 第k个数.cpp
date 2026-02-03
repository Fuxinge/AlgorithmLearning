#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void quickselect(int a[],int l,int r ,int k )
{
    if(l>=r) return ;
    int i = l-1,j=r+1,x=a[l + ( r - l ) / 2];

    while(i<j)
    {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }

    if(k<=j)
        quickselect(a,l,j,k);
    else if(k>j)
        quickselect(a,j+1,r,k);
}
int a[100010];
int main()
{
    int n ,k;
    cin>>n>>k;
    k--;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }

    quickselect(a,0,n-1,k);

    cout<<a[k];


    return 0;
}
