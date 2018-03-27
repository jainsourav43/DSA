#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long 
int m;
int flag=0;
void print(int n)
{
    if(n==m)
    {
        return ;
    }
    if(n<0)
    {
        flag=1;
    }
    if(!flag)
    {
        cout<<n<<" ";
        print(n-5);
    }
    else
    {
        cout<<n<<" ";
        print(n+5);
    }
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    m=n;
	    cout<<n<<" ";
	    print(n-5);
	    cout<<endl;
	}
	return 0;
}
