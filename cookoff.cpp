#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<map>
#define mod 1000000007
#include <unordered_map>
int prime1[100001];
using namespace std;
int count1=0;
unordered_multimap<int, int> mm;
void prime(int n)
{
	// Print the number of 2s that divide n
	while (n%2 == 0)
	{
		//printf("%d ", 2);
		if(mm.count(2)==0)
		count1++;
		mm.insert(2,n);
	//	prime1[2]++;
		n = n/2;
	}

	// n must be odd at this point. So we can skip 
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i+2)
	{
		// While i divides n, print i and divide n
		while (n%i == 0)
		{
			//printf("%d ", i);
				if(mm.count(i)==0)
				count1++;
			mm.insert(i,n);
			n = n/i;
		}
	}

	// This condition is to handle the case when n 
	// is a prime number greater than 2
	if (n > 2)
	{
	if(mm.count(n)==0)
		count1++;
	mm.insert(n,n);
}
	//prime1[n]++;
		//printf ("%d ", n);
}

int main()
{
	int n;
	cin>>n;
	int a[n],i,j;
	for(i=0;i<100001;i++)
	{
		prime1[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		prime(a[i]);
	}
	
	
	//sort(prime1,prime1+100001);
	typeof(mm.begin())itr=mm.begin();
	long long  max1=0,pro=1,ans=0;
	for(itr=mm.begin();itr!=mm.end();itr++)
	{
		if(mm.
	}
	if(ans)
	{
		cout<<"justdoit\n";
	}
	else
	{
		for(j=100000;j>=0&&prime1[j]>0;j--)
		{
			while(prime1[j]<max1)
			{
				pro=(pro*j)%mod;
				prime1[j]++;
			}
		}
		cout<<pro<<endl;
	}

}
