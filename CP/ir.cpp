#include<iostream>
using namespace std;
class base
{
	public:
	virtual void fun()
	{
		cout<<"Hii\n";
	}
};
class derived:public base
{
	public:
	void fun()
	{
		cout<<"bye\n";
	}
};
int main()
{
	base *bp=new derived();
	bp->fun();	
}
