#include<iostream>
//#include<iomainp>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		double r,b,rt,bt;
		cin>>r>>b;
		cin>>rt;
		bt=r+b-rt;
		double sum=0;
		cout.precision(10);
		if(rt<bt)
		{
			sum=sum+rt/(r+b);
			if(bt>=b)
			sum=sum+b;
			else
			sum+=bt;
		}
		else if (bt<rt)
		{
			sum=sum+bt/(r+b);
			if(rt>=r)
			{
				sum=sum+r;
			}
			else
			sum+=rt;
		}
		else if (rt==bt)
		{
			sum=b/bt+r/rt;
		}
	//	cout.setf(6);
		cout<<sum<<endl;
		
	}
}
