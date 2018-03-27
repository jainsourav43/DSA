#include<iostream>
#define ll long long 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t1;
	cin>>t1;
	int t=0;
	while(t1--)
	{
		t++;
		int p,q;
		cin>>p>>q;
		char str1[p+1],str2[q+1];
		cin>>str1>>str2;
		int l[p+1][q+1],i,j;
		for(i=0;i<=p;i++)
		{
			for(j=0;j<=q;j++)
			{
				if(i==0||j==0)
				{
					l[i][j]=0;
				}
				else if(str1[i-1]==str2[j-1])
				{
					l[i][j]=1+l[i-1][j-1];
				}
				else
				{
					l[i][j]=max(l[i-1][j],l[i][j-1]);
				}
				
				
			//	cout<<l[i][j]<<" ";
			}
			//cout<<endl;
		}
		
		cout<<"Case "<<t<<": "<<p+q-l[p][q]<<endl;
		
		
	}
}
