#include<iostream>
#include<stdio.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	//cin>>t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
	//	cin>>n;
		scanf("%lld",&n);
		ll p[n+1],i,v[n],u[n],j;
		int **flag;
		flag=new int*[n+1];
		flag[0]=new int[n+1];
		for(i=1;i<=n;i++)
		{
			flag[i]=new int[n+1];
		}
		for(i=1;i<=n;i++)
		{
			//cin>>p[i];
			scanf("%lld",&p[i]);
		}
		for(i=1;i<n;i++)
		{
			//cin>>v[i]>>u[i];
			scanf("%lld %lld",&v[i],&u[i]);
			flag[v[i]][u[i]]=1;
			flag[u[i]][v[i]]=1;
		}
		ll max=0,in=0;
		int check;
		for(i=1;i<=n;i++)
		{
			check=0;
			max=0;
			for(j=1;j<=n;j++)
			{
				if(flag[i][j]!=1&&flag[j][i]!=1&&i!=j)
				{
					if(max<p[j])
					{
						max=p[j];
						in=j;
						check=1;
					}
				}
			}
			if(check==0)
			{
				cout<<0<<" ";
			}	
		    else
		    {
		    	cout<<in<<" ";
		    } 
		}
		cout<<endl;
	}
}  
