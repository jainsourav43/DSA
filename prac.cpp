#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>m>>n;
	
	int l[m+1][n+1];
	int a[m],b[n];
	for(int i=0;i<m;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	cin>>b[i];
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
			{
				l[i][j]=0;
			}
			else if(a[i]==b[j])
			{
				l[i][j]=1+l[i-1][j-1];
			}
			else
			{
				l[i][j]=max(l[i][j-1],l[i-1][j]);
			}
		}
	}
	cout<<l[m][n]<<endl;
	
}
