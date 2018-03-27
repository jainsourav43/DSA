#include<iostream>
#define ll long long int
using namespace std;
int main()
{
	ll t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll a[n],i,count=0,count1=0,count2=0,flag=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==0)
			flag=1;
			else if(a[i]==1)
			count1++;
			else if(a[i]==-1)
			count2++;
			else 
			count++;
		}
		if(count>1)
		cout<<"no\n";
		else if(count==1)
		{
			if(count1&&count2)
			cout<<"no\n";
			else if(count2>1&&count1==0)
			cout<<"no\n";
			else if(count2==0)
			cout<<"yes\n";
			else
			cout<<"no\n";
		}
		else if(count==0)
		{
			if(count2>1&&count1==0)
			cout<<"no\n";
			else
			cout<<"yes\n";
		}
	
	}
	return 0;
}
