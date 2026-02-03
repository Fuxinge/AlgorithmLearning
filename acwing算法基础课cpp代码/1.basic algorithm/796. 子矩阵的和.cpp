#include<iostream>

#include<vector>

using namespace std;

int a[1010][1010],b[1010][1010];

int main()
{
    int n, m,q;
    cin>>n>>m>>q;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    // b[1][1] = a[1][1];

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j]; 
            // cout<<b[i][j]<<" ";
        }
        // cout<<endl;
    }

    while(q--)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        cout<<b[x2][y2]+b[x1-1][y1-1]-b[x2][y1-1]-b[x1-1][y2]<<endl;
    }

    return 0;
}