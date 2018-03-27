#include<iostream>
#define ll long long 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ll n,s,t,i=0;
	cin>>n>>s>>t;
	ll r[n],seed,g,p;
	cin>>r[0]>>g>>seed>>p;
	for(i=i;i<n;i++)
	{
		r[i]=(r[i-1]*g+seed)%p;
		
	}
	queue<int>q ;
	int count=0;i=0;
	while(s!=t&&i<n)
	{
		if(s+r[s]<=t)
		{
		//	cout<<"one\n";
			s=t;
			count++;
			break;	
		}
		else if(s-r[s]<0)
		{
			if(n-(r[s]-s)<=t)
			{
			s=t;
			count++;
			break;
			}
			else
			{
				s=n-(s-r[s]);
			}
			count++;
		}
		else if(s-r[s]>=t)
		{
		//	cout<<"three\n";
			count++;
			s=t;
			break;
			
			
		}
		else
		{
			s=s+r[s];
		}
		i++;
	}
	if(s==t)
	cout<<count<<endl;
	else
	cout<<-1<<endl;
}
