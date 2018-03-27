#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=10,b;
	b=a++ + ++a;
	cout<<"a= "<<a<<endl;
	cout<<b<<endl;
	cout<<a++<<endl;
	cout<<a<<endl;
	cout<<++a<<endl;
	cout<<b<<" "<<a++<<" "<<a<<"  "<<++a<<endl;
	int index=11;
	cout<<(index&(-index))<<endl;
}
