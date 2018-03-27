#include<iostream>
using namespace std;

int findlis(int a[],int prev,int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			if(a[i])
		}
	}
	
}
int main()
{
	int n;
	cin>>n;
	int a[n],i,j;
	for(i=0;i<n;i++)
	cin>>a[i];
	int max1=0,count1=1,prev=a[0];
	for(j=1;j<n;j++)
	{
		if(a[j]>prev)
		{
			count1++;
			prev=a[j];
			if(max1<count1)
			{
				max1=count1;
			}
		}
		else
		{
		//count1=0;	
		}
		
	}
	cout<<max1<<endl;	
}
