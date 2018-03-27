//#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#define ll long long
//using namespace std;
ll maxe(ll a,ll b)
{
    if(a>b)
    {
        return a;
    }
    else
    return b;
}
ll prime(ll n)
{
    ll i;

    if(n==2)
        return 1;

    if (n%2==0)
        return 0;

    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;

    return 1;
}
ll least(ll n)
{
    ll i;
	if(n==1)
	return 1;
	else if(n%2==0)
	{
		return 2;
	}
	else if(prime(n))
	{
		return n;
	}
	else 
	{
	for( i=3;i<=sqrt(n);i+=2)
	{
		if(n%i==0)
		{
			return i;
		}
	}
	return 1;
}
}

ll least1(ll n)
{
	if (n==0 || n==1) return n;
    if (n%2==0) return 2;
    if (n%3==0) return 3;
    if (n%5==0) return 5;

    for (ll i = 7; (i*i) <= n; i += 30 ) {
        if ( n % i == 0 ) {
            return i;
        }
        if ( n % ( i+4 ) == 0) {
            return i+4;
        }
        if ( n % ( i+6 ) == 0) {
            return i+6;
        }
        if ( n % ( i+10 ) == 0) {
            return i+10;
        }
        if ( n % ( i+12 ) == 0) {
            return i+12;
        }
        if ( n % ( i+16 ) == 0) {
            return i+16;
        }
        if ( n % ( i+22 ) == 0) {
            return i+22;
        }
        if ( n % ( i+24 ) == 0) {
            return i+24;
        }
    }
    return n;
}

int main()
{
	ll t;
	//cin>>t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld ",&n);
		scanf("%lld",&m);
		ll i,j,k;
		ll a[n+1];ll result;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ll l[m+1],c[m+1],r[m+1];
		for(i=1;i<=m;i++)
		{
			scanf("%lld %lld %lld",&c[i],&l[i],&r[i]);
			if(c[i]==0)
			{
				for(j=l[i];j<=r[i];j++)
				{
					a[j]=a[j]/least1(a[j]);
				}
			}
			else
			{
			result =1;
			for(j=l[i];j<=r[i];j++)
			{
				result=maxe(result,least1(a[j]));
			}
			printf("%lld\n",result);
			}
		}
		
    }
	return 0;
}
