#include<bits/stdc++.h>
#define ll long long 
using namespace std;

map<int,int> ma;
int main()
{
	ll n,qu;
	
	cin>>n>>qu;
	ll a[n],q[qu],i,p;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<qu;i++)
	{
		cin>>q[i];
	}
	for(i=0;i<n;i++)
	{
		ma[a[i]]++;
		p=a[i];
		//ans[count1++]=a[i];
		for(int j=i+1;j<n;j++)
		{
			ma[__gcd(p,a[j])]++;
			
			if(__gcd(p,a[j])==1)
			{
				ma[1]=ma[1]+n-j-i-1;
				break;
			}
			else
			{
				p=p*a[j];
			}
		}
	}
	typeof(ma.begin()) it=ma.begin();
	
//	for(; it!=ma.end();it++) 
//	{
//		sum[i]=sum[i-1]+1;
//	}
	int count1=0;
//	cout<<"i1,i2  "<<it->first<<" "<<it->second<<"  ";cout<<endl;
	for(i=0;i<qu;i++)
	{
		count1=0;
		for(it=ma.begin();it!=ma.end();it++)
		{
			if(count1+it->second>=q[i])
			{
				cout<<it->first<<endl;
				break;
			}
			count1+=it->second;
		}
	}
}
