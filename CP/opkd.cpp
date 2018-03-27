#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int l[n+1][n+1],flag=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(flag==0)
			{
			if(i==0||j==0)
			{
				l[i][j]=0;
			}
			else if(a[i-1]>a[j])
			{
				l[i][j]=1+l[i-1][j-1];
			}
			else
			{
				l[i][j]=max(l[i][j-1],l[i-1][j]);
			}
			}
			else
			{
				if(i==0||j==0)
				{
					l[i][j]=0;
				}
				else if(a[i-1]a[j])
				{
					l[i][j]=1+l[i-1][j-1];
				}
				else
				{
					l[i][j]=max(l[i][j-1],l[i-1][j]);
				}
			}
		}
	}
}
