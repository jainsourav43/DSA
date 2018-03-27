#include<bits/stdc++.h>
using namespace std;
int a[10][4];int count1[10];
long sum=0;
class UnsealTheSafe
{
public:long countPasswords(int N,int);
void initialise()
{
	int i;
	for(i=0;i<9;i++)
	{
		if(i==7)
		{
			a[i][count1[i]++]=0;
			a[i][count1[i]++]=4;
		}
		else if(i==0)
		{
			a[i][count1[i]++]=7;
		
		}
		else
		{
			if(i+3<=9)
			{
				a[i][count1[i]++]=i+3;
			}
			if(i-3>0)
			{
				a[i][count1[i]++]=i-3;
			}
			if(i+1<=9)
			{
				a[i][count1[i]++]=i+1;
			}
			if(i-1>0)
			{
				a[i][count1[i]++]=i-1;
			}
		}
	}
}


};
int bb[31][31];
long UnsealTheSafe::countPasswords(int n,int n1)
{
	int i,j;
	
	if(n==0)
	{
		sum=sum+count1[n1];
	}
	else
	{
		//cout<<"n1= "<<n1<<endl;
		//cout<<"count ="<<count1[n1]<<endl;
	
		
		for(int i=0;i<count1[n1];i++)
		{
			//cout<<"n11= "<<n1<<endl;
			//cout<<"a,count ="<<a[n1][i]<<"  "<<count1[i]<<endl;
			countPasswords(n-1,a[n1][i]);
		}
		
		//	sum=sum+count1[n1];
		//return sum;
	}
} 
int main()
{
	int n;
	UnsealTheSafe u;
	cin>>n;
	u.initialise();int j;
	for(int i=0;i<9;i++) j=count1[i]+j;  cout<<"total = "<<j<<endl;
    for(int i=0;i<9;i++)
	u.countPasswords(n-2,i);
	cout<<sum<<endl;
}
