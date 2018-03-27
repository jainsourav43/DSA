#include<bits/stdc++.h>
#define null NULL
using namespace std;
typedef
struct anode
{
	int data;
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
	vptr vp=vp1;
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
		vp->front->data=v;
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
	ap->data=v;
	ap->next=null;
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
	while(v!=-1)
	{
		c++;
		cout<<"Enter the edges from u else -1\n";
		cin>>v;
		if(v!=-1)
		{
			if(c==1)
			{
			vp->front=new anode;
			vp->front->data=v;
			vp->front->next=null;	
			}
			else
			{
			ap=vp->front;
			while(ap->next!=null)
			ap=ap->next;
		    ap->next=new anode;
		    ap=ap->next;
			ap->next=null;
			ap->data=v;
		    }
		}
	}
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
			cout<<a->data<<"  ";
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
	v->down=null;
	v->front=null;
	cout<<"enter the first  vertex \n";
	cin>>ue;
	v->ver=ue;
	while(ch!=-1)
	{
	cout<<"Enter 1 for vertex addition or 2 for edge addtion\n";
	cin>>ch;
	if(ch==1)
	{
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
    print(v);
}
