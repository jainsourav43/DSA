#include<iostream>
using namespace std;
int main()
{
	long long n,t;
	long long c,zr,zl;
	unsigned long long l;
	cin>>t;
	while(t--)
	{
		l=0;
		char s[100000];
		cin>>n;
		cin>>s;
		c=-1;
		zl=-1;
		zr=-1;
		
		long long a[100000];
		for(long long i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(s[0]=='0')
		{	
			zr=a[0];
			zl=a[0];
		}
		else
		c=a[0];
		for(long long i=1;i<n-1;i++)
		{
			if(s[i]=='1')
			{
				if(s[i-1]=='0')
				{
					if(c!=-1)
					{
					l+=(a[i]-zl)>(zr-c)?(zr-c):(a[i]-zl);
					}
					else if(zl!=-1)
					l+=a[i]-zl;
				}
				c=a[i];
			}
			else
			{
				if(s[i-1]=='1')
				zl=a[i];
				if(s[i+1]=='1')
				zr=a[i];
			}
		}
		if(s[n-1]=='0')
		{
			l+=a[n-1]-c;
		}
		else if(zl!=-1&&s[n-1]=='1'&&s[n-2]=='0')
		{
		if(c!=-1)
		l+=(a[n-1]-zl)>(zr-c)?(zr-c):(a[n-1]-zl);
		else 
		
		l+=a[n-1]-zl;
		}
		
		cout<<l<<endl;
	}
	return 0;
}
		
