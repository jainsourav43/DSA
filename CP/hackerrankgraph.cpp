#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> m;
int main()
{
	ll t;
	cin>>t;

while(t--)
{
	ll n;
	m.clear();
	cin>>n;
	ll a[n],i,sum=0,ans=0,min;
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		sum=sum+a[i];
	}
	map<ll,ll> :: iterator it,it2; 
	i=1;
	if(n==2)
	{
		cout<<a[0]+a[1]-2*1<<endl;
	}
	else if(n%2==0)
	{	
		
		it2=m.end();
		//it2--;
		min=*min_element(a,a+n);
		ans=ans+min;
		m[min]--;
		i=1;
		for(it=m.begin();it!=m.end();)
		{		
			if(it->first==i)
			{
				if(it->second==2)
				{
					it->second-=2;
					it++;
				}
				else if(it->second>2)
				{
				//	ans=ans+(it->first)*(it->second)-2*it->first;
					it->second-=2;
					it++;
				}
				else
				{
					int count=it->second,value=it->first;
					it->second--;
					it++;
						if(it!=m.end())
						{	
							ans=ans+(it->first)-value;
							it->second--;
						}
						else
						{
						//	it->second--;
						}
				}
				i++;
			}
			else
			{
				
				if(it->first>=i)
				{
				
				if(it->second>=2)
				{
				//	ans=ans+2*(it->first-i);
					it->second-=2;
					//it++;
				}
				else
				{
					ans=ans+(it->first)-i;
			    	int count=it->second,value=it->first;
					it->second--;
					it++;
					if(it!=m.end())
					{
					ans=ans+(it->first)-i;
					it->second--;
					}
					else
					{
					//	it->second--;
					ans=ans+value-i;
					}
				}
			}
			else
			{
				break;
			}
				i++;
			}
			
		}
		for(it=m.begin();it!=m.end();it++)
		ans+=(it->first)*(it->second);
		cout<<ans<<endl;
	}
	else 
	{
		i=1;
		it2=it;
		if(it->first==i)
		{
		
		if(it->second>=2)
		{
			it->second-=2;
			i++;
		}
		
		else
		{
			
			it->second--;
			it++;
			ans=ans+it->first-i;
		}
		}
		else
		{
			if(it->count>=2)
			{
				ans=ans+2*(it->first)-i;
				it->second--;
			}
			else
			{
				ans=ans+2*(it->first)-i;
				it->second--;
				it++;
				ans=ans+2*(it->first)-i;
				it->second--;
			}
		}
		i++;
		it2=it;
		it2++;
		for(it=m.begin();it!=m.end();)
		{		
	//	cout<<"BYE\n";
			if(it->first==i)
			{
				if(it2!=m.end())
				{
				
				if(it->second==2)
				{
	//			    cout<<"bolo\n";
					it->second-=2;
					it++;
				}
				else if(it->second>2)
				{
				//	ans=ans+(it->first)*(it->second)-2*it->first;
					it->second-=2;
					it++;
				}
				else
				{
					int count=it->second,value=it->first;
					it->second--;
					it++;
						if(it!=m.end())
						{	
						//	ans=ans+(it->first)-value;
							it->second--;
						}
						else
						{
						//	ans=ans+value-i;
						}
				}
			}
			else
			{
				
			}
				i++;
			}
			else
			{
				
				if(it->second>=2)
				{
					ans=ans+2*(it->first-i);
					it->second-=2;
					//it++;
				}
				else
				{
					ans=ans+(it->first)-i;
					int count=it->second,value=it->first;
					it->second--;
					it++;
					if(it!=m.end())
					{
					ans=ans+(it->first)-i;
					it->second--;
					}
					else{
						ans+=value-i;
					}
				
				}
				
				i++;
			}
			
		}
		for(it=m.begin();it!=m.end();it++)
		ans+=(it->first)*(it->second);
		cout<<ans<<endl;
	}
	
}
}

