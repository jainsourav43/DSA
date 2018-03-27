#include<iostream>
#include<bits/stdc++.h>
#define ll long  long
ll count1=0,n,k;
using namespace std;
ll c;
void prod(ll a[],ll i,ll j,ll in,ll p)
{
	//ll p=a[i];
	ll j1,j2;
	if(in<n)
	{
	for(j1=0;j1<j;j1++)
	{
		p=p*a[in];
		if(j1==j-1&&c==j+1)
		{
			cout<<"j= "<<j<<endl;
			cout<<"p ="<<p<<endl;
			if(p<=k)
			{
				count1++;
			}
		}
		//swap(a[j1],a[j1+1]);
		if(j==1)
		prod(a,i,j,in+1,a[i]);
		else
		{
		prod(a,i,j,in+1,p,++c);
		}
		p/=a[in];
		--c;
		
		//swap(a[i],a[j+1]);
	}
	}
}
void check(ll a[],ll i,ll j,ll k2,ll count2)
{
//	cout<<"enter\n";
	 ll p=a[i],k1=1;
	 ll loc=0;
	cout<<"k2,i = "<<k2<<"  "<<i <<endl;
	if(k2<n)
	{
//		cout<<"inside\n";
		cout<<" j =  "<<j<<endl;
		while(k1<=j&&k2<n)
		{
			p=p*a[k2];
			cout<<"p in loop =  "<<p<<endl;
			loc++;
			k2++;
			k1++;
			check(a,i,j,k2,count2);
		}
		
			cout<<"p = "<<p<<endl;
			if(p<=k&&loc==count2)
			{
				count1++;
			}
	}	

}
int main()
{
	cin>>n>>k;
	ll a[n],i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]<=k)
		{
			count1++;
		}
	}
	ll count2=1;
	
	for(i=0;i<n;i++)
	{
		//count2=1;
		for(j=1;j<n-i;j++)
		{
			c=j+1;
			//check(a,i,j,i+1,count2);
			//count2++;
			prod(a,i,j,i+1,a[i]);
		}
	}
	cout<<count1<<endl;
}
