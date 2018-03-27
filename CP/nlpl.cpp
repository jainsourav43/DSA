#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
int main()
{
long long int n;
cin>>n;
long long int a[n],max=0,min=1000000;
for(long long int i=0;i<n;i++)
{
	cin>>a[i];
	if(min>a[i])
	min=a[i];
	if(max<a[i])
	max=a[i];
	cout<<max-min<<endl;
}
return 0;
}
