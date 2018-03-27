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
		cin>>n>>k;
		ll ans=0;
		ll a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		unordered_map<int,vector<int> > m;
		for(i=0;i<n;i++)
		{
			m[a[i]].push_back(i);
		}
		auto it=m.begin();
		int count=0;
		for( ; it!=m.end(); it++)
		{
			cout<<"It->first ,it->size() = "<<it->first<<" "<<it->second.size()<<endl;
			for(i=0;i<it->second.size();i++)
			{
				count=1;
				auto it1=it->second.begin();
				auto temp1=it1;
				it1++;
				
			for(j=i+1;j<it->second.size();j++)
			{
				cout<<"*it1, *temp1= "<<*it1<<" "<<*temp1<<endl;
				cout<<"Frst ="<<it->first<<endl;
				if(((*it1)-*temp1)%k==0)
				{
					count++;
					int temp=it->second[j];
					it->second.erase(it1);
				}
				it1++;
			}
			cout<<"Frstkckj ="<<it->first<<endl;
			cout<<"Count = "<<count<<endl;
			ans=ans+(count*(count-1))/2;
			it->second.erase(temp1);
			cout<<"It->size = "<<it->second.size()<<endl;
		
	    	}
	    	
			   
	
	}
	cout<<ans<<endl;
}
}
