#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;


int a[100010];
int tmp[100010];

void merged_sort(int a[],int l, int r)
{
    if(l>=r) return;
    int mid = (l+r) >>1;
    merged_sort(a,l,mid);
    merged_sort(a,mid+1,r);
    int k = 0,i = l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j]) tmp[k++] = a[i++];
        else tmp[k++]=a[j++];
    }
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];

    for (i = l, j = 0; i <= r; i ++, j ++ ) a[i] = tmp[j];
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }

    merged_sort(a,0,n-1);

    for(int i = 0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}