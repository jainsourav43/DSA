#include<iostream>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,i,j;
		cin>>n>>m;
		char a[n][m];
		int check1=0,check2=0,check3=0,checkmate=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]=='W')
				{
					if(j==m-1||j==0||i==n-1||(j<m-1&&a[i][j+1]=='A')||(j>0&&a[i][j-1]=='A')||(i<n-1&&a[i+1][j]=='A'))
					{
						cout<<"no\n";
						checkmate=1;
						break;
					}
				}
				else if(a[i][j]=='B')
				{
					if(i<n-1&&a[i+1][j]=='A')
					{
						cout<<"no\n";
						checkmate=1;
						break;
					}
				}
			}
			if(checkmate==1)
			{
				break;
			}
		}
		if(checkmate==0)
		{
			cout<<"yes\n";
		}
	
	}
	return 0;
}
