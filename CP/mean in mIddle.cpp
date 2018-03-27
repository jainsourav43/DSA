#include<algorithm>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[40];
ll x[40][70000],y[40][70000]; 
void prime(ll a[],ll n)
{
	set<ll > se;
	ll i,j,check=0;
	for(i=0;i<n;i++)
	{
		ll temp=a[i];
		check=0;
		ll sum=1;
		se.clear();
		while(temp%2==0)
		{
			check=1;
			temp=temp/2;
		}
		if(check)
		{
			se.insert(2);
		}
		int sq=sqrt(temp);
		for(j=3;j<=sq;j+=2)
		{
			if(temp%j==0)
			{
				se.insert(j);
				temp/=j;
			}
		}
		if(temp>2)
		{
			se.insert(temp);
		}
		set<ll> :: iterator it=se.begin();
	//	cout<<"for = "<<a[i]<<endl;
		for(;it!=se.end();it++)
		{
	//	cout<<" it= "<<*it<<endl;
		sum=sum*(*it);
		}
		p[i]=sum;
    //	cout<<p[i]<<endl;
	}
 }
ll n,k,a,b,size1[40],size2[40],ans1=0,ans2=0;
 void recur(ll pos,ll sum,ll count1)
{
	ll i;
	sum=sum+p[pos];
	//cout<<"sum,pos,n ="<<sum<<" "<<pos<<"  "<<"  "<<n<<endl;
	if(count1<=k&&sum<=b)
	{
		if(sum>=a)
		ans2++;
		x[count1][size1[count1]++]=sum;
	 	for(i=pos+1;i<n/2;i++)
	 	{
	 		//sum=sum+p[i];
	 	//	count1++;
	 		recur(i,sum,count1+1);
	 	
	 		//	count1--;
		}
	       //	count1--;
			sum=sum-p[pos];
	}
} 
 void recur2(ll pos,ll sum,ll count1)
{
	ll i;
	sum=sum+p[pos];
	
	if(count1<=k&&sum<=b)
	{
		if(sum>=a)
		ans1++;
		y[count1][size2[count1]++]=sum;
	 	for(i=pos+1;i<n;i++)
	 	{
	 	//	sum=sum+p[i];
	    //	count1++;
	 		recur2(i,sum,count1+1);
	 	
	 		//count1--;
		}
		//	count1--;
			sum=sum-p[pos];
	}
}
int main()
{

	cin>>n>>k>>a>>b;
	ll ar[n],i,j;
	for(i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	prime(ar,n);
	sort(p,p+n);
	for(i=0;i<n/2;i++)
	{
		recur(i,0,1);
	}
	for(i=n/2;i<n;i++)
	{
		recur2(i,0,1);
	}
//	cout<<"x= "<<endl;
	for(i=1;i<=k;i++)
	{
		
		for(j=0;j<size1[i];j++)
		cout<<x[i][j]<<" ";cout<<endl;
	}
//	cout<<"y= "<<endl;
//		for(j=1;j<=k;j++){
//		
//	for(i=0;i<size2[j];i++)
//		cout<<y[j][i]<<"  ";cout<<endl;
//}
for(i=1;i<=k;i++)
sort(y[i],y[i]+size2[i]);
ll ans3=0,j1;
for(i=1;i<k;i++)
{
	for(j1=1;j1<=k-i;j1++)
	for(j=0;j<size1[i];j++)
	{
			ll index1=upper_bound(y[j1],y[j1]+size2[j1],b-x[i][j])-y[j1];
			ll index2=lower_bound(y[j1],y[j1]+size2[j1],a-x[i][j])-y[j1];
			//cout<<" i1,i2 = "<<index1<<"  "<<index2<<endl;
			ans3=ans3+index1-index2;
	}
}

	cout<<ans3+ans1+ans2<<endl;
}
