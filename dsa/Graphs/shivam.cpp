#include<iostream>
using namespace std;
void add(int a[50],int s)
{
	int i=0;
	while(a[i]!=-1)
	i++;
	a[i]=s;
}
void fill(int A[20][20],int n,int a[50],int s)
{
	int f=1;
	while(f==1)
	{
		f=0;
		add(a,s);
		for(int i=1;i<=n;i++)
		{
			if(A[s][i]!=0)
			{
				A[s][i]=0;
				A[i][s]=0;
				s=i;
				f=1;
				break;
			}
		}
	}
}
int deg(int A[20][20],int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(A[k][i]!=0)
		return 1;
	}
	return 0;
}
int func(int a[50],int A[20][20],int n)
{
	int k=0,s;
	while(a[k]!=-1)
	{
		s=a[k];
		for(int i=1;i<=n;i++)
		{
			if(A[s][i]!=0)
			{
				if(deg(A,i,n)!=0)
				return s;
			}
		}
		k++;
	}
	return -1;
}
void print(int a2[50])
{
	int i=0;
	while(a2[i]!=-1)
	cout<<a2[i++]<<" ";
	
}
void splice(int a[50],int b[50],int s)
{	
	int i=0;
	while(b[i]!=s)
	{
		i++;
	}
	int tmp[50];
	for(int j=0;j<50;j++)
	tmp[j]=-1;
	int c=0;
	for(int j=i+1;b[j]!=-1;j++)
	{
		tmp[c]=b[j];
		c++;
	}
	cout<<"tmp: ";
	print(tmp);
	int j;
	for(j=i;a[j-i]!=-1;j++)
	{
		b[j]=a[j-i];
	}
	int x=0;
	while(b[x]!=-1)
	x++;
	for(int k=0;k<c;k++)
	{	
		b[x]=tmp[k];
		x++;
	}
	
}
void assign(int a[50],int b[50])
{
	int i=0;
	while(a[i]!=-1)
	{
		b[i]=a[i];
		i++;
	}
}
void empty(int a[50])
{
	int i=0;
	while(a[i]!=-1)
	{
		a[i]=-1;
		i++;
	}
}
int main()
{
	int n;
	cout<<"Enter n: ";
	cin>>n;
	int A[20][20];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			A[i][j]=0;
		}
	}
	int i1,i2;
	while(1)
	{
		cin>>i1;
		if(i1==-1) break;
		cin>>i2;
		A[i1][i2]=1;
	}
	int s;
	cout<<"\nEnter starting vertex: ";
	cin>>s;
	int a1[50];
	int a2[50];
	for(int i=0;i<50;i++)
	{
		a1[i]=-1;
		a2[i]=-1;
	}
	int f,c=0,nzdv;
	while(1)
	{
		fill(A,n,a1,s);
		print(a1);
		cout<<endl;
		if(c==0)
		{
			assign(a1,a2);
			empty(a1);
			nzdv = func(a2,A,n);
			s = nzdv;
			c=1;
			if(s==-1)
			break;
		}
		else
		{
			splice(a1,a2,nzdv);
			cout<<"Spliced: ";
			print(a2);
			cout<<endl;
			empty(a1);
			nzdv = func(a2,A,n);
			s = nzdv;
			if(s==-1)
			break;
			
		}
	}
	print(a2);
	return 0;
}
