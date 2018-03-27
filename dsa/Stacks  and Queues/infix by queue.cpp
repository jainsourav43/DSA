#include<iostream>
#include<string.h>
using namespace std;
union u
{
	int i;
	char ch; 
};
struct st
{
	int tag;
	u u1;
};
struct queue
{
	int size;
	st s1[50];
	int front;
	int rear;
};
int prior(char ch)
{
	if(ch=='*'||ch=='/')
	return 2;
	else if(ch=='+'||ch=='-')
	return 1;
	else if(ch=='^')
	return 3;
}
void enque(queue &q,st x)
{
	if((+q.rear+1)%q.size==q.front)
	{
		cout<<"Queue is overloaded\n";
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.s1[q.rear]=x;
	}
}
st deque(queue &q)
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
		return q.s1[t];
    }    	
}
int main()
{
	char arr[50];
	int j,l;queue q;
	st s1;
	cout<<"Enter the expression\n";
	cin>>arr;
	st temp1,temp2,temp3,k;int c=strlen(arr);
	for(j=0;j<strlen(arr);j++)
	{
		if(arr[j]=='+'||arr[j]=='-'||arr[j]=='*'||arr[j]=='/')
		{
		    s1.tag=1;
			s1.u1.ch=arr[j];
			enque(q,s1);  
		}
		else
		{
			s1.u1.i=arr[j];
			enque(q,s1);
			s1.tag=2;
		}
	}
	for(j=0;j<c;j++)
	{
	k=deque(q);
	if(k!='*')
	temp1=k;
	k=deque(q);
	if(k!='*')
	temp2=k;
	k=deque(q);
	if(k!='*')
	temp3=k;
	}
	
}
