#include <bits/stdc++.h>
#define ll long long
#include<map>
using namespace std;

map<ll,ll> m;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n],i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			m[a[i]]++;
		}
		int ma=*max_element(a,a+n);
		m[ma]=m[ma]-1;
		int ans=0;
		//auto it=m.begin();
		i=1;
		map<ll,ll> :: iterator it;
		for(it=m.begin();it!=m.end();)
		{		
			if(it->first==i)
			{
				if(it->second==2)
				{
				//	i++;
					it++;it++;
				///	continue;
					
				}
				else if(it->second>2)
				{
					ans=ans+(it->first)*(it->second)-2*it->first;
					it++;it++;
				}
				else
				{
					int temp=it->second,count1=it->first;
					it++;
					if(temp==1)
					{
					ans=ans+(it->first)-count1;
					it->second--;
					}
					else
					{
						if(it->second>=2)
						{
						
						ans=ans+2*(it->first)-2*count1;
						it->second-=2;
						}
						else
						{
							it->second--;
							ans=ans+it->first-count1;
							it++;
							ans=ans+it->first-count1;
							it->second--;
						}
					}
				}
				i++;
			}
			else
			{
				
				if(it->second>=2)
				{
					ans=ans+2*(it->first-i);
					it->second-=2;
					it++;
				}
				else
				{
					ans=ans+(it->first)-i;
					it->second--;
					it++;
					ans=ans+(it->first)-i;
				}
				i++;
			}
			
		}
		cout<<ans<<endl;
	}
	
}

