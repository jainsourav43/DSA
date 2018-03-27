#include<iostream>
using namespace std;
#define ll long long 
#include<algorithm>
int main()
{
	 ll n,m;
	 cin>>n>>m;
	 ll a[m],i,j;
	 for(i=0;i<m;i++)
	 {
	 	cin>>a[i];
	 }
	 sort(a,a+m);
	 ll ans=a[n-1]-a[0];
	 for(i=0;i<=m-n;i++)
	 {
	 	
	 	if(ans>a[i+n-1]-a[i])
	 	{
	 		ans=a[i+n-1]-a[i];
		 }
	 }
	 cout<<ans<<endl;
}
