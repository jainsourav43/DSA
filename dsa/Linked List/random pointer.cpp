#include<iostream>
#define null NULL
using namespace std;
typedef
struct rpnode
{
	char data;
	rpnode *ran;
	rpnode *next;
} *rpptr;
void random(rpptr p)
{
	rpptr t1,t2;
	t1=p;
	char ch;
	while(t1!=null)
	{
	cout<<"Enter the character where u wanna point the random of "<<t1->data<<"  ";
	cin>>ch;
	t2=t1;
	while(t2!=null)
	{
		if(t2->data==ch)
		{
			t1->ran=t2;
			break;
		}
		t2=t2->next;
	}
	t1=t1->next;
    }
}
void addend(rpptr p,char d)
{
	rpptr t1;
	t1=p;
	while(t1->next!=null)
	{
		t1=t1->next;
	}
	t1->next=new rpnode;
	t1=t1->next;
	t1->data=d;
	t1->ran=null;
	t1->next=null;
}
 void create(rpptr p)
 {
 	rpptr t1=p,t2;char d;
 	while(d!='.')
 	{
 	cout<<"Enter the first character to be inserted\n else '.' ";
 	cin>>d;
 	if(d!='.')
 	{
 		addend(t1,d);
	}
   }
 }
 void display(rpptr p)
 {
 	rpptr t1;
 	t1=p;
	 while(t1!=null)
	 {
	 	cout<<t1->data<<"   ";
	 	t1=t1->next;
	 }cout<<endl;
 }
 void display1(rpptr p)
 {
 	rpptr t1;
 	t1=p;
 	while(t1!=null)
 	{
 		cout<<t1->data<<"  ";
 		if(t1->ran!=null)
 		{
 			cout<<"->"<<t1->ran->data<<"  ";
		 }
		 t1=t1->next;
	 }
 }
 int main()
 {
 	rpptr p=new rpnode;
 	char d;
 	cout<<"Enter the first character to be inserted\n else '.' ";
 	cin>>d;
 	if(d!='.')
 	{
 		p->data=d;
 		p->ran=null;
 		p->next=null;
	}
 	create(p);
 	display(p);
 	random(p);
 	display1(p);
 	return 0;
 }
