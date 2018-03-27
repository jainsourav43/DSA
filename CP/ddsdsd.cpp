#include<stdio.h>
#define ll long long
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		if(n==2||n==1)
		{
			printf("%s\n","No");	
		}
	 else if(n%4==0&&n%3!=0) 
		{
			printf("%s\n","No");
		}
		else 
		{
			printf("%s\n","Yes");
		}
	}
	return 0;
}
