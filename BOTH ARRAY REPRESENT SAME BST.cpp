#incude<iostream>
using namespace std;
bool check(int a[],int b[],int i1,int i1,int min,int max,int n)
{
	for(i=i1;i<n;i++)
	if(a[i]>min&&a[i]<max)
	break;
	for(j=i2;j<n;j++)
	if(b[j]>min&&b[j]<max)
	break;
	if(j==n&&i==n)
	return true;
	if(((j==n)^(i==n))||b[j]!=a[i])
	return false;
	return check(a,b,i+1,j+1,a[i],max,n)&&check(a,b,i+1,j+1,min,a[i],n);
	
}
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	int i=0;
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	cin>>b[i];
	cout<<check(a,b,0,0,INT_MIN,INT_MAX,n);
}
