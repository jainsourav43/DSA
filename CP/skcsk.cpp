#include<iostream>
#include<string.h>
#include<set>
#define ll long long 
using namespace std;
int main()
{
	ll n,i,j;
	cin>>n;
	string b[n+1],u[n+1],result[n+1];
	
	char c[n+1];
	
	int l=0,m=0;
	for(i=0;i<n;i++)
	{
		cin>>c[i];
		if(c[i]=='+')
		{
			cin>>u[l++];
		}
		else
		{
			cin>>b[m++];
		}
	}
	int r=0,ans=0;
	set< string >se;
	for(i=0;i<m;i++)
	{
		for(int k=1;k<b[i].length();k++)
		{
			ans=1;
			for(j=0;j<l;j++)
			{
				string temp1=b[i].substr(0,k),temp2=u[j].substr(0,k);
				if(temp1==temp2)
				{
					ans=0;
					break;
				
				}
			}
			if(ans==1)
			{
				result[r++]=b[i].substr(0,k);	
				break;
			}
		}
	}
	for(i=0;i<r;i++)
	{
		se.insert(se.end(),result[i]);
	}
	if(se.size()==0)
	cout<<-1<<endl;
	else
	{
	cout<<se.size()<<endl;
	typeof(se.begin()) it=se.begin();
	for(int i=0;it!=se.end();i++)
	{
		cout<<*it<<" \n";
		it++;
	}
	}
	cout<<endl;
	
} 
