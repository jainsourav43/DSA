#include<iostream>
#define ll long long
#define u 1000000007
using namespace std;
ll per(ll i)
{
	ll ans=1;
	if(i==0)
	return 1;
	else if(i==1)
	{
		return 1;
	}
	else
	for(ll j=2;j<=i;j++)
	{
		ans=(ans*j)%u;
	}
	return ans;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		char s[100001];
		cin>>s;ll i;
		int a[26]={0};ll c=0,ans;
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='a')
			{
				a[0]++;
			}
			if(s[i]=='b')
			{
				a[1]++;
			}if(s[i]=='c')
			{
				a[2]++;
			}if(s[i]=='d')
			{
				a[3]++;
			}if(s[i]=='e')
			{
				a[4]++;
			}if(s[i]=='f')
			{
				a[5]++;
			}if(s[i]=='g')
			{
				a[6]++;
			}if(s[i]=='h')
			{
				a[7]++;
			}if(s[i]=='i')
			{
				a[8]++;
			}if(s[i]=='j')
			{
				a[9]++;
			}if(s[i]=='k')
			{
				a[10]++;
			}if(s[i]=='l')
			{
				a[11]++;
			}if(s[i]=='m')
			{
				a[12]++;
			}if(s[i]=='n')
			{
				a[13]++;
			}if(s[i]=='o')
			{
				a[14]++;
			}if(s[i]=='p')
			{
				a[15]++;
			}if(s[i]=='q')
			{
				a[16]++;
			}if(s[i]=='r')
			{
				a[17]++;
			}if(s[i]=='s')
			{
				a[18]++;
			}if(s[i]=='t')
			{
				a[19]++;
			}if(s[i]=='u')
			{
				a[20]++;
			}if(s[i]=='v')
			{
				a[21]++;
			}if(s[i]=='w')
			{
				a[22]++;
			}if(s[i]=='x')
			{
				a[23]++;
			}if(s[i]=='y')
			{
				a[24]++;
			}if(s[i]=='z')
			{
				a[25]++;
			}
		}
		for(ll j=0;j<26;j++)
		{
			if(a[j]>0)
			{
			c++;
			}
		}
		ans=per(c)%u;
		for(ll j=0;j<26;j++)
		{
			ans=(ans*per(a[j]))%u;
		}
		cout<<ans%u<<endl;
		}
	return 0;
}

