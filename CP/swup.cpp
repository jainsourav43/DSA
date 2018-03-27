#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
			int min=10000000,sum=0;
	for(i=0;i<n;i+=3)
	{
		min=10000000;
		for(j=i;j<i+3&&j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
			}
			
		}
	//	cout<<min<<" ";
		sum+=min;
	}
	cout<<sum<<endl;
}
