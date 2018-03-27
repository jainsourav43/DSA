#include<iostream>
#define null NULL
#include<algorithm>
#define ll long long 
using namespace std;

ll n,k;
ll count1=0;
ll count2[30];
typedef
struct lnode
{
	ll data;
	lnode *next;
} *lptr;
void addend(lptr l,ll data)
{
	lptr t=l;
	while(t->next!=null)
	{
		t=t->next;
		
	}
	t->next=new lnode;
	t=t->next;
	t->data=data;
	t->next=null;
}
void addbegin(lptr &l,ll data)
{
	lptr t=new lnode;
	t->data=data;
	t->next=l;
	l=t;
}
void print(lptr l)
{
	lptr t=l;
	while(t!=null){
		cout<<t->data<<" ";
		t=t->next;
	} 
}
void func(ll a[],ll i,ll p,lptr l)
{
	 	p=p*a[i];
	 	//cout<<"P ="<<p<<endl;
	  	if(p>0&&p<=k)
	  	{
	  	count1++;
	  	addend(l,p);
		for(ll j=i+1;j<n;j++)
	  	{
	  		func(a,j,p,l);
		}	  
		//	p1=p1*a[i];
		//	cout<<"p1= "<<p1<<endl;
//			if(p1<=k&&p1>0)
//			{
//				count1++;
//			}	
			p=p/a[i];
		}
}
int main()
{
	
	cin>>n>>k;
	ll i,j,a[n];
	lptr l;
	l=new lnode;
	l->data=-1;
	l->next=null;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<1;i++)
	{
	if(k>=a[i])
	func(a,i,1,l);
	}
	
	lptr t=l
	t=l->next;
	while(t!=null)
	{
		if()
	}
	print(l);
	
}
