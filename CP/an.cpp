#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cost=0;
struct p
{
	ll index;
	ll price;
	
};
ll dp(ll pos,ll total,p pr[],ll k)
{
	if(total>0)
	{

	if(pos<k)
	{
		if(pr[pos].price!=-1)
		{
			int temp=total/pr[pos].index;
			cost=min(temp*pr[pos].price+dp(pos+1,total-temp,pr,k),dp(pos+1,total,pr,k));	
		}
		else
		{
			return INT_MAX;
		}
	}
	}
	else 
	{
		return cost;
	}
	
}
bool comp(p x,p y)
{
	return x.price<y.price;
}
void merge(p pr[],ll m,ll l,ll r)
{
	ll n1,n2,i=0,j=0,k=0;
	cout<<"m,l,h= "<<m<<" "<<l<<" "<<r<<endl;
	n1=m-l+1;
	n2=r-m;
	p lp[n1+1],rp[n2+1];
	for(i=0;i<n1;i++)
	{
		lp[i]=pr[i+l];
		cout<<"lp[i]= "<<lp[i].price<<endl;
	}cout<<"bye1\n";
	for(j=0;j<n2;j++)
	{
		
		rp[j]=pr[j+m+1];
		cout<<"rp[i]= "<<rp[j].price<<endl;
	}
	cout<<"bye2\n";
	i=0;j=0;k=l;
	while(i<n1&&j<n2)
	{
		if(lp[i].price<rp[j].price)
		{
			pr[k]=lp[i];
			i++;
			k++;
		}
		else 
		{
			pr[k]=rp[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		pr[k++]=lp[i++];
	}
	while(j<n2)
	{
		pr[k++]=rp[j++];
	}
	
	
}
void mergesort(p pr[],ll l,ll h)
{
	if(l<h)
	{
		ll	mid=l+(h-l)/2;
		mergesort(pr,l,mid);
		mergesort(pr,mid+1,h);
		merge(pr,mid,l,h);
	}
}
//void dp(ll p,ll k,ll pos,ll n)
//{
//	if(p[i]!=-1)
//	{
//		if()
//	}
//}
int main()
{
	ll c;
	cin>>c;
	while(c--)
	{
		ll n,k;
		cin>>n>>k;
		p pr[n+1];ll i,j;
		for(i=0;i<k;i++)
		{
			cin>>pr[i].price;
			pr[i].index=i+1;
		}
	//	mergesort(pr,0,k-1);
//	
sort(pr,pr+k,comp);
//	//for(i=0;i<k;i++) cout<<pr[i].price<<" "  ;cout<<endl;
//	for(i=0;i<n;i++)
//	{
//		if(pr[i].price==-1)
//		{
//			continue;
//		}
//		
//		else
//		{
//			if(k%pr[i].index==0)
//			{
//				ans=pr[i].price*k;
//			}
//			else if()
//			{
//				
//			}
//		}
//	}
//	
//	
cost=dp(0,k,pr,k);
//cout<<cost<<endl;
if(cost==INT_MAX)
{
	cout<<-1<<endl;
}
else
{
	cout<<cost<<endl;
}
		
	}
}
