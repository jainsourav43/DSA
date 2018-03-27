#include<iostream>
using namespace std;
struct queue
{
	int size;
	int front;
	int rear;
	int element[50];
};
struct stack
{
	int top;
	int size;
	queue q1,q2;
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
	    enque(s1.q1,x);
	}
}
int pop(stack &s1)
{    
    int temp;
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
		return -1;
	}
	else
	{	
	while(s1.q1.front<s1.q1.rear)
	{
	
		enque(s1.q2,deque(s1.q1));
	}
	temp= (deque(s1.q1));
	while(1)
	{
	if(s1.q2.front==s1.q2.rear)
	{	
	break;
    }
	enque(s1.q1,deque(s1.q2));
	}
	return temp;
	}
}
int main()
{
	stack s1;
	s1.q1.size=50;
	s1.q2.size=50;
	s1.q1.front=-1;
	s1.q2.front=-1;
	s1.q1.rear=-1;
	s1.q2.rear=-1;
	s1.top=-1;
	s1.size=50;
	int i,j,k,l,n;
	while(1)
	{
		cout<<"\nEnter 1 for push 2 for pop 3 for exit\n";
		cin>>j;
		if(j==1)
		{
			cout<<"Enter the number \n";
			cin>>n;
			push(s1,n);
		}
		else if (j==2)
		{
			cout<<"The Poped element from the stack is \n";
			cout<<pop(s1);
		}
		else
		{
			break;
		}
	}
	cout<<"The elements of the stacks are \n";
	while(s1.top!=-1)
	{
		cout<<pop(s1)<<"  ";
	}
	return 0;
}

