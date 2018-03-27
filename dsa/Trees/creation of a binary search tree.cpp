//program to create binary search tree iteratively
#include<iostream>
#define null NULL
using namespace std;
typedef
struct bstnode
{
	bstnode *lchild;
	int data ;
	bstnode *rchild;
	
} *bstptr;
void ldr(bstptr t)
{
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}
bool twoarraysamebst(int a[],int b[],int i1,int i2,int min,int max,int n)
{
	int j,k;
	for(j=i1;j<n;j++)
	{
		if(a[j]>min&&a[j]<max)
		{
			break;
		}
	}
	for(k=i2;k<n;k++)
	{
		if(b[k]>min&&b[k]<max)
		break;
	}
	
	if(j==n&&k==n)
	return true;
	if((j==n^k==n) || (a[j]!=b[k]))
	{
		return false;
	}
	return (twoarraysamebst(a,b,j+1,k+1,min,a[j],n)&&twoarraysamebst(a,b,j+1,k+1,a[j],max,n));
	
}
int getSum(bstptr t)
{
//	static int sum=0;
	if(t==null)
	return 0;
	return(t->data+getSum(t->lchild)+getSum(t->rchild));
}
void addgreater(bstptr t)
{
	if(t==null)
	return ;
	static int Sum=getSum(t),sum;
	addgreater(t->lchild);
	int temp=t->data;
	t->data=Sum-sum;
	sum=temp+sum;
	addgreater(t->rchild);//we can use reverse inorder traversal too here
//	cout<<Sum<<endl;
}
bool hasOnlyOneChild(int pre[], int size)
{
    int nextDiff, lastDiff;
 
    for (int i=0; i<size-1; i++)
    {
        nextDiff = pre[i] - pre[i+1];
        lastDiff = pre[i] - pre[size-1];
        if (nextDiff*lastDiff < 0)
            return false;;
    }
    return true;
}
 
 int hasOnlyOneChild1(int pre[], int size)
{
    // Initialize min and max using last two elements
    int min, max;
    if (pre[size-1] > pre[size-2])
    {
        max = pre[size-1];
        min = pre[size-2];
    }
    else
    {
        max = pre[size-2];
        min = pre[size-1];
    }
 
 
    // Every element must be either smaller than min or
    // greater than max
    for (int i=size-3; i>=0; i--)
    {
        if (pre[i] < min)
            min = pre[i];
        else if (pre[i] > max)
            max = pre[i];
        else
            return false;
    }
    return true;
}
 
bstptr removerange(bstptr t,int min,int max)
{
	if(t==null)
	return null;
	t->lchild=removerange(t->lchild,min,max);
	t->rchild=removerange(t->rchild,min,max);
	if(t->data<min)
	{
		bstptr temp=t->rchild;
		delete t;
		return temp;
	}
	if(t->data>max)
	{
		bstptr temp=t->lchild;
		delete t;
		return temp;
	}
	return t;
}


int findlca(bstptr t,int n1,int n2)
{
	if(t==null)
	return -1;
	else if(t->data>n1&&t->data>n2)
	{
		return (t->lchild,n1,n2);
	}
	else if(t->data<n1&&t->data<n2)
	{
		return (t->rchild,n1,n2);
	}
	else
	{
		return t->data;
	}
}

