#include<iostream>
using namespace std;
char str[11][16];
int max; 
void func(int n,int l)
{
	for(i=l;i<n;i++)
	{
		if(str[i][strlen(str)-1]==str[(i+1)%n][0])
		{
			count++;
			func(n,l+1);
			if(max<count)
			{
				max=count;
			}
		}
	}
}
int main()
{
	int n,j,i,k;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>str[i];
	}
	func(n,0);
	
}
