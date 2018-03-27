#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
string s,temp;
int main()
{
	int t;
	atoi()
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		     		cin>>s;

		bool v[n];
		for(int i=0;i<n;i++)
		v[i]=true;
		if(s.at(0)=='1')
		{
			v[0]=false;
			v[1]=false;
		}
		if(s.at(n-1)=='1')
		{
			v[n-2]=false;
			v[n-1]=false;
		}
			int ans=0;
		//	int len=s.length();
			for(int i=1;i<n-1;i++)
			{
				if(s.at(i)=='1')
				{
					v[i]=false;
					v[i-1]=false;
					v[i+1]=false;
				}
			}
			for(int i=0;i<n;i++)
			{
				if(v[i])
				ans++;
			}
			cout<<ans<<endl;
			
	}
}
