#include<bits/stdc++.h>
using namespace std;
long long  dp[1000001];
long long  calculate(int n,int pos)
{
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,H;
		cin>>n>>H;
		int h[n],l[n],i,j;
		for(i=0;i<n;i++)
		{
			cin>>l[i]>>h[i];
		}
		int index1=max_element(l,l+n)-l;
		int index2=min_element(h,h+n)-h;
		int max1=*max_element(l,l+n)-1;
		int min1=*min_element(h,h+n);
		int present=min1-max1;
		cout<<"i1,i2= "<<index1<<"  "<<index2<<endl;
		int max=l[index1],min=h[index2];
		if(present>=H)
		{
			cout<<0<<endl;
		}
		else
		{
			for(i=0;i<n;i++)
			{
				
			}
		}
	}
}
