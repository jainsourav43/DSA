#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,count=0;
		cin>>n>>m;
		
	int a[n],b[m],i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<m;i++)
	{
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+m);
	for(i=0,j=0; i<n&&j<m; )
	{
		if(a[i]==b[j])
		{
		count++;
		i++;j++;
		}
		else if(a[i]>b[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}
	cout<<count<<endl;
	}
}
