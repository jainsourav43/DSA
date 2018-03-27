#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long 
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   ll n,q;
    cin>>n>>q;
    ll i,j,k,l[q],r[q],x[q],y[q],count,a[n];
  for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<q;i++)
        {
        cin>>l[i]>>r[i]>>x[i]>>y[i];
        count=0;
        for(j=l[i];j<=r[i];j++)
            {
            if(a[j]%x[i]==y[i])
                {
               count++;
			   }
           }
        cout<<count<<endl;
        
        
       }
    
    return 0;
}
