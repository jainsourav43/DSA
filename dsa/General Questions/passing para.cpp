#include<iostream>
using namespace std;
void swap1(int x,int y)
{
	int t;
	t=x;x=y;y=t;
}
void swap2(int &x,int &y)
{
	int t;
	t=x;
	x=y;
	y=t;
}
void swap3(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
void swap4(int *x,int y)
{
	int t;
	t=*x;
	*x=y;
	y=t;
}
void swap5(int x,int *y)
{
	int t;
	t=x;
	x=*y;
	*y=t;
}
void swap6(int *x,int *y)
{cout<<"&x  ="<<x<<" "<<"&y ="<<y<<endl;
	int *t;
	t=x;
	x=y;
	y=t;
	cout<<"&x  ="<<x<<" "<<"&y ="<<y<<endl;
}
int main()
{
	int a1=1,b1=10,a2=2,b2=9,a3=3,b3=8,a4=4,b4=7,a5=5,b5=6;int a6=12,b6=19;
	swap1(a1,b1);
	cout<<"a1 = "<<a1<<"b1 = "<<b1<<endl;
	swap2(a2,b2);
	cout<<"a2 = "<<a2<<"b2 = "<<b2<<endl; 
	swap3(&a3,&b3);
	cout<<"a3 = "<<a3<<"b3=  "<<b3<<endl; 
	swap4(&a4,b4);
	cout<<"a4 = "<<a4<<"b4 = "<<b4<<endl;
	swap5(a5,&b5);
	cout<<"a5 = "<<a5<<"b5 = "<<b5<<endl;
	cout<<"a6  "<<a6<<"b6  "<<b6<<endl;
	swap6(&a6,&b6);
	cout<<"a6 = "<<a6<<"b6 = "<<b6<<endl;	
	return 0;
}
