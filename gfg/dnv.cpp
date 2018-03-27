#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int lis[n],lis1[n],flag=0,j;
	 for (i = 0; i < n; i++ ){
	    lis[i] = 1;   lis1[i] = 1;
	 
	 } 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
    {
        for (j = 0; j < i; j++ )
		{
			if(a[i]>a[j]&&lis[i]<lis[j]+1)
			{
				lis[i]=lis[j]+1;
			}
			else  if(lis[i-1]>lis[i])
			{
				lis[i]=lis[i-1];
			}
		}
	}	for (i = n-2; i >= 0; i--)
      for (j = n-1; j > i; j--)
         if (a[i] > a[j] && lis1[i] < lis1[j] + 1)
            lis1[i] = lis1[j] + 1;
	int max=0;
	max=lis[0]+(lis1[0])-1;
for(i=0;i<n;i++)
{
	if(max<lis[i]+lis1[i]-1)
	{
		max=lis[i]+lis1[i]-1;
	}
}
cout<<max<<endl;
}
