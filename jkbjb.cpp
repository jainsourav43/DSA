#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 
#define  mod 1000000007
ll pow1(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
       
    }
    return (ans%mod);
}
int main() {

    string s;
    cin>>s;
    ll n=s.length(),i,j,gp,sum=0,dp,hp,mp;
  //  gp=pow1(10,n);       
    for(i=0;i<n;i++)
    {
        gp=pow1(10,n-i);
        hp=ceil((double)(gp-1)/(double)9 );
        dp=((s[i]-'0')*hp);
        mp=(dp*(i+1))%mod;
        sum=(sum+mp)%mod;
        
    }
     cout<<sum<<endl;    
    
    return 0;
}

