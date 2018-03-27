#include<iostream>
#define ll long long
#include<cmath>
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll f0,f1,n;
		cin>>f0>>f1>>n;
		double  k1=(pow(((1+sqrt(5))/2),n-1)-pow(((1-sqrt(5))/2),n-1))/sqrt(5);
		double k2=(pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n))/sqrt(5);
//		cout<<"k1  = "<<k1<<endl;
//		cout<<"k2  = "<<k2<<endl;
//		//F(n) = (F(0)+1)^Fib(n-1) * (F(1)+1)^Fib(n) - 1,
        cout<<(pow((f0+1),(pow(((1+sqrt(5))/2),n-1)-pow(((1-sqrt(5))/2),n-1))/sqrt(5))*pow((f1+1),(pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n))/sqrt(5)))-1<<endl;
	}
	return 0;
}
