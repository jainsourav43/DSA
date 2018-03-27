#include<iostream>
#define null NULL
using namespace std;
typedef
struct btnode
{
	btnode *lchild;
	char data ;
	btnode *rchild;
	btnode *thread;
} *btptr;
void ldr(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{
		ldr(t->lchild);
		cout<<t->data<<"   ";
		ldr(t->rchild);
	}
}	
 int c=0;
void cuntnodes(btptr t)
{

	if(t==null)
	return ;
	c++;
cuntnodes(t->lchild);
cuntnodes(t->rchild);
}
bool isComplete(btptr t,int index,int no)
{
	if(t==null)
	return true;
	if(index>no)
	return false;
	return (isComplete(t->lchild,2*index+1,no)&&isComplete(t->rchild,2*index+2,no));
}
bool isHeap(btptr t)
{
	if(t==null||(t->lchild==null&&t->rchild==null))
	return true;
	if(t->lchild&&t->rchild)
	{
		return(t->data<t->lchild->data&&t->data<t->rchild->data&&isHeap(t->lchild)&&isHeap(t->rchild));
	}
	else if(t->lchild)
	{
		return t->data<t->lchild->data;
	}

}
bool checkforheap(btptr t)
{
	int no=c;
	return (isComplete(t,0,no)&&isHeap(t));
}
void dlr(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{		cout<<(int)t->data<<"   ";

		dlr(t->lchild);
		dlr(t->rchild);
	}
}
bool binarycheckBst(btptr t,int min,int max)//Other Methods are find max in left subtree check with data and min in right subtree check with data or keep an auxilary of inorder 
{
	if(t==null)
	{
		return 1;
	}
	if(t->data<min||t->data>max)
	return  false;
	return (binarycheckBst(t->lchild,min,t->data-1)&&binarycheckBst(t->rchild,t->data+1,max));
}
bool checkBst(btptr t)//WE are checking for sorted order at each node
{
	static int d=-1;
	if(t!=null)
	{
		 if(checkBst(t->lchild))
		 return false;
		if(d!=-1&&d>t->data)
		return false;
		d=t->data;
		return checkBst(t->rchild);
	}
	return 1;
}
int getHeight(btptr t)
{
	if(t==null)
	return 0;
	return (max(getHeight(t->lchild),getHeight(t->rchild))+1);
}
void printlevel(btptr t,int k)
{
	if(t==null)
	return ;
	if(k==0)
	{
	
	cout<<t->data<<" ";
	return;
	}
	printlevel(t->lchild,k-1);
	printlevel(t->rchild,k-1);
}
void levelorderrecursive(btptr t)
{
	int i;
	int height=getHeight(t);
	for(i=0;i<height;i++)
	{
		printlevel(t,i);
	}
}
void lrd(btptr t)
{
   // cout<<"CALLING\n";
	if(t!=null)
	{		
		lrd(t->lchild);
		lrd(t->rchild);
		cout<<t->data<<"   ";

	}
}
void mirror(btptr &t)
{
	if(t!=NULL)
	{
		//cout<<"CALLING\n";

	//cout<<"1\n";
	mirror(t->lchild);
	//cout<<"2\n";
	mirror(t->rchild);
		btptr temp;
		temp=t->lchild;
		t->lchild=t->rchild;
		t->rchild=temp;
}
}

void create(btptr &t,btptr suc)
{
	btptr t1,t2;
	char ch;
	cout<<"Enter the character to input or '.' to return \n";
	cin>>ch;
	if(ch=='.')
	{
	return;
	}
	else if(t==null)
	{
		t=new btnode;
		t->data=ch;
		t->lchild=null;
		t->rchild=suc;
	}
	create(t->lchild,t);
	{
		
	}
	cout<<" Your current  position is  "<<t->data<<endl;
	create(t->rchild,t->thread);
	cout<<"Your current   position is  "<<t->data<<endl;
}
void create(btptr &t)
{
	btptr t1,t2;
	char ch;
	cout<<"Enter the character to input or '.' to return \n";
	cin>>ch;
	if(ch=='.')
	return;
	else if(t==null)
	{
		t=new btnode;
		t->data=ch;
		t->lchild=null;
		t->rchild=null;
	}

	create(t->lchild);
	{
		
	}
	cout<<" Your current  position is  "<<t->data<<endl;
	create(t->rchild);
	cout<<"Your current   position is  "<<t->data<<endl;
}
void printall(btptr t,int i)
{
	static char  a[40];
	if(t!=null)
	{
		a[i]=t->data;
	//	cout<<"a["<<i<<"]"<<a[i]<<endl;
		i++;
		printall(t->lchild,i);	
		if(t->lchild==null&&t->rchild==null)
		for(int j=0;j<i;j++)
		{
			cout<<a[j]<<"  ";
		}cout<<endl;
	//	i--;
		printall(t->rchild,i);
//		for(int j=0;j<i;j++)
//		{
//			cout<<a[i]<<"  ";
//		}
	}

}
int equal(btptr t1,btptr t2)
{
	cout<<"\nCAlling";
	 if(t1==null&&t2==null)
	{
	    cout<<"\n 1";
		return 1;
	}
	else if(t1!=null&&t2!=null)
	{
	return(equal(t1->lchild,t2->lchild)&&equal(t1->rchild,t2->rchild)&&t1->data==t2->data);
    }
   return 0;
}
 char sumofchild(btptr &t)
{
	if(t==null)
	return 0;
	if(t->lchild==null&&t->rchild==null)
	return 	t->data;
	else
	{
		t->data=sumofchild(t->lchild)+sumofchild(t->rchild);
	}
}
int main()
{
	btptr t=null,t1=null;
	create(t);
	cout<<"Input for second tree\n";
	//create(t1);
	cout<<"PREORDER TRAVERSAL OF TREE IS \n";
	dlr(t);cout<<endl;
	cout<<"POSTORDER TRAVERSAL OF TREE IS \n";
	lrd(t);cout<<endl;
	cout<<"INORDER TRAVERSAL OF TREE IS \n";
	ldr(t);cout<<endl;
	//mirror(t);
//	cout<<"MIRROR\n";
	//ldr(t);
//	int k=equal(t,t1);
//	if(k)
//	{
//		cout<<"\nTHE trees are equal\n";
//		
//	}
//	else
//	{
//		cout<<"\nThe trees are not equal\n";
//	}
//	cout<<"Print all calling \n";
	printall(t,0);
	cout<<binarycheckBst(t,INT_MIN,INT_MAX)<<endl;
	cout<<"Check for BST = "<<checkBst(t)<<endl;
	levelorderrecursive(t);
	sumofchild(t);
	dlr(t);
	return 0;
}
