#include<iostream>
using namespace std;

union ic{
	int a;
	char b;
};
struct type{
	
	int tag;
	union ic u;
};
struct queue{
	
	int size;
	int rear;
	int front;
	struct type elements[50];
};

void enqueue(struct queue &Q,struct type t)
{
	if(Q.rear==-1)
	{
		Q.rear=0;
		Q.front=0;
		Q.elements[Q.rear]=t;
	}
	else if((Q.rear+1)%Q.size==Q.front)
	{
		cout<<"\nOVERFLOW!!\n";
	}
	else
	{
		Q.rear=(Q.rear+1)%Q.size;
		Q.elements[Q.rear]=t;
	}
}

struct type dequeue(struct queue &Q)
{
	
	struct type x=Q.elements[Q.front];
	
	if(Q.rear==-1)
	{
		cout<<"\nUNDERFLOW!!!";
	}
		
	else if(Q.rear==Q.front)
	{
		Q.rear=-1;
		Q.front=-1;
		return x;
	}
	
	else
	{
		Q.front=(Q.front+1)%Q.size;
		return x;
	}
}

int main()
{
	struct queue Q;
	struct type t;
	Q.front=-1;
	Q.rear=-1;
	Q.size=50;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t.tag=1;
			t.u.a=s[i]-48;
		}
		else
		{
			t.tag=2;
			t.u.b=s[i];
		}
		enqueue(Q,t);
	}
	int tmp_int1,tmp_int2;
	char tmp_char;
	for(int i=0;i<s.length();i++)
	{
		t = dequeue(Q);
		if(t.tag == 1)
		{
			tmp_int1 = t.u.a;
		}
		else
		{
			tmp_char = t.u.b;
			if(tmp_char=='*')
			{
				t=dequeue(Q);
				i++;
				tmp_int2 = t.u.a;
				tmp_int1 = tmp_int1*tmp_int2;
				continue;
			}
			else if(tmp_char=='/')
			{
				t=dequeue(Q);
				i++;
				tmp_int2 = t.u.a;
				tmp_int1 = tmp_int1/tmp_int2;
				continue;					
			}
			t.tag = 1;
			t.u.a = tmp_int1;
			enqueue(Q,t);
			t.tag = 2;
			t.u.b = tmp_char;
			enqueue(Q,t);
			
		}		
	}
	t.tag=1;
	t.u.a=tmp_int1;
	enqueue(Q,t);
	while(Q.front!=-1)
	{
		t = dequeue(Q);
		if(t.tag==1)
		tmp_int1=t.u.a;
		else
		{
			tmp_char=t.u.b;
			tmp_int2=dequeue(Q).u.a;
			if(tmp_char=='+')
			tmp_int1=tmp_int1+tmp_int2;
			else
			tmp_int1=tmp_int1-tmp_int2;
			
		}
		
	}
	cout<<"\nANSWER: "<<tmp_int1;

	return 0;
}
