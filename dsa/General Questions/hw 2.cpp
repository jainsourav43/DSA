#include<iostream>
using namespace std;
union u1
{
	int a1;
	float b1;
};
struct s1
{
	int g;
	char f;
	int t1;
};
union u2
{
	union u1 h;
	struct s1 i;
};
union u3
{
	int a2;
	char b2;

};
struct s2
{
int a;
union u2 *c;
union u3 *d;
int t2;
int t3;
int t4;
float e;	
};
int main()
{
	int t,y;
	struct s2 s;
	s.d=new(union u3);
	s.c=new(union u2 );
	cout<<"enter 1 for entering a2 and 2 for b2\n";
	cin>>s.t3;int te;
	if(s.t3==1)
	{
		cout<<"enter the value of int a2\n";
		cin>>s.d->a2;
		cout<<"The value of int a2\n"<<s.d->a2<<endl;
	}
	else
	{
		cout<<"enter the value of char b2\n";
		cin>>s.d->b2;
		cout<<"The value of int b2\n"<<s.d->b2<<endl;

	}
	cout<<"Enter 1 for accessing structure and 2 for union\n";
	cin>>s.t2;
	if(s.t2==1)
	{
		cout<<"Enter the value of char f and int g resp.\n";
		cin>>s.c->i.f;
		cin>>s.c->i.g;
	    cout<<"The value of char f and int g are resp.\n"<<s.c->i.f<<"  "<<s.c->i.g;
		}
	else
	{
		cout<<"Enter 1 for accessing int and 2 for float\n";
		cin>>s.t4;
		if(s.t4==1)
		{
			cout<<"Enter the value of a1\n";
			cin>>s.c->h.a1;
			cout<<"The value of a1\n "<<s.c->h.a1;
		}
		else
		{
			cout<<"Enter the value of b1\n";
			cin>>s.c->h.b1;
			cout<<"The value of b1\n   "<<s.c->h.b1;
		}
	}
return 0;
}
