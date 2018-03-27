#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,c,z,mx;
        scanf("%d",&n);
        int a[n],b[n],ans[n];
        int c1[n-1],c2[n-1];
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
 
        for(i=0;i<(n-1);i++)
        {
            scanf("%d %d",&c1[i],&c2[i]);
        }
 
        for(i=0;i<n;i++)
            ans[i]=0;
 
 
        for(c=1;c<=n;c++)
        {
        for(i=0;i<n;i++)
            b[i]=a[i];
 
 
        for(i=0;i<(n-1);i++)
        {
            if(c1[i]==c)
                b[c2[i]-1]=0;
            if(c2[i]==c)
                b[c1[i]-1]=0;
        }
        b[c-1]=0;
        mx=0;
        for(i=0;i<n;i++)
        {
            if(b[i]>b[mx])
                mx=i;
        }
        ans[c]=mx+1;
        }
 
        for(i=1;i<=n;i++)
            printf("%d ",ans[i]);
        printf("\n");
 
 
    }
    return 0;
}
