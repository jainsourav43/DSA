#include<iostream>
#define null NULL
#include<stack>
using namespace std;
int c=0;
typedef
struct btnode
{
	btnode *lchild;
	char data ;
	btnode *rchild;
} *btptr;
struct stack1
{
	int size;
	int top;
	btptr ele[50];
};
void push(stack1 &s1,btptr x )
{
	if(s1.top==s1.size-1)
	{
		cout<<"Overflow of stack1\n";
	}
	else
	{
		s1.top++;
		s1.ele[s1.top]=x;
	}
}

bool isequal(btptr t1,btptr t2)
{
	if(t1==NULL&&t2==NULL)
	return true;
	if(t1==NULL||t2==NULL)
	return false;
	return (t1->val==t2->val&&isequal(t1->left,t2->left)&&isequal(t1->right,t2->right));
}
bool isMirror(btptr t1,btptr t2)
{
	if(t1==NULL&&t2==NULL)
	return true;
	bool le=isequal(t1->left,t2->right);
	bool re=isequal(t1->right,t2->left);
	if(le&&re)
	return true;
	else
	return false;
	
	
	
	
	
}
bool myfun(btptr t1)
{
	bool le=isMirror(t1->left,t1->right);
	return le;
}
btptr pop(stack1 &s1)
{
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (s1.ele[s1.top--]);
	}
}
bool empty(stack1 s)
{
	if(s.top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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
	{c++;
		t=new btnode;
		t->data=ch;
		t->lchild=null;
		t->rchild=null;
	}
cout<<"AGAIN ENTER THE LEFT NODE\n";
	create(t->lchild);
	cout<<" Your current  position is  "<<t->data<<endl;
	cout<<"ENTER THE RIGHT NODE AT YOUR CURRENT POSITION\n";
	create(t->rchild);
	cout<<"Your current   position is  "<<t->data<<endl;
}

//typedef btnode TreeNode;
//void postorder(TreeNode* t)
//{
//	vector<int> ans;
//	stack<TreeNode*> s;
//	if(t==NULL)
//	return ;
//	s.push(t);
//	TreeNode *t1=t,*t2=t,*t3,*t4=t;
//	while(!s.empty())
//	{
//		t1=t2;
//		if(t1->left==NULL&&t1->right==NULL)
//		{
//			ans.push_back(t1->val);
//			t3=s.top();
//			s.pop();
//			while(t3->right==t2||t3->left==t2)
//			{
//				ans.push_back(t3->val);
//				if(t3==t4)
//				return;
//				t2=t3;
//				t3=s.top();
//				s.pop();
//			}

//			t2=t3;
//			
//			
//		}
//		else
//		{
//			if(t1->right&&t1->left)
//			{
//			//	s.push(t1->left);
//				s.push(t1);
//				s.push(t1->right);
//			
//				t2=t1->left;
//			}
//			else if(t1->right)
//			{
//			//	s.push(t1->right);
//				s.push(t1);
//				t2=t1->right;
//				
//			}
//			else if(t1->left)
//			{
//			//	s.push(t1->left);
//				s.push(t1);
//				t2=t1->left;
//			}
//			
//		}
//	}
//}
int main()
{
	btptr t=null;
	create(t);int k=0;
	bool v[50];
	for(int i=0;i<c;i++){
		v[i]=false;
	}
	btptr t2;
	stack1 s;
	s.top=-1;
	s.size=50;
	t2=t;
	push(s,t);
//	t=t->lchild;
	t2=t;
	while(!empty(s))
	{ 
	t=t2;
	while(t->lchild!=null)
	{   
	    
		if(t->lchild!=null)
		{
		 push(s,t->lchild);
	    }
   	    t=t->lchild;
	}
	t2=pop(s);
	cout<<t2->data<<" ";//k=1;
	if(t2->rchild)
	{
		push(s,t2->rchild);
		t2=t2->rchild;
	}
	else
	{
		if(!empty(s))
		{
			t2=pop(s);
			cout<<t2->data<<" ";
		

	while(!empty(s)&&t2->rchild==null)
	{	
	    t2=pop(s);
	    cout<<t2->data<<" ";
	}
//	cout<<t2->data;
     if(t2->rchild)
     {
	 
	push(s,t2->rchild);
	t2=t2->rchild;
	}
	
}
}
	
    }
}
