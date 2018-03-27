#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
 
ll n,k;
ll count1=0,count2=0;
ll x[40000],y[40000];
bool check(ll p,ll a)
{
	if(p>a)
	{
			if(LONG_LONG_MAX/p>a)
			{
				return true;
			}
	}
	else
	{
			if(LONG_LONG_MAX/a>p)
			{
				return true;
			}
	}
	return false;

}
 int dig(ll n1)
 {
 	int ans=0;
 	while(n1)
 	{
 		n1/=10;
 		ans++;
	 }
	 //cout<<"ans= "<<ans<<endl;
	 return ans;
 }
void func(ll a[],ll i,ll p)
{
	if(dig(p)+dig(a[i])<=20&&check(p,a[i]))
	{
	
	  ll temp=p*a[i];
	 
	  if(temp>0)
	  {
	   p=p*a[i];
	// cout<<"p ="<<p<<endl;
	  if(p<=k&&p>0)
	  {
		x[count1++]=p; 
	  	for(ll j=i+1;j<n/2;j++)
	  	{
	  		if(p*a[j]>k||p*a[j]<0)break;
	  		func(a,j,p);
		}	  	
			p=p/a[i];
		}
	}
}
}
void func1(ll a[],ll i,ll p)
{
	if(dig(p)+dig(a[i])<=20&&check(p,a[i]))
	{

	
	ll temp=p*a[i];
	 //cout<<"come\n";
	  if(temp>0)
	  {//cout<<"go\n";
	  p=p*a[i];
	//cout<<"p ="<<p<<endl;
	  	if(p<=k&&p>0)
	  	{
		y[count2++]=p; 
	  	for(ll j=i+1;j<n;j++)
	  	{
	  		if(p*a[j]>k||p*a[j]<0) break;
	  		func1(a,j,p);
		}	  	
			p=p/a[i];
		}
	}
}

}
int main()
{
	
	cin>>n>>k;
	ll i,j,a[n],po=pow(2,n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n/2;i++)
	{
	if(k>=a[i])
	func(a,i,1);
	}
	for(i=n/2;i<n;i++)
	{
	if(k>=a[i])
	func1(a,i,1);
	}
	sort(x,x+count1);
//	for(i=0;i<count1;i++)
//	{
//		cout<<"x[i] = " <<x[i]<<endl;
//	}
		sort(y,y+count2);

//	for(i=0;i<count2;i++)
//	cout<<"y[i] = "<<y[i]<<endl;
	ll p;ll sum=0;
	for(i=0;i<count1;i++)
	{
		 p = upper_bound(y, y+count2, k/x[i]) - y;
		 //	p = upper_bound(y, y+p, k/x[i]) - y;
		 		//	 cout<<"spec p= "<<p<<endl;

		ll temp;
		//cout<<"y[p]= "<<y[p]<<endl;
		//cout<<"x[i] = "<<x[i]<<endl;
		if(check(y[p],x[i]))
		{
		temp=y[p]*x[i];
		 //cout<<"temp= "<<temp<<endl;
		 //cout<<"p = "<<p<<endl;
		 if(p==count2)
		 {
		 	sum=sum+p;
		 	
		 }
		 else
		 {
		 	
		 
		if(temp>=0)
		{
		if(temp>k)
		{
//				p = upper_bound(y, y+p, k/x[i]) - y;
//				cout<<"p1 = "<<p<<endl;
				p--;
		}
	//	cout<<"p= "<<p<<endl;
		if(p==count2)
		sum+=p;
		else
		{
			sum+=p+1;
		}
		}
		else
		{//cout<<"else\n";
			if(p>=1)
			{
				//p = lower_bound(y, y+count2, k/x[i]) - y;
				p--;
			//	cout<<"pin  ="<<p<<endl;
				temp=y[p]*x[i];
					if(temp>k)
					{
						p--;
					}
				//	cout<<"p= "<<p<<endl;
					if(p==count2)
					sum+=p;
					else
					{
						sum+=p+1;
					}
			}
		}
	}
	}
	else
	{
		if(p>=1)
		{
		
				p--;
			//	cout<<"pin  ="<<p<<endl
				temp=y[p]*x[i];
					if(temp>k)
					{
						p--;
					}
				//	cout<<"p= "<<p<<endl;
					if(p==count2)
					sum+=p;
					else
					{
						sum+=p+1;
					}
		}
	}
	}
	
	cout<<count1+count2+sum<<endl;
	
} 
