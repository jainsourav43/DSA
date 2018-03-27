#include<iostream>
#include<algorithm>
#include<string.h>
#include <sstream>
#define ll int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n],i,j,k,l;ll ka=0,ki=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			std::string s[i];
            std::stringstream out;
            out << a[i];
             s[i] = out.str();
            sort(s,s+n);
            // l=strlen(s[i]);
             if(s[i][l-1]=='a'&&s[i][l-2]=='k')
             {
             		ka++;
			 }
			 else if(s[i][l-1]=='i'&&s[i][l-2]=='k')
			 {
			 	ki++;
			 }
		}
		if(ka>=ki)
		{
			cout<<ka<<endl;
		}		
				else
				{
					cout<<ki<<endl;
				}
	}
return 0;
}
