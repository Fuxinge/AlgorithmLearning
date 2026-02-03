#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n ,a[100010],tmp[100010];

long long calReverse(int a[],int l,int r)
{
    if(l >= r) return 0;
    int mid = l + (r - l >> 1);
    long long ans = 0;
    ans += calReverse(a,l,mid);
    ans += calReverse(a,mid+1,r);

    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) tmp[k++] = a[i++];//要写等于，等于的时候不构成逆序对
        else
        {
            tmp[k++] = a[j++];
            ans += mid - i + 1;
        }
    }

    while(i<=mid) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];

    for(i = l ,j = 0;i<=r;i++,j++)
    {
        a[i] = tmp[j];
    }

    return ans;
}

int main()
{
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<calReverse(a,0,n-1)<<endl;
    return 0;
}
