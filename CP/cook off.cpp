#include<iostream>
#include<string.h>
#define ll long long 
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		char s[4];
		cin>>n;
		cin>>s;
		ll a[n],k,i,j,sum=0,o=0,e=0;
		if(strcmp(s,"dee")==0)
		{
			k=1;
		}
		else
		{
			k=0;
		}
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0)
			{
				e++;
			}
			else
			{
				o++;
			}
			sum=sum+a[i];
		}
		if(sum%2==0)
		{
			cout<<"Dum\n";
		}
		else if(sum%2!=0)
		cout<<"Dee\n";
	//	}
	/*	else if(e%2==0&&o%2==0)
		{
			cout<<"Dum\n";
		}
		else if(e%2!=0&&o%2!=0)
		{
			cout<<"Dum\n";
		}*/
		
	}
	return 0;
}
