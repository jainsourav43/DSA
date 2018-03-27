#include<bits/stdc++.h>
#define ll long long 
#define null NULL
using namespace std;
typedef
struct anode
{
	ll data;
	anode *next; 
}*aptr;
typedef
struct vnode
{
	ll ver;
	anode *front;
	vnode *down;
}*vptr;
void addedge(vptr &vp1,ll  u,ll v)
{
	vptr vp=vp1;
	aptr ap;
	while(vp->ver!=u)
	{
		vp=vp->down;
	}
//	cout<<"after\n";
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
   while(vp->ver!=v)
	{
		vp=vp->down;
	}
//	cout<<"after\n";
	ap=vp->front;
	if(ap==null)
	{
		vp->front= new anode;
		vp->front->data=u;
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
	ap->data=u;
	ap->next=null;
   }
}
void addvertex(vptr &vp1,llu)
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
//llmain()
//{
//	llue,ve,ch;
//	vptr v=new vnode;
//	v->down=null;
//	v->front=null;
//	cout<<"enter the first  vertex \n";
//	cin>>ue;
//	v->ver=ue;
//	while(ch!=-1)
//	{
//	cout<<"Enter 1 for vertex addition or 2 for edge addtion\n";
//	cin>>ch;
//	if(ch==1)
//	{
//		cout<<"Enter the vertex \n";
//		cin>>ue;
//		addvertex(v,ue);
//	}
//	else if(ch==2)
//	{
//		cout<<"Enter the u and v such that u->v\n";
//		cin>>ue>>ve;
//		addedge(v,ue,ve);
//	}
//	else
//	{
//		break;
//	}
//    }
//    print(v);
//}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll p[n+1],i,v1[n],u[n],j;
		for(i=1;i<=n;i++)
		{
			cin>>p[i];
		}
		vptr v=new vnode;
		v->down=null;
		v->front=null;
		v->ver=1;
		for(i=2;i<=n;i++)
		{
			addvertex(v,i);
		}
		for(i=1;i<n;i++)
		{
			cin>>v1[i]>>u[i];
			addedge(v,v1[i],u[i])
		}
		for(i=1;i<=n;i++)
		{
			int flag[n+1]={0};
			while(v!=null)
			{
				flag[v->ver]=1;
			}
			
		}
		
    }
}
