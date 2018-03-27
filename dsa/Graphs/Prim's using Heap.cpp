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
void heapsort(heap h[],int &s,int vcount,int n,int so)
{
	static int tcount =0;int check3=0;
	cout<<"heapsort== "<<h[1].c<<"   "<<"h[1].a  ="<<h[1].a<<" h[1].b = "<<h[1].b<<endl;
	if(vcount!=n-1&&s>=1)
	{
		int check=0,ans1=0,ans2=0;
		if(vcount==0&&((so==h[1].a)||so==h[1].b))
		{
		check3=1;
		cout<<"temp3\n";
		vcount++;
		output[vcount]=h[1];
       }
	    else
	    {
	    	for(int i=1;i<=vcount;i++)
	    	{
	    		if(h[1].a==output[i].a||h[1].b==output[i].b||h[1].a==output[i].b||h[1].b==output[i].a)
	    		{
	    			for(int j=1;j<=vcount;j++)
	    			{
	    				if(h[1].a==output[j].a||h[1].a==output[j].b)
	    				{
	    					ans1=1;
	    					
						}
						if(h[1].b==output[j].a||h[1].b==output[j].b)
	    				{
	    					ans2=1;
						}
						
					}
					if(ans1==0||ans2==0)
					{
					cout<<" h[1].a = "<<h[1].a<<"   "<<"h[1].b  ="<<h[1].b<<endl;
	    			vcount++;	cout<<"temp3\n";
	    			check=1;
	    			output[vcount]=h[1];
	    			break;
	    		    }
				}
			}
			if(check==0)
			{
				tcount++;
				cout<<"temp\n";
				temp[tcount]=h[1];
			}
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
	if(check==1||check3==1)
	{
		for(j=tcount;j>0;j--)
		{cout<<"temp2\n";
			insert(h,temp[j],s);
		}
		tcount=0;
	}
	heapsort(h,s,vcount,n,so);
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
	cout<<"Enter the number of edges\n";
	cin>>n1;int cost;
	for(i=1;i<=n1;i++)
	{
	   cout<<"enter the u and v 'u->v' \n";
	   cin>>u>>v;
	   cout<<"Enter the cost\n";
	   cin>>cost;
	   a[u][v]=cost;
	   a[v][u]=cost;
	   input[i].c=cost;
	   input[i].a=u;
	   input[i].b=v;
	   insert(h,input[i],s);
	}
	int so;
	cout<<"Enter the source\n";
	cin>>so;
	heapsort(h,s,0,n,so);int sum=0;
	for(i=1;i<n;i++)
	{
		cout<<output[i].a<<"   "<<output[i].b<<endl;
		sum=sum+a[output[i].a][output[i].b];
	}
	cout<<"\n Total = "<<sum<<endl;
	return 0;
}

