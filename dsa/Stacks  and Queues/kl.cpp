#include<iostream>
using namespace std;
struct queue
{
	int size;
	int element[50];
	int front;
	int rear;
};
struct stack
{
	int top;
	int size;
	int ele[50];
};

void enque(queue &q,int x)
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
int deque(queue &q)
{
	int t;
	
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
void push(stack &s1,int x )
{
	if(s1.top==s1.size-1)
	{
		cout<<"Overflow of stack\n";
	}
	else
	{
		s1.top++;
		s1.ele[s1.top]=x;
	}
}
int pop(stack &s1)
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


void insertatbottom(stack &s,int temp)
{
	if(s.top!=-1)
	{
		int 	tmp=pop(s);
		insertatbottom(s,temp);
		push(s,tmp);
	}
	else
	{
		push(s,temp);
	}
}
void reverse(stack &s)
{
	int temp;
	if(s.top>=0)
	{
	 temp=pop(s);
	 cout<<"temp= "<<temp<<endl;
	 	reverse(s);
	insertatbottom(s,temp);
	}

}

int main()
{
	int n,i,j,k,l;
queue q;
q.size=50;
q.rear=-1;
q.front=-1;
stack s;
s.size=50;
s.top=-1;
cout<<"Enter the no. of elements in queue\n";
cin>>n;int a[n];
for(i=0;i<n;i++)
{
	cin>>a[i];
	push(s,a[i]);
}

for(i=0;i<n;i++)
cout<<pop(s)<<endl;
for(i=0;i<n;i++)
{
//	cin>>a[i];
	push(s,a[i]);
}
reverse(s);
for(i=0;i<n;i++)
cout<<pop(s)<<endl;
//for(i=0;i<n;i++)
//{
//	push(s,deque(q));
//}
//for(i=0;i<n;i++)
//{
//	enque(q,pop(s));
//}
//cout<<"The Queue after Reversal is \n";
//for(i=0;i<n;i++)
//cout<<deque(q)<<" ";



return 0;	
}
