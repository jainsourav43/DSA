#include<iostream>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll c,d,l;
		cin>>c>>d>>l;
		if(l%4!=0)
		{
			cout<<"no\n"<<endl;
		}
		else
		{
			   if(2*d<c&&l>=(4*d+(c-2*d)*4)&&l<=(c+d)*4)
			   {
			   	cout<<"yes\n";
			   }
			   else if(2*d>=c&&l>=4*d&&l<=4*d+c*4)
			   cout<<"yes\n";
			   else
			   cout<<"no\n";
		}
	}
}
