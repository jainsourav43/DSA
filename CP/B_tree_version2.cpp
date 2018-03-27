//Program to create a B+ tree

#include<iostream>
using namespace std;

typedef struct bnode{
	int count;
	int key[2];
	bnode *ptr[3];
	bnode *parent;
}*BPTR;

void add( BPTR &T, int d);

struct queue{
	int size;
	BPTR ele[50];
	int front;
	int rear;
};
void enqueue(queue &s,BPTR x)
{
	if((s.rear+1)%s.size==s.front)
	return;
	else
	{
		if(s.front==-1)
		{
			s.front=0;
		}
		s.rear=(s.rear+1)%s.size;
		s.ele[s.rear]=x;
	}
}

BPTR dequeue(queue &s)
{
	if(s.front==-1)
	{		
		return NULL;
	}
	else
	{
		BPTR t=s.ele[s.front];
		if(s.front==s.rear)
		{
			s.front=-1;
			s.rear=-1;
		}
		else
		s.front=(s.front+1)%s.size;
		return t;
	}
}


void sort(BPTR T)
{
		for(int k=0;k<T->count;k++)
			for(int l=0;l<T->count-k-1;l++)
			{
				if(T->key[l]>T->key[l+1])
				{
					int temp=T->key[l+1];
					T->key[l+1]=T->key[l];
					T->key[l]=temp;
				}
			}
	
}

BPTR search(BPTR T,int d)
{
	if(T->ptr[1]==NULL)return T;
	else if(T->key[0]>=d)search(T->ptr[0],d);
	else if(T->key[1]<=d && T->ptr[2]!=NULL)search(T->ptr[2],d);
	else search(T->ptr[1],d);
}

void insert(BPTR &T,int d)
{
	T->key[T->count++]=d;
	sort(T);
}


int overflow(BPTR T)
{
  int flag=0;
  if(T->count==2)flag=1;
  return flag;
}

BPTR find_leaf(BPTR T)
{
	if(T->ptr[1]==NULL) return T;
	else find_leaf(T->ptr[0]);
}

BPTR find_leaf2(BPTR T)
{
	if(T->ptr[1]==NULL) return T;
	else if(T->ptr[2]!=NULL) find_leaf2(T->ptr[2]);
	else find_leaf2(T->ptr[1]);
}

void node_split(BPTR &T,BPTR &T1,BPTR &root,int d)
{
	int dd=T->key[0];
	int a[2],i=0;
	while(i<T->count)
	{
		a[i]=T->key[i];
		i++;
	}
	a[i]=d;
	for(int k=0;k<=2;k++)
	for(int l=0;l<=2-k-1;l++)
	{
		if(a[l]>a[l+1])
		{
			int temp=a[l+1];
			a[l+1]=a[l];
			a[l]=temp;
		}
	}
	T->count--;
	T->key[0]=a[0];
	BPTR T2=new bnode;
	T2->count=0;
	if(T->ptr[1]==NULL)
	{
	T2->key[T2->count++]=a[1];
	T2->key[T2->count++]=a[2];
   }
   else{
   	T2->key[T2->count++]=a[2];
   }
	for(int i=0;i<=2;i++)
	{
		T2->ptr[i]=NULL;
	}
	if(d>dd)
	{
	if(T->ptr[1]!=NULL && T->ptr[2]==NULL)
	{
		T2->ptr[0]=T->ptr[1];
		T2->ptr[1]=T->ptr[2];
	}
	else if(T->ptr[2]!=NULL && T->ptr[1]!=NULL)
	{
		if(T1->key[0]<T2->key[0])
		{
			T2->ptr[0]=T1;
		T2->ptr[1]=T->ptr[2];
		T->ptr[2]->parent=T2;
		T->ptr[2]=NULL;
		T1->parent=T2;
		}
		else{
		T2->ptr[0]=T->ptr[2];
		T2->ptr[1]=T1;
		T->ptr[2]->parent=T2;
		T->ptr[2]=NULL;
		T1->parent=T2;
	}
		
	}
    }
	else {
		if(T->ptr[1]!=NULL && T->ptr[2]==NULL)
		{
			T2->ptr[0]=T->ptr[1];
		    T2->ptr[1]=T->ptr[2];
		}
		else if(T->ptr[2]!=NULL && T->ptr[1]!=NULL)
			{
				T2->ptr[1]=T->ptr[2];
				T2->ptr[0]=T->ptr[1];
				T->ptr[1]=T1;
				T->ptr[2]=NULL;
				T1->parent=T;
				T2->ptr[1]->parent=T2;
				T2->ptr[0]->parent=T2;
			}
		
	}
   	if(T->ptr[1]==NULL && T2->ptr[1]==NULL)
	{
		if(T->parent==NULL)
		{
			T->ptr[2]=T2;
			T2->ptr[0]=T;
		}
		else {
			if(T2->key[0]>=T->parent->key[0] && T->parent->ptr[2]==NULL)
			{
				T->ptr[2]=T2;
				T2->ptr[0]=T;
			}
			else if(T2->key[0]>T->parent->key[1] && T->parent->ptr[2]!=NULL)
			{
				T->ptr[2]=T2;
				T2->ptr[0]=T;
			}
			else if(T2->key[0]>T->parent->key[0] && T2->key[0]<T->parent->key[1])
			{
				
				T2->ptr[2]=T->ptr[2];
				T->ptr[2]->ptr[0]=T2;
				T->ptr[2]=T2;
				T2->ptr[0]=T;
			}
			else if(T2->key[0]<T->parent->key[0] || T2->key[0]<=T->parent->key[1])
			{
				T2->ptr[2]=T->ptr[2];
				T->ptr[2]->ptr[0]=T2;
				T->ptr[2]=T2;
				T2->ptr[0]=T;
			}
		}
	}
	
	if(T->parent==NULL)
	{
		BPTR P=new bnode;
		P->parent=NULL;
		P->count=0;
		P->key[P->count++]=a[1];
	    for(int i=0;i<=2;i++)
	   {
		P->ptr[i]=NULL;
	   }
		P->ptr[0]=T;
        P->ptr[1]=T2;
        T->parent=P;
        T2->parent=P;
        T=P;
	}
	else if(T->parent!=NULL)
	{
		BPTR tmp=T->parent;
		if(overflow(T->parent)==1)
		{
			T1=T2;
			node_split(tmp,T1,root,a[1]);
			T=tmp;
		}
		else{
			if(a[1]>T->parent->key[0])
		{
		insert(T->parent,a[1]);
		T2->parent=T->parent;
		T->parent->ptr[2]=T2;
		T=root;
	      }
	    else{
	    	insert(T->parent,a[1]);
	    	sort(T->parent);
	    	T2->parent=T->parent;
	    	T->parent->ptr[2]=T->parent->ptr[1];
	    	T->parent->ptr[1]=T2;
	        T=root;
		}
	}
}
}

