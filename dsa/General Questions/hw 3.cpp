#include<iostream>
using namespace std;
int maxe=0,mini,avg,sum1=0;int k=0;

void sum(int *p,int s)
{
	if(s==0)
	{cout.setf(ios::fixed);
cout.precision(2);
	cout<<"average\n"<<float(sum1)/k<<endl;
		return ;
	}
	else
	{
	k++; 
	if((*p)> maxe)
	{
		maxe=*p;
	}
	if((*p)<mini)
	{
	  mini=*p;
	}
		sum1=sum1+*p;
		sum(p+1, s-1);
	}
}
int main()
{
	int n;
	cout<<"Enter the no. of elements\n";
	cin>>n;
	int i,j,k;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mini=a[0];
     cout.setf(ios::fixed);
     cout.precision(2);
	sum(a,n);
	cout<<"Minimum  =" <<mini<<endl;
	cout<<"Maximum  = "<<maxe<<endl;
	cout<<"Sum  ="<<sum1<<endl;
	
		return 0;
}
