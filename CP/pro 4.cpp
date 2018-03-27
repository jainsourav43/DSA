#include<iostream>
using namespace std;
int main()
{
	int p1,p2,p3,w,a1,a2,a3;
	cin>>p1>>p2>>p3>>w;
	a1=p1+p2;
	a2=p2+p3;
	a3=p1+p3;
	if(a1>=w||a2>=w||a3>=w)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}
