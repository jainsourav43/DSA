#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll pow1[200],pow2[200],count2=0,count3=0;
void pow(ll x,ll y,ll a1,ll b1,ll r)
{
	pow1[0]=1;pow2[0]=1;ll i;
	count2=1,count3=1;
	for(i=1;i<=a1;i++)
	{
		
		if(pow1[i-1]<=1e18/x&&pow1[i-1]<=r)\
		{
		count2++;
		pow1[i]=pow1[i-1]*x;
		}
		else
		break;
	}
//	cout<<"HII\n";
//	count2=i-1;
	for(i=1;i<=b1;i++)
	{
		if(pow2[i-1]<=1e18/y&&pow2[i-1]<=r)
		{
		count3++;
		pow2[i]=pow2[i-1]*y;
		}
		else
		break;
	}
//	int jl;


}
int main()
{
	ll x,y,l,r;
	cin>>x>>y>>l>>r;
	ll a1,b1;
	a1=log2(r)/log2(x);
	b1=log2(r)/log2(y);
//	cout<<"a1,b1= "<<a1<<" "<<b1<<endl;
	a1=a1+1;
	b1=b1+1;
	pow(x,y,a1,b1,r);
	ll i,j;
	//map<ll,bool> year;
	vector<ll> v;
	for(i=0;i<count2;i++)
	{
		for(j=0;j<count3;j++)
		{
		//	cout<<pow1[i]+pow2[j]<<endl;
			if(pow1[i]+pow2[j]<=r&&pow1[i]+pow2[j]>=l)
			{
				v.push_back(pow1[i]+pow2[j]);
			}
			if(pow2[j]>r)
			break;
		}
		if(pow1[i]>r)
		break;
	}
	
	ll ans=0;
	sort(v.begin(),v.end());
	int len=v.size();
	if(len==0)
	{
		cout<<r-l+1<<endl;
	}
	else{
	
	ans=v[0]-l;
	for(i=0;i<len-1;i++)
	{
		ans=max(ans,v[i+1]-v[i]-1);
	}
	ans=max(ans,r-v[len-1]);
	cout<<ans<<endl;
}
}
