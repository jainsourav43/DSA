#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int c=1;
		for(int i=1;i<n-1;i++)
		{
			if(arr[i+1]==arr[i])
			{
				c++;
			}
			arr[i+1]=arr[i+1]+1;
		}
		cout<<c<<endl;
	}
}
