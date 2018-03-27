#include<iostream>
#define ll long long
#include<algorithm>
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n],i,j,k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);//cout<<"sorted \n";
//		for(i=0;i<n;i++)
//		{
//			cout<<a[i]<<"  ";
//		}cout<<endl;
	     if(a[n-1]-a[n-2]!=1)
	     {
	     	cout<<a[n-1]<<endl;
		 }
		 else  if(a[1]-a[0]!=1)
		 {
		 	
		 	cout<<a[0]<<endl;
		 }
		 else
		 {
		 	for(i=0;i<n-1;i++)
		 	{
		 		if(a[i]==a[i+1])
		 		{
		 			cout<<a[i]<<endl;
				 }
			 }
		 }
	}
	return 0;
}
