#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],i,j;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	int l[n],flag=0;
	l[0]=0;
	for(i=0;i<n;i++)
	{
		l[i]=1;
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<i;j++)
		{
			if(flag==0)
			{
				if(a[j]<a[j+1]&&l[i]<l[j]+1)
				{
					l[i]=l[j]+1;
					flag=1;
				}
			}
			else 
			{
					if(a[j]>a[j+1]&&l[i]<l[j]+1)
					{
						l[i]=l[j]+1;
						flag=0;
					}
			}
		}
	}
	//for(i=0;i<n;i++)
	cout<<l[n-1]<<endl;
	
}
