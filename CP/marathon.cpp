#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
  bool prime[1000000+10];
void SieveOfEratosthenes(int n)
{

    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
//    for (int p=2; p<=n; p++)
//       if (prime[p])
//          cout << p << " ";
}
int main()
{
	ll t;
	t=1;
	while(t--)
	{
		ll n;
		ll i,j,k;
		cin>>n;
		ll a[n];
		SieveOfEratosthenes(1000000);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		map<int,int> m;
		int left[n+1],right[n+1];
		ll sum=0;
		left[0]=0;
		for(i=1;i<n;i++)
		{
			if(prime[a[i]])
			{
				cout<<a[i]<<" Is Prime \n ";
				m[a[i]]++;
				if(m[a[i]]==2)
				{
					left[i]=left[i-1]+1;
				}
				else if(m[a[i]]>2)
				{
					left[i]=left[i-1]-1;
				}
				else
				{
					left[i]=left[i-1];
				}
				
			}
			else
			{
				left[i]=left[i-1];
			}
		}
		m.clear();
		right[n-1]=0;
		for(i=n-2;i>=0;i--)
		{
			if(prime[a[i]])
			{
				m[a[i]]++;
				if(m[a[i]]==2)
				{
					right[i]=right[i+1]+1;
				}
				else if(m[a[i]]>2)
				{
					right[i]=right[i+1]-1;
				}
				else
				{
					right[i]=right[i+1];
				}
				
			}
			else
			{
				right[i]=right[i+1];	
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<left[i]<<" ";
		}
		cout<<endl;
		for(i=n-1;i>=0;i--)
		{
			cout<<right[i]<<" ";
		}
		cout<<endl;
		m.clear();
		for(i=0;i<n;i++)
		{
			if(prime[a[i]])
			{
				m[a[i]]++;
			}
		}
		auto it=m.begin();
		for(; it!=m.end();it++)
		{
			if(it->second==2)
			{
				sum++;
			}
		}
		ll q;
		cin>>q;
		for(i=0;i<q;i++)
		{
			ll l,r;
			cin>>l>>r;
			cout<<"Out= ";
			cout<<sum-left[l-1]-right[r-1]<<endl;
		}
		
	}
}
