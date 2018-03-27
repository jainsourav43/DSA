#include<iostream>
using namespace std;
int min1(int a,int b,int c)
{
	a=min(a,b);
	a=min(a,c);
	return a;
}
int main()
{
	long long n;
	cin>>n;
	long long i,j,a[n],sum[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)
	{
		cout<<0<<endl;
	}
	else if(n==3)
	{
		cout<<min1(a[0],a[1],a[2])<<endl;
	}
	else
	{
	long long int sum1=a[0],sum2=a[1],sum3=a[2];
	for(i=3;i<n-2;i+=3)
	{
		sum1=min1(a[i]+sum1,a[i]+sum2,a[i]+sum3);
		sum2=min1(a[i+1]+sum1,a[i+1]+sum2,a[i+1]+sum3);
		sum3=min1(a[i+2]+sum1,a[i+2]+sum2,a[i+2]+sum3);
	}
	if(n%3==1)
	{
		sum1=min1(a[n-1]+sum1,a[n-1]+sum2,a[n-1]+sum3);
		cout<<sum1<<endl;
	}
	else if(n%3==2)
	{
		sum1=min1(a[n-2]+sum1,a[n-2]+sum2,a[n-2]+sum3);
		sum2=min(a[n-1]+sum2,a[n-1]+sum3);
		cout<<min(sum1,sum2)<<endl;
	}
	else
	{
	cout<<min1(sum1,sum2,sum3)<<endl;
	}
	}
}
