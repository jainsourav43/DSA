#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
struct st {
	ll w;
	ll x;
};
void merge(st arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
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
	ll n,k,i,j;
	cin>>n>>k;
	bool v[n];
	for(i=0;i<n;i++)
	v[i]=false;
	struct st obj[n],obj1[n];
	for(i=0;i<n;i++)
	{
		cin>>obj[i].x>>obj[i].w;
		obj1[i]=obj[i];
	}
    mergeSort(obj,0,n-1);
//    for(int i=0;i<n;i++)
//	{
//		cout<<obj[i].x<<" "<<obj[i].w<<endl;	cout<<obj1[i].x<<" "<<obj1[i].w<<endl;
//	}
	ll n1=n;
    for(i=1;i<k;i++)
    {
    	v[n1-1]=true;
    	n1--;
	}
	//v[0]=true;
	ll sum=0;
	
	n1=n;j=0;
	for(i=n-1;i>=0;i--)
	{
		//for(i=1;i<k;i++)
		
		
		//{
		if(j>=k-1) break;
			if(obj[n1-1].x<obj1[i].x)
			{//cout<<"ans =  "<<obj1[i].w*(obj1[i].x-obj[n1-1].x)<<" ";
				sum=sum+obj1[i].w*(obj1[i].x-obj[n1-1].x);
			}
			else
			{
			
			n1--;
			j++;
		   }
		//}
	//   sum=sum	
	}
	
	for(j=i;j>0;j--)
	{//cout<<"ans2 = "<<obj1[i].w*(obj1[i].x-obj1[0].x)<" ";
		sum=sum+obj1[j].w*(obj1[j].x-obj1[0].x);
	}
	cout<<sum<<endl;
	
	
	
    
    
    
	//for(i)
}
