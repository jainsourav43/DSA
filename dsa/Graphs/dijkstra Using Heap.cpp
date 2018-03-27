#include<iostream>
#define max 100
using namespace std;
int g;
struct heap
{
	int a;
	int b;
	int c;
};
struct vertex
{
	int  visit;
	int dist;
	int prev;
};
void swap(heap &k1,heap &k2)
{
	heap temp;
	temp=k1;
	k1=k2;
	k2=temp;
}
void insert(heap h[],heap k,int &s)
{
	int i,j;
	if(s<max)
	{
    s++;
    h[s]=k;
    j=s;
    while(j!=1&&h[j/2].c>h[j].c)
    {
    	if(h[j/2].c>h[j].c)
    	{
    		swap(h[j/2],h[j]);
    	}
    	j=j/2;
    }
   }
}
struct heap output[50];
struct heap temp[50];
static vertex ve[50];int vcount=0;
int dcheck=0;
void heapsort(heap h[],int &s,int n,int so,int g)
{
	cout<<"Welcome\n";
	static int tcount =0;int ans1=0;int ans2=0,i;
	if(dcheck==1)
	{
    if(ve[h[1].a].visit==-1||ve[h[1].b].visit==-1)
    {
    	ve[h[1].a].visit=1;
    	ve[h[1].b].visit=1;
    	ve[h[1].b].prev=h[1].a;
		output[++vcount]=h[1]; 
	}
	h[1]=h[s];
	int j=1;
	s--;
	if(s>=2*j+1)
	{
		while(2*j+1<=s&&((h[j].c>h[2*j+1].c)||(h[j].c>h[2*j].c)))
		{
			 if(h[j].c>h[2*j].c&&h[j].c>h[2*j+1].c)
			{
				if(h[2*j].c>h[2*j+1].c)
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
			else if(h[j].c>h[2*j].c)
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
	}
	else if(s>=2*j)
	{
		 if(h[j].c>h[2*j].c)
		 {
		swap(h[j],h[2*j]);
     	j=2*j;
        }
	}
	for(i=1;i<=n;i++)
	{
		if((output[i].a==g||output[i].b==g)&&(output[i].a==so||output[i].b==so))
		{
			dcheck=0;
		}
	}
	heapsort(h,s,n,s,g);
  }
   return ;
}
int a[50][50];
int main()
{
	int n,n1,i;	struct heap h[max];	
	int s=0,k=1,j;	
	struct heap input[50];
	cout<<"Enter the number of vertices\n";
	cin>>n;
	int in[n],u,v,i1;
	for(i=1;i<=n;i++)
	{
		ve[i].dist=10000;
		ve[i].visit=-1;
		ve[i].prev=-1;
	}
	cout<<"Enter the number of edges\n";
	cin>>n1;int cost;
	for(i=1;i<=n1;i++)
	{
	   cout<<"enter the u and v 'u->v' \n";
	   cin>>u>>v;
	   cout<<"Enter the cost\n";
	   cin>>cost;
	   a[u][v]=cost;
	   input[i].c=cost;
	   input[i].a=u;
	   input[i].b=v;
	   insert(h,input[i],s);
	}
	int so;
	cout<<"Enter the source\n";
	cin>>so;	
	cout<<"Enter the source\n";
	int g;
	cin>>g;
	heapsort(h,s,n,so,g);
	for(i=1;i<vcount;i++)
	{
		cout<<output[i].a<<"   "<<output[i].b<<endl;
	}
	
}

