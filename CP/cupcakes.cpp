#include<iostream>
#include<cstring>
using namespace std;
int main()
{
int t;
cin>>t;
int n[t];
for(int i=0;i<t;i++)
{
	cin>>n[i];
}
for(int j=0;j<t;j++)
{
	{
		cout<<(n[j]/2)+1<<endl;
	}
}
	return 0;	
} 
