#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i,j,k,l,sum=0;k=n;
		if(n==1)
		{
			cout<<1<<endl;

		}
		else
		{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        //printf("%d ", 2);
        n = n/2;
        sum=sum+2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
           // printf("%d ", i);
            n = n/i;
            sum=sum+i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
    {
    	sum=sum+n;
	}
        //printf ("%d ", n);
        cout<<sum+k<<endl;
}
		}
		
	return 0;
}
 
