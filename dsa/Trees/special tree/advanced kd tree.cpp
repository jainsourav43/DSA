#include<iostream>
#define null NULL
using namespace std;
int j=0;
union u 
{
	int a;
	char b;
};
struct si
{
	int tag;
	u u1;
};
typedef
struct kdnode
{
	kdnode *lchild;
	si st[10];
	kdnode *rchild;
} *kdptr;
void ldr(kdptr t,int n)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{
		ldr(t->lchild,n);
		cout<<"(";
		for(int i=0;i<n;i++)
		{
			if(t->st[i].tag==1)
			{
				cout<<t->st[i].u1.a<<"   ";
			}
			else if(t->st[i].tag==2)
			{
				cout<<t->st[i].u1.b<<"   ";
			}
	    }
	    cout<<")";
		ldr(t->rchild,n);
	}
}
void insert(kdptr &t, struct si d[],int n)
{
	if(t==null)
	 {
	    //cout<<"NULL\n";
		t=new kdnode;
		for(int s=0;s<n;s++)
		{
		 if(d[s].tag==1)
		 {
		 	t->st[s].tag=1;
		 	t->st[s].u1.a=d[s].u1.a;//cout<<"d[s].u1.a;"<<d[s].u1.a<<"  ";
		 }
		 else if(d[s].tag=2)
		 {
		 	t->st[s].tag=2;
		 	t->st[s].u1.b=d[s].u1.b;//cout<<"d[s].u1.b;"<<d[s].u1.b<<"  ";
		 }
		}
		t->lchild=null;
		t->rchild=null;
	}
	else if(t->st[j].tag==1)
	{
	 if(t->st[j].u1.a>d[j].u1.a)
	{
		j=(j+1)%n;
		insert(t->lchild,d,n);
	}
	else if(t->st[j].u1.a<d[j].u1.a)
	{
		j=(j+1)%n;
		insert(t->rchild,d,n);
	}
   }
   else if(t->st[j].tag=2)
   {
    if(t->st[j].u1.b>d[j].u1.b)
	{
		j=(j+1)%n;
		insert(t->lchild,d,n);
	}
	else if(t->st[j].u1.b<d[j].u1.b)
	{
		j=(j+1)%n;
		insert(t->rchild,d,n);
	}
   
}
}
int  search(kdptr t,si d[],int n)
{
	if(t==null)
	return 0;
	if(t->st[j].tag==1)
	{//cout<<"IF tag =1\n";
	 if(t->st[j].u1.a>d[j].u1.a)
	{
		j=(j+1)%n;
		return search(t->lchild,d,n);
	}
	else if(t->st[j].u1.a<d[j].u1.a)
	{//cout<<"else   tag =1 \n";
		j=(j+1)%n;
		return search(t->rchild,d,n);	
	}
	else
	{//cout<<"else 2   tag =1 \n";
		return 1;
	}	
  }
  else
  {
  	if(t->st[j].u1.b>d[j].u1.b)
	{
		j=(j+1)%n;//cout<<"if tag =2 \n";
		return search(t->lchild,d,n);
	}
	else if(t->st[j].u1.b<d[j].u1.b)
	{
		j=(j+1)%n;cout<<"else   tag =2 \n";
		return search(t->rchild,d,n);	
	}
	else
	{//cout<<"else  2  tag =2 \n";
		return 1;
	}
  }
}
int main()
{
	kdptr t=null;
	int n=1,i;
	cout<<"enter the no. of elements else -1\n";
	cin>>n;
	si s1[n],s3[n];int a1,k;int co=1;
	char ch,g;s1[0].tag=1;
	while(co!=-1)
	{
		cout<<"ENTER THE ELEMENTS\n";
			cout<<"Enter 1 for continue else -1\n";
			cin>>co;
		for(i=0;i<n&&co!=-1;i++)
		{
		
			if(co!=-1)
			{
			cout<<"ENtre 1 for int and 2 char \n";
			cin>>s1[i].tag;
			if(s1[i].tag==1)
            {
            	cin>>a1;
            	s1[i].u1.a=a1;
			}
			else if(s1[i].tag==2)
			{
				cin>>ch;
				s1[i].u1.b=ch;
				
			}
		  }
		}j=0;
		if(co!=-1)
		insert(t,s1,n);
    }
    j=0;
    cout<<"Enter the key  no. to be searched\n";
    for(i=0;i<n;i++)
     {
     	cout<<"Enter the tag\n";
     	cin>>s3[i].tag;
     	if(s3[i].tag==1)
        {
        	cin>>s3[i].u1.a;
		}
		else
		{
			cin>>s3[i].u1.b;
		}
	 }
    int ans=search(t,s3,n);
    if(ans)
    {
    	cout<<"THE KEY IS PRESENT IN THE TREE \n";
	}
	else
	{
		cout<<"THE KEY IS NOT PRESENT IN THE TREE \n";
	}
	ldr(t,n);
	return 0;
}

