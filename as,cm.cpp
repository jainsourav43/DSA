#include<iostream>
#include<cmath>
using namespace std;
 long long squareRoot(long long n)
{
long long   int x = n;
  long long int y = 1;
  while(x > y)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}
int sqrt1(int x) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details   
long long   start=0,end=x,mid=0,prevmid=0,dif=(start+end)/2-prevmid;
while(dif>=1)
{
    prevmid=mid;
    mid=(start+end)/2;
    dif=abs(mid-prevmid);
    if(mid*mid>x)
    {
        end=mid-1;
    }
    else if(mid*mid<x)
    {
        start=mid+1;
    }
}
return (int)mid;
}
int main()
{
	int n;
	cin>>n;
	cout<<sqrt1(n)<<endl;
}
