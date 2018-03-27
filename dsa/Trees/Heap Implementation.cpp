#include<iostream>
#define max 100
using namespace std;
int g;
void swap(int &k1,int &k2)
{
	int temp;
	temp=k1;
	k1=k2;
	k2=temp;
}
void insert(int h[],int k,int &s)
{
	int i,j;
	if(s<max)
	{
    s++;
    h[s]=k;
    j=s;
    while(j!=1&&h[j/2]>h[j])
    {
    	if(h[j/2]>h[j])
    	{
    		swap(h[j/2],h[j]);
    	}
    	j=j/2;
    }
   }
}
void perculatedown(int h[],int s,int j )
{
	if(s>=2*j)
	{
	if(s>=2*j+1)
	{

		 if(h[j]>h[2*j]&&h[j]>h[2*j+1])
			{
				if(h[2*j]>h[2*j+1])
		         {
				swap(h[j],h[2*j+1]);
				j=2*j+1;
			     }
			     else
			     {
			    swap(h[j],h[2*j]);
			    	j=2*j;
			     }
			}
			else if(h[j]>h[2*j])
			{
			swap(h[j],h[2*j]);
			j=2*j;
			}
			else
			   {
		   swap(h[j],h[2*j+1]);
			j=2*j+1;
			   }
		}
		else if(s>=2*j)
		{
		if(h[j]>h[2*j])
		 {
		swap(h[j],h[2*j]);
     	j=2*j;
        }
		}
		perculatedown(h,s,j );
	}
	else return ;
}
void heapsort(int h[],int &s)
{
	if(s>=1)
	{
	cout<<h[1]<<"  ";
	h[1]=h[s];
	int j=1;
	s--;
	if(s>=2*j+1)
	{
	while(2*j+1<=s&&((h[j]>h[2*j+1])||(h[j]>h[2*j])))
		{
			 if(h[j]>h[2*j]&&h[j]>h[2*j+1])
			{
				if(h[2*j]>h[2*j+1])
		         {
				swap(h[j],h[2*j+1]);
				j=2*j+1;
			     }
			     else
			     {
			    swap(h[j],h[2*j]);
				j=2*j;
			     }
			}
			else if(h[j]>h[2*j])
			{
			swap(h[j],h[2*j]);
			j=2*j;
			}
			else
			   {
			   swap(h[j],h[2*j+1]);
				j=2*j+1;
			   }
		}*/
		perculatedown(h,s,j);
	}
	else if(s>=2*j)
	{
		 if(h[j]>h[2*j])
		 {
		swap(h[j],h[2*j]);
     	j=2*j;
        }
	}
	heapsort(h,s);
  }
   return ;
}
void perculateup(int h[],int &s,int j)
{
	if(j>1)
	{
		if(j>1)
		{
    if(h[j/2]>h[j])
    	{
    		swap(h[j/2],h[j]);
    		
    	}
    	j=j/2;
    	if(j>1)
    	{
    		perculateup(h,s,j);
    	}
    }
    }
    else return ;
}
void insert1(int h[],int &s,int &j,int k)
{
	if(s<max)
	{
		if(g==1)
		{
		  s++;
          h[s]=k;
          g=0;
		}
		if(j>1)
		{ 
         if(h[j/2]>h[j])
    	{
    		swap(h[j/2],h[j]);
    		
    	}
    	j=j/2;
    	if(j>1)
    	{
    		insert1(h,s,j,k);
    	}
    }
    }
}
int main()
{
	int n,n1,i;
	cout<<"Enter the number of vertices\n";
	cin>>n;
	int in[n],u,v,i1;
	cout<<"Enter the number of edges\n";
	cin>>n1;
	int cost;
//	for(i=1;i<=n1;i++)
//	{
//	   cout<<"enter the u and v 'u->v' \n";
//	   cin>>u>>v;
//	   cout<<"Enter the cost\n";
//	   cin>>cost;
//	   //a[u][v]=cost;
//	   a[v][u]=cost;
//	}
	int h[max];
	int s=0,k=1,j;
	//heap input;
	while(k!=13)
	{
     //input[k].
	if(k!=-1)
	{
	 
	g=1;j=s+1;
	insert1(h,s,j,k); 
   }
    }
    heapsort(h,s);
	
	
}
