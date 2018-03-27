#include<iostream>
using namespace std;
#define ll long long 
#include<vector>
#include<bits/stdc++.h>
//vector<pair<ll,pair<ll,ll> > >v1; 
vector<ll> v[100001];
int main()
{
	ll n;
	cin>>n;
	ll i,j,p[n+1],a[n+1],ans=0,cost[n+1]
	;
	for(i=2;i<=n;i++)
	{
		cin>>p[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ve;
	v[1].push_back(-1);
	cost[1]=a[1];
	for(i=2;i<=n;i++)
	{
		v[i].push_back(p[i]);
		//cost[i]=*min_element(a+1,a+i+1);
	}
	ll count=0,path[n+1];
	cout<<a[1]<<endl;
	for(i=2;i<=n;i++)
	{
		ve=i;
		ans=0;
		count=0;
		while(ve!=-1)
		{
	//		cout<<"ve= "<<ve<<"  ";
			//	ans=ans+cost[ve];
				path[count]=ve;
					cost[count]=a[ve];
			     ve=v[ve][0];
		count++;
		}
	//	cout<<"end\n";
	//	sort(path,path+count);
		for(j=0;j<count;j++)
		{
			ans=ans+*min_element(cost,cost+j+1);
		}
		cout<<ans<<endl;
	}
	
	
	
	
	
}
