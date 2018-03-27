#include<iostream>
#include<algorithm>
#define null NULL
char a2[30];
using namespace std;
typedef
struct node
{
	int fr;
	char da;
	struct node *next;
} *lptr;
typedef
struct hmnode
{
   hmnode *lchild;
   char  data;
   hmnode *rchild;
   int wt;
    
} *hmptr;
hmptr ans;
void ldr(hmptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		cout<<t->wt<<"    ";
		cout<<endl;
		ldr(t->rchild);
	}
}
int check(hmptr t1[],int w,int i)//using this whether t[2]or t[3] or etc should come
{
	for(int j=0;j<i;j++)
	{
		if(t1[j]->wt==w)
		{
			return j;
		}
	}
}
void display(lptr l)//display for linked list
{
	lptr t=l;
	while(t!=NULL)
	{		cout<<t->da<<"   ";	

		cout<<t->fr<<" ";
		t=t->next;
	}cout<<endl;	
}
void addbegin(lptr &l1,int a,char c)
{
	   lptr t;//cout<<"!! \n";
      	t=new node;
		t->fr=a;
		t->da=c;
		t->next=l1;
		l1=t;
}
lptr deleteend(lptr l)
{
lptr t,t3;//cout<<"DELETE ENd\n";
t=l;
if(t->next==null)
{t3=t;
t=null;
	return t3;
}
else
{
	while(t->next->next!=NULL)
	{//cout<<"While end \n";
		t=t->next;
	}
	lptr t2;//cout<<"@\n";
	t2=t->next;//cout<<"##\n";
	t->next=NULL;//cout<<"$$\n";
	return (t2);
}	//delete(t2);
}
void addprior(lptr l,int a,char c)//adding to the linked list a/c to the priority or decreasing order
{  // cout<<"ADD PRIOR\n";
	lptr t=l,t1,t2;
	if(t->next==null)
	{
		t2=t->next;
		t->next=new node;
		t=t->next;
	    t->fr=a;
		t->da=c; 
		t->next=t2;
	}
	else
	{
	while(t->next!=null&&t->next->fr>a)
		{
			t=t->next;
		}
		t2=t->next;
		t->next=new node;
		t=t->next;
	    t->fr=a;
		t->da=c; 
		t->next=t2;
   }
    }
void deleteend1(lptr l)
{
    lptr t;
    t=l;
	while(t->next->next!=NULL)
	{
		t=t->next;
	}
	lptr t2;
	t2=t->next;
	t->next=NULL;
	delete(t2);
}
void create(hmptr t1)
{
	int n;int chk;
    cout<<"enter the no of elements \n";
	cin>>n;
	hmptr t[n-1],t2,t3;
	char ch[n];
	lptr l=null,l1,l2;
	int a[n],i;
	for (i=0;i<n;i++)
	{
	  cout<<"Enter the elements and its frequency\n";
	  cin>>ch[i];
	  cin>>a[i];
    }
   for(i=0;i<n;i++)
   {
    if(l==null)
    {
    	    addbegin(l,a[i],ch[i]);
	}
    else if(l->fr<a[i])
        addbegin(l,a[i],ch[i]);
else
   	addprior(l,a[i],ch[i]);
   }
   display(l);
   for(i=0;i<n-1;i++)
   {
   	t[i]=new hmnode;
   	l1=deleteend(l);//cout<<"l1->data   "<<l1->da<<"  ";
   	l2=deleteend(l);//cout<<"l2 ->data"<<l2->da<<"   ";
   	t2=new hmnode;
   	t2->wt=l1->fr;
   	t2->data=l1->da;
   	if(l1->da!='.')
   	{
   	t2->lchild=null;
   	t2->rchild=null;
     }
    
   	//addprior(l,t[i]->wt,t[i]->data);
   	t3=new hmnode;
   	t3->data=l2->da;
   	t3->wt=l2->fr;
   	if(l2->da!='.')
   	{
   	t3->lchild=null;
   	t3->rchild=null;
     }
   	t[i]->data='.';//using . to differ the leaf and non leaf
   	t[i]->wt=t2->wt+t3->wt;//cout<<"Total wt  "<<t[i]->wt<<"   ";
   	if(l2->da=='.'&&l1->da=='.')
   	{
		   chk=check(t,l2->fr,i);
		   t[i]->rchild=t[chk];
		   chk=check(t,l1->fr,i);
		   t[i]->lchild=t[chk];
	}	
	else if(l2->da=='.')
	{
		chk=check(t,l2->fr,i);
     t[i]->rchild=t[chk];
	}
	else if(l1->da=='.')
	{
		chk=check(t,l1->fr,i);
		t[i]->lchild=t[chk];
	}
	if(l1->da!='.')
	{
	 t[i]->lchild=t2;
	}
	if(l2->da!='.')
	{
		t[i]->rchild=t3;
	}
   	if(l->fr<t[i]->wt||i==n-2)
   	addbegin(l,t[i]->wt,t[i]->data);
   	   	else 
   	addprior(l,t[i]->wt,t[i]->data);
   }
   ans=t[n-2];
}
void entode(hmptr t,char str[])
{
	hmptr t1,t2;
	t1=t;int i=0;
	while(str[i]!='\0')
	{
	    t1=t;//cout<<"%%\n";
		while(t1->data=='.')
		{
		if(str[i]=='1'&&t1->data=='.')
		{
			t1=t1->rchild;
			i++;
		}
		else
		if(str[i]=='0'&&t1->data=='.')
		{
			t1=t1->lchild;
			i++;
		}
	    }
	    cout<<t1->data;
	}
}
void dlr(hmptr t,int i,char e)
{
	    static char a2[40];
        if(t!=null)
        {
        if(t->lchild!=null)
        a2[i]='0';i++;
		dlr(t->lchild,i,e);
		i--;
		if(t->data==e)
        {
		for( int j=0;j<i;j++)
		{
		   cout<<a2[j];
		}
		cout<<endl;
		}
		if(t->rchild!=null)
			a2[i]='1';i++;
		dlr(t->rchild,i,e);
		i--;
	   }
}
int main()
{
	hmptr t1=null;int n,i;
	create(t1);  
	ldr(ans);char str[50];
	cout<<"enter the encoded data\n";
	cin>>str;
	entode(ans,str);//using this function to decode the data
	cout<<endl;
	cout<<"enter the sting in decode\n";
	cin>>str;//cout<<"   "<<str<<" ";
	cout<<endl;
	while(str[i]!='\0')
	{
	dlr(ans,0,str[i]);//using dlr to encode the data
	i++;
    }
}
