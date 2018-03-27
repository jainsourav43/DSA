#include<iostream>
#include<algorithm>
#include<vector>
#define ll  long long
using namespace std;
struct st
{
	ll index;
	ll val;
	bool enable=false;
};
struct check
{
	int val;
	int data;
	bool enable=false;
};
bool comp(const st &a,const st &b )
{
	return a.val>b.val;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,i,j,k;
		cin>>n;
		st p1[n];
		vector <st> p(n);
		typedef vector<check> che;
		typedef vector<che> act;
		act ram(n,che(n));
		for(i=0;i<n;i++)
		{
			cin>>p[i].val;
			p[i].index=i;
		//	che[i]
		}
		sort(p.begin(),p.end(),comp);
		ll v[n-1],u[n-1];
	
		for(i=0;i<n-1;i++)
		{
			cin>>v[i]>>u[i];
             ram[v[i]].push_back(u[i]);
             ram[u[i]].push_back(v[i]);
		}
		//cout<<"IGGG\n";

		for(i=0;i<n;i++)
		{
			
			
			for(k=0;k<n;k++)
			{
				if(p1[p1[k].index].enable==false)
				{
			cout<<p1[k].index+1<<endl;
					break;
				}
			}
			if(k==n)
			{
			cout<<0<<endl;
			}
			
		}
	}
}
