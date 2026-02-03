#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void quicksort(int a[],int l,int r )
{
    if(l>=r) return ;
    int i = l-1,j=r+1,x=a[(l+r)/2];

    while(i<j)
    {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }

    quicksort(a,l,j);
    quicksort(a,j+1,r);
}
int a[100010];
int main()
{
    int n ;
    cin>>n;
    
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }

    quicksort(a,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }


    return 0;
}
