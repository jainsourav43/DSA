#include<iostream>
#define ll long long
#include<algorithm>
using namespace std;
int main()
{
	ll n,k,d;
	cin>>n>>k>>d;
	bool v[n]={true};
	ll i,a[n],d1;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<1<<" "<<0<<endl;
	if(d>1500)
	{
		d1=1500;
	}
	else
	{
		d1=d;
	}
	ll max[d1]={0},in[d1],j,check=0,l;
	for(j=0;j<d1;j++)
	{
	for(i=0;i<n;i++)
	{
		if(max[j]<a[i])
		{
			check=0;
			for(l=0;l<j;l++)
			{
				if(max[l]>a[i])
				{
					continue;
				}
				else 
				{
					check=1;
					break;
				}
			}
		    if(check==0)
		    {
			max[j]=a[i];
			in[j]=i;
		   }
		}
	}
}
for(i=0;i<d1;i++)
{
	cout<<2<<" "<<in[i]+1<<endl;
}
	cout<<-1<<endl;
  }

