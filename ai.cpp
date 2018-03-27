#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],i,sum=0,max=0,total=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum=sum+a[i];
		total=a[i]*i+total;
	}
	max=total;
	for(i=0;i<n-1;i++)
	{
		total=total-a[n-1-i]*n+sum;
		if(total>max)
		max=total;
	}
	cout<<max<<endl;
	
}
