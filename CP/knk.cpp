#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> a[n];
		int c=1,j,i;
		for(i=0;i<n-1;i++)
		{
			
			a[i].push_back(c);
			a[i].push_back(c+1);
			c++;
		}
		a[n-1].push_back(1);
		a[n-1].push_back(n);
		cout<<n<<endl;
		for(i=0;i<n;i++)
		{
			cout<<n<<endl;
			int count=0;
			for(j=i;count<n;j=(j+1)%n)
			{
				cout<<count+1<<" ";
				cout<<a[j][0]<<" "<<a[j][1]<<endl;
				count++;
			}
			
		}
		
		
		
		
	}
}
