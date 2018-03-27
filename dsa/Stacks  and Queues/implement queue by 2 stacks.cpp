#include<iostream>
using namespace std;
struct stack
{
	int top;
	int size;
	int ele[5];
};
struct queue
{
	int size;
	stack s1,s2;
	int front;
	int rear;
};
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
        push(q.s1, x);
	}
}
int deque(queue &q)
{
	int t,i;
	
	if(q.front==-1)
	{
		return -1;
	}
	else
	{
		//t=q.front;
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		for(i=q.s1.top;i>0;i--)
		{
	      push(q.s2,pop(q.s1));
	    }
	    t=pop(q.s1);
	    for(i=q.s2.top;i>=0;i--)
	    push(q.s1,pop(q.s2));
		return t;
    }    	
}

int main()
{
	int n,i,j,k,l;
queue q;
q.size=5;
q.rear=-1;
q.front=-1;
q.s1.size=5;
q.s2.size=5;
q.s2.top=-1;
q.s1.top=-1;int t;
//cout<<"Enter the no. of elements in queue\n";
//cin>>n;int a[n];
/*for(i=0;i<n;i++)
{
	cin>>a[i];
	enque(q,a[i]);
}
for(i=0;i<n;i++)
{
	cout<<deque(q)<<"  ";
}*/
while(1)
{
	cout<<"\nPress 1 for enque 2 for deque 3 for exit\n";
	cin>>j;
	if(j==1)
	{
		cout<<"Enter the no. u wanna enter \n";
		cin>>n;
		enque(q,n);
	}
	else if(j==2)
	{
		cout<<"dequed element\n";
		cout<<deque(q);
	}
	else
	{
		break;
	}
}
	t=deque(q);
		cout<<"Elements of the Queue\n";
       while(t!=-1)
       {
       cout<<t<<" ";
       t=deque(q);
       }
return 0;
}