void add(BPTR &T,int d)
{
   	if(T==NULL)
   	{
   		T=new bnode;
   		T->count=0;
   		T->parent=NULL;
   		insert(T,d);
   		for(int i=0;i<=2;i++)
   		{
   			T->ptr[i]=NULL;
		}
	}
   	else{
	BPTR tmp=search(T,d);	
	int flag=overflow(tmp);
   	if(flag==1)
   	{
   		BPTR T1;
   		BPTR root=T;
   		node_split(tmp,T1,root,d);
   		T=tmp;
	}
	else {
		insert(tmp,d);
		sort(tmp);
	}
   	}
}
	

void print(BPTR T)
{
	for(int i=0;i<=T->count;i++)
	{
		if(T->ptr[i]!=NULL)
		{
			print(T->ptr[i]);
			if(i!=T->count)
			cout<<T->key[i]<<"->";
		}
		else if(T->ptr[i]==NULL && i!=T->count)
		cout<<T->key[i]<<"->";
	}
}

void print1(BPTR t)
{
	if(t!=NULL)
	{
	for(int i=0;i<=2;i++ )
	{
		print1(t->ptr[i]);
		if(i+1<=t->count)
		{
			cout<<t->key[i]<<"  ";
		}
	}
	}
}

void print_leaves(BPTR T)
{
	while(T!=NULL)
	{
		for(int i=0;i<T->count;i++)
		{
			cout<<T->key[i]<<"->";
		}
		T=T->ptr[2];
	}
}

void print_leaves_reverse(BPTR T)
{
		while(T!=NULL)
	{
		for(int i=T->count-1;i>=0;i--)
		{
			cout<<T->key[i]<<"->";
		}
		T=T->ptr[0];
	}
}
void print_by_level(BPTR T)
{
	queue q;
	BPTR x=new bnode;
	x->key[0]=-1;
	for(int i=0;i<=2;i++)
	x->ptr[i]=NULL;
	q.front=-1;
	q.rear=-1;
	q.size=50;
	enqueue(q,T);
	enqueue(q,x);
	while(q.front!=-1)
	{
		if(q.front==q.rear&&q.rear==0)
		{
			break;
		}
		BPTR temp=dequeue(q);
		if(temp->key[0]==-1)
		{
			cout<<endl;
			enqueue(q,x);
		}
		else {
			for(int j=0;j<temp->count;j++ )
			{
				cout<<temp->key[j]<<" ";	
			}
			cout<<"   ";
		}
		if(temp->ptr[0]!=NULL && temp->ptr[1]!=NULL)
		{
			enqueue(q,temp->ptr[0]);	
		}
		if(temp->ptr[1]!=NULL)
		{
			enqueue(q,temp->ptr[1]);
		}
		if(temp->ptr[2]!=NULL && temp->ptr[1]!=NULL)
		{
			enqueue(q,temp->ptr[2]);
		}
	}
}

 int main()
 {
 	BPTR T;
 	T=NULL;
 	int d;
 	cout<<"Enter data(-1 to exit) :";
 	cin>>d;
 	while(d!=-1)
 	{
 		add(T,d);
 		cout<<"-------------------------------------------"<<endl;
 		cout<<"Level order :"<<endl;
 		print_by_level(T);
 		cout<<endl;
 		cout<<"Printing leaves :"<<endl;
 		BPTR te=find_leaf(T);
 		print_leaves(te);
 		cout<<endl;
 		BPTR tr=find_leaf2(T);
	    cout<<"The list in reverse :"<<endl;
        print_leaves_reverse(tr);
        cout<<endl;
 		cout<<"--------------------------------------------"<<endl;
 		cout<<"Enter data(-1 to exit) :";
 	    cin>>d;
	}
 }
 
 
 
 
 
 
 
 
