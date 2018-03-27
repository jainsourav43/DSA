#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
struct st {
	ll w;
	ll x;
};
void merge(st arr[], ll l,ll m, ll r)
{
    ll  i, j, k;
   ll n1 = m - l + 1;
   ll  n2 =  r - m;
 
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
        if (L[i].w <= R[j].w)
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
void mergeSort(st arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
	    struct st obj[n+1];
	    ll i,j,k;
	    for(i=1;i<=n;i++)
	    {
	    	cin>>obj[i].w;
	    	obj[i].x=i;
		}
		mergeSort(obj,1,n);
		ll sum=0;
		for(i=1;i<=n;i++)
		{
			cout<<obj[i].w<<" ";
			sum=sum+i*obj[i].x;
		}
		cout<<endl;
		cout<<sum<<endl;
		
	}
	return 0;
}
