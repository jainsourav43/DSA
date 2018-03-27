#include<iostream>
using namespace std;
int a[50][50]={0};
int in_degree(int n,int v)
{
	int dg=0;
	for(int i=0;i<n;i++)
	{
		if(a[i][v]==1)
		{
			dg++;
		}
	}
	return dg-1;
}
int out_degree(int n,int v)
{
	int dg=0;
	for(int i=0;i<n;i++){
		if(a[v][i]==1)
		{
			dg++;
		}
	}
	return dg-1;
}
int main()
{
	int n,n1,i;;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	int in[n],u,v,i1;
	cout<<"Enter the number of edges\n";
	cin>>n1;
	for(i=0;i<n1;i++)
	{
	   cout<<"enter the u and v 'u->v' \n";
	   cin>>u>>v;
	   a[u-1][v-1]=1;
	}
	for(i=0;i<n;i++)
	{
		a[i][i]=1;
	}
	for(i=0;i<n;i++)
	{
		in[i]=in_degree(n,i);
	}
	int count =0,j;
	for(i=0;i<n;i++)
    {
    	if(count==n)
    	break;
    	for(int k=0;k<n;k++)
        {
    	if(in[k]==0)
    	{    
		    in[k]=-1;
    		count++;
    		cout<<k+1<<"    ";
    	for(j=0;j<n;j++)
		{
			if(a[k][j]==1)
			a[k][j]--;	
				
		}
		 for(i1=0;i1<n;i1++)
		{
		 in[i1]=in_degree(n,i1);
		}
    		break;
    	}	
	   }
	}
}
