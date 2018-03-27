#include<bits/stdc++.h>
using namespace std;
double d=0.0000000000001;
double fun(double ar[],int n,double l,double r){
    double f=0,mid=(l+r)/2;
    for(int i=0;i<n;i++){
        f+=1/(ar[i]-mid);
    }
    if(abs(f)<d)
    return mid;
    else if(f>0)
    return fun(ar,n,l,mid);
    return fun(ar,n,mid,r);
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    double ar[n];
	    for(int i=0;i<n;i++)
	    cin>>ar[i];
        for(int i=0;i<n-1;i++){
            cout<<setprecision(2)<<fixed<<fun(ar,n,ar[i],ar[i+1])<<" ";
        }
        cout<<endl;
	}
}
