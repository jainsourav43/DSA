#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#define ll long long
using namespace std;
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
void build(ll node, ll start, ll end,ll A,ll tree)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        ll mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid,a,tree);
        // Recurse on the right child
        build(2*node+1, mid+1, end,a,tree);
        // Internal node will have the sum of both of its children
        tree[node] = max(least(tree[2*node]),least(tree[2*n+1]));//tree[2*node] + tree[2*node+1];
    }
}
void update(ll node, ll start, ll end, ll idx, ll val,ll tree,ll a)
{
    if(start == end)
    {
        // Leaf node
        A[idx] =a[idx]/least(a[idx]);
        tree[node] =tree[node]/least(tree[idx]);
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val,tree,a);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val,tree ,a);
        }
        // Internal node will have the sum of both of its children
        //tree[node] = least(tree[])//tree[2*node] + tree[2*node+1];
        tree[node]=max(least(tree[2*node]),least(tree[2*node+1]);
    }
}
ll query(ll node, ll start, ll end, ll l, ll r,ll tree)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    ll mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r,tree);
    ll p2 = query(2*node+1, mid+1, end, l, r,tree);
    return max(p1,p2);
}
/*void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        printf ("%d ", n);
}*/
ll least(ll n)
{
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
	for(ll i=3;i<=sqrt(n);i+=2)
	{
		if(n%i==0)
		{
			return i;
		}
	}
}
}
int main()
{
	ll t;
	//cin>>t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,m;
		//cin>>n>>m;
		scanf("%lld ",&n);
		scanf("%lld",&m);
		ll i,j,k;
		ll a[n+1];ll result;
		for(i=1;i<=n;i++)
		{
		//	cin>>a[i];
			scanf("%lld",&a[i]);
		}
		ll tree[n-1];
		build(0,0,n-1,a,tree);//ll node, ll start, ll end,,ll a,ll tree
		ll l[m+1],c[m+1],r[m+1];
		for(i=1;i<=m;i++)
		{
			//cin>>c[i]>>l[i]>>r[i];
			scanf("%lld %lld %lld",&c[i],&l[i],&r[i]);
			if(c[i]==0)
			{
				for(j=l[i];j<=r[i];j++)
				{
					a[j]=a[j]/least(a[j]);
				}
			}
			else
			{
			result =1;
			for(j=l[i];j<=r[i];j++)
			{
				result=max(result,least(a[j]));
			}
			//cout<<result<<endl;
			printf("%lld\n",result);
			}
		}
		
    }
	return 0;
}
