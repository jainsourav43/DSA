#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		int flag=0;
		cin>>n>>m;
		char b[m];
		char c[m];
		for(int i=0;i<n;i++)
		{
			cin>>b;
			if(b[0]=='W' && b[m-1]=='W')
			{
				flag=1;
			}
			if(i!=0 && flag==0)
			{
				for(int j=0;j<m;j++)
				{
					if(c[j]=='W')
					{
						if(j-1>=0 && j+1<m)
						{
							if((c[j-1]!='B' && c[j-1]!='W') || (c[j+1]!='B' && c[j+1]!='W') || (b[j]!='B' && b[j]!='W'))
							{
								flag=1;
								break;
							}
						}
					}
					if(b[j]=='A')
					{
						if(c[j]=='B' || c[j]=='W')
						{
							flag=1;
							break;
						}
					}
					if(b[j]=='W')
					{
						if(c[j]=='B')
						{
							flag=1;
							break;
						}
					}
//					if(i==n-1)
//					{
//						if(b[j]=='W')
//						{
//							flag=1;
//							break;
//						}
//					}
				}
			}
			strcpy(c,b);
		}
		if(flag==1)
		cout<<"no\n";
		else
		cout<<"yes\n";
	}
	return 0;
}
