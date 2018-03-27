#include<iostream>
#include<stdio.h>
//#define ll long long 
using namespace std;
int main()
{
	long long  t;
	scanf("%lld",&t);
	//cin>>t;
	while(t--)
	{
		long long  n;
		//cin>>n;
		scanf("%lld",&n);
		long long  i,j,k=0,i1=0;
		long long  a[n+1],sum1=0;
		for(i=1;i<=n;i++)
		{
			//cin>>a[i];
			scanf("%lld",&a[i]);
			sum1=sum1+a[i];
		}
		long long  s;
		scanf("%lld",&s);
		//cin>>s;
		j=n;i=1;long long sum=0,ans[n+1],an=0;
		if(sum1<s)
		{
			cout<<"BING\n";
			continue;
		}
		while(j>n/2||i<=n/2)
		{
			sum=sum+a[i];
			ans[i1++]=i;
			if(sum==s)
			{	an=1;
				break;
			}
			i++;
			sum=sum+a[j];
			ans[i1++]=j;
			j--;
			if(sum==s)
			{
				an=1;
				break;
			}
		}
		if(an==0)
		{
			cout<<"BING\n";
		}
		else
		{			
			for(i=0;i<i1;i++)
			//cout<<ans[i]<<" ";
			printf("%lld  ",ans[i]);
		}
		cout<<endl;
	}
}
