#include<iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	while(1)
	{
		ll w,b,n;
		cin>>w>>b;
		if(w==-1&&b==-1)
		{
			break;
		}
		cin>>n;
		ll i,x[n],y[n],r[n],y1[n],y2[n];
		for(i=0;i<n;i++)
		{
			cin>>x[i]>>y[i]>>r[i];
			y1[i]=y[i]+r[i];
			y2[i]=y[i]-r[i];
		}
		ll max=0,p=0,count=0,j;
		for(i=0;i<n;i++)
		{
			count=0;
			for(j=0;j<n;j++)
			{
				if(y2[j]<=y1[i]&&)
				{
					count1++;
				}
				else
				{
					count++;
				}
			}
			if(count>max)
			{
				max=count;
			}
		}
		cout<<max<<endl;
	}
}
