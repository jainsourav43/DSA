#include<iostream>
#include<string.h>
using namespace std;
union u
{
	int a;
	char b;
};
struct queue
{
	int size;
	u u1[50];
	int front;
	int rear;
};
void enque(queue &q,u x)
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
	//	q.u1[q.rear]=x;
	if()

		
	}
}
u deque(queue &q)
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
		return q.u1[t];
    }    	
}
int main()
{
	char arr[50];
	queue q;
    q.size=50;
    q.rear=-1;
    q.front=-1;
    cout<<"Enter the infix expression\n";
    cin>>arr;int i;
    for(i=0;i<strlen(arr);i++)
    {
    	if(arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/')
    	q.u1.b=arr[i];
    	enque(q,q.u1);
    	else
    	enque(q,arr[i]);

	}
}
