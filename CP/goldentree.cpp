#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
#define mod 100000007
#define mod2 100000006
#define MS 105
using namespace std;
int A[MS][MS], R[MS][MS], tax[MS],tpow[MS][MS],tmul[MS][MS],sz;


void matmul(int ab[MS][MS],int a[MS][MS],int b[MS][MS])
{
	int i,j,j1;
	for(i=0;i<sz;i++) for(j=0;j<sz;j++)
	{
		ll x=0;
		for(j1=0;j1<sz;j1++)
		{
		x = x + (1ll*a[i][j1]*b[j1][j]);
		if(x>=mod2)
		{
			x%=mod2;
		}
				tmul[i][j] = x;

		}
	}
	for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) ab[i][j] = tmul[i][j];
	
	
}
void matpow(int R[MS][MS] ,int A[MS][MS],int p,int s)
{
	 sz=s ;int i,j;
	for(int i=0;i<sz;i++) for(int j=0;j<sz;j++) 
		R[i][j]=(i==j), tpow[i][j] = A[i][j];
		
		while(p)
		{
			if(p&1)
			{
				matmul(R,R,tpow);
				
			}
			 if((p>>=1))
			{
				matmul(tpow,tpow,tpow);
			}
		}
}

ll modpow1(ll a, ll b)
{
	ll r=1;
	while(b)
	{
		if(b&1)
		{
			r=r*a;
		}
		if(b>>=1)
		{
			a=a*a;
		}
	}
	return r;
}

int modpow(ll a,ll P)
{
	ll r = 1;
	for(;P>0;P>>=1)
	{
		if(P&1) r = (r*a)%mod;
		a = (a*a)%mod;
	}
	return r;
}
int main()
{
	ll t,ans=1;
	cin>>t;
	while(t--)
	{
		ll in,s1,s2,n,k,i,j;
		ans=1;
		cin>>in>>s1>>s2>>k>>n;
		tax[0]=in;
		for(i=1;i<=s1;i++)
		{
			tax[i]=tax[i-1]+1;
		}
		for(i=s1+1;i<=+s1+s2;i++)
		{
			tax[i]=2*tax[i-1]%mod;
		}
		if(n<=s1+s2+1)
		{
			cout<<tax[n-1]<<endl;
		}
		else
		{
			--n;
			memset(A,0,sizeof A);
			for(i=0;i<k;i++)
			{
				A[i+1][i]=A[0][i]=1;
			}
			matpow(R,A,n-(s1+s2),k);
		//	cout<<"printting R =\n";
		//	for(i=0;i<k;i++)
		//	{
		//		for(j=0;j<k;j++)
		//		{
		//			cout<<R[i][j]<<" ";
		//		}
		//		cout<<endl;
		//	}
			
			for(i=0;i<k;i++)
			{
		//	ll	k1=modpow(tax[(s1+s2)-i],R[0][i]);
		//	cout<<"k1 = "<<k1<<endl;
		//	cout<<"tax = "<<tax[(s1+s2)-i]<<endl;
				ans=ans*(modpow(tax[(s1+s2)-i],R[0][i]))%mod;
			}
			cout<<ans<<endl;
			
		}
		
		
		
	}
}
