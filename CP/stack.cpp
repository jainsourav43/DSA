#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
struct stack
{
long long  size;
long long  top;
char ele[10000];	
};
struct st
    {
    int a;
    char ch[10000];
};
void push(stack &s1,char x )
{
	if(s1.top==s1.size-1)
	{
		//cout<<"Overflow of stack\n";
	}
	else
	{
		s1.top++;
		s1.ele[s1.top]=x;
	}
}
char pop(stack &s1)
{
	if(s1.top==-1)
	{
		cout<<"Underflow\n";
	}
	else
	{	
	return (s1.ele[s1.top--]);
	}
    return 0;
}
int main()
{
	stack s;
	long long  i,j,res,q,t;
    char str[10000],b[10000];
	s.top=-1;
	s.size=10000;
	cin>>q;
    st e[q];long long p=0;
    while(q--)
    {
        cin>>t;
        if(t==1)
         {
            cin>>str;e[p].a=1;
            //e[p].ch=str;
            strcpy(e[p].ch,str);p++;
            for(i=0;str[i]!='\0';i++)
                {
push(s,str[i]);
            }
        }
        else if(t==2)
            {
              cin>>j;e[p].a=2;

              for(i=0;i<j;i++)
                  {
                 //  e[p].ch[i]=  pop(s);
               b[i]=pop(s);
              }
             strcpy(e[p].ch,b);
            p++;
             }
        else if(t==3)
            {
            cin>>j;
            cout<<s.ele[j-1];
        }
        else if(t==4)
            {
            if(e[p-1].a==1)
                {for(i=0;e[p-1].ch[i]!='\0';i++)
                    {
                    pop(s);
}
                 p--;
}
else if(e[p-1].a==2)
  {
for(i=0;e[p-1].ch[i]!='\0';i++)
            {
            	b[i]=e[p].ch[i];
    //push(s,e[p-1].ch[i]);
}
b[i]='\0';
for(i=strlen(b)-1;i>=0;i--)
{
	push(s,b[i]);
}
p--;
}
}
    }
	return 0;
}
