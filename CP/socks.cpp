#include<iostream>
#define ll long long 
using namespace std;
int main()
{
ll a,b,total;
cin>>a>>b>>total;
ll total1=total-a;
ll no=total1/b;
if(no%2==0)
{
	cout<<"Lucky Chef\n";
}
else
{
	cout<<"Unlucky Chef\n";
}
}
