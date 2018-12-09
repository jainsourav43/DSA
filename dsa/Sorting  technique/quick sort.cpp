// Quick sort

#include<bits/stdc++.h>
using namespace std;

void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int a[],int low ,int high)
{
	int pivot=a[high];
	int i=low-1;
	
	for(int j=low;j<=high-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}

int quicksort(int a[],int low ,int high)
{
	int pi;
	if(low<high)
	{
		pi =partition(a,low,high);
	
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
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
	int n,a[50];
	cout<<"Enter the no of elements:";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter the data:";
		cin>>a[i];
	}
	cout<<"Elements before sorting:";
	printarray(a,n);
	quicksort(a,0,n-1);
	cout<<"\nElements after sorting:";
	printarray(a,n);
	return 0;
}
