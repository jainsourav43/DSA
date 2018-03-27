#include<iostream>
#define d 2
#include<algorithm>
#define null NULL
using namespace std;
typedef 
struct bnode
{
	bnode *par;
	int key[4];
	int tag;
	union un
	{
	bnode *ptr[5];
	bnode *ptr2;
    }ptr1;
	int count;
}*bptr;
struct queue
{
	int size;
	bptr element[60];
	int front;
	int rear;
};
void enque(queue &q,bptr x)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"Queue is overloaded\n";
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.element[q.rear]=x;
	}
}
bptr deque(queue &q)
{
	int  t;
	
	if(q.front==-1)
	{
		cout<<"Queue is Empty\n";
	}
	else
	{
		t=q.front;
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return q.element[t];
    }    	
}
bptr  search(bptr t,int k)
{
	if(t!=null)
	{
	if(t->tag==0)
	{
	int check =0,i;
	if(t->key[0]>k)
	{
	  if(t->tag==0&&t->ptr1.ptr[0]!=null)
	return search(t->ptr1.ptr[0],k);
	else
	return t;
	}
	else if(t->key[0]<k)
	{
	for( i=0;i<=t->count;i++)
	{
		if(t->key[i]<k)
		{
			if(t->tag==0&&t->ptr1.ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]>k)
			{ 
			return search(t->ptr1.ptr[i+1],k);
		}
			else if(t->tag==0&&t->ptr1.ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]<k&&i+2>=t->count+1&&t->ptr1.ptr[i+2]!=null)
			{
			  return search(t->ptr1.ptr[i+2],k);
		     }
			else if(t->tag==0&&t->ptr1.ptr[i+1]!=null&&i+1<=t->count&&t->key[i+1]<k&&i+2<=t->count)
			{  
			continue;
	      	}
			else if(t->tag==0&&t->ptr1.ptr[i+1]!=null)
			{ 
			return search(t->ptr1.ptr[i+1],k);
	       }
		}	
		else if(t->key[i]>=k)
		{
			check=1;
			return search(t->ptr1.ptr[i],k);
		}
         return t;
   }
  }	
}
else
{
	return t;
}
}
}
void print(bptr t,int m)
{	
	if(t!=null)
	{
	    int j,i;
		for(i=0;i<=t->count+1;i++)
		{
		print(t->ptr1.ptr[i],m);
	   	if(i<=t->count)
	   	{ 
		cout<<t->key[i]<<"  ";}
        }
	}
}
void printleaf(bptr t)
{
	if(t!=null)
	{
	for(int i=0;i<=t->count;i++)
	{
		cout<<t->key[i]<<"   ";
	}
	printleaf(t->ptr1.ptr[2*d]);
}
}
void printBplus(bptr t,int m)
{	
	  if(t!=null)
	  {
	  	while(t->ptr1.ptr[0]!=null)
		t=t->ptr1.ptr[0];
	   	printleaf(t);
	  }
}
void initialise(bptr &t)
{
	for(int i=0;i<=2*d;i++)
	{
		t->ptr1.ptr[i]=null;
	}
	t->count=-1;
}
void printlevel(bptr t,int m)
{
	if(t!=null)
	{
		queue q;
		q.front=-1;
		q.rear=-1;
		q.size=50;
		bptr t2,t3;
	     int i,c[20],f=0;
		enque(q,t);
		while(q.front!=-1)
		{
			f++;
			t2=deque(q);
			for(i=0;i<=t2->count;i++)
			{
				cout<<t2->key[i]<<"  ";
			}
			cout<<endl;
			for(i=0;i<=t2->count+1;i++)
			{
				if(t2->ptr1.ptr[i]!=null)
				{
					if(t2->ptr1.ptr[0]==null)
					continue;
					else
					enque(q,t2->ptr1.ptr[i]);
				}
			}
		}
	}
}
int search1(bptr t,int k)
{
	if(t!=null)
	{
		for(int i=0;i<=t->count+1;i++)
		{
			if(t->ptr1.ptr[i]->key[0]==k)
			return i;
		}
	}
}
bptr T;
void overflow(bptr &t,bptr lc,bptr rc,int k,int a[])
{
int i,j,l,che=0,b[5],che1=0;
if(t->par==null)
{cout<<"Overflow 1\n";
 bptr t2=new bnode;
 bptr t3=new bnode;
 initialise(t2);
 initialise(t3);
 t2->par=t;
 t3->par=t;
 int f=0;
  for(i=0;i<=2*d;i++)
  {
  	if(t->ptr1.ptr[i]!=null)
  	{
  		f=1;
	  }
  }
if(t->ptr1.ptr[0]==null)
{
  	t2->tag=1;
  	t3->tag=1;
  	t->tag=0;
 for(i=0;i<d;i++)
 {
 	t2->key[i]=a[i];
 }
 if(t->ptr1.ptr[0]==null)
 {
 for(i=d;i<=2*d;i++)
 t3->key[i-d]=a[i];
 t3->count=2;
}
 else
 {
 for(i=0;i<d;i++)
 t3->key[i]=a[i+d+1];
  t3->count=1;
}
 t2->count=1;
 t->key[0]=a[d];
 bptr t4 =t2,t5=t3;
t->key[0]=a[d];   
if(f==1)
t2->ptr1.ptr2=t3;
t3->ptr1.ptr2=null;
 t->count=0;
 t->par=null;t->key[0]=a[d];
 t->ptr1.ptr[0]=t2;  
 t->ptr1.ptr[1]=t3; 
 for(int i=2;i<=2*d;i++)
t->ptr1.ptr[i]=null;
t->key[0]=a[d];
}
else
{
 
  	t2->tag=0;
  	t3->tag=0;
  	t->tag=0;
 for(i=0;i<d;i++)
 {
 	t2->key[i]=a[i];
 }
 if(t->ptr1.ptr[0]==null)
 {
 for(i=d;i<=2*d;i++)
 t3->key[i-d]=a[i];
 t3->count=2;
}
 else
 {
 for(i=0;i<d;i++)
 t3->key[i]=a[i+d+1];
  t3->count=1;
}
 t2->count=1;
 t->key[0]=a[d];
 bptr t4 =t2,t5=t3;
  for(i=0;i<=d;i++)
 {
 	if(t2->key[i]!=k)
 	{
 		if(che==1)
 		t2->ptr1.ptr[i]=t->ptr1.ptr[i-d+1];
 		else
 		t2->ptr1.ptr[i]=t->ptr1.ptr[i];
 		if(t2->ptr1.ptr[i])
	 	t2->ptr1.ptr[i]->par=t4;
 		if(i+1==d&&t2->key[i]!=k)
 		{
 		t2->ptr1.ptr[i+1]=t->ptr1.ptr[i+1];
 		if(t2->ptr1.ptr[i])
	 	t2->ptr1.ptr[i]->par=t4;
 		i++;
 	    }
	 }
	 else
	 {
	 	che=1;
	 	t2->ptr1.ptr[i]=lc;
	 	if(t2->ptr1.ptr[i])
	 	t2->ptr1.ptr[i]->par=t4;
	 	t2->ptr1.ptr[i+1]=rc;
	 	if(t2->ptr1.ptr[i+1])
	 	t2->ptr1.ptr[i+1]->par=t4;
	 	i++;
	 }
 } 
t->key[0]=a[d]; 
 for(i=d;i<2*d;i++)
 {
 	if(t3->key[i-d]!=k)
 	{
 		if(che==1)
 		{
 		t3->ptr1.ptr[i-d]=t->ptr1.ptr[i]; 
 		if(t3->ptr1.ptr[i-d])
	 	t3->ptr1.ptr[i-d]->par=t5;
	    }
 		else
 		{
 		t3->ptr1.ptr[i-d]=t->ptr1.ptr[i+1]; //cout<<"else = t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr1.ptr[i-d])
	 	t3->ptr1.ptr[i-d]->par=t5;// cout<<" if  5= t3->key[0]  ="<<t3->key[0]<<endl;
		 }
 	
 		if(i+1==2*d&&t3->key[i]!=k)
 		{
 		t3->ptr1.ptr[i+1-d]=t->ptr1.ptr[i+1]; //cout<<"if 2 =t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr1.ptr[i+1-d])
	 	t3->ptr1.ptr[i+1-d]->par=t5; //cout<<"if 5 =t3->key[0]  ="<<t3->key[0]<<endl;
 		i++;
 	   }
	 }
	 else
	 {
	 	che1=1;
	 	t3->ptr1.ptr[i-d]=lc;
	 	if(t3->ptr1.ptr[i+1-d])
	 	t3->ptr1.ptr[i-d]->par=t5;
	 	t3->ptr1.ptr[i-d+1]=rc;
	 	if(t3->ptr1.ptr[i+1-d])
	 	t3->ptr1.ptr[i+1-d]->par=t5;
	 	i++;
	 }
 }
 if(che==0&&che1==0)
 {
 	t2->ptr1.ptr[d]=lc;
 	t3->ptr1.ptr[0]=rc;
 	for(int i=d;i<2*d;i++)
 	{
 		t3->ptr1.ptr[i-d+1]=t->ptr1.ptr[i+1];
	 }
 }  
if(t2->ptr1.ptr[0]==null)
t2->ptr1.ptr[2*d]=t3;
 t->count=0;
 t->par=null;t->key[0]=a[d];
 t->ptr1.ptr[0]=t2;  
 t->ptr1.ptr[1]=t3; 
 for(int i=2;i<=2*d;i++)
t->ptr1.ptr[i]=null;
t->key[0]=a[d]; 
}
}
else
{    
    cout<<"Overflow 2\n";
	bptr t2=new bnode,t3=new bnode;bptr t5;
//	t5=t;
	initialise(t2);
	initialise(t3);
	t2->par=t->par;
	t3->par=t->par;
	if(t->ptr1.ptr[0]==null)
	{
		t2->tag=1;
		t3->tag=1;
	for(i=0;i<d;i++)
	{
		t3->key[i]=a[i];
	}
	if(t->ptr1.ptr[0]==null)
	{cout<<"Enter 1 \n";
	for(i=d;i<=2*d;i++)
	{
	t2->key[i-d]=a[i];
	t2->count++;
	}
    }
	else
	{cout<<"Enter 2 \n";
	for(i=0;i<d;i++)
	{
	t2->key[i]=a[i+d+1];
	t2->count++;
	}
	}
	t3->count=1;
 int flag=0;
 if(t3->ptr1.ptr[0]==null)
 {
  flag=1;
 t3->ptr1.ptr[2*d]=t2;
 j=search1(t3->par,t3->key[0]);
 for(i=0;i<j;i++)
 {
 if(t3->par->ptr1.ptr[i]!=null)
 continue;
 else
 break;
} 		cout<<"T->par->kay= = "<<t->par->key[i]<<endl;

if(i-1>=0&&t3->par->ptr1.ptr[i-1])
{
 t3->par->ptr1.ptr[i-1]->ptr1.ptr2=t3;
 cout<<"Wekl\n"; 		cout<<"T->par->kay=  "<<t->par->key[i]<<endl;

}
}
for(i=3;i<=2*d;i++)
 {
   if(i<2*d||(i==2*d&&flag==0))
   {
   t3->ptr[i]=null;
}
   t2->ptr[i]=null;
}//t=t5;
}
else
{
	t2->tag=0
	t3->tag=0;
	for(i=0;i<d;i++)
	{
		t3->key[i]=a[i];
	}
	if(t->ptr1.ptr[0]==null)
	{cout<<"Enter 1 \n";
	for(i=d;i<=2*d;i++)
	{
	t2->key[i-d]=a[i];
	t2->count++;
	}
    }
	else
	{cout<<"Enter 2 \n";
	for(i=0;i<d;i++)
	{
	t2->key[i]=a[i+d+1];
	t2->count++;
	}
	}
	bptr t4 =t2,t5=t3;
  for(i=0;i<=d;i++)
 {
 	if(t2->key[i]!=k)
 	{
 		if(che==1)
 		t2->ptr1.ptr[i]=t->ptr1.ptr[i-d+1];
 		else
 		t2->ptr1.ptr[i]=t->ptr1.ptr[i];
 		if(t2->ptr1.ptr[i])
	 	t2->ptr1.ptr[i]->par=t4;
 		if(i+1==d&&t2->key[i]!=k)
 		{
 		t2->ptr1.ptr[i+1]=t->ptr1.ptr[i+1];
 		if(t2->ptr1.ptr[i])
	 	t2->ptr1.ptr[i]->par=t4;
 		i++;
 	    }
	 }
	 else
	 {
	 	che=1;
	 	t2->ptr1.ptr[i]=lc;
	 	if(t2->ptr1.ptr[i])
	 	t2->ptr1.ptr[i]->par=t4;
	 	t2->ptr1.ptr[i+1]=rc;
	 	if(t2->ptr1.ptr[i+1])
	 	t2->ptr1.ptr[i+1]->par=t4;
	 	i++;
	 }
 } 
 for(i=d;i<2*d;i++)
 {
 	if(t3->key[i-d]!=k)
 	{
 		if(che==1)
 		{
 		t3->ptr1.ptr[i-d]=t->ptr1.ptr[i]; 
 		if(t3->ptr1.ptr[i-d])
	 	t3->ptr1.ptr[i-d]->par=t5;
	    }
 		else
 		{
 		t3->ptr1.ptr[i-d]=t->ptr1.ptr[i+1]; //cout<<"else = t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr1.ptr[i-d])
	 	t3->ptr1.ptr[i-d]->par=t5;// cout<<" if  5= t3->key[0]  ="<<t3->key[0]<<endl;
		 }
 	
 		if(i+1==2*d&&t3->key[i]!=k)
 		{
 		t3->ptr1.ptr[i+1-d]=t->ptr1.ptr[i+1]; //cout<<"if 2 =t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr1.ptr[i+1-d])
	 	t3->ptr1.ptr[i+1-d]->par=t5; //cout<<"if 5 =t3->key[0]  ="<<t3->key[0]<<endl;
 		i++;
 	   }
	 }
	 else
	 {
	 	che1=1;
	 	t3->ptr1.ptr[i-d]=lc;
	 	if(t3->ptr1.ptr[i+1-d])
	 	t3->ptr1.ptr[i-d]->par=t5;
	 	t3->ptr1.ptr[i-d+1]=rc;
	 	if(t3->ptr1.ptr[i+1-d])
	 	t3->ptr1.ptr[i+1-d]->par=t5;
	 	i++;
	 }
 }
 if(che==0&&che1==0)
 {
 	t2->ptr1.ptr[d]=lc;
 	t3->ptr1.ptr[0]=rc;
 	for(int i=d;i<2*d;i++)
 	{
 		t3->ptr1.ptr[i-d+1]=t->ptr1.ptr[i+1];
	 }
 }
}
 if(t->par->count==3)
 {
 	    for(i=0;i<4;i++)
      	b[i]=t->par->key[i];
      	b[4]=a[d];
      	sort(b,b+5);
      	overflow(t->par,t3,t4,a[d],b);
 }
 else
 {
 	for(i=t->par->count;i>=0;i--)
 	{
 		cout<<"T->par->kay=  "<<t->par->key[i]<<endl;
 		if(t->par->key[i]>a[d])
 		{
 			t->par->key[i+1]=t->par->key[i];
 			t->par->ptr[i+2]=t->par->ptr[i+1];
		 }
		 else
		 {
		 	break;
		 }
 		
	 }
	 t->par->key[i+1]=a[d];
	 t->par->ptr[i+1]=t3;
	 t->par->ptr[i+2]=t2;
	 t->par->count++;
 } 
}
}
void add(bptr &t1,int k)
{
	int i;
	bptr t=search(t1,k);
	bptr temp=t->ptr1.ptr[2*d];int flag=0;
	if(t->ptr[0]==null)
	 flag=1;
	if(t->count<2*d-1)
	{
	for( i=t->count;i>=0;i--)
		{
		if(t->key[i]>k)
			{
				t->key[i+1]=t->key[i];
				t->ptr[i+2]=t->ptr[i+1];
			}
			else
			{
				break;
			}
		}
		t->key[i+1]=k;
		t->count++;
		t->ptr[i+2]=t->ptr[i+2];
		t->ptr[i+1]=t->ptr[i+1];
		if(flag==1)
		{
			t->ptr[2*d]=temp;
		 }
	}
	else 
	{		int a[5];
		for(int i=0;i<2*d;i++)
		{
            a[i]=t->key[i];
		}
		a[4]=k;
		sort(a,a+5);
		overflow(t,null,null,a[d],a);
	}
}
int main()
{
	bptr t=null;
	t=new bnode;
	int n=1;
	t->par=null;
	cout<<"Enter the no. to add else -1\n";
	cin>>n;
	t->count=0;
	t->key[0]=n;
	t->tag=1;
	t->ptr1.ptr2=null;
	while(n!=14)
	{
	//cout<<"Enter the no. to add else -1\n";
  //  cin>>n;
        if(n!=-1)
		add(t,n);
		//print(t,2*d);	
		printBplus(t,2*d);
		cout<<"\nLevel order ::"<<endl;
		printlevel(t,2*d);n++;
	}
	return 0;
}
