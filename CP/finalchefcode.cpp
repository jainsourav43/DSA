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
	}
	for(;i<n;i++)
	{
		
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
	ll count2=1,k1,k2,k3;
	ll p=1;
	for(i=0;i<n;i++)
	{
		cout<<"level1\n";
		for(j=1;j<n-i;j++)
		{cout<<"level2\n";
				p=a[i];
			int l=i+1;
			for(k1=0;k1<j;k1++)
			{cout<<"level3\n";
				p=p*a[l];
				l++;
					
			}
			if(p<=k)
			{
				cout<<"p = "<<p<<endl;
				count1++;
			}
			if(j<n-1)
			{
			for(k2=i+j;k2>i;k2--)
			{
				p=p/a[k2];
				cout<<"level4\n";
				for(k3=i+j+1;k3<n;k3++)
				{	
					cout<<"level5\n";
					p=p*a[k3];
					if(p<=k)
					{
					cout<<"p= "<<p<<endl;
						count1++;
					}
					p=p/a[k3];
				}
				p=p*a[k2];
			}
			}
		}
	}
	cout<<count1<<endl;
}
