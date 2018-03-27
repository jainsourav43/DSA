#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> m1;
map<ll,ll> m2; 
ll inc[100001]; // Length of increasing subarray ending at all indexes
ll dec1[100001];
ll bitonic(ll arr[], ll n)
{
    // Length of dec1reasing subarray starting at all indexes
    ll i, max;
 
    // length of increasing sequence ending at first index is 1
    inc[0] = 1;
 
    // length of increasing sequence starting at first index is 1
    dec1[n-1] = 1;
 	
    // Step 1) Construct increasing sequence array
    for (i = 1; i < n; i++)
    {
	
	if(arr[i]>arr[i-1])
	{
		
		inc[i]=inc[i-1]+1;
		
	}
	else
	{
		inc[i]=1;
	}
	}
       //inc[i] = (arr[i] > arr[i-1])? inc[i-1] + 1: 1;
       
 
    // Step 2) Construct dec1reasing sequence array
    for (i = n-2; i >= 0; i--)
    {
    	if(arr[i]>arr[i+1])
    	{
    		dec1[i]=dec1[i+1]+1;
    		
		}
		else
		{
			
			dec1[i]=1;
		}
	}
	
    //   dec1[i] = (arr[i] > arr[i+1])? dec1[i+1] + 1: 1;
    
 
    // Step 3) Find the length of maximum length bitonic sequence
    max = inc[0] + dec1[0] - 1;
    ll in=0;
    for (i = 1; i < n; i++)
        if (inc[i] + dec1[i] - 1 > max)
        {
        	max = inc[i] + dec1[i] - 1;
        	in =i;
		}
          //  cout<<dec1[7]<<" "<<inc[7]<<endl;
 
    return in;
}
 
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,ans=0;
		cin>>n;
		ll a[n],i,j;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll index= bitonic(a,n),sum=0,indexcopy=index;
		if(dec1[index]>inc[index])
		indexcopy=index+(abs(inc[index]-dec1[index])/2)+1;
		else if(dec1[index]<inc[index])
		indexcopy=index-(abs(inc[index]-dec1[index])/2);
		//cout<<"indexcopy = "<<indexcopy<<endl;
		//ll index1=min(dec1[index],inc[index]);
    	ll index1=(dec1[index]+inc[index])/2;
		ll mid=index1;
		sum=sum+a[indexcopy]-mid;
		ll mid1=mid-1;
	//	cout<<"index1= "<<index1<<endl;
	//		cout<<"inndex= "<<index<<endl;
	//		cout<<"inc,dec= "<<inc[index]<<" "<<dec1[index]<<endl;
			if(index<index1)
			index=index1;
		for(i=0;i<=indexcopy-index1;i++)
		{
			sum=sum+a[i];
		}
		//	cout<<"sum 1=  "<<sum<<endl;
		for(i=indexcopy-1;i>indexcopy-index1;i--)
		{	
			sum=sum+a[i]-(mid1);
			mid1--;
		}	//cout<<"sum2 =  "<<sum<<endl;
		mid1=mid-1;
		for(i=indexcopy+1;i<indexcopy+index1;i++)
		{
			sum=sum+a[i]-mid1;
			mid1--;
		}	//cout<<"sum3 =  "<<sum<<endl;
		for(i=indexcopy+index1;i<n;i++)
		{
			sum=sum+a[i];
		}
		//cout<<"sum4 =  "<<sum<<endl;
	cout<<sum<<endl;
		
		
		
	}
}
