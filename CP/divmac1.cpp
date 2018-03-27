#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define vi vector<int>
#define pb push_back
 
vector<bool> p(1000001,true);
vi lpd(1000001,-1);
void lpd_generator()
{
    p[1]=false;
    lpd[1]=1;
    for(int i=2;i<=1000000;i+=2) {p[i]=false;lpd[i]=2;}
    for(int i=3;i<=1000;i+=2) if(p[i])
    {
        lpd[i]=i;
        for(int j=i*i;j<=1000000;j+=(i<<1)) {p[j]=false;if(lpd[j]==-1) lpd[j]=i;}
    }
    for(int i=1001;i<=1000000;i++) if(lpd[i]==-1) lpd[i]=i;
}
 
void build(vi &t,vi &a,int s,int e,int n)
{
    if(s==e)
    {
        t[n]=lpd[a[s]];
        return;
    }
    int mid=(s+e)/2;
    build(t,a,s,mid,2*n+1);
    build(t,a,mid+1,e,2*n+2);
    t[n]=max(t[2*n+1],t[2*n+2]);
}
 
int query(vi &t,int l,int r,int s,int e,int n)
{
    if(s>e||s>r||e<l) return -1;
    if(l<=s&&r>=e) return t[n];
    int mid=(s+e)/2;
    return max(query(t,l,r,s,mid,2*n+1),query(t,l,r,mid+1,e,2*n+2));
}
 
void update(vi &a,vi &t,int l,int r,int s,int e,int n)
{
    if(s>e||s>r||e<l) return;
    if(l<=s&&r>=e&&t[n]==1) return; 
    if(s==e)
    {
        a[s]=a[s]/t[n];
        t[n]=lpd[a[s]];
        return;
    }
    int mid=(s+e)/2;
    update(a,t,l,r,s,mid,2*n+1);
    update(a,t,l,r,mid+1,e,2*n+2);
    t[n]=max(t[2*n+1],t[2*n+2]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    lpd_generator();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,m,type,l,r;
        scanf("%d %d",&n, &m);
        vi a(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int size=2*pow(2,ceil(log2(n)))-1;
        vi t(size,-1);
        build(t,a,0,n-1,0);
        while(m--)
        {
            scanf("%d %d %d",&type,&l,&r);
            if(type) 
            {
                printf("%d ",query(t,l-1,r-1,0,n-1,0));
            }
            else
            {
                update(a,t,l-1,r-1,0,n-1,0);
            }
        }
        printf("\n");
    }
}
