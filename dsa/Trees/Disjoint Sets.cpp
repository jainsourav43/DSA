#include<iostream>
using namespace std;
int ans1=0,ans2=0;
void myfin(vector<int> v)
{
	v[0]=2;
}
int find(int s[],int i)
{
	
	if(s[i]==0)
	{
		return i;
	}
	else 
	{ans1++;
	return find(s,s[i]);
	}
}
int find1(int s[],int i)
{
	ans2++;
	if(s[i]==0)
	{
		return i;
	}
	else 
	return find(s,s[i]);
}
void unions(int s[],int i,int j)
{
	if(s[j]==0)
	{
		s[j]=i;
	}
	else if(s[i]==0)
	{
		s[i]=j;
	}
	else
	{
		s[find(s,i)]=s[find(s,j)];
	}
}
int sizes(int s[],int i,int n)
{
	find(s,i);
	for(int j=1;j<=n;j++)
	{
		if(s[j]==i)
		{
			find1(s,j);	
			break;

		}
	}
}



int main()
{
	int n,m;
	cout<<"Enter the no of elements\n";
	cin>>n;
	int i=1,j;
	int s[n+1]={0};
	while(i!=-1)
	{
		cout<<"Enter the first element of the group else -1 \n";
		cin>>i;
		if(i!=-1)
		{
			cout<<"Enter the second element of the group  \n";
		    cin>>j;
		    unions(s,i,j);
		}
	}
	cout<<"Enter the key for which u wanna search\n";
	cin>>m;
	sizes(s,m,n);int k=(ans1+ans2);
	cout<<"Ans="<<k<<endl;
	return 0;
}
