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
	ll n,max[3]={0},max2=0,max3=0,max1=0;
	cin>>n;
	ll a[n],b[n],c[n],count[6]={0};
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(a[i]>=max[0])
		{
			max[0]=a[i];
		}
		if(b[i]>=max[1])
		{
			max[1]=b[i];
		}
		if(c[i]>=max[2])
		{
			max[2]=c[i];
		}
	}
	max1=max[0];
	max2=max[1];
	max3=max[2];
//	sort(max,max+3);
	if(max[0]+max[1]+max[2]<=10000)
	{//cout<<"y\n";
		cout<<"Case #"<<j<<": "<<n<<endl;continue;
	}
	else
	{
	if(max[1]+max[2]<=10000)
	{
      for(i=0;i<n;i++)
      {
      	if(a[i]<=10000-max[1]-max[2])
      	{
      		count[0]++;
		}
	  }
    }
     if(max[0]+max[1]<=10000)
     {
     	for(i=0;i<n;i++)
     	{
     		if(c[i]<=10000-max[1]-max[0])
     		{
     			count[1]++;
			 }
		 }
	 }
	 if(max[2]+max[0]<=10000)
	 {
	 	for(i=0;i<n;i++)
	 	{
		 if(b[i]<=10000-max[0]-max[2])
		 {
		 	count[2]++;
		 }
		}
	 }
	 if(max[0]<=10000)
	 {
	 	for(i=0;i<n;i++)
	 	{
	 		if(b[i]+c[i]<=10000-max[0]&&b[i]!=max[1])
	 		{
	 			count[3]++;
			 }
		 }
	 }
	if(max[1]<=10000)
	 {
	 	//sum=max[1]+b[0]+c[0];
	 	//sum=sum+b[i]+c[i];
	 	for(i=0;i<n;i++)
	 	{
	 		if(a[i]+c[i]<=10000-max[1]&&c[i]!=max[2])
	 		{
	 			//sum1=b[i]+c[i]+max[1];
	 			count[4]++;

	 			//if(sum1>=sum)
	 			//{

				 //}
			 }
		 }
	 }
	 if(max[2]<=10000)
	 {
	 	for(i=0;i<n;i++)
	 	{
	 		if(b[i]+a[i]<=10000-max[2]&&a[i]!=max[0])
	 		{
	 			count[5]++;
			 }
		 }
	 }
	}
	sort(count,count+6);
	cout<<"Case #"<<j<<": "<<count[5]<<endl;

	}
	return 0;
}

