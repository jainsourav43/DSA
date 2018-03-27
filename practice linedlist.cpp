#include<iostream>
#define null NULL
using namespace std;
typedef
struct gnode
{
	int data;
	int count ;
	gnode **next;
}*gptr ;
typedef
struct node
{
	int data;
	node* next;
} *lptr;
typedef
struct pnode
{
	int data;
	int expo;
	pnode* next;
}*pptr;
void ratate(lptr &l,int k)
{
	lptr prevhead=l,temp1=l,t1=l,t2;
	int i=1;
	while(i<k)
	{
		t1=t1->next;
		i++;
	}
	lptr newhead=t1->next;
	t2=newhead;
	t1->next=NULL;
	while(t2&&t2->next)
	{
		t2=t2->next;
	}
	t2->next=prevhead;
	l=newhead;
	
}



void print(gptr g,int co)
{
	static int a[40];
	if(g!=null)
	{
		
		//cout<<g->data<<"  ";
		a[co++]=g->data;
		if(g->count==0)
		{
			for(int i=0;i<co;i++)
			cout<<a[i]<<" "; cout<<endl;
		}
		for(int i=0;i<g->count;i++)
		{
			print(g->next[i],co);
		}
		
			//cout<<endl;
	}
//	else

}
void create(gptr &g)
{
	if(g==null)
	{
		g=new gnode;
		cout<<"Enter the data \n";
		cin>>g->data;
		cout<<"Enter the count \n";
		cin>>g->count;
		g->next=new gnode*[g->count];
		for(int i=0;i<g->count;i++)
		{
			int da;
			g->next[i]=null;
			cout<<"Enter the data at "<<g->data<<endl;
			create(g->next[i]);
		}
	}
}
void removedulli(lptr &l)
{
	lptr t=l,temp,prev=l,next,prev2=l;
	int count1=0,count=0;
	while(t&&t->next)
	{	
		int check=0;
		count1++;
		count=0;
		while(t&&t->next&&t->data==t->next->data)
		{
			//t->next=t->next->next;
			t=t->next;
			count++;
		}
	//	temp=t;
		next=t->next;
		if((prev==l&&count>=1)||count1==1&&count>=1)
		{
			l=t->next;
		//	cout<<"HII\n";
		}
		 else if(count>=1)
		{
			prev2->next=t->next;
			check=1;
		}
		//temp->next=t->next;
		if(check==0)
		prev2=t;
		t=next;
		prev=t;
		
	}
}
void create(lptr &l)
{
	if(l==null)
	{
		int temp;
		cout<<"Enter the new data  else -1\n";
		cin>>temp;
		if(temp==-1)
		return;
		l=new node;
		l->data=temp;
		l->next=null;
	}
	int choice =1;
//	cout<<"Enter 1  for continue else -1\n";
//	cin>>choice;
//	if(choice!=-1)
//	{
		create(l->next);
//	}
	
}
void create(pptr &l)
{
	if(l==null)
	{
		int temp;
		cout<<"Enter the new data  else -1\n";
		cin>>temp;
		if(temp==-1)
		return;
		l=new pnode;
		l->data=temp;
		cout<<"Enter the expo\n";
		cin>>temp;
		l->expo=temp;
		l->next=null;
	}
	int choice =1;
//	cout<<"Enter 1  for continue else -1\n";
//	cin>>choice;
//	if(choice!=-1)
//	{
		create(l->next);
//	}
	
}
void print(lptr l)
{
	if(l!=null)
	{
		cout<<l->data<<" ";
		print(l->next);
	}
}
void deletedata(lptr l,int data)
{
	lptr t=l;
	while(t&&t->data!=data)
	{
	//	cout<<"t "<<t->data<<endl;
		t=t->next;
	}
	lptr t2=t->next;
	t->next=t->next->next;
//	delete t2;
	print(l);
	
}
void print(pptr l)
{
	if(l!=null)
	{
		if(l->next!=null)
		cout<<l->data<<"x^"<<l->expo<<"+";
		else
		cout<<l->data<<"x^"<<l->expo;
		print(l->next);
	}
}
void addbegin(lptr &l,int data)
{
//	cout<<"hii\n";
	lptr t=new node;
	t->data=data;
	t->next=l;
	l=t;
}

