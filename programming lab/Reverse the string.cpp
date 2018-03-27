#include<iostream>
#include<string.h>
using namespace std;
class reverse
{
	private :
		char *rear;
		char *front;
		int length;
			
	public:
		reverse()
		{
			rear=NULL;
			front=NULL;
		}
		reverse(char *str)
		{
			front=str;
			rear=str+strlen(str)-1;
		}
		char* getrear()
		{
			return rear; 
		}
		char* getfront()
		{
			return front;
		}
		int getlength()
		{
			return length;
		}
		void setlength(char str[])
		{
			length=strlen(str);
		}
		void reverseodd(char*);
		void reverseeven(char*);
};
void reverse:: reverseodd(char str[])
{
	char temp;
	int i=1;
	while(rear!=front)
	{
		temp=*front;
		*front=*rear;
		*rear=temp;
		rear=str+strlen(str)-1-i;
		front=str+i;
		i++;
	}
}
void reverse:: reverseeven(char str[])
{
	int i=1;
	char temp;
	while(i<=strlen(str)/2)
	{
		temp=*front;
		*front=*rear;
		*rear=temp;
		rear=str+strlen(str)-1-i;
		front=str+i;
		i++;
	}
}
int main()
{
	char str[50];
	cout<<"Heartly Welcome to the Very First Program of Programming Lab\n";
	cout<<"Enter the string\n";
	cin>>str;
	reverse obj1(str);
	obj1.setlength(str);
	if(obj1.getlength()%2==0)
	{
		obj1.reverseeven(str);
	}
	else
	{
		obj1.reverseodd(str);
	}
	cout<<"Reversed string\n";
	cout<<str<<endl;
	return 0;
}
