#include<iostream>
#include<algorithm>
#define d 2
#define null NULL
using namespace std;
typedef
struct bnode
{
	int key[2*d];
	bnode *ptr[2*d+1];
	int count;
	bnode *par;
} *bptr;
struct queue
{
	bptr element[50];
	int front;
	int rear;
	int size;
};
void enque(queue &q,bptr x)
{
	if((q.rear+1)%q.size==q.front)
	{
	//	cout<<"Overflow\n";
	}
	else
	{
		if(q.front==-1)
		{
			q.front=0;
		}
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
void printlevel(bptr t)
{
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=50;
	enque(q,t);
	bptr t2;int i;
	while(q.front!=-1)
	{
		t2=deque(q);
		for( i=0;i<=t2->count;i++)
		{
			cout<<t2->key[i]<<"  ";
		}cout<<endl;
		for(i=0;i<=2*d;i++)
		{
			if(t2->ptr[i]!=null)
			{
				enque(q,t2->ptr[i]);
			}
		}
	}
}
void print(bptr t)
{
	if(t!=null)
	{int i;
		for(i=0;i<=2*d;i++)
		{
		print(t->ptr[i]);
		if(i<=t->count)
		cout<<t->key[i]<<"  ";
	}
	}
}
void initialise(bptr &t)
{
	t->count=-1;
    for(int i=0;i<=2*d;i++)
    {
    	t->ptr[i]=null;
	}
}
bptr  search(bptr t,int k)
{
	if(t!=null)
	{
	int check =0,i;
	if(t->key[0]>k)
	{  
	  if(t->ptr[0]!=null)
	return search(t->ptr[0],k);
	else
	return t;
	}
	else if(t->key[0]<k)
	{
	for( i=0;i<=t->count;i++)
	{
		if(t->key[i]<k)
		{
			if(t->ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]>k)
			{ 
			return search(t->ptr[i+1],k);
		    }
			else if(t->ptr[i+1]!=null&&i+1>=t->count&&t->key[i+1]<k&&i+2>=t->count+1&&t->ptr[i+2]!=null)
			{
			  return search(t->ptr[i+2],k);
		     }
			else if(t->ptr[i+1]!=null&&i+1<=t->count&&t->key[i+1]<k&&i+2<=t->count)
			{  //cout<<"COME3\n";
			continue;
	      	}
			else if(t->ptr[i+1]!=null)
			{  //cout<<"COME4\n";
			return search(t->ptr[i+1],k);
	       }
		}	
		else if(t->key[i]>=k)
		{
		  //  cout<<"@ ELSE IF \n";
			check=1;
			return search(t->ptr[i],k);
		}
	//	cout<<"t->key[0]"<<t->key[0]<<endl;
         return t;
   }
  }	
//cout<<"END\n";
}
}
void overflow(bptr &t,bptr lc,bptr rc,int k,int a[])
{
	int i,j,l,m,n,che=0,che1=0,b[2*d+1];
	if(t->par==null)
	{
	    bptr t2=new bnode;
	    bptr t3=new bnode;
	    initialise(t2);
	    initialise(t3);
	    for(i=0;i<d;i++)
	    t2->key[i]=a[i];cout<<"t3->key[0]   = "<<t3->key[0]<<endl; 
	    for(i=0;i<d;i++)
	    t3->key[i]=a[i+d+1];cout<<"t2->key[0] = "<<t2->key[0]<<endl;cout<<"t2->key[0] = "<<t2->key[1]<<endl;
	    t3->par=t;
	    t2->par=t;
	    t3->count=1;
	    t2->count=1; //t->key[0]=a[d];

	    t->count=0;//cout<<"t-ptr[0]= "<<t->ptr[0]<<endl;
	    		bptr t4=t2,t5=t3;

	    for(i=0;i<=d;i++)
	    {
	    	if(t2->key[i]!=k)
	    	{
	    		if(che==1)
	    		{
	    			t2->ptr[i]=t->ptr[i-d+1];
				}
	             else 
	             {//cout<<"come\n";
	             	t2->ptr[i]=t->ptr[i];
				 }
				 if(t2->ptr[i])
	 	         t2->ptr[i]->par=t4;
				 if(i==d-1&&t2->key[i]!=k)
				 {
				 	t2->ptr[i+1]=t->ptr[i+1];
				 	i++;
				 	if(t2->ptr[i+1])
	 				t2->ptr[i+1]->par=t4;
				 }
			}
			else  if(t2->key[i]==k)
			{
				t2->ptr[i]=lc;
				if(t2->ptr[i])
	 	       t2->ptr[i]->par=t4;
				if(lc)
				lc->par=t4;
				t4->ptr[i+1]=rc;
				
				if(rc)
				rc->par=t4;
				if(t2->ptr[i+1])
	 			t2->ptr[i+1]->par=t4;
				i++;
				che=1;
			}
		}//cout<<"YYY\n";cout<<t3->ptr[0]<<"   t3-ptr  "<<t->ptr[0];
for(i=d;i<2*d;i++)
 {
 	if(t3->key[i-d]!=k)
 	{
 		if(che==1)
 		{
 		t3->ptr[i-d]=t->ptr[i]; //cout<<"if  =t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr[i-d])
	 	t3->ptr[i-d]->par=t5; //cout<<"if  6 = t3->key[0]  ="<<t3->key[0]<<endl;
	    }
 		else
 		{
 		t3->ptr[i-d]=t->ptr[i+1]; //cout<<"else = t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr[i-d])
	 	t3->ptr[i-d]->par=t5;// cout<<" if  5= t3->key[0]  ="<<t3->key[0]<<endl;
		 }
 	
 		if(i+1==2*d&&t3->key[i]!=k)
 		{
 		t3->ptr[i+1-d]=t->ptr[i+1]; //cout<<"if 2 =t3->key[0]  ="<<t3->key[0]<<endl;
 		if(t3->ptr[i+1-d])
	 	t3->ptr[i+1-d]->par=t5; //cout<<"if 5 =t3->key[0]  ="<<t3->key[0]<<endl;
 		i++;
 	    }
	 }
	 else
	 {
	 	che1=1;
	 	t3->ptr[i-d]=lc;// cout<<" lc =t3->key[0]  ="<<t3->key[0]<<endl;
	 	if(t3->ptr[i+1-d])
	 	t3->ptr[i-d]->par=t5;
	 	t3->ptr[i-d+1]=rc;// cout<<" rc =t3->key[0]  ="<<t3->key[0]<<endl;
	 	if(t3->ptr[i+1-d])
	 	t3->ptr[i+1-d]->par=t5;// cout<<"t3->key[0]  ="<<t3->key[0]<<endl;
	 	i++;
	 }
 }//cout<<"YYY\n";
			cout<<"t2->key[0] = "<<t2->key[0]<<endl;
		 if(che==0&&che1==0)
		 {
		 	t2->ptr[d]=lc;
		 	t3->ptr[0]=rc;
		 	for(int i=d;i<2*d;i++)
		 	{
		 	t3->ptr[i-d+1]=t->ptr[i+1];
			}
		 }//cout<<"ll\n";
		 	cout<<"t2->key[0] ff= "<<t2->key[0]<<endl;
		 t->key[0]=a[d];
		 t->count=0;
		 t->par=null;
	     t->ptr[0]=t2;
	     t->ptr[1]=t3;	cout<<"t2->key[0]fg = "<<t3->key[0]<<endl;
	     cout<<"t->ptr[0]->key[0] = "<<t->ptr[0]->key[0]<<endl;
	     cout<<"t->ptr[1]->key[0] = "<<t->ptr[1]->key[0]<<endl;
		 cout<<"t2 = ->"<<t2->key[0]<<"  "<<t3->key[0]<<endl;
 		 for(i=d;i<=2*d;i++)
		  t->ptr[i]=null;
 
	}
	else
	{cout<<"Overflow\n";
		bptr t2=new bnode;
		initialise(t2);
		for(i=0;i<d;i++)
	    t->key[i]=a[i];
	    for(i=0;i<d;i++)
	    t2->key[i]=a[i+d+1];
	    t2->par=t->par;
	    t->count=1;
	    t2->count=1;
	     for(i=0;i<=d;i++)
	    {
	    	if(t->key[i]!=k)
	    	{
	    		if(che==1)
	    		{
	    			t->ptr[i]=t->ptr[i-d+1];
				}
	             else 
	             {
	             	t->ptr[i]=t->ptr[i];
				 }
				 if(i==d-1&&t->key[i]!=k)
				 {
				 	t->ptr[i+1]=t->ptr[i+1];
				 	i++;
				 }
			}
			else  if(t->key[i]==k)
			{
				t->ptr[i]=lc;
				if(lc)
				lc->par=t;
				t->ptr[i+1]=rc;
				if(rc)
				rc->par=t;
				i++;
				che=1;
			}
		}
		for(i=0;i<=d;i++)
		{
			if(t2->key[i]!=k)
			{
				if(che==0&&che1==0&&i+1+d<=4)
				t2->ptr[i]=t->ptr[i+1+d];
				else
				t2->ptr[i]=t->ptr[i+d];
				if(i==d-1&&t2->key[i]!=k)
				{
					t2->ptr[i+1]=t->ptr[i+1+d];
					i++;
				}
			}
			else
			{
				che1=1;
				t2->ptr[i]=lc;
				if(lc)
				lc->par=t2;
				t2->ptr[i+1]=rc;
				if(rc)
				rc->par=t2;
				i++;
			}
		}cout<<"KJHGF\n";
		 if(che==0&&che1==0)
		 {
		 	t->ptr[d]=lc;
		 	t2->ptr[0]=rc;
		 	for(int i=d;i<2*d;i++)
		 	{
		 	t2->ptr[i-d+1]=t->ptr[i+1];
			}
		 }
		 for(i=0;i<d;i++)
		 if(t2->ptr[i])
		 t2->ptr[i]->par=t2;cout<<"LOUeY\n";
		 if(t->par->count==2*d-1)
		 {cout<"KJUYT\n";
		 	for(i=0;i<2*d;i++)
		 		b[i]=t->par->key[i];
		 		b[i]=a[d];
		 		sort(b,b+2*d+1);
		 		cout<<"a ="<<a[d]<<endl;cout<<" t ->"<<t->key[0]<<"  t2 = "<<t2->key[0]<<endl;
		 		overflow(t->par,t,t2,a[d],b);
		 		
		 }
		 else
		 {//cout<<"come\n";
		 	for(i=t->par->count;i>=0;i--)
		 	{
		 		if(t->par->key[i]>a[d])
		 		{
		 			t->par->key[i+1]=t->par->key[i];
		 			t->par->ptr[i+2]=t->par->ptr[i+1];
				 }
				 else
				 break;
			 }
			 t->par->key[i+1]=a[d];
			 t->par->ptr[i+1]=t;cout<<"t->key[0] ="<<t->key[0]<<endl;
			 t->par->ptr[i+2]=t2;cout<<"t2->key[0] ="<<t2->key[0]<<endl;
			 t->par->count++;
		 }
	}
}
void add(bptr &t1,int k)
{
	int i,j,a[2*d+1];
	bptr t=search(t1,k);
	cout<<"KK\n";
	cout<<"T  "<<t;
		cout<<"T->ptr [0] = "<<t->ptr[0]<<endl;

	if(t->count<2*d-1)
	{
		for(i=t->count;i>=0;i--)
		{
		   if(t->key[i]>k)
		   {
		   	t->key[i+1]=t->key[i];
		   	t->ptr[i+2]=t->ptr[i+1];
		   }
		   else 
		   break;
		}
		t->key[i+1]=k;
		t->count++;
	}
	else
	{//cout<<"t->ptr [0] = "<<t->ptr[0]<<endl;
		for(int i=0;i<2*d;i++)
		{
			a[i]=t->key[i];
		}
		a[2*d]=k;
		sort(a,a+2*d+1);
		//cout<<a[d]<<"KKj\n"<<"t->ptr"<<t->ptr[0]<<endl;
		overflow(t,null,null,a[d],a);
	}
}
int main()
{
	int n,i;
	bptr t=new bnode;
	t->count=-1;
	cout<<"Enter the key to be add \n";
	cin>>n;
	t->key[0]=n;
	t->count=0;
	for(i=0;i<=2*d;i++)
	{
		t->ptr[i]=null;
	}
	t->par=null;n++;
	while(n<=53)
	{
		//cout<<"ENter the no to add  else -1\n";
		//cin>>n;
		if(n!=-1)
		
		add(t,n);cout<<"YYY2\n";
    	//for(i=0;i<=2*d;i++)
		//cout<<t->ptr[i]<<"   ";
		print(t);cout<<endl;
	printlevel(t);n++;
	}
return 0;	
}

