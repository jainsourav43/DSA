#include<iostream>
#define ll long long 
#include<map>
using namespace std;
void ff(		map<ll,bool> &che)
{
	cout<<che[2147483647]<<" ";
}
int main()
{
		map<ll,bool> che;
		che[2147483647]=1;
	ff(che);
}	
