// shall sort

#include<iostream>
using namespace std;

int shellsort(int a[],int n)
{
	for(int gap=n/2;gap>0;gap/=2)
	{
		for(int i=gap;i<n;i+=1)
		{
			int temp=a[i];
			int j;
			for(j=i;j>gap && a[j-gap]>temp;j-=gap)
			{
				a[j]=a[j-gap];
			}
			a[j]=temp;
		}
	}
}

int printarray(int a[],int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
}

int main()
{
	int n,temp,a[50];
	cout<<"Enter no of elements:";
	cin>>n;
	cout<<"Enter elements:";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<"Array before sorting:";
	printarray(a,n);
	shellsort(a,n);
	cout<<"\nArray after sorting:";
	printarray(a,n);
	return 0;
}
