#include<iostream>
#define ll long long
#include<vector>
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll p[n+1],i,v[n],u[n],j;
		vector<vector<ll>> flag;
		for(i=1;i<=n;i++)
		{
			cin>>p[i];
		}
		for(i=1;i<n;i++)
		{
			cin>>v[i]>>u[i];
			flag[v[i]].push_back(u[i]);
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
