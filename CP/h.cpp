#include<iostream>
using namespace std;
#define ll long long
ll fact(ll n)
{
	ll i,j=1;
	for(i=2;i<=n;i++)
	j=j*i;
	return j;
}
int main()
{
ll n,m,c;
ll i,j,k;
cin>>n>>m>>c;
i=n-c;
j=m-c;
k=i+j+c;
cout<<fact(k-1)<<endl;
return 0;
}
