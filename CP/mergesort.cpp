#include<iostream>
#define ll long long
#include<limits.h>
using namespace std;
#include<cmath>
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
struct st
{
	int x;
	char name[6];
};
void merge(st arr[], ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;
 
    /* create temp arrays */
    st L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].x<= R[j].x)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(st arr[], ll l, ll r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ll m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
int main()
{
	ll  t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
	    st obj[n];
	   ll i,j;
	  for( i=0;i<n;i++)
	  {
	  	cin>>obj[i].name;
	  	cin>>obj[i].x;
	  }
    mergeSort(obj,0,n-1);
    int check=0,check1=0,check2=0;
   for(i=0;i<n-1;i++)
   {
   	if(obj[i].x==obj[i+1].x)
   	{
   	   	check=1;
	}
	else
	{
		if(check==0)
		{
			check1=1;
			cout<<obj[i].name<<endl;
			break;
		}
		if(i==n-2)
		{
			check2=1;
		}
		check=0;
	}
   }
   if(n==1)
   {
   	cout<<obj[0].name<<endl;
   }
   else if (check==0&&check2==1)
   {
   		cout<<obj[n-1].name<<endl;
   }
  else  if(!check1&&n!=1)
   {
   	cout<<"Nobody wins.\n";
   }
   }
  return 0;
}
