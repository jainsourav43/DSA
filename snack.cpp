#include<bits/stdc++.h>
#define ll long long 
#include<vector>
#include<stack>
bool v[501][501],v1[501][501];
ll n,m;
ll maximum(ll a,ll b)
{
	if(a>b)
	return a;
	return b;
}
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
			ll hour=0;

		cin>>n>>m;
		ll a[n+1][m+1],r[n+1],c[m+1],count1=0,count2=0;
		ll i,j,k,max=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
				v[i][j]=false;
				if(a[i][j]>max)
				{
					max=a[i][j];
				}
			}
		}
//		for(i=0;i<n;i++)
//		{
//			for(j=0;j<m;j++)
//			{
//				if(a[i][j]==max)
//				{
//					count1++;
//					v[i][j]=true;
//				}
//			}
//		}
			for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			v1[i][j]=true;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]==max)
				{
				       //v1[i-1][j]=false;
						r[count1++]=i;
						c[count2++]=j;
				}
			}
		}
		set<ll> se1;
		set<ll> se2;
		for(i=0;i<count1;i++)
		{
			se1.insert(r[i]);
		}
		for(i=0;i<count2;i++)
		{
			se2.insert(c[i]);
		}
		set<ll> :: iterator it1,it2;
		////it1=se1.begin();
		//it1++;
		count1=0,count2=0;
		for(it1=se1.begin();it1!=se1.end();it1++)
		{
			r[count1++]=*it1;
			cout<<"it1 ="<<*it1<<endl;
		}
		for(it2=se2.begin();it2!=se2.end();it2++)
		{
			c[count2++]=*it2;
			cout<<"it2 ="<<*it2<<endl;
		}
		ll hour1=0,hour2=0;
		hour1=hour1+r[0]-0;
		for(i=1;i<count1;i++)
		{
		//	if((r[i]-r[i-1])%2==0)
			hour1=hour1+(r[i]-r[i-1])/2;
//			else
//			{
//				hour1=hour1+(r[i]-r[i-1])/2+1;
//			}
		}
		hour1=hour1+n-r[count1-1]-1;
		for(i=1;i<count2;i++)
		{
		//	if((c[i]-c[i-1])%2==0)
		//	{
				hour2=hour2+(c[i]-c[i-1])/2;
		//	}
		//	else
		//	{
		//		hour2=hour2+(c[i]-c[i-1])/2+1;
		//	}
		}
		hour2=hour2+c[0]-0;
		hour2=hour2+n-1-c[count2];
		cout<<maximum(hour1,hour2)<<endl;
	}
	
}
