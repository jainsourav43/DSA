// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
#define ll long long 
using namespace std;
 
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
    ll t;
	cin>>t;
	//t=1;
	while(t--)
	{
		int  n;
		cin>>n;
		int  flag=0,sum=0,i,j,k,a[n],max=-100000000;
		for(i=0;i<n;i++)
		cin>>a[i];
		max=maxSubArraySum(a,n);
//		for(i=0;i<n;i++)
//		{
//			if(a[i]>sum)
//			{
//			sum=0;	
//			}
//			sum+=a[i];
//			if(i==0)
//			{
//				max=sum;
//			}
//			if(max<sum)
//			{
//			max=sum;
//			}
//			
//		}
	cout<<max<<endl;
	}
}
