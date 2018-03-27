#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int i,j;
	vector <int >v(5,5);
	typeof(v.begin()) it=v.begin();
	for(; it!=v.end();it++)
	cout<<*it<<" ";
	return 0;
}
