#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long 
double d =0.0000000000001;
double myfun(double a[],double l,double r,int n)
{
    int i;
    double sum=0;
    double mid=0;
    mid=((double)l+(double)r)/2;
  //  cout<<"Mid="<<mid<<endl;
    for(i=0;i<n;i++)
    {
        sum=sum+1/(a[i]-mid);
    }
    cout<<setprecision(5)<<fixed<<"Sum= "<<sum<<endl;
    if(abs(sum)<d)return mid;
    if(sum>0)
    return (myfun(a,l,mid,n));
    return myfun(a,mid,r,n);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    double a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=0;i<n-1;i++)
	    {
	        cout<<setprecision(2)<<fixed<<myfun(a,a[i],a[i+1],n)<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
