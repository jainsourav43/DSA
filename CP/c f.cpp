#include<iostream>
using namespace std;
int main()
{
	long long n,ans,ans1=0,ans2=0;
	cin>>n;
	long long i,j,a[n],b[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i]>b[i])
		{
			ans1++;
		}
		else if(a[i]<b[i])
	{
		ans2++;
	}
	}
	if(ans1>ans2)
	{
		cout<<"Mishka"<<endl;
	}
	else if(ans2>ans1)
	{
		cout<<"Chris\n";
	}
	else
	{
		cout<<"Friendship is magic!^^"<<endl;
	}
}
