#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int d;
		d=abs(n-m);
	    if(d<k)
	    {
	    	cout<<0<<endl;
		}
		else
		{
			cout<<d-k<<endl;
		}
	}
	return 0;
}
