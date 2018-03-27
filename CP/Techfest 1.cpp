#include<string.h>
#define ll long long
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int i,j;
	for(j=1;j<=t;j++)
	{
	ll n,max=0,max2=0,max3=0,max1=0,k,l,m,count=0;
	cin>>n;
	ll a[n],b[n],c[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
     for(k=0;k<n;k++)
     {
     	for(l=0;l<n;l++)
     	{
     		count=0;
     		for(m=0;m<n;m++)
     		{
     			if(a[k]+b[l]+c[m]<=10000)
     			{
     				count++;
				 }
			 }
			 if(max<count)
			 {
			 	max=count;
			 }
		 }
	 }
	cout<<"Case #"<<j<<": "<<max<<endl;
	
	}
	return 0;
}

