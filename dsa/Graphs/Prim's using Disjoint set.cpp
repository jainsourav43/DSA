#include<iostream>
using namespace std;
struct heap
{
	int a;
	int b;
	int c;
};
int find(int s[],int i)
{
	cout<<"find\n";
	if(s[i]==0)
	{
		return i;
	}
	else 
	{//ans1++;
	return find(s,s[i]);
	}
}
void unions(int s[],int i,int j)
{
	cout<<"union\n";
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
int a[50][50];
int main()
{
	int n,n1,i;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	struct heap input[50];
    int s[n+1]={0};
	int in[n],u,v,i1;
	cout<<"Enter the number of edges\n";
	cin>>n1;
	int cost;
	for(i=1;i<=n1;i++)
	{
	   cout<<"enter the u and v 'u->v' \n";
	   cin>>u>>v;
	   cout<<"Enter the cost\n";
	   cin>>cost;
	   a[u][v]=cost;
	   a[u][v]=cost;
	   input[i].a=u;
	   input[i].b=v;
	   input[i].c=cost;
	}
	int so,ans1,t1,t2;
	cout<<"Enter the source vertex\n";
	cin>>so;
	int min=100;
	int count=0,vcount=0;
	int ans[50][2];
	while(vcount<n-1)
	{
       min=100;
	   for(i=1;i<=n1;i++)
	   {  
		if(vcount==0)
		{
			if(min>input[i].c&&input[i].a==so)
			{
			min=input[i].c;
			ans1=i;
		    }
		}
	    else
		{
			 if(min>input[i].c)
			 {
				min=input[i].c;
				ans1=i;
		     }
		}
       	}
	t1=find(s,input[ans1].a);
	t2=find(s,input[ans1].b);
	if(vcount==0)
	{
	vcount++;
	ans[vcount][0]=input[ans1].a;
    ans[vcount][1]=input[ans1].b;
	unions(s,input[ans1].a,input[ans1].b);
	input[ans1].c=1000;
	}
	else 
    {
    	if(t1!=t2)
    	{
	    vcount++;
	    ans[vcount][0]=input[ans1].a;
	    ans[vcount][1]=input[ans1].b;
		unions(s,input[ans1].a,input[ans1].b);
		input[ans1].c=1000;
	   }
	   else 
	   {
	   //vcount++;
	   input[ans1].c=1000;
	   }
    }
   }
   int sum=0;
   for(i=1;i<=vcount;i++)
	{
		cout<<ans[i][0]<<"  "<<ans[i][1]<<"  "<<endl;
		sum=sum+a[ans[i][0]][ans[i][1]];
	}
	cout<<"\nTotal ="<<sum<<endl;	
	return 0;
}
