#include<iostream>
#include<string.h>
#include<queue>
#define  null NULL
bool v[50];
using namespace std;
char is[50],ls[50];
int sizels=0;
typedef
struct btnode
{
	btnode *lchild;
	char data ;
	btnode *rchild;
} *btptr;
queue<btptr> q;
queue<int> q1;
int index=0;
void print(btptr l)
{
	if(l==null)
	return;
	print(l->lchild);
	cout<<l->data<<" ";
	print(l->rchild);
}
void create(btptr &t,int s,int e)
{
		int i,in;
		btptr temp,temp1;
		if(t==null&&index<sizels)
		{
			t=new  btnode;
			t->lchild=null;
			t->rchild=null;
			t->data=ls[index++];
		}
		q.push(t);
		for(i=s;i<e;i++)
		{
			if(is[i]==ls[index-1])
			{
				in=i;
				break;
			}
		}
		v[in]=true;
		cout<<"in ="<<in<<endl;
		q1.push(in);
	while(!q.empty())
	{
	//cout<<"while\n";
	//
	//levelorderline(t);
	print(t);cout<<endl;
	    //cout<<"size= "<<q.size()<<endl;
		in=q1.front();
		int tempin=in;
		//cout<<"in ="<<in<<endl;
		q1.pop();
		temp=q.front();
		temp1=temp;
		q.pop();
		if(in-1>=0&&v[in-1]==false)
		{	
			temp1->lchild=new  btnode;
			temp1=temp1->lchild;
			temp1->data=ls[index];
	    //	cout<<"is ="<<ls[index]<<endl;
			temp1->lchild=null;
			temp1->rchild=null;
			index++;
			
			for(i=s;i<e;i++)
			{
				if(is[i]==ls[index-1])
				{
					in=i;
					break;
				}
			}
		//	cout<<"going false\n"<<in<<endl;
			q.push(temp1);
			v[in]=true;
			q1.push(in);
		} 
		temp1=temp;
		if((tempin+1)<sizels&&v[tempin+1]==false)
		{
			temp1->rchild=new  btnode;
			temp1=temp1->rchild;
			temp1->data=ls[index];
		//	cout<<"is ="<<ls[index]<<endl;
			temp1->lchild=null;
			temp1->rchild=null;
			index++;
			for(i=s;i<e;i++)
			{
				if(is[i]==ls[index-1])
				{
					in=i;
					break;
				}
			}
		cout<<"going false\n"<<in<<endl; 
			q.push(temp1);
			v[in]=true;
			q1.push(in);
		}
	}
}
void levelorderline(btptr t)
{
	
	while(!q.empty()) q.pop();
	cout<<"CALLING\n";
	btptr t1;
//	q.size=50;
  //  q.rear=-1;
    //q.front=-1;
//	enque(q,t);
	q.push(t);
	q.push(null);
//	enque(q,null);
	int i=1;
	while(!q.empty())
	{
		
		cout<<"LEVEL "<<i<<":: ";
		while(q.front()!=null)
		{
		
		//t1=deque(q);
		t1=q.front();
		q.pop();
		//cout<<"t1"<<t1<<endl;
		cout<<t1->data<<" ";
		if(t1->lchild!=null)
		{//cout<<"IF1\n";
			//enque(q,t1->lchild);
			q.push(t1->lchild);
		}
		if(t1->rchild!=null)
		{//cout<<"IF2\n";
		//	enque(q,t1->rchild);
			q.push(t1->rchild);
		}
		
		}
		
		cout<<endl;
		i++;
		q.pop();
	//	deque(q);
		if(!q.empty())
		q.push(null);
		//enque(q,null);
		
		
	}
}

int main()
{
	cout<<"Enter the inorder string\n";
	cin>>is;
	cout<<"Enter the levelorder string \n";
	cin>>ls;
	sizels=strlen(ls);
	btptr t=null;
	create(t,0,sizels);
	print(t);
	levelorderline(t);
}
