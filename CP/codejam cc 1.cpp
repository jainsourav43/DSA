#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll i,j,k,q;
	ll a[n+1];
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//sort(a,a+n);
	cin>>q;
ll 	l[q],r[q];
	for(i=0;i<q;i++)
	{
		cin>>l[i]>>r[i];
	}ll m;
	for(i=0;i<q;i++)
	{
	ll b[n*n];k=0;
	for(j=l[i];j<=r[i];j++)
	{
		b[k]=a[j];
		k++;
	}
	sort(b,b+k);
	if(k==1)
	cout<<b[0]<<endl;
	else if(k%2==0)
	cout<<b[k/2-1]<<endl;
	else
	cout<<b[k/2]<<endl;
	}
	return 0;
	
}