int  findmin(bstptr t)
{
	if(t==null)
	return -1;
	while(t->lchild!=null)
	
	{
		t=t->lchild;
	}
	return t->data;
	cout<<"minimum no."<<t->data<<endl;
}
int findmax(bstptr t)
{	
	
	if(t==null) return -1;
	while(t->rchild!=null)
	{
		t=t->rchild;
	}
	return t->data;
	cout<<"maximum no."<<t->data<<endl;
}
void morristraversal(bstptr  t )
{
	bstptr pred,current;
	if(t==null)
	{
		return ;
	}
	current=t;
	while(current!=null)
	{
		if(current->lchild==null)
		{
			cout<<current->data<<endl;
			current=current->rchild;
		}
		else
		{
			pred=current->lchild;
			while(pred->rchild!=null&&pred->rchild!=current)
			{
				pred=pred->rchild;
			}
			
			if(pred->rchild==null)
			{
				pred->rchild=current;
				current=current->lchild;
			}
			else
			{
				pred->rchild=null;
				cout<<current->data<<endl;
				cout<<"GOING TO ";
				current=current->rchild;
				if(current) cout<<current->data<<endl;
			}
			
			
		}
	}
	
}
void kthsmallmorristraversal(bstptr  t ,int k)
{
	
	int count=0;
	int kthsmall=INT_MIN;
	bstptr pred,current;
	if(t==null)
	{
		return ;
	}
	current=t;
	while(current!=null)
	{
		if(current->lchild==null)
		{
			count++;
			if(count==k)
			kthsmall=current->data;
		//	cout<<current->data<<endl;
			
			
			current=current->rchild;
		}
		else
		{
			pred=current->lchild;
			while(pred->rchild!=null&&pred->rchild!=current)
			{
				pred=pred->rchild;
			}
			
			if(pred->rchild==null)
			{
				pred->rchild=current;
				current=current->lchild;
			}
			else
			{
				pred->rchild=null;
				count++;
				if(k==count)
				kthsmall=current->data;
				//cout<<current->data<<endl;
				//cout<<"GOING TO ";
				current=current->rchild;
				//if(current) cout<<current->data<<endl;
			}
			
			
		}
	}
	
}
void findinorderpred(bstptr t,int &pred,int &succ,int d)
{
	if(t==null)
	{
		return;
	}
	if(t->data==d)
	{
		if(t->rchild)
		succ=findmin(t->rchild);
		if(t->lchild)
		pred=findmax(t->lchild);
		return;
	}
	 if(t->data>d)
	{
		
		succ=t->data;
		findinorderpred(t->lchild,pred,succ,d);
	}
	else if(t->data<d)
	{
		pred=t->data;
		findinorderpred(t->rchild,pred,succ,d);
	}
	
}
void print(int a[],int s,int e)
{
	if(s<=e)
	{
		print(a,2*s+1,e);
		cout<<a[s]<<endl;
		print(a,2*s+2,e);
	}
}
void create1(bstptr t)
{
	bstptr t1,t2;int d=1;int k1,k2;
         while(d!=-1)
         {
          t1=t;t2=t;
          cout<<"Enter the data or -1 to exit\n";
          cin>>d;
          if(d!=-1)
          {
		  while(t2!=null)
		  {k1=0;k2=0;
		  	if(t1->data>d)
		  	{k1=1;
		  	if(t1->lchild!=null)
		  	t1=t1->lchild;	
		  	t2=t2->lchild;
			  }
			  else
			  {k2=1;
			    if(t1->rchild!=null)
			  	t1=t1->rchild;
			  	t2=t2->rchild;
			  }
			  
	      }
		  if(k1==1)
		  {	
		  t1->lchild=new bstnode;
	      t1=t1->lchild;
          t1->data=d;
       	  t1->lchild=null;
     	  t1->rchild=null;
	      }
	      else
	      {
	      t1->rchild=new bstnode;
	      t1=t1->rchild;
          t1->data=d;
       	  t1->lchild=null;
     	  t1->rchild=null;
		  }
		  	 
		}
}
}
void insert(bstptr &t,int k)
{
	if(t==null)
	{
		t=new bstnode;
		t->data=k;
		t->lchild=null;
		t->rchild=null;
	}
	else if(k<t->data)
	{
		insert(t->lchild,k);
	}
	else
	{
		insert(t->rchild,k);
	}
}

void convertbsttodll(bstptr t,bstptr &head,bstptr &tail)
{
	if(t==null)
	return;
	if(t->lchild)
	convertbsttodll(t->lchild,head,tail);
	t->lchild=tail;
	if(tail)
	{
	tail->rchild=t;
	}
	else
	{
		head=t;
	}
	tail=t;
	if(t->rchild)
	convertbsttodll(t->rchild,head,tail);
}
int main()
{   
    int d=1;
	bstptr t=new bstnode;
	
	cout<<"Enter the data\n";
    cin>>d;
	t->data=d;
	t->lchild=null;
	t->rchild=null;
//	create1(t);
	while(d!=-1)
	{
		cout<<"ENter the data\n";
		cin>>d;
		if(d!=-1)
		insert(t,d);
	}
	ldr(t);
	cout<<endl;
	findmax(t);
	findmin(t);
	cout<<findlca(t,2,3);
	int pred,succ;
	cout<<"pred and succ are \n";
		findinorderpred(t,pred,succ,4);
	cout<<pred<<" "<<succ<<endl;
	morristraversal(t);
	addgreater(t);//<<endl;
	cout<<endl;
	ldr(t);
	cout<<endl;
	bstptr head=null,tail=null;
	convertbsttodll(t,head,tail);

	return 0;
}
//---------------------------------------creation from preorder--------------------------------------------------


/*struct node* constructTreeUtil( int pre[], int* preIndex, int key,
                                int min, int max, int size )
{
    // Base case
    if( *preIndex >= size )
        return NULL;
  
    struct node* root = NULL;
  
    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if( key > min && key < max )
    {
        // Allocate memory for root of this subtree and increment *preIndex
        root = newNode ( key );
        *preIndex = *preIndex + 1;
         
        if (*preIndex < size)
        {
            // Contruct the subtree under root
            // All nodes which are in range {min .. key} will go in left
            // subtree, and first such node will be root of left subtree.
            root->left = constructTreeUtil( pre, preIndex, pre[*preIndex],
                                        min, key, size );
  
            // All nodes which are in range {key..max} will go in right
            // subtree, and first such node will be root of right subtree.
            root->right = constructTreeUtil( pre, preIndex, pre[*preIndex],
                                         key, max, size );
        }
    }
  
    return root;
}
 
// The main function to construct BST from given preorder traversal.
// This function mainly uses constructTreeUtil()
struct node *constructTree (int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil ( pre, &preIndex, pre[0], INT_MIN, INT_MAX, size );
}*/


//------------------------------------------------------------------------------------------------
int Ceil(node *root, int input)
{
    // Base case
    if( root == NULL )
        return -1;
 
    // We found equal key
    if( root->key == input )
        return root->key;
 
    // If root's key is smaller, ceil must be in right subtree
    if( root->key < input )
        return Ceil(root->right, input);
 
    // Else, either left subtree or root has the ceil value
    int ceil = Ceil(root->left, input);
    return (ceil >= input) ? ceil : root->key;
}
 
 
 