void addbefore(lptr &l,int data1 ,int data)
{
	lptr t=l;
	if(t->data==data)
	{
		addbegin(l,data1);
	}
	else
	{
		while(t&&t->next&&t->next->data!=data)
		{
			t=t->next;
			
		}
		lptr t2=t->next;
		t->next=new node;
		t=t->next;
		t->data=data1;
		t->next=t2;
	}	//print(l);
//	cout<<"addbegin\n";
}
void deleteatpos(lptr l,lptr p)
{
lptr t1;
t1=l;
while(t1->next!=p)
{
	t1=t1->next;
}
if(t1->next->next!=NULL)
t1->next=t1->next->next;
else
{
	t1->next=NULL;
}

}
void insertionsort(lptr &l,lptr l1)
{
	lptr t1=l;
	lptr t2=l1;
	
//	while(t2)
//	{
		if(t2)
		{
		t1=l;
		lptr t3=t2;
		//cout<<"t2->data= "<<t2->data<<" ";
		
		while(t1!=t2)
		{
		//	cout<<"byee\n";
		//	cout<<"t1->dtaa="<<t1->data<<" ";
			if(t2->data<t1->data)
			{
				addbefore(l,t2->data,t1->data);
			    deleteatpos(l,t3);
			//	deletedata(l,t1->data);
				//t2=t3;
				break;
			}
			t1=t1->next;
		}
	//	t2=t2->next;
	///	cout<<"hey\n";
	//}
	insertionsort(l,t2->next);
}
}
void UnionAndIntersection(lptr l1,lptr l2)
{
		lptr t1=l1,t2=l2;
	lptr union2=null,inter1=null;
	lptr inter=inter1;
	union2=new node;
	union2->data=t1->data;
	union2->next=null;
	t1=t1->next;
	lptr union1=union2;

	while(t1!=null)
	{
		union1->next=new node;
		union1=union1->next;
		union1->data=t1->data;
		union1->next=null;
		t1=t1->next;
	}
	t1=l1;
	while(t2!=null)
	{
		t1=l1;
		while(t1!=null)
		{
			if(t1->data==t2->data)
			{
				break;
			}
			t1=t1->next;
		}
		if(t1==null)
		{
			union1->next=new node;
			union1=union1->next;
			union1->data=t2->data;
			union1->next=null;
		}
		t2=t2->next;
	}
	print(union2);
	t2=l2;t1=l1;
	int flag=0;
	while(t2!=null)
	{
		t1=l1;
		
		while(t1!=null)
		{
			if(t1->data==t2->data)
			{
				flag++;
				break;
			}
			t1=t1->next;
		}
		if(t1!=null)
		{
			if(flag==1)
			{
				cout<<"Creating first \n";
				inter=new node;
				inter1=inter;
				inter->next=null;
				inter->data=t2->data;
			}
			else
			{
					cout<<"Creating \n";
			inter->next=new node;
			inter=inter->next;
			inter->data=t2->data;
			inter->next=null;
			}
		}
		
		t2=t2->next;
	}
	cout<<"printing inter\n";
	print(inter1);
	cout<<endl;
}
void polynomial(pptr l1,pptr l2)
{
	int flag=0;
	pptr result1=null;
	pptr t1=l1,t2=l2,result=null;
	if(t1==null&&t2==null)
	result=null;
	else if(t1==null)
	result=t2;
	else if(t2==null)
	result=t1;
	else{
	
	while(t1!=null&&t2!=null)
	{
		flag++;
		if(t1->expo>t2->expo)
		{
			if(flag==1)
			{
			result=new pnode;
			result1=result;
			result->data=t1->data;
			result->expo=t1->expo;
			result->next=null;
			}
			else
			{
				result->next=new pnode;
				result=result->next;
				result->data=t1->data;
				result->expo=t1->expo;
				result->next=null;
			}
			t1=t1->next;
			
		}
		else if(t2->expo>t1->expo)
		{
			if(flag==1)
			{
			result=new pnode;
				result1=result;
			result->data=t2->data;
			result->expo=t2->expo;
			result->next=null;
			}
			else
			{
				result->next=new pnode;
				result=result->next;
				result->data=t2->data;
				result->expo=t2->expo;
				result->next=null;
			}
			t2=t2->next;
		}
		else
		{
			if(flag==1)
			{
				result=new pnode;
					result1=result;
				result->data=t1->data+t2->data;
				result->expo=t1->expo;
				result->next=null;
			}
			else
			{
				result->next=new pnode;
				result=result->next;
				result->data=t1->data+t2->data;
				result->expo=t1->expo;
				result->next=null;
			}
			t1=t1->next;
			t2=t2->next;
		}
	}
	while(t2!=null)
	{
		result->next=new pnode;
		result=result->next;
		result->data=t2->data;
		result->expo=t2->expo;
		result->next=null;
		t2=t2->next;
	}
	while(t1!=null)
	{
		result->next=new pnode;
		result=result->next;
		result->data=t1->data;
		result->expo=t1->expo;
		result->next=null;
		t1=t1->next;
			
	}
}
if(result1)
result=result1;
	print(result);
	
}
void insertiosort(lptr &l)
{
	lptr t1=l;
	lptr t2=l->next;
	
	while(t2)
	{
		t1=l;
		lptr t3=t2;
		//cout<<"t2->data= "<<t2->data<<" ";
		
		while(t1!=t2)
		{
		//	cout<<"byee\n";
		//	cout<<"t1->dtaa="<<t1->data<<" ";
			if(t2->data<t1->data)
			{
				addbefore(l,t2->data,t1->data);
			    deleteatpos(l,t3);
			//	deletedata(l,t1->data);
				//t2=t3;
				break;
			}
			t1=t1->next;
		}
		t2=t2->next;
	///	cout<<"hey\n";
	}
}

int main()
{
	gptr g=null;
	lptr l=null;
//	create(g);
cout<<"Creating l1\n";
	create(l);
	pptr l1=null;
	ratate(l,4);
	print(l);
	//cout<<"Creating l2\n";
	//create(l1);
//	cout<<"printing l1\n";
//	print(l);
//	cout<<endl;
//	cout<<"Printing L2\n";
//	print(l1);
//	cout<<endl;
//	cout<<"Sorted List is: \n";
//	insertionsort(l,l->next);
//	print(l);
//	cout<<endl;
//	cout<<"Printing UNion\n";
//	UnionAndIntersection(l,l1);
//	cout<<"result of Polynomials\n";
//	polynomial(l,l1);
//	removedulli(l);
//	print(l);
	//print(g,0);
}
