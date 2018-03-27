#include<bits/stdc++.h>
#define null NULL
using namespace std;
struct vnode;
typedef
struct anode
{
	//int data;
	vnode *ptr;
	anode *next; 
}*aptr;
typedef
struct vnode
{
	int ver;
	anode *front;
	vnode *down;
}*vptr;
void addedge(vptr &vp1,int u,int v)
{
	vptr vp=vp1,vp2=vp1;
	aptr ap;
	while(vp->ver!=u)
	{
		vp=vp->down;
	}
	cout<<"after\n";
	ap=vp->front;
	if(ap==null)
	{
		vp->front= new anode;
		while(vp2->ver!=v)
		{
			vp2=vp2->down;
		}
		vp->front->ptr=vp2;
		//vp->front->data=v;
	    vp->front->next=null;
	}
	else
	{
	while(ap->next!=null)
	{
		ap=ap->next;
	}
	ap->next=new anode;
	ap=ap->next;
	while(vp2->ver!=v)
	{
		vp2=vp2->down;
	}
	//ap->data=v;
	ap->ptr=vp2;
	ap->next=null;
   }
}
int visit[10];
void dfs(vptr v,aptr a)
{
if(v!=null&&visit[v->ver]==0)
{
	cout<<v->ver<<"   ";
	visit[v->ver]=1;
	while(v->front!=null&&a!=null)
	{
		if(visit[a->ptr->ver]==0)
		{
		dfs(a->ptr,a->ptr->front);
	    }
	    a=a->next;
	}
}
}
void addvertex(vptr &vp1,int u)
{
	aptr ap;
	vptr vp=vp1;
	while(vp->down!=null)
	{
		vp=vp->down;
	}
	vp->down = new vnode;
	vp=vp->down;
	vp->ver=u;
	vp->down=null;
	vp->front=null;
	int v=1;
	int c=0;
//	while(v!=-1)
//	{
//		c++;
//		cout<<"Enter the edges from u else -1\n";
//		cin>>v;
//		if(v!=-1)
//		{
//			if(c==1)
//			{
//			vp->front=new anode;
//			vp->front->data=v;
//			vp->front->next=null;	
//			}
//			else
//			{
//			ap=vp->front;
//			while(ap->next!=null)
//			ap=ap->next;
//		    ap->next=new anode;
//		    ap=ap->next;
//			ap->next=null;
//			ap->data=v;
//		    }
//		}
}
void print(vptr v)
{
	aptr a;
	while(v!=null)
	{
		a=v->front;
		cout<<v->ver<<"  ";
		while(a!=null)
		{
			cout<<a->ptr->ver<<"  ";
			a=a->next;
		}
		v=v->down;
		cout<<endl;
	}
}
int main()
{
	int ue,ve,ch;
	vptr v=new vnode;
	v->down=null;int n=0;
	v->front=null;
	cout<<"enter the first  vertex \n";
	cin>>ue;
	v->ver=ue;
	while(ch!=-1)
	{
	cout<<"Enter 1 for vertex addition or 2 for edge addtion\n";
	cin>>ch;
	if(ch==1)
	{n++;
		cout<<"Enter the vertex \n";
		cin>>ue;
		addvertex(v,ue);
	}
	else if(ch==2)
	{
		cout<<"Enter the u and v such that u->v\n";
		cin>>ue>>ve;
		addedge(v,ue,ve);
	}
	else
	{
		break;
	}
    }
    print(v);int s;
    vptr temp=v;
    cout<<"Enter the source vertex \n";
    cin>>s;
    while(temp->ver!=s)
    {
    	temp=temp->down;
	}
    dfs(temp,temp->front);
    int check=0,i;
    while(check==0)
    {
    	for(i=1;i<=n;i++)
    	{
    		if(visit[i]==0)
    		{   
			    temp=v;
    			while(temp->ver!=i)
			    {
			    	temp=temp->down;
				}
    			dfs(temp,temp->front);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(visit[i]==1)
			{
				check=1;
			}
			else
			{
				check=0;
				break;
			}
		}
	}
}
