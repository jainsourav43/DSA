#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	   ll n,m;ll max=0;
	   cin>>n>>m;
	   ll c[n+1],i,j,k;
	   for(i=1;i<=n;i++)
	   {
	   	cin>>c[i];
	   	max=max+c[i];
	   }
	   bool v[m+1][n+1]={false},v1[m+1][n+1]={false};
	   ll p[m+1],q[m+1],cost[m+1]={0};
	   for(i=1;i<=m;i++)
	   {
	   	cin>>p[i]>>q[i];ll a[i][q[i]+1];
	   	for(j=1;j<=q[i];j++)
	   	{
	   		cin>>a[i][j];
	   		v[i][a[i][j]]=true;
		}
		for(k=1;k<=n;k++)
		{
			if(v[i][k]==false)
			{
				cost[i]=cost[i]+c[k];
			}
		}
		cost[i]=cost[i]+p[i];
	   }
	   cost1[m*m];
	   for(i=1;i<=m;i++)
	   {
	   	  for(j=1;j<=m;j++)
	   	  {
	   	  	for()
	   	  	if(v[i][j])
		  }
	   }
	   ll min=10000000000000;
	   for(i=1;i<=n;i++)
	   {
	   	if(min>cost[i])
	   	{
	   		min=cost[i];
		}
	   }
	   if(min<max)
	   cout<<min<<endl;
	   else
	   {
	   	cout<<max<<endl;
	   }
	}
}
