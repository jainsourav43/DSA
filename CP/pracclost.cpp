#include<iostream>
#define ll long long 
#include<bits/stdc++.h>
using namespace std;
void merge(ll  arr[][2], ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;
 
    /* create temp arrays */
 	ll L[n1][2], R[n2][2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    for (j = 0; j < n2; j++)
    {
        R[j][0] = arr[m + 1+ j][0];
        R[j][1] = arr[m + 1+ j][1];
 	}
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i][0]<= R[j][0])
        {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
       arr[k][0] = R[j][0];
       arr[k][1] = R[j][1];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(ll arr[][2], ll l, ll r)
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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll a[k][2],i,j;
		char s[n+1];
		for(i=0;i<=n;i++)
		{
			s[i]='\0';
		}
		for(i=0;i<k;i++)
		{
			cin>>a[i][0]>>a[i][1];
		}
		mergeSort(a,0,k-1);
	//	cout<<"s = "<<s<<endl;
	//	for(i=0;i<k;i++)
	//	{
	//	cout<<a[i][0]<<"  "<<a[i][1]<<"\n";
	//	}
		for(i=0;i<k;i++)
		{
			s[a[i][0]]='(';
			s[a[i][1]]=')';
			
			if(i==k-1)
			{
				for(j=a[i][0]+1;j<=a[i][1]/2;j++)
				{
					//cout<<"j = "<<j<<endl;
					s[j]='(';
				}
				for(j=a[i][1]/2+1;j<a[i][1];j++)
				{	//cout<<"j1   =  "<<j<<endl;
					s[j]=')';
					//cout<<"j2   =  "<<j<<endl;
				}
			}
			else
			{
			for(j=a[i][0]+1;j<=a[i+1][1]/2;j++)
			{
				s[j]='(';
			}
			for(j=a[i][1]/2+1;j<a[i][1];j++)
			{	//cout<<"j1   =  "<<j<<endl;
				s[j]=')';
				//cout<<"j2   =  "<<j<<endl;
			}
			}
			
			
		}
	
		cout<<s<<endl;
		
	}
}
